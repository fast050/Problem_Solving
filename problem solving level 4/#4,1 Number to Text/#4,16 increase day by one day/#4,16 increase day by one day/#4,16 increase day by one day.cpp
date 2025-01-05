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

bool isLeapYear(short year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

short numberOfDayInMonth(short month, short year) {

    if (month > 12 || month < 1)
        return 0;

    short monthsDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return month == 2 ? (isLeapYear(year) ? 29 : 28) : monthsDays[month - 1];
}

stDate increaseDateByOne(stDate date) {

    date.day++;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {

        date.day = 1;
        date.month++;

        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
        

    return date;
}

int main()
{
    stDate finalDate = increaseDateByOne(readDate());


    cout << "\nDate after adding a day is : " <<
        finalDate.day << "/" << finalDate.month << "/" << finalDate.year << endl;
}