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

short numberOfDaysFromBeiningOfTheYear(short day, short month, short year) {

    short totalDays = 0;

    for (short i = 1; i < month; i++)
    {
        totalDays += numberOfDaysInMonth(i, year);
    }

    return totalDays + day;
}

short numberOfDaysFromBeiningOfTheYear(stDate date) {
    return numberOfDaysFromBeiningOfTheYear(date.day, date.month, date.year);
}
      
int differenceInTwoDatesInDays(stDate date1, stDate date2 ,bool includeEndDay = false) {

    short totalDate1Days = numberOfDaysFromBeiningOfTheYear(date1);
    int totalDate2Days = 0;
    
    while (isDate1LessThenDate2(date1, date2)) {
        totalDate2Days += numberOfDaysFromBeiningOfTheYear(date2);
        date2.year--;
        date2.month = 12;
        date2.day = 31;
    }
   
    return includeEndDay ? (totalDate2Days - totalDate1Days) + 1 : totalDate2Days - totalDate1Days;

}

int periodLengthInDays(stPeriod period , bool incudeEndDay = false) {
    return differenceInTwoDatesInDays(period.start, period.end , incudeEndDay);
}

int main()
{
    cout << "Enter Period 1:";
    stPeriod Period1 = readPeriod();

    cout << "\nPeriod Length is: " << periodLengthInDays(Period1);
    cout << "\nPeriod Length (Including End Date) is: " <<
        periodLengthInDays(Period1, true);

    system("pause>0");
    return 0;
}