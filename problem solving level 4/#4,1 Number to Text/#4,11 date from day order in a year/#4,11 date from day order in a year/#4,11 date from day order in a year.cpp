#include <iostream>
#include <string>

using namespace std;

int readNumber(string message) {

    int number;

    cout << message;
    cin >> number;

    return number;

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

short numberOfDayFromBeginingOfTheYear(short day, short month, short year) {

    short numberOfDayInMonths = 0;

    for (short i = 1; i < month; i++)
    {
        numberOfDayInMonths += numberOfDaysInMonth(i, year);
    }

    return numberOfDayInMonths + day;
}

string dateOfNumberOfDayFromBeginingOfTheYear(short numberOfDayFromBeginingOfTheYear, short year) {

    int monthNumber = 1;
    while ( numberOfDayFromBeginingOfTheYear - numberOfDaysInMonth(monthNumber, year) > 0) {
        numberOfDayFromBeginingOfTheYear -= numberOfDaysInMonth(monthNumber, year);
        monthNumber++;
    }

    return to_string(numberOfDayFromBeginingOfTheYear) + "/" + to_string(monthNumber) + "/" + to_string(year);
}

int main()
{
    short day = readNumber("Please enter a Day ?");
    short month = readNumber("\nPlease enter a Month?");
    short year = readNumber("\nPlease enter a Year?");

    short numberOfDay = numberOfDayFromBeginingOfTheYear(day, month, year);

    cout << "\n\nNumber of days from the begining of the year is " << numberOfDay;

    cout << "\n\ndate for [" << numberOfDay << "] is " << dateOfNumberOfDayFromBeginingOfTheYear(numberOfDay, year)<<endl;

    system("pause>0");
}