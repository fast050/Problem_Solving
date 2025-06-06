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

void swapDates(stDate &date1, stDate &date2) {

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

int differenceInTwoDays(stDate date1, stDate date2, bool isIncludeEndDay = false) {



        int totalDate1Days = 0;
        int totalDate2Days = 0;
        int swapFlag = 1;


        if (!isDate1LessThenDate2(date1, date2)) {
            swapDates(date1, date2);
            swapFlag = -1;
        }


        totalDate1Days = numberOfDayFromBeginingOfYear(date1.day, date1.month, date1.year);

        while (date1.year <= date2.year) {

            totalDate2Days += numberOfDayFromBeginingOfYear(date2.day, date2.month, date2.year);
            date2.day = 31;
            date2.month = 12;
            date2.year--;
        }


        int differenceInDays = totalDate2Days - totalDate1Days;

        return isIncludeEndDay ? ++differenceInDays * swapFlag : differenceInDays * swapFlag ;
        
         
}




int main()
{
    cout << "Please Enter your two Dates that u want the different between in days: \n";
    cout << endl;
    stDate date1 = readDate();
    cout << endl;
    stDate date2 = readDate();


    cout << "\ndifferent is : " << differenceInTwoDays(date1, date2) << " Day(s).";
    cout << "\ndifferent (Including End Day) is : " << differenceInTwoDays(date1, date2 , true) << " Day(s).";


    system("pause>0");
}