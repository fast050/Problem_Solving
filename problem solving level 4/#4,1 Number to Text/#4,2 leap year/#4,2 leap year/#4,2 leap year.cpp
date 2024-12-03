

#include <iostream>
using namespace std;

int readNumber(string message) {

    int number;

    cout << message;
    cin >> number;

    return number;

}

bool checkLeapYear(short year) {

    if (year % 4 == 0 && year % 100 > 0)
        return true;

    if (year % 100 == 0 && year % 400 == 0)
        return true;

    return false;
}

bool inCheckLeapYear(short year) {

    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}

bool inCheckLeapYearImprov(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool checkLeapYearImpr(short year) {
    return ((year % 4 == 0 && year % 100 > 0) || (year % 100 == 0 && year % 400 == 0));
}

int main()
{
    int years[] = { 1968,2004,2012,1200,1600,2000,1971,2006,2010,1700,1800,1900 };

    for (short i = 0; i < 12; i++)
    {
        if (checkLeapYearImpr(years[i]))
            cout << "year " << years[i] << " is leap year \n";
        else
            cout << "year " << years[i] << " is not leap year \n";
    }
} 
