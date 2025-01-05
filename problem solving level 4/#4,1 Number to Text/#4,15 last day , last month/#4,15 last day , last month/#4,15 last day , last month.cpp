
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

bool isLastDayInMonth(short day, short month , short year) {
    return numberOfDayInMonth(month, year) == day;
}

bool isLastMonthInYear(short month) {
    return month == 12;
}

int main()
{
    stDate date = readDate();
    cout << endl;

    if (isLastDayInMonth(date.day , date.month , date.year))
        cout << "\nYes, Day is last day in month";
    else
        cout << "\nNo, Day is not last day in month";

    if (isLastMonthInYear(date.month))
        cout << "\nYes, Month is last day in year";
    else
        cout << "\nNo, Month is not last day in year";

}
