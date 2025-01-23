#include <iostream>

using namespace std;

struct stDate {
    short year;
    short month;
    short day;
};

struct stPeriod {
    stDate start;
    stDate end;
};

enum enDateCompare {
    Before = -1,
    Equal = 0,
    After = 1
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

stPeriod readPeriod() {

    stPeriod dates;

    cout << "Enter Start Date\n";
    dates.start = readDate();
    cout << endl;
    cout << "Enter end Date\n";
    dates.end = readDate();
    cout << endl;

    return dates;

}

bool isLearYear(short year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

short numberOfDaysInMonth(short month, short year) {

    if (month > 12 || month < 1)
        return 0;

    int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return  month == 2 ? (isLearYear(year) ? 29 : 28) : monthDays[month - 1];
}

bool isDate1LessThenDate2(stDate date1, stDate date2) {
    return date1.year < date2.year ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false);
}

bool isDatesEquals(stDate date1, stDate date2) {
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

bool isDate1AfterDate2(stDate date1, stDate date2) {
    return !isDate1LessThenDate2(date1, date2) && !isDatesEquals(date1, date2);
}

enDateCompare compareDates(stDate date1, stDate date2) {
    if (isDate1AfterDate2(date1, date2))
        return enDateCompare::After;
    else if (isDatesEquals(date1, date2))
        return enDateCompare::Equal;
    else
        return enDateCompare::Before;
}

bool isDateWithinThePeriod(stPeriod period, stDate date) {

    return !(compareDates(date, period.start) == enDateCompare::Before ||
              compareDates(period.end, date) == enDateCompare::Before);
}


int main()
{
    cout << "Enter Period :\n";
    stPeriod Period1 = readPeriod();

    cout << "\nEnter date to check :\n";
    stDate date = readDate();

    if (isDateWithinThePeriod(Period1, date))
        cout << "\nYes, Date is within period";
    else
        cout << "\nNo, Date is within period";

    system("pause>0");
    return 0;
}