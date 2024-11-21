#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
const string ClientsFileName = "Clients.txt";


enum enTransactionsMenuOption {
    eDeposit = 1,
    eWithDraw = 2,
    eTotalBalance = 3,
    eMainMenu = 4
};

void perfromTransactionsMenueOption(enTransactionsMenuOption);
void showTransactionMenu();
void transactionsScreen();
void startBanking();

struct stClient {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    float accountBalance;
    bool isMarkForDelete = false;
};

enum enMainMenuOption {

    eListClients = 1, 
    eAddNewClient = 2,
    eDeleteClient = 3, 
    eUpdateClient = 4,
    eFindClient = 5,
    eTransactions = 6,
    eExit = 7
};

string readText(string message) {
    string text;

    cout << message;
    getline(cin >> ws, text);

    return text;
}

char readCharacter(string message) {
    char character;
    cout << message;
    cin >> character;

    return character;
}

short readNumber(string text) {

    short number;

    cout << text;
    cin >> number;

    return number;
}

double readDouble(string text) {
    double number;

    cout << text;
    cin >> number;

    return number;
}

stClient readClient(string accountNumber) {

    stClient c;

    c.accountNumber = accountNumber;

    cout << "\nEnter Client Pin Number? ";
    getline(cin >> ws, c.pinCode);

    cout << "Enter Client Name? ";
    getline(cin, c.name);

    cout << "Enter Client Phone? ";
    getline(cin, c.phone);

    cout << "Enter Client Account Balance? ";
    cin >> c.accountBalance;

    return c;
}

void enterToMainScreen()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    startBanking();
}

void enterToTransactionScreen()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    transactionsScreen();
}

void clearScreen() {
    system("cls");
}

void printClient(stClient client) {
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------\n";
    cout << "Account Number : " << client.accountNumber<<"\n";
    cout << "Pin Code       : " << client.pinCode << "\n";
    cout << "name           : " << client.name << "\n";
    cout << "phone          : " << client.phone << "\n";
    cout << "Account Balance: " << client.accountBalance << "\n";
    cout << "-----------------------------------\n";
}

vector<string> spiltString(string text, string delimiter) {
    
    string word = "";
    int pos = string::npos;
    vector<string> words;

    while ((pos = text.find(delimiter)) != string::npos) {

        word = text.substr(0, pos);

        if (word != "") {
            words.push_back(word);
        }

        text.erase(0, pos + delimiter.length());
    }

    if (text != "") {
        words.push_back(text);
    }

    return words;
}

stClient getClient(vector<string> words) {

    stClient client;

    client.accountNumber = words[0];
    client.pinCode = words[1];
    client.name = words[2];
    client.phone = words[3];
    client.accountBalance = stof(words[4]);
    
    return client;
}

string getLineFromClient(stClient client , string delimiter) {
    string line = "";
    
    line += client.accountNumber + delimiter;
    line += client.pinCode + delimiter;
    line += client.name + delimiter;
    line += client.phone + delimiter;
    line += to_string(client.accountBalance);

    return line;
}

vector<stClient> loadClientDataFromFile(string fileName) {
    fstream myFile;
    vector<stClient> clients;

    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {

        string line;
        while (getline(myFile, line)) {

            vector<string> words = spiltString(line, "#//#");
            stClient client = getClient(words);
            clients.push_back(client);

        }

        myFile.close();
    }

    return clients;
}

float totalBalance(vector<stClient> clients) {

    float total = 0.0;

    for (stClient& c : clients) {
        total += c.accountBalance;
    }

    return total;
}

void markClientForDelete(vector<stClient>& clients, string accountNumber) {

    for (stClient& c : clients) {
        if (c.accountNumber == accountNumber) {
            c.isMarkForDelete = true;
            break;
        }
    }
}

void updateClientInClients(vector<stClient>& clients, string accountNumber) {
    for (stClient& c : clients) {
        if (c.accountNumber == accountNumber) {
            c = readClient(accountNumber);
            break;
        }
    }
}

void updateClientAmountInClients(vector<stClient>& clients, string accountNumber , double amount) {
    for (stClient& c : clients) {
        if (c.accountNumber == accountNumber) {
            c.accountBalance += amount;
            break;
        }
    }
}

void saveClientDateIntoFile(string fileName , vector<stClient> clients) {
    fstream myFile;

    myFile.open(fileName, ios::out);
    if (myFile.is_open()) {
        
        for (stClient& c : clients) {
            if (c.isMarkForDelete == false) {
              myFile << getLineFromClient(c , "#//#") << "\n";
            }
        }
        
        
        myFile.close();
    }

}

void addClientDataIntoFile(string fileName, string clientToLine) {

    fstream myfile;

    myfile.open(fileName, ios::out | ios::app);
    if (myfile.is_open()) {

        if (clientToLine != "") {
            myfile << clientToLine << "\n";
        }
        myfile.close();

    }

}

bool findClientByAccountNumber(string accountNumber ,vector<stClient> clients , stClient &client) {
    
    for (stClient& c : clients) {
        if (c.accountNumber == accountNumber) {
            client = c;
            return true;
        }
    }
    return false;
}

bool isClientByAccountNumberExit(string accountNumber, vector<stClient> clients) {

    for (stClient& c : clients) {
        if (c.accountNumber == accountNumber) {
            return true;
        }
    }
    return false;
}

void showClientListScreen() {

    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);

    cout << "\n                      Client List ("<<clients.size()<<") Client(s).\n";
    cout << "_____________________________________________________________________________\n" << endl;

    cout << "| Account Number | Pin Code | Client Name             | Phone       | Balance\n";
    cout << "_____________________________________________________________________________\n" << endl;


    if (clients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
    for (short i = 0; i < clients.size(); i++)
    {
       cout << "| " << left <<setw(15) << clients[i].accountNumber
            << "| " << left << setw(9) << clients[i].pinCode
            << "| " << left << setw(24) << clients[i].name
            << "| " << left << setw(12) << clients[i].phone
            << "| " << left << setw(7) << clients[i].accountBalance<<"\n";
    }
    cout << "\n_____________________________________________________________________________\n" << endl;

}

void addNewClient(string accountNumber) {
    stClient client = readClient(accountNumber);
    addClientDataIntoFile(ClientsFileName, getLineFromClient(client, "#//#"));
}

void addNewClients() {
    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);

    char choice = 'y';

    do {

        string accountNumber = readText("\nEnter Account Number? ");
        while (isClientByAccountNumberExit(accountNumber, clients)) {
            accountNumber = readText("Client with [" + accountNumber + "] already exists, Enter another Account Number? ");
        }

        addNewClient(accountNumber);

        choice = readCharacter("\nClient Added Successfully , do you want to add more clients? Y/N? ");

    } while (toupper(choice) == 'Y');

}

void deleteClientByAccountNumber(string accountNumber) {
    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);

    stClient client;
    char choice = 'y';

    while (!findClientByAccountNumber(accountNumber, clients, client)) {
        accountNumber = readText("Client with [" + accountNumber + "] not exists! , Enter another Account Number? ");
    }

    printClient(client);

    choice = readCharacter("\ndo you want to delete this client? Y/N? ");

    if (toupper(choice) == 'Y') {
        markClientForDelete(clients, accountNumber);
        saveClientDateIntoFile(ClientsFileName, clients);
        cout << "\nClient Delete Successfully.\n";
    }
}

void updateClientByAccountNumber(string accountNumber) {
    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);
    char choice = 'y';

    stClient client;

    while (!findClientByAccountNumber(accountNumber, clients, client)) {
        accountNumber = readText("Client with [" + accountNumber + "] not exists!, Enter another Account Number? ");
    }

    printClient(client);

    choice = readCharacter("\ndo you want to update this client? Y/N? ");

    if (toupper(choice) == 'Y') {
        updateClientInClients(clients, accountNumber);
        saveClientDateIntoFile(ClientsFileName, clients);
        cout << "\nClient Update Successfully.\n";
    }
}

void findClientByAccountNumber(string accountNumber) {
    stClient client;
    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);


    while (!findClientByAccountNumber(accountNumber, clients, client)) {
        accountNumber = readText("Client with [" + accountNumber + "] not exists! , Enter another Account Number? ");
    }

    printClient(client);
}

void depositByAccountNumber(string accountNumber) {

    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);
    char choice = 'y';
    stClient client;


    while (!findClientByAccountNumber(accountNumber, clients, client)) {
        accountNumber = readText("Client with [" + accountNumber + "] not exists!, Enter another Account Number? ");
    }

    printClient(client);

    double depositAmount = readDouble("Please enter deposit amount? ");

    choice = readCharacter("\nAre you sure you want perform this transaction? Y/N? ");

    if (toupper(choice) == 'Y') {
        updateClientAmountInClients(clients, client.accountNumber, depositAmount);
        saveClientDateIntoFile(ClientsFileName, clients);
        cout << "Deposit Added Successfully , Total Balance Amount is " << client.accountBalance + depositAmount << "\n";
    }
}

void withDrawByAccountNumber(string accountNumber) {
    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);
    char choice = 'y';
    stClient client;

    while (!findClientByAccountNumber(accountNumber, clients, client)) {
        accountNumber = readText("Client with [" + accountNumber + "] not exists!, Enter another Account Number? ");
    }

    printClient(client);

    double depositAmount = readDouble("Please enter deposit amount? ");

    while (client.accountBalance < depositAmount) {
        depositAmount = readDouble("deposit amount exceeds the limit you can withDraw "+
            to_string(client.accountBalance) +
            ", Please enter valid deposit amount ? ");
    }

    choice = readCharacter("\nAre you sure you want perform this transaction? Y/N? ");

    if (toupper(choice) == 'Y') {

        updateClientAmountInClients(clients, client.accountNumber, -depositAmount);
        saveClientDateIntoFile(ClientsFileName, clients);
        cout << "Deposit Added Successfully , Total Balance Amount is " << client.accountBalance - depositAmount << "\n";
    }
}

void addNewClientScreen() {



    cout << "--------------------------------------------\n";
    cout << "         Add New Clients Screen\n";
    cout << "--------------------------------------------\n";
    cout << "Adding New Client:\n";

    addNewClients();
}

void deleteClientScreen() {

    cout << "--------------------------------------------\n";
    cout << "          Delete Clients Screen\n";
    cout << "--------------------------------------------\n";
   
    string accountNumber = readText("Please enter AccountNumber? ");
    deleteClientByAccountNumber(accountNumber);
}

void updateClientScreen() {

    cout << "--------------------------------------------\n";
    cout << "          Update Clients Screen\n";
    cout << "--------------------------------------------\n";
    cout << "Adding New Client:\n";


   
    string accountNumber = readText("\nEnter Account Number? ");
    updateClientByAccountNumber(accountNumber);
   
}

void findClientScreen() {


    cout << "--------------------------------------------\n";
    cout << "          Find Clients Screen\n";
    cout << "--------------------------------------------\n";

    string accountNumber = readText("Please enter AccountNumber? ");
    findClientByAccountNumber(accountNumber);

}

void transactionsScreen() {
    clearScreen();
    showTransactionMenu();
    short choice = readNumber("Choose what do you want to do ? [1 to 4]? ");
    perfromTransactionsMenueOption((enTransactionsMenuOption)choice);
}

void DepositScreen() {


    cout << "--------------------------------------------\n";
    cout << "            Deposit Screen\n";
    cout << "--------------------------------------------\n";
    string accountNumber = readText("\nEnter Account Number? ");
    depositByAccountNumber(accountNumber);
   
}

void WithDrawScreen() {
   

    cout << "--------------------------------------------\n";
    cout << "            With Draw Screen\n";
    cout << "--------------------------------------------\n";
    string accountNumber = readText("\nEnter Account Number? ");
    withDrawByAccountNumber(accountNumber);
   
}

void TotalBalancesTransactionScreen() {
    vector<stClient> clients = loadClientDataFromFile(ClientsFileName);

    cout << "\n                      Client List (" << clients.size() << ") Client(s).\n";
    cout << "_____________________________________________________________________________\n" << endl;

    cout << "| Account Number | Client Name             | Balance\n";
    cout << "_____________________________________________________________________________\n" << endl;


    if(clients.size() > 0)
    for (short i = 0; i < clients.size(); i++)
    {
        cout << "| " << left << setw(15) << clients[i].accountNumber
            << "| " << left << setw(24) << clients[i].name
            << "| " << left << setw(8) << clients[i].accountBalance << "\n";
    }
    else
        cout << "\t\t no Client Avaliable right now.\n";

    cout << "\n_____________________________________________________________________________\n" << endl;
    cout << "\n                     Total Balance = "<< totalBalance(clients) <<"\n";


}

void exitScreen() {
    cout << "--------------------------------------------\n";
    cout << "            Progam Ends ;-)\n";
    cout << "--------------------------------------------\n";
    
}

void showTransactionMenu() {
    cout << "=====================================================\n";
    cout << "             Transactions Menu Screan           \n";
    cout << "=====================================================\n";
    cout << "       [1] Deposit.\n";
    cout << "       [2] WithDraw.\n";
    cout << "       [3] Total Balances.\n";
    cout << "       [4] Main Menu.\n";
    cout << "=====================================\n";
}

void showMainMenu() {
    cout << "=====================================\n";
    cout << "          Main Menu Screan           \n";
    cout << "=====================================\n";
    cout << "       [1] Show Client List.\n";
    cout << "       [2] Add New Client.\n";
    cout << "       [3] Delete Client.\n";
    cout << "       [4] Update Client Info.\n";
    cout << "       [5] Find Client.\n";
    cout << "       [6] Transactions.\n";
    cout << "       [7] Exit.\n";
    cout << "=====================================\n";
}

void perfromMainMenueOption(enMainMenuOption choice) {
    clearScreen();

    switch (choice)
    {
    case enMainMenuOption::eListClients:
        showClientListScreen();
        enterToMainScreen();
        break;
    case enMainMenuOption::eAddNewClient:
        addNewClientScreen();
        enterToMainScreen();
        break;
    case enMainMenuOption::eDeleteClient:
        deleteClientScreen();
        enterToMainScreen();
        break;
    case enMainMenuOption::eUpdateClient:
        updateClientScreen();
        enterToMainScreen();
        break;
    case enMainMenuOption::eFindClient:
        findClientScreen();
        enterToMainScreen();
        break;
    case enMainMenuOption::eTransactions:
        transactionsScreen();
        enterToMainScreen();
    case enMainMenuOption::eExit:
        exitScreen();
        break;

    default:
        break;
    }
}

void perfromTransactionsMenueOption(enTransactionsMenuOption choice) {
    clearScreen();

    switch (choice)
    {
    case eDeposit:
        DepositScreen();
        enterToTransactionScreen();
        break;
    case eWithDraw:
        WithDrawScreen();
        enterToTransactionScreen();
        break;
    case eTotalBalance:
        TotalBalancesTransactionScreen();
        enterToTransactionScreen();
        break;
    case eMainMenu:
        enterToMainScreen();
        break;
    default:
        break;
    }
}

void startBanking() {
  
  clearScreen();
  showMainMenu();
  short choice = readNumber("Choose what do you want to do ? [1 to 7]? ");
  perfromMainMenueOption((enMainMenuOption)choice);
        
}

int main()
{
    startBanking();
    system("pause>0");
}