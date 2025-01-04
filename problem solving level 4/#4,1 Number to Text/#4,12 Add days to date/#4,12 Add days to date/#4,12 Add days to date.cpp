

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

bool isLeapYear(short year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

short numberOfDayInMonth(short month, short year) {

    if (month > 12 || month < 1)
        return 0;

    short monthsDay[] = { 31 , 28 , 31, 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : monthsDay[month - 1];
}

stDate setDate(short day, short month, short year) {
    stDate date;
    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}

stDate addDaysToDate(stDate date, short daysToAdd) {

    short monthDays = numberOfDayInMonth(date.month, date.year);

    while (daysToAdd > monthDays) {
        daysToAdd -= monthDays;
        date.month = (date.month == 12) ? 1 : ++date.month;
        date.year = (date.month == 12) ? ++date.year : date.year;
    }

    monthDays = numberOfDayInMonth(date.month, date.year);

    if (date.day + daysToAdd > monthDays) {
        date.day = date.day + daysToAdd - monthDays;
        date.month = (date.month == 12) ? 1 : ++date.month;
        date.year = (date.month == 12) ? ++date.year : date.year;

    }else
        date.day += daysToAdd;


    return date;
}

short numberOfDaysFromTheBeginingOfTheYear(short day, short month, short year)
{
    short totalDays = 0;
    for (int i = 1; i < month; i++)
    {
        totalDays += numberOfDayInMonth(i, year);
    }
    totalDays += day;
    return totalDays;
}


stDate addDaysToDateOtherSolution(stDate date, short daysToAdd) {
    //convert the date give to all days to start from month 1 
    short RemainingDays = daysToAdd + numberOfDaysFromTheBeginingOfTheYear(date.day, date.month, date.year) ;
    short monthDays = 0;

    date.month = 1;

    while (true) {

        monthDays = numberOfDayInMonth(date.month, date.year);
        if (RemainingDays > monthDays) {

            date.month++;

            if (date.month > 12) {
            
                date.month = 1;
                date.year++;
            }

            RemainingDays -= monthDays;
        }else
        {
            date.day = RemainingDays;
            break;
        }

    }


    return date;

}


int main()
{
   
    short day = readNumber("Please enter a Day? ");
    short month = readNumber("\nPlease enter a Month? ");
    short year = readNumber("\nPlease enter a year? ");
    short dayToAdd = readNumber("\nHow many days to add? ");

    stDate startDate = setDate(day, month, year);

    stDate finalDate = addDaysToDateOtherSolution(startDate, dayToAdd);


    cout << "\nDate after adding [" << dayToAdd << "] days is : " <<
        finalDate.day << "/" << finalDate.month << "/" <<finalDate.year << endl;
                    
}