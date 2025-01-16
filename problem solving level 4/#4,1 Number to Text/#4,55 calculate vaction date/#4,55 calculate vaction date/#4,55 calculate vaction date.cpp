#include <iostream>

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

short numberOfDayFromBeginingOfYear(short day, short month, short year) {

    short totalDays = 0;

    for (short i = 1; i < month; i++)
    {
        totalDays += numberOfDayInMonth(i, year);
    }

    return totalDays + day;
}

bool isDate1LessThenDate2(stDate date1, stDate date2) {
    return date1.year < date2.year ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false);
}

void swapDates(stDate& date1, stDate& date2) {

    stDate temp;
    temp.year = date1.year;
    temp.month = date1.month;
    temp.day = date1.day;

    date1.year = date2.year;
    date1.month = date2.month;
    date1.day = date2.day;

    date2.year = temp.year;
    date2.month = temp.month;
    date2.day = temp.day;
}

short dayOfWeekOrder(short day, short month, short year) {
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    //Gergorian : 
    //0:Sun, 1 :Mon, 2:Tue, 3:Wed ...etc.
    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

short dayOfWeekOrder(stDate date) {
    return dayOfWeekOrder(date.day, date.month, date.year);
}

string dayShortName(short dayOfWeekOrder) {
    string days[] = { "Sun" , "Mon" , "Tur" , "Web" , "Thu" , "Fri" , "Sat" };
    return days[dayOfWeekOrder];
}

bool isWeekEnd(stDate date) {
    // holiday at Sat(6) , Sun(0)

    short dayOrder = dayOfWeekOrder(date.day, date.month, date.year);

    return  dayOrder == 6 || dayOrder == 0;
}

bool isBusinessDay(stDate date) {
    return !isWeekEnd(date);
}

stDate increaseOneDay(stDate date) {

    date.day++;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.month++;
        date.day = 1;
    }

    if (date.month > 12) {
        date.year++;
    }

    return date;
}

stDate calculateVactionReturnDate(stDate start, short vactionDays) {

    while (vactionDays != 0) {
        vactionDays -= isBusinessDay(start);
        start = increaseOneDay(start);
    }

    return start;
}

int main()
{
    cout << "Vacation Start: \n";
    stDate startVactionDate = readDate();
   
    short vactionDays = readNumber("\nPlease enter vaction days ? ");

    stDate returnDate = calculateVactionReturnDate(startVactionDate, vactionDays);

    cout << "\nReturn Date : " << dayShortName(dayOfWeekOrder(returnDate)) << " , " <<
        returnDate.day << "/" << returnDate.month << "/" << returnDate.year;
   

    system("pause>0");
}