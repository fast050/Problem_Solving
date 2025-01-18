
#include <iostream>

using namespace std;

struct stDate {
    short year;
    short month;
    short day;
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

int main()
{
    cout << "Enter Date1:\n";
    stDate Date1 = readDate();
    cout << "\nEnter Date2:\n";
    stDate Date2 = readDate();

    cout << "\nCompare Result = " << compareDates(Date1, Date2);
    system("pause>0");
}
