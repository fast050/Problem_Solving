#include <iostream>

using namespace std;

struct stDate {
    short year;
    short month;
    short day;
};

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

bool isDate1LessThenDate2(stDate date1, stDate date2) {
    return date1.year < date2.year ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false);
}

bool isDate1EqualDate2(stDate date1, stDate date2) {
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.month;
}

bool isDate1AfterDate2(stDate date1, stDate date2) {
    return !isDate1LessThenDate2(date1, date2) && !isDate1EqualDate2(date1, date2);
}

int main()
{
    stDate date1 = readDate();
    cout << endl;
    stDate date2 = readDate();

    if (isDate1AfterDate2(date1, date2))
        cout << "\nYes, Date1 is after date2";
    else
        cout << "\nNo, date1 is not after date2";
}