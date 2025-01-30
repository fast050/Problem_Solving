#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stDate {
    short year;
    short month;
    short day;
};

string readText(string message) {
    
    string text;

    cout << message;
    cin >> text;

    return text;
}

int readNumber(string message) {
    int number;

    cout << message;
    cin >> number;

    return number;
}

stDate readDate() {
    stDate date;
    date.day = readNumber("Please enter a Day? ");;
    date.month = readNumber("Please enter a Month? ");
    date.year = readNumber("Please enter a year? ");

    return date;
}

vector<short> splitString(string date , string delimeter = "/") {

    vector<short> dateItems;
    short pos = string::npos;

    while ( (pos = date.find(delimeter)) != string::npos ) {

        string text = date.substr(0, pos);

        if (text != "")
        dateItems.push_back(stoi(text));

        date.erase(0, text.length() + delimeter.length());
    }

    if(date != "")
     dateItems.push_back(stoi(date));

    return dateItems;
}

stDate StringToDate(string date) {

    vector<short> dateItems = splitString(date);

    stDate dateItem;
    dateItem.day = dateItems[0];
    dateItem.month = dateItems[1];
    dateItem.year = dateItems[2];

    return dateItem;
}

string DateToString(stDate date) {
    return  to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}


int main()
{

    string dateInText = readText("Please Enter Date dd/mm/yyyy? ");

    stDate date = StringToDate(dateInText);

    cout << "\nDate:" << date.day << "\n";
    cout << "Month:" << date.month << "\n";
    cout << "Year:" << date.year << "\n";

    cout << "\nYou Entered: " << DateToString(date);

    system("pause>0");
}