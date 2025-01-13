#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

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

short dayOfWeekOrder(short day, short month, short year) {
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    //Gergorian : 
    //0:Sun, 1 :Mon, 2:Tue, 3:Wed ...etc.
    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string dayShortName(short dayOfWeekOrder) {
    string days[] = { "Sun" , "Mon" , "Tur" , "Web" , "Thu" , "Fri" , "Sat" };
    return days[dayOfWeekOrder];
}

stDate getSystemDate()
{
    stDate date;
    time_t t = time(0);
    tm* now = localtime(&t);
    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;
    return date;
}

bool isEndOfWeek(stDate date) {
    return dayOfWeekOrder(date.day , date.month  , date.year) == 6;
}

bool isWeekEnd(stDate date) {
    // holiday at Sat(6) , Sun(1)
    return dayOfWeekOrder(date.day, date.month, date.year) == 6 || dayOfWeekOrder(date.day, date.month, date.year) == 1;
}

bool isBusinessDay(stDate date) {
    return !isWeekEnd(date);
}

short daysUntilTheEndOfWeek(stDate date) {
    return 6 - dayOfWeekOrder(date.day, date.month, date.year);
}

short daysUntilTheEndOfMonth(stDate date) {
    return numberOfDayInMonth(date.month, date.year) - date.day;
}

short daysUntilTheEndOfYear(stDate date) {

    short totalDays = daysUntilTheEndOfMonth(date);

    for (short i = ++date.month; i <= 12; i++)
    {
        totalDays += numberOfDayInMonth(date.month, date.year);
    }

    return totalDays;
}

int main()
{
    stDate Date1;
    Date1.day = 27;
    Date1.month = 9;
    Date1.year = 2022;

    cout << "\nToday is " << dayShortName(dayOfWeekOrder(Date1.day , Date1.month , Date1.year))
        << " , "
        << Date1.day << "/" << Date1.month << "/" << Date1.year <<
        endl;
    //---------------------
    cout << "\nIs it End of Week?\n";
    if (isEndOfWeek(Date1))
        cout << "Yes it is Saturday, it's of Week.";
    else
        cout << "No it's Not end of week.";
    //---------------------
    cout << "\n\nIs it Weekend?\n";
    if (isWeekEnd(Date1))
        cout << "Yes it is a week end.";
    else
        cout << "No today is " <<
        dayShortName(dayOfWeekOrder(Date1.day, Date1.month, Date1.year)) << ", Not a weekend.";
    //---------------------
    cout << "\n\nIs it Business Day?\n";
    if (isBusinessDay(Date1))
        cout << "Yes it is a business day.";
    else
        cout << "No it is NOT a business day.";
    //---------------------
    cout << "\n\nDays until end of week : "
        << daysUntilTheEndOfWeek(Date1) << " Day(s).";
    //---------------------
    cout << "\nDays until end of month : "
        << daysUntilTheEndOfMonth(Date1) << " Day(s).";
    //---------------------
    cout << "\nDays until end of year : "
        << daysUntilTheEndOfYear(Date1) << " Day(s).";
    system("pause>0");
    return 0;
}
