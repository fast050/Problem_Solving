// ATM System project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void ShowMainMenuScreen();

string FileClientName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

enum enMainMenuOption {

    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5
};

stClient LoginClient;

string ReadText(string message) {

    string text;

    cout << message;
    getline(cin >> ws, text);

    return text;
}

int ReadNumber(string message) {

    int number;
    cout << message;
    cin >> number;

    return number;
}

double ReadDouble(string message) {

    double number;
    cout << message;
    cin >> number;

    return number;
}

bool ReadChoiceByYOrN(string message) {

    char choice;
    cout << message << "? y/n ?";
    cin >> choice;

    return tolower(choice) == 'y';
}

void GoBackToMainMenu() {
    cout << "\n\n\nPress any key to go back to Main Menu...\n";
    system("pause>0");
    ShowMainMenuScreen();
}

void ClearScreen() {
    system("cls");
}

vector<string> SpliteString(string line, string seprator = "#//#") {

    vector<string> words;
    int pos = string::npos;

    while ((pos = line.find(seprator)) != string::npos){

        string word = line.substr(0, pos);
        if (word != "")
            words.push_back(word);

        line.erase(0, pos + seprator.length());
    }

    if (line != "")
        words.push_back(line);


    return words;
}

stClient ConvertLineToClient(string line) {

   vector<string> vLine = SpliteString(line);
   stClient client;

   client.AccountNumber = vLine[0];
   client.PinCode = vLine[1];
   client.Name = vLine[2];
   client.Phone = vLine[3];
   client.AccountBalance = stoi(vLine[4]);

   return client;
}

string ConvertClientToLine(stClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

vector<stClient> LoadClientsFromFile(string fileName) {

    fstream file;
    vector<stClient> clients;
    

    file.open(fileName, ios::in);

    if (file.is_open()) {

        string line;
        while (getline(file, line)) {
            clients.push_back(ConvertLineToClient(line));
        }

        file.close();
    }

    return clients;
}

vector<stClient> SaveClientsToFile(string fileName , vector<stClient> clients) {

    fstream file;

    file.open(fileName, ios::out);

    if (file.is_open()) {

        for (stClient& c : clients)
        {
           file << ConvertClientToLine(c) << endl;
        }

        file.close();
    }

    return clients;
}

bool FindClientByAccountNumberAndPingCode(string accountNumber, string pingCode, stClient &loginClient) {

    vector <stClient> clients = LoadClientsFromFile(FileClientName);

    for (stClient& c : clients)
    {
        if (accountNumber == c.AccountNumber && pingCode == c.PinCode)
        {
            loginClient = c;
            return true;
        }
    }

    return false;
    
}

bool UpdateClientBalance(double balance) {

    if (LoginClient.AccountBalance < balance) {
        cout << "The amount exceeds your balance make another choice.";
        return false;
    }

    vector<stClient> clients = LoadClientsFromFile(FileClientName);

    for (stClient& client : clients) {

        if (client.AccountNumber == LoginClient.AccountNumber) {
            client.AccountBalance += balance;
            LoginClient.AccountBalance = client.AccountBalance;
            SaveClientsToFile(FileClientName , clients);
            return true;
        }
    }

    return false;
}

void PerfromNormalWithdraw() {
    double withdrawAmount;

    do
    {
        withdrawAmount = ReadDouble("Enter an amount multiple of 5's? ");
    } while ((int)withdrawAmount % 5 != 0);

    bool isTransactionConfirm = ReadChoiceByYOrN("Are you sure your want perfrom this transaction");
    
    if (isTransactionConfirm)
    {
        UpdateClientBalance(-withdrawAmount);
        cout << "Done Successfully. New Balance is : " << LoginClient.AccountBalance << endl;
    }
}

void ShowNormalWithdraw() {

    cout << "=================================\n";
    cout << "\tNormal Withdraw Screen\n";
    cout << "=================================\n";
    PerfromNormalWithdraw();
}

void ShowLoginScreen() {
    bool isLoginFailed = false;
    string accountNumber , pingCode;

    do {
       
        ClearScreen();

        cout << "--------------------------------\n";
        cout << "\tLogin Screen\n";
        cout << "--------------------------------\n";

        if (isLoginFailed) {
            cout << "Invald Account Number/PinCode!\n";
        }

        accountNumber = ReadText("Enter Account Number? ");
        pingCode = ReadText("Enter Pin? ");

        isLoginFailed = !FindClientByAccountNumberAndPingCode(accountNumber, pingCode, LoginClient);

    } while (isLoginFailed);

    ShowMainMenuScreen();
}

void PerformQuickWithdraw(int choice)  {

    bool isTransactionConfirm = ReadChoiceByYOrN("Are you sure your want perfrom this transaction");

    if (choice >= 9 || choice < -1 || !isTransactionConfirm) {
        return;
    }
       
    int withdrawOptions[] = { 0 , 20 , 50 , 100 , 400 ,  600 , 800 , 1000 };

    if (UpdateClientBalance(-(withdrawOptions[choice]))) {
        cout << "Done Successfully. New Balance is : " << LoginClient.AccountBalance << endl;
    }
}

void ShowQuickWithdrawScreen() {
    cout << "=================================\n";
    cout << "\tQuick Withdraw\n";
    cout << "=================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "=================================\n";
    cout << "Your Balance is " << LoginClient.AccountBalance;
    int choice = ReadNumber("Choose what to withdraw from [1] to 6]? ");
    PerformQuickWithdraw(choice);
}

void PerformDeposit() {

    double depositAmount = ReadDouble("Enter a positive Deposit Amount? ");
    bool isTransactionConfirm = ReadChoiceByYOrN("Are you sure your want perfrom this transaction");

    if (isTransactionConfirm)
    {
        UpdateClientBalance(depositAmount);
        cout << "Done Successfully. New Balance is : " << LoginClient.AccountBalance << endl;
    }
}

void ShowDepositScreen() {
    cout << "=================================\n";
    cout << "\tDeposit Screen\n";
    cout << "=================================\n";
    PerformDeposit();
}

void ShowCheckBalanceScreen() {

    cout << "=================================\n";
    cout << "\tCheck Balance Screen\n";
    cout << "=================================\n";
    
    cout << "Your Balance is " << LoginClient.AccountBalance;
}

void PerfromMainMenuOptions(enMainMenuOption option) {
    ClearScreen();

    switch (option)
    {
    case eQuickWithdraw:
        ShowQuickWithdrawScreen();
        GoBackToMainMenu();
        break;
    case eNormalWithdraw:
        ShowNormalWithdraw();
        GoBackToMainMenu();
        break;
    case eDeposit:
        ShowDepositScreen();
        GoBackToMainMenu();
        break;
    case eCheckBalance:
        ShowCheckBalanceScreen();
        GoBackToMainMenu();
        break;
    case eLogout:
        ShowLoginScreen();
        break;
    default:
        break;
    }
}

void ShowMainMenuScreen() {
    ClearScreen();

    cout << "=================================\n";
    cout << "\tATM Main Menu Screen\n";
    cout << "=================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "=================================\n";
    int choice =  ReadNumber("Choose what do you want to do ? [1 to 5]? ");
    PerfromMainMenuOptions((enMainMenuOption)choice);
}

int main()
{
    ShowLoginScreen();
    system("puase>0");
}