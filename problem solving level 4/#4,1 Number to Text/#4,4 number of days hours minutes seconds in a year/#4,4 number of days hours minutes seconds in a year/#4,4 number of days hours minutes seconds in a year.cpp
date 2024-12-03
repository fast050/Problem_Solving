#include <iostream>
using namespace std;

int readNumber(string message) {

    int number;

    cout << message;
    cin >> number;

    return number;

}

bool inCheckLeapYearImprov(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool checkLeapYearImpr(short year) {
    return ((year % 4 == 0 && year % 100 > 0) || (year % 100 == 0 && year % 400 == 0));
}

short numberOfDayInYear(short year) {
    return checkLeapYearImpr(year) ? 366 : 365;
}

short numberOfHoursInYear(short year) {
    return numberOfDayInYear(year) * 24;
}

int numberOfMinutesInYear(short year) {
    return numberOfHoursInYear(year) * 60;
}

int numberOfSecondsInYear(short year) {
    return numberOfMinutesInYear(year) * 60;
}


int main()
{
    int years[] = { 1968,2004,2012,1200,1600,2000  // leap years
                 ,1971,2006,2010,1700,1800,1900 }; // not leap years

    
    short year = readNumber("Enter the year\n");

    printf("number of days in Year [%d]    is %d \n", year, numberOfDayInYear(year));
    printf("number of hours in Year [%d]   is %d \n", year, numberOfHoursInYear(year));
    printf("number of minutes in Year [%d] is %d \n", year, numberOfMinutesInYear(year));
    printf("number of seconds in Year [%d] is %d \n", year, numberOfSecondsInYear(year));
}
