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

bool isOverlapPeriod(stPeriod period1, stPeriod period2) {
    if (compareDates(period1.end, period2.start) == enDateCompare::Before ||
        compareDates(period2.end, period1.start) == enDateCompare::Before)
        return false;
    else
        return true;
}

int main()
{
    cout << "Enter Period 1:\n";
    stPeriod period1 = readPeriod();
    cout << "\nEnter Period 2:\n";
    stPeriod period2 = readPeriod();

    if (isOverlapPeriod(period1, period2)) {
        cout << "\nYes , Periods is overlap";
    }
    else
        cout << "\nNo , Periods is not overlap";

    system("pause>0");
}
