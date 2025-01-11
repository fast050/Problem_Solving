
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

stDate increaseDateByOneDay(stDate date) {

    date.day++;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = 1;
        date.month++;
    }

    if (date.month > 12) {
        date.day = 1;
        date.month = 1;
        date.year++;
    }

    return date;
}

stDate increaseDateByDays(int days , stDate date) {

    for (int i = 0; i < days; i++) {
        date = increaseDateByOneDay(date);
    }

    return date;
}

stDate increaseDateByOneWeek(stDate date) {
    return  increaseDateByDays(7, date);;
}

stDate increaseDateByWeeks(int weeks, stDate date) {

    for (short i = 0; i < weeks; i++)
    {
        date = increaseDateByOneWeek(date);
    }

    return date;
}

stDate increaseDateByOneMonth(stDate date) {

    date.month++;

    if (date.month > 12) {
        date.month = 1;
        date.year++;
    }

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }
    
    return date;
}

stDate increaseDateByMonths(short months, stDate date) {

    for (short i = 0; i < months; i++)
    {
        date = increaseDateByOneMonth(date);
    }

    return date;
}

stDate increaseDateByOneYear(stDate date) {
    date.year++;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate increaseDateByYears(short years, stDate date) {
    for (short i = 0; i < years; i++)
    {
        date = increaseDateByOneYear(date);
    }

    return date;
}

stDate increaseDateByYearsFaster(short years, stDate date) {
    date.year += years;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate increaseDateByOneDecade(stDate date) {
    date.year += 10;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate increaseDateByDecades(short decades, stDate date) {

    for (short i = 0; i < decades; i++)
    {
        date = increaseDateByOneDecade(date);
    }

    return date;
}

stDate increaseDateByDecadesFaster(short decades, stDate date) {

    date.year += decades * 10;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate increaseDateByOneCentury(stDate date) {
     return  increaseDateByDecadesFaster(10 , date);
}

stDate increaseDateByOneMillennium(stDate date) {
    
    for (short i = 0; i < 10; i++) {
    
        date = increaseDateByOneCentury(date);
    }

    return date;
}

int main()
{
    stDate Date1 = readDate();
    cout << "\nDate After: \n";
    Date1 = increaseDateByOneDay(Date1);
    cout << "\n01-Adding one day is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByDays(10, Date1);
    cout << "\n02-Adding 10 days is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByOneWeek(Date1);
    cout << "\n03-Adding one week is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByWeeks(10, Date1);
    cout << "\n04-Adding 10 weeks is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByOneMonth(Date1);
    cout << "\n05-Adding one month is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByMonths(5, Date1);
    cout << "\n06-Adding 5 months is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByOneYear(Date1);
    cout << "\n07-Adding one year is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByYears(10, Date1);
    cout << "\n08-Adding 10 Years is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByYearsFaster(10, Date1);
    cout << "\n09-Adding 10 Years (faster) is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByOneDecade(Date1);
    cout << "\n10-Adding one Decade is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByDecades(10, Date1);
    cout << "\n11-Adding 10 Decades is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByDecadesFaster(10, Date1);
    cout << "\n12-Adding 10 Decade (faster) is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByOneCentury(Date1);
    cout << "\n13-Adding One Century is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = increaseDateByOneMillennium(Date1);
    cout << "\n14-Adding One Millennium is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;

    system("pause>0");
}