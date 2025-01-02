
#include <iostream>
#include <iomanip>

using namespace std;

int readNumber(string message) {

    int number;

    cout << message;
    cin >> number;

    return number;

}

short dayOfWeekOrder(short year, short month, short day) {
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    //Gergorian : 
    //0:Sun, 1 :Mon, 2:Tue, 3:Wed ...etc.
    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

bool checkLeapYear(short year) {
    return (year % 400) || (year % 100 != 0 && year % 4 == 0);
}

short numberOfDayInMonth(bool isleapYear , short month) {

    if (month > 12 || month < 1)
        return 0;

    short months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return month == 2 ? (isleapYear ? 29 : 28) : months[month - 1];

}

string getMonthName(short month) {
    if (month > 12 || month < 1)
        return "";

    string monthsName[12] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" ,"Jun" ,"Jul" ,"Aug" , "Sep" ,"Oct" ,"Nov" ,"Dec" };
    return monthsName[month - 1];
}

void printMonthCalendarForm(short month , short year) {

    short numberOfDay = numberOfDayInMonth(checkLeapYear(year), month);

    short dayOrder = dayOfWeekOrder(year, month, 1);

    cout << "_______________"<<getMonthName(month)<<"_______________\n\n";
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";


    short startDay = 1;
    for (short i = 0; i < 5; i++)
    {
        for (short j = 0; j < 7; j++)
        {
            if (numberOfDay < startDay)
                break;

            if (i == 0 && j < dayOrder) {
                cout <<"     ";
            }
            else {
                cout << setw(3) << startDay << "  ";
                startDay++;
            }
                
            
        }

        cout << "\n";
    }


    cout << "_________________________________\n";


}

void printCalenderFrom(short month, short year) {

    short numberOfDay = numberOfDayInMonth(checkLeapYear(year), month);

    short dayOrder = dayOfWeekOrder(year, month, 1);

    cout << "\n_______________" << getMonthName(month) << "_______________\n\n";
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    short i;
    for ( i = 0; i < dayOrder; i++)
    {
        cout << "     ";

    }

    for (short j = 1; j <= numberOfDay; j++)
    {
        cout <<setw(3) << j << "  ";

        if (++i == 7) {
            cout << '\n';
            i = 0;
        }
    }

    cout << "\n_________________________________\n";
}


int main()
{
    short year = readNumber("Please Enter a Year? ");
    cout << "\n";
    short month = readNumber("Please Enter a Month? ");
    
    printCalenderFrom(month, year);

    system("pause>0");
}