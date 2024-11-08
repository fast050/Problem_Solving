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
};

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

stClient getClient(vector<string> words) {

    stClient client;

    client.accountNumber = words[0];
    client.pinCode = words[1];
    client.name = words[2];
    client.phone = words[3];
    client.accountBalance = stoi(words[4]);

    return client;
}

vector<stClient> readClientFromRecordInFile(string fileName) {

    fstream myFile;
    vector<stClient> clients;

    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {

        string line;
        while (getline(myFile, line)) {

            if (line != "") {
                clients.push_back(getClient(spiltString(line, "#//#")));
                //cout << line << endl;
            }

        }

        myFile.close();
    }

    return clients;
}

short findRecordByName(vector<stClient> clients, string accountName) {


    for (short i = 0; i < clients.size(); i++)
    {
        if (clients[i].accountNumber == accountName)
            return i;
    }

    return -1;
}

void printClient(stClient client) {

    cout << "Account Number : " << client.accountNumber << "\n";
    cout << "Pin Code : " << client.pinCode << "\n";
    cout << "Name  : " << client.name << "\n";
    cout << "Phone  : " << client.phone << "\n";
    cout << "Account Balance : " << client.accountBalance << "\n";

}


int main()
{
    vector<stClient> clients = readClientFromRecordInFile("myFile.txt");
    short index = 0;
    string accountNumber = "A152";


    if ((index = findRecordByName(clients, accountNumber)) != -1 )
        printClient(clients[index]);
    else
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";


    system("pause>0");
}