#include <iostream>
using namespace std;

short readNumber(string message) {
    short number;
    cout << message;
    cin >> number;

    return number;
}

bool checkLeapYear(short year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

short numberOfDaysInMonth(short year , short month) {
    if (month > 12 || month < 1)
        return 0;

    if (month == 2) {
        return (checkLeapYear(year)) ? 29 : 28;
    }

    short arr[7] = { 1,3,5,7,8,10,12 };

    for (short i = 0; i < 7; i++)
    {
        if (arr[i] == month)
            return 31;
    }

    return 30;
}

short numberOfDaysInMonthImprov(short year, short month) {
    if (month > 12 || month < 1)
        return 0;

    short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? ((checkLeapYear(year)) ? 29 : 28) : arr[month - 1];
}

short numberOfHoursInMonth(short year , short day) {
    return numberOfDaysInMonthImprov(year, day) * 24;
}

int numberOfMinutesInMonth(short year, short day) {
    return numberOfHoursInMonth(year, day) * 60;
}

int numberOfSecondsInMonth(short year, short day) {
    return numberOfMinutesInMonth(year, day) * 60;
}

int main()
{

    int years[] = { 1968,2004,2012,1200,1600,2000  // leap years
                ,1971,2006,2010,1700,1800,1900 }; // not leap years


    short year = readNumber("Enter the year\n");

    short month = readNumber("Enter the Month\n");

    printf("number of days in Month [%d]    is %d \n", month, numberOfDaysInMonth(year , month));
    printf("number of hours in Month [%d]   is %d \n", month, numberOfHoursInMonth(year , month));
    printf("number of minutes in Month [%d] is %d \n", month, numberOfMinutesInMonth(year , month));
    printf("number of seconds in Month [%d] is %d \n", month, numberOfSecondsInMonth(year , month));

}