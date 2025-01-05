
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

//this solution is better in term of readability
bool isDate1LessThenDate2(stDate date1, stDate date2) {
    if (date1.year < date2.year) {
        return true;
    }
    else if (date1.year == date2.year) {

        if (date1.month < date2.month) {
            return true;
        }
        else if (date1.month == date2.month) {
            if (date1.day < date2.day) {
                return true;
            }
            else
                return false;
        }
    }
}

//when it nested like this not good idea to use it for readability
bool isDate1LessThenDate2OtherSolution(stDate date1, stDate date2) {
    return date1.year < date2.year ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false);
}

int main()
{
    stDate date1 = readDate();
    cout << endl;
    stDate date2 = readDate();

    if (isDate1LessThenDate2OtherSolution(date1, date2))
        cout << "\Yes, Date1 is less then date2";
    else
        cout << "No, date1 is not less then date2";
}