
#include <iostream>

using namespace std;

struct stDate {
    short year;
    short month;
    short day;
};

struct stPeriod {
    stDate start;
    stDate end;
};

enum enDateCompare {
    Before = -1,
    Equal = 0,
    After = 1
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


bool isLearYear(short year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

short numberOfDaysInMonth(short month, short year) {

    if (month > 12 || month < 1)
        return 0;

    int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return  month == 2 ? (isLearYear(year) ? 29 : 28) : monthDays[month - 1];
}

bool isValidDate(stDate date) {
    return (date.month <= 12 && date.month >= 1) && (numberOfDaysInMonth(date.month, date.year) >= date.day);
}


int main()
{
    stDate Date1 = readDate();
    if (isValidDate(Date1))
        cout << "\nYes, Date is a valide date.\n";
    else
        cout << "\nNo, Date is a NOT valide date\n";
    system("pause>0");
}