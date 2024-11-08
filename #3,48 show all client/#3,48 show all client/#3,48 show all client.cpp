
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct stClient {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    string accountBalance;
};

string verticalDash(short number , char symbol = '-') {
	
    string result = "";
    for (short i = 0; i < number; i++)
	{
        result += symbol;
	}

    return result;
}

vector<string> splitString(string text, string delimiter) {

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

stClient convertRecordToClient(string text , string delimiter) {

    stClient client;

    vector<string> words = splitString(text, delimiter);
    client.accountNumber = words[0];
    client.pinCode = words[1];
    client.name = words[2];
    client.phone = words[3];
    client.accountBalance = words[4];

    return client;
}

vector<stClient> readRecordFromFileAndConvertToVector(string fileName) {

    fstream myFile;
    vector<stClient> clients;

    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {
        
        string line;
        while (getline(myFile, line)) {
            if (line != "") {
                clients.push_back(convertRecordToClient(line, "#//#"));
            }
        }

        myFile.close();
    }

    return clients;
}

void printClientRecord(stClient Client)
{
    cout << "| " << setw(15) << left << Client.accountNumber;
    cout << "| " << setw(10) << left << Client.pinCode;
    cout << "| " << setw(40) << left << Client.name;
    cout << "| " << setw(12) << left << Client.phone;
    cout << "| " << setw(12) << left << Client.accountBalance;
    cout << endl;
}

void printClient(vector<stClient> clients) {

    cout << "\n\t\t\t\t\tClient List (" << clients.size() << ")Client(s).";
    cout <<"\n" << verticalDash(100) << "\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "pin Number";
    cout << "| " << left << setw(40) << "client Name";
    cout << "| " << left << setw(12) << "phone";
    cout << "| " << left << setw(12) << "Account Balance" ;
    cout << endl;
    cout << verticalDash(100) << "\n\n";
    for (short i = 0; i < clients.size(); i++)
    {
        printClientRecord(clients[i]);
    }

    cout << verticalDash(100) << "\n\n";



}

int main()
{
    printClient(readRecordFromFileAndConvertToVector("MyFile.txt"));

}