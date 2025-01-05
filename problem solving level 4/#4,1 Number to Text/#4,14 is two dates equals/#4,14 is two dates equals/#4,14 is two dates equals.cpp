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

// this better solution 
bool isDatesEquals(stDate date1, stDate date2) {
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

//when it nested like this not good idea to use it for readability
bool isDatesEqualsOtherSolution(stDate date1, stDate date2) {
    return date1.year == date2.year ?  (date1.month == date2.month ?  date1.day == date2.day : false) : false ;
}

int main()
{
    stDate date1 = readDate();
    cout << endl;
    stDate date2 = readDate();

    if (isDatesEqualsOtherSolution(date1, date2))
        cout << "\Yes, date1 is eqaul date2";
    else
        cout << "No, date1 is not eqaul date2";
}