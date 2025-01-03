

#include <iostream>

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

short numberOfDaysInMonth(short month , short year) {
    
    if (month > 12 || month < 1)
        return 0;

    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return  month == 2 ? (isLearYear(year) ? 29 : 28) : monthDays[month - 1];
}

int numberOfDayFromBeginingOfTheYear(short day , short month, short year) {

    short numberOfDayInMonths = 0;

    for ( short i = 1; i < month ; i++)
    {
        numberOfDayInMonths += numberOfDaysInMonth(i, year);
    }

    return numberOfDayInMonths + day;
}

int main()
{
    short day = readNumber("Please enter a Day ?");
    short month = readNumber("\nPlease enter a Month?");
    short year = readNumber("\nPlease enter a Year?");

    cout << "\n\nNumber of days from the begining of the year is " << numberOfDayFromBeginingOfTheYear(day, month, year);
}