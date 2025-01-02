// #4,7 Day name.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

short dayOfWeekOrder(short year, short month , short day) {
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    //Gergorian : 
    //0:Sun, 1 :Mon, 2:Tue, 3:Wed ...etc.
    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string getDayName(short dayOfWeekOrder) {

    switch (dayOfWeekOrder) {
    
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thurday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    }

    return "";
}

int main()
{
  
    cout << getDayName(dayOfWeekOrder(1953, 8, 2));

}