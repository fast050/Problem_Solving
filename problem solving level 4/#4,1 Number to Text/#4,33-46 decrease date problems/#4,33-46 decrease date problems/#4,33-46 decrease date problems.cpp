
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

stDate decreaseDateByOneDay(stDate date) {

    date.day--;

    if (date.day < 1) {
        date.month--;

        if (date.month < 1) {
            date.month = 12;
            date.year--;
        }

        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate decreaseDateByDays(int days, stDate date) {

    for (int i = 0; i < days; i++) {
        date = decreaseDateByOneDay(date);
    }

    return date;
}

stDate decreaseDateByOneWeek(stDate date) {
    return decreaseDateByDays(7, date);;
}

stDate decreaseDateByWeeks(int weeks, stDate date) {

    for (short i = 0; i < weeks; i++)
    {
        date = decreaseDateByOneWeek(date);
    }

    return date;
}

stDate decreaseDateByOneMonth(stDate date) {

    date.month--;

    if (date.month < 1) {
        date.month = 12;
        date.year--;
    }

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate decreaseDateByMonths(short months, stDate date) {

    for (short i = 0; i < months; i++)
    {
        date = decreaseDateByOneMonth(date);
    }

    return date;
}

stDate decreaseDateByOneYear(stDate date) {
    date.year--;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate decreaseDateByYears(short years, stDate date) {
    for (short i = 0; i < years; i++)
    {
        date = decreaseDateByOneYear(date);
    }

    return date;
}

stDate decreaseDateByYearsFaster(short years, stDate date) {
    date.year -= years;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate decreaseDateByOneDecade(stDate date) {
    date.year -= 10;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate decreaseDateByDecades(short decades, stDate date) {

    for (short i = 0; i < decades; i++)
    {
        date = decreaseDateByOneDecade(date);
    }

    return date;
}

stDate decreaseDateByDecadesFaster(short decades, stDate date) {

    date.year -= decades * 10;

    if (date.day > numberOfDayInMonth(date.month, date.year)) {
        date.day = numberOfDayInMonth(date.month, date.year);
    }

    return date;
}

stDate decreaseDateByOneCentury(stDate date) {
    return decreaseDateByDecadesFaster(10, date);
}

stDate decreaseDateByOneMillennium(stDate date) {

    for (short i = 0; i < 10; i++) {

        date = decreaseDateByOneCentury(date);
    }

    return date;
}

int main()
{
    stDate Date1 = readDate();
  
    cout << "\nDate After: \n";
    Date1 = decreaseDateByOneDay(Date1);
    cout << "\n01-Subtracting one day is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByDays(10, Date1);
    cout << "\n02-Subtracting 10 days is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByOneWeek(Date1);
    cout << "\n03-Subtracting one week is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByWeeks(10, Date1);
    cout << "\n04-Subtracting 10 weeks is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByOneMonth(Date1);
    cout << "\n05-Subtracting one month is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByMonths(5, Date1);
    cout << "\n06-Subtracting 5 months is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByOneYear(Date1);
    cout << "\n07-Subtracting one year is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByYears(10, Date1);
    cout << "\n08-Subtracting 10 Years is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByYearsFaster(10, Date1);
    cout << "\n09-Subtracting 10 Years (faster) is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByOneDecade(Date1);
    cout << "\n10-Subtracting one Decade is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByDecades(10, Date1);
    cout << "\n11-Subtracting 10 Decades is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByDecadesFaster(10, Date1);
    cout << "\n12-Subtracting 10 Decade (faster) is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByOneCentury(Date1);
    cout << "\n13-Subtracting One Century is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;
    Date1 = decreaseDateByOneMillennium(Date1);
    cout << "\n14-Subtracting One Millennium is: "
        << Date1.day << "/" << Date1.month << "/" << Date1.year;

    system("pause>0");
}