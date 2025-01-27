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

short numberOfDaysFromBeginingOfYear(short day , short month, short year) {

    short totalDays = 0;

    for (short i = 1; i < month; i++)
    {
        totalDays += numberOfDaysInMonth(i, year);
    }

    return totalDays + day;
}

short numberOfDaysFromBeginingOfYear(stDate date) {
    return numberOfDaysFromBeginingOfYear(date.day, date.month, date.year);
}

void swapDates(stDate date1, stDate date2) {

    stDate swap;

    swap.day = date1.day;
    swap.month = date1.month;
    swap.year = date1.year;

    date1.day = date2.day;
    date1.month = date2.month;
    date1.year = date2.year;

    date2.day = swap.day;
    date2.month = swap.month;
    date2.year = swap.year;
}

stDate increaseDateByOneDay(stDate date) {

    date.day++;

    if (numberOfDaysInMonth(date.month, date.year) < date.day) {
        date.month++;
        date.day = 1;
    }

    if (date.month > 12) {
        date.month = 1;
        date.year++;
    }

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

int numberOfDaysBetweenDates(stDate date1, stDate date2 , bool isIncludeEndDay = false) {

    if (compareDates(date1, date2) == After)
        swapDates(date1, date2);

    short totalDaysDate1 = numberOfDaysFromBeginingOfYear(date1);
    short totalDaysDate2 = 0;

    while (compareDates(date1, date2) == Before) {
        totalDaysDate2 = numberOfDaysFromBeginingOfYear(date2);
        date2.year--;
        date2.month = 12;
        date2.day = 31;
    }

    return isIncludeEndDay ? (totalDaysDate2 - totalDaysDate1) + 1 : totalDaysDate2 - totalDaysDate1;
}

bool isOverlapPeriod(stPeriod period1, stPeriod period2) {
    if (compareDates(period1.end, period2.start) == enDateCompare::Before ||
        compareDates(period2.end, period1.start) == enDateCompare::Before)
        return false;
    else
        return true;
}

bool isDateWithinPeriod(stPeriod period, stDate date) {

    return !(compareDates(date, period.start) == enDateCompare::Before ||
               compareDates(date, period.end) == enDateCompare::After);
}

int numberOfDayOverlapPeriods(stPeriod period1, stPeriod period2) {

    if (isOverlapPeriod(period1, period2)) {
    
        if (compareDates(period1.start, period2.start) == enDateCompare::Before) {
            return numberOfDaysBetweenDates(period2.start, period1.end);
        }
        else if (compareDates(period2.start, period1.start) == enDateCompare::Before) {
            return numberOfDaysBetweenDates(period1.start , period2.end);
        }
        else {
        
            short numberOfDays = numberOfDaysBetweenDates(period1.start, period1.end) - 
                numberOfDaysBetweenDates(period2.start, period2.end);
            if (numberOfDays < 0)
                numberOfDays *= -1;
           
            return numberOfDays;
        
        }
    }
    
    else
        return 0;
}

int countOverlapDaysInPeriods(stPeriod period1, stPeriod period2) {

    if (!isOverlapPeriod(period1, period2))
        return 0;

    int lengthPeriod1 = numberOfDaysBetweenDates(period1.start, period1.end);
    int lengthPeriod2 = numberOfDaysBetweenDates(period2.start, period2.end);

    short countOverlapDays = 0;

    if (lengthPeriod1 < lengthPeriod2) {
    
        while (isDate1LessThenDate2(period1.start, period1.end)) {
          if (isDateWithinPeriod(period2, period1.start))
              countOverlapDays++;

           period1.start = increaseDateByOneDay(period1.start);
        }
        
    }
    else
    {
        while (isDate1LessThenDate2(period2.start, period2.end)) {
            if (isDateWithinPeriod(period1, period2.start))
                countOverlapDays++;

            period2.start = increaseDateByOneDay(period2.start);
        }
    }

    return countOverlapDays;
}

int main()
{
    cout << "Enter Period 1 :\n";
    stPeriod Period1 = readPeriod();

    cout << "Enter Period 2 :\n";
    stPeriod Period2 = readPeriod();

    cout << "\nOverlap Days Count Is: " <<
        countOverlapDaysInPeriods(Period1, Period2);

    system("pause>0");
    return 0;
}

