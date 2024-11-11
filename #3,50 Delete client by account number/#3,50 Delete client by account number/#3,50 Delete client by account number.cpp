#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct stClient {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    int accountBalance;
    bool isMarkToDelete = false;
};

string readText(string message) {
    string text;

    cout << message;
    getline(cin >> ws, text);

    return text;
}

vector<string> spiltString(string text, string delimiter) {

    short pos = string::npos;
    string word = "";
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

string joinString(vector<string> words, string delimiter = "#//#") {

    string result = "";
    for (string& word : words) {
    
        result += word + delimiter;
    }

    return result.substr(0, result.length() - delimiter.length());
}

stClient getClient(vector<string> words) {
    stClient client;

    client.accountNumber = words[0];
    client.pinCode = words[1];
    client.name = words[2];
    client.phone = words[3];
    client.accountBalance = stoi(words[4]);

    return client;
}

vector<stClient> loadCleintsDataFromFile(string fileName) {
    fstream myFile;
    vector<stClient> clients;

    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {

        string line;

        while (getline(myFile, line)) {

            if (line != "") {
                vector<string> words = spiltString(line, "#//#");
                stClient client = getClient(words);
                clients.push_back(client);
            }

        }
        myFile.close();
    }

    return clients;
}

vector<string> clientToVector(stClient client) {

    vector<string> words;

    words.push_back(client.accountNumber);
    words.push_back(client.pinCode);
    words.push_back(client.name);
    words.push_back(client.phone);
    words.push_back(to_string(client.accountBalance));

    return words;
}

void saveClientDataIntoFile(string fileName , vector<stClient> clients) {

    fstream myFile;

    myFile.open(fileName, ios::out);
    if (myFile.is_open()) {

        for (stClient& client : clients) {

            if (client.isMarkToDelete == false) {
              vector<string> words = clientToVector(client);
              string record = joinString(words);
              myFile << record << "\n";
            }
           
        }
        myFile.close();
    }

}

void printClient(stClient client) {
    cout << "Account Number : " << client.accountNumber << "\n";
    cout << "Pin Code : " << client.pinCode << "\n";
    cout << "Name  : " << client.name << "\n";
    cout << "Phone  : " << client.phone << "\n";
    cout << "Account Balance : " << client.accountBalance << "\n";

}

bool findClientByAccountNumber(string accountNumber, vector<stClient> clients, stClient& client) {

    for (stClient& c : clients) {
        if (c.accountNumber == accountNumber) {
            client = c;
            return true;
        }
   }

    return false;
}

void markClientToDelete(stClient client, vector<stClient>& clients) {

    for (stClient& c : clients) {
        if (c.accountNumber == client.accountNumber) {
            c.isMarkToDelete = true;
        }
    }

}


int main()
{
    vector<stClient> clients = loadCleintsDataFromFile("MyFile.txt");
    stClient client;
    string accountNumber = readText("Enter Account Number \n");

    if (findClientByAccountNumber(accountNumber , clients , client)) {
        printClient(client);

        char choice;

        cout << "Do you want to delete this client? [Y/N]";
        cin >> choice;

        if (tolower(choice) == 'y') {
            markClientToDelete(client, clients);
            saveClientDataIntoFile("MyFile - Copy.txt", clients);
            printf("Client with AccountNumber:%s is Delete Successfully.", accountNumber);
        }
    }
    else
        cout << "Client with Account number : (" << accountNumber << ") Not exsit!";


    system("pause>0");
    
}