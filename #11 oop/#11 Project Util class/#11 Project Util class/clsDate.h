#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include "clsString.h"
#include<ctime>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class clsDate
{
	short _Day;
	short _Month;
	int _Year;

	static void swap(clsDate& Date1, clsDate& Date2) {
		clsDate temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

	static string getMonthName(short month) {
		if (month > 12 || month < 1)
			return "";

		string monthsName[12] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" ,"Jun" ,"Jul" ,"Aug" , "Sep" ,"Oct" ,"Nov" ,"Dec" };
		return monthsName[month - 1];
	}

public:

	enum enDateCompare {
		Before = -1,
		Equal = 0,
		After = 1
	};

	clsDate() {
		_Day = GetDateNow()._Day;
		_Month = GetDateNow()._Month;
		_Year = GetDateNow()._Year;
	}

	clsDate(string Time) {
		vector<string> vTimeString = clsString::SplitText(Time, "/");

		_Day = stoi(vTimeString[0]);
		_Month = stoi(vTimeString[1]);
		_Year = stoi(vTimeString[2]);
	}

	clsDate(short Day, short Month, int Year) {
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(int Days, int Year) {
		clsDate Date = AddDaysToYear(Days, Year);

		_Day = Date._Day;
		_Month = Date._Month;
		_Year = Date._Year;
	}

	void SetDay(short Day) {
		_Day = (Day > 31 || Day < 1) ? 1 : Day;
	}

	short GetDay() {
		return _Day;
	}

	void SetMonth(int Month) {
		_Month = (Month > 12 || Month < 1) ? 1 : Month;
	}

	short GetMonth() {
		return _Month;
	}

	void SetYear(int Year) {
		_Year = Year;
	}

	int GetYear() {
		return _Year;
	}

	__declspec(property(put = SetDay, get = GetDay)) short Day;
	__declspec(property(put = SetMonth, get = GetMonth)) short Month;
	__declspec(property(put = SetYear, get = GetYear)) int Year;

	static clsDate GetDateNow() {
		time_t t = time(0);
		tm* now = localtime(&t);

		clsDate Date(now->tm_mday,
			now->tm_mon + 1,
			now->tm_year + 1900);

		return Date;
	}

	static short NumberOfDaysInYear(short Year) {
		return (IsLeapYear(Year)) ? 366 : 365;
	}

	short NumberOfDaysInYear() {
		return NumberOfDaysInYear(_Year);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date) {

		if (IsLastDayInMonth(Date)) {
			if (isLastMonthInYear(Date.Month)) {
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else {
				Date._Month++;
				Date._Day = 1;
			}
		}
		else {
			Date._Day++;
		}

		return Date;
	}

	void IncreaseDateByOneDay() {
		*this = IncreaseDateByOneDay(*this);
	}

	static clsDate AddDaysToYear(int NumberOfDayFromBeginingOfTheYear, int Year) {


		int monthNumber = 1;
		while (NumberOfDayFromBeginingOfTheYear - NumberOfDaysInMonth(monthNumber, Year) > 0) {
			NumberOfDayFromBeginingOfTheYear -= NumberOfDaysInMonth(monthNumber, Year);
			monthNumber++;

			if (monthNumber > 12) {
				monthNumber = 1;
				Year++;
			}
		}

		clsDate Date;
		Date._Day = NumberOfDayFromBeginingOfTheYear;
		Date._Month = monthNumber;
		Date._Year = Year;

		return Date;
	}

	void AddDaysToYear(int Days) {
		*this = AddDaysToYear(Days, _Year);
	}

	static bool IsLeapYear(int Year) {
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool IsLeapYear() {
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInMonth(short Month, int Year) {

		if (Month > 12 || Month < 1)
			return 0;

		short monthNumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : monthNumberOfDays[Month - 1];
	}

	static short NumberOfDaysInMonth(clsDate Date) {
		return NumberOfDaysInMonth(Date.Month, Date.Year);
	}

	short NumberOfDaysInMonth() {
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static bool IsDateBeforeDate2(clsDate date, clsDate date2) {
		return (date.Year < date2.Year) ? true : ((date.Year == date2.Year) ? ((date.Month < date2.Month) ? true : (date.Day < date2.Day)) : false);
	}

	static bool IsDateBefore(clsDate d1, clsDate d2) {
		if (d1.Year != d2.Year)
			return d1.Year < d2.Year;
		if (d1.Month != d2.Month)
			return d1.Month < d2.Month;
		return d1.Day < d2.Day;
	}

	bool IsDateBeforeDate2(clsDate date2) {
		return IsDateBeforeDate2(*this, date2);
	}

	static bool IsDateEqualDate2(clsDate date, clsDate date2) {
		return (date.Year == date2.Year) && (date.Month == date2.Month) && (date.Day == date2.Day);
	}

	bool IsDateEqualDate2(clsDate date2) {
		return IsDateEqualDate2(*this, date2);
	}

	static bool IsDateAfterDate2(clsDate date, clsDate date2) {
		return !(IsDateBeforeDate2(date, date2)) && !(IsDateEqualDate2(date, date2));
	}

	bool IsDateAfterDate2(clsDate date2) {
		return IsDateAfterDate2(*this, date2);
	}

	static bool isLastMonthInYear(short month) {
		return month == 12;
	}

	bool isLastMonthInYear() {
		return isLastMonthInYear(_Month);
	}

	static bool IsLastDayInMonth(clsDate Date) {
		return NumberOfDaysInMonth(Date.Month, Date.Year) == Date.Day;
	}

	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}

	static int NumberOfDayFromBeginingOfTheYear(clsDate Date) {
		int numberOfDays = 0;

		for (short i = 1; i < Date.Month; i++)
		{
			numberOfDays += NumberOfDaysInMonth(i, Date._Year);
		}

		return numberOfDays + Date._Day;
	}

	static clsDate AddDaysToDate(clsDate Date, int Days) {

		short numberOfDayFromBegining = NumberOfDayFromBeginingOfTheYear(Date);
		Days += numberOfDayFromBegining;

		return AddDaysToYear(Days, Date.Year);

	}

	clsDate AddDaysToDate(int Days) {
		return AddDaysToDate(*this, Days);
	}

	static int DifferentInTwoDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		int diff = 0;
		int SwapFlagValue = 1;

		if (IsDateBeforeDate2(Date2, Date1)) {
			swap(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDateBeforeDate2(Date1, Date2)) {
			Date1 = IncreaseDateByOneDay(Date1);
			diff++;
		}

		return IncludeEndDay ? ++diff * SwapFlagValue : diff * SwapFlagValue;
	}

	int DifferentInTwoDates(clsDate Date, bool IncudeEndDay = false) {
		return DifferentInTwoDates(*this, Date, IncudeEndDay);
	}

	static int AgeInDays(clsDate BirthDate) {
		return DifferentInTwoDates(BirthDate, GetDateNow());
	}

	static clsDate IncreaseDateByDays(int Days, clsDate& Date) {

		for (short i = 0; i < Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByDays(int Days) {
		*this = IncreaseDateByDays(Days, *this);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date) {
		return  IncreaseDateByDays(7, Date);
	}

	void IncreaseDateByOneWeek() {
		*this = IncreaseDateByDays(7, *this);
	}

	static clsDate IncreaseDateByWeeks(int weeks, clsDate& Date) {

		for (short i = 0; i < weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void IncreaseDateByWeeks(int Weeks) {
		*this = IncreaseDateByWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date) {

		if (Date.Month == 12) {
			Date._Month = 1;
			Date._Year++;
		}
		else {
			Date._Month++;
		}

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void IncreaseDatebyOneMonth() {
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByMonths(short Months, clsDate& Date) {

		for (short i = 0; i < Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void IncreaseDateByMonths(int Months) {
		*this = IncreaseDateByMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date) {
		Date.Year++;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void IncreaseDateByOneYear() {
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByYears(short Years, clsDate& Date) {
		for (short i = 0; i < Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	void IncreaseDateByYears(int Years) {
		*this = IncreaseDateByYears(Years, *this);
	}

	static clsDate IncreaseDateByYearsFaster(int Years, clsDate& Date) {
		Date.Year += Years;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void IncreaseDateByYearsFaster(int Years) {

		*this = IncreaseDateByYearsFaster(Years, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date) {
		Date.Year += 10;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void IncreaseDateByOneDecade() {
		*this = IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByDecades(short Decades, clsDate& Date) {

		Date.Year += Decades * 10;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void IncreaseDateByDecades(short Decades) {
		*this = IncreaseDateByDecades(Decades, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date) {
		Date._Year += 100;
		return  Date;
	}

	void IncreaseDateByOneCentury() {
		*this = IncreaseDateByOneCentury(*this);
	}

	clsDate IncreaseDateByOneMillennium(clsDate& Date) {
		Date._Year += 1000;
		return Date;
	}

	void IncreaseDateByOneMillennium() {
		*this = IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date) {

		if (Date._Day == 1) {

			if (Date._Month == 1)
			{
				Date._Year--;
				Date._Month = 12;
				Date._Day = 31;
			}
			else {
				Date._Month--;
				Date._Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}

		}
		else {
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay() {
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByDays(int Days, clsDate& Date) {

		for (short i = 0; i < Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByDays(int Days) {
		*this = DecreaseDateByDays(Days, *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date) {
		return  DecreaseDateByDays(7, Date);
	}

	void DecreaseDateByOneWeek() {
		*this = DecreaseDateByDays(7, *this);
	}

	static clsDate DecreaseDateByWeeks(int weeks, clsDate& Date) {

		for (short i = 0; i < weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void DecreaseDateByWeeks(int Weeks) {
		*this = DecreaseDateByWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date) {

		if (Date._Month == 1) {
			Date._Month = 12;
			Date._Year--;
		}
		else {
			Date._Month--;
		}

		if (Date._Day > NumberOfDaysInMonth(Date._Month, Date._Year))
			Date._Day = NumberOfDaysInMonth(Date._Month, Date.Year);

		return Date;
	}

	void DecreaseDateByOneMonth() {
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByMonths(short Months, clsDate& Date) {

		for (short i = 0; i < Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void DecreaseDateByMonths(int Months) {
		*this = DecreaseDateByMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date) {
		Date.Year--;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void DecreaseDateByOneYear() {
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByYears(short Years, clsDate& Date) {
		for (short i = 0; i < Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	void DecreaseDateByYears(int Years) {
		*this = DecreaseDateByYears(Years, *this);
	}

	static clsDate DecreaseDateByYearsFaster(int Years, clsDate& Date) {
		Date.Year -= Years;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void DecreaseDateByYearsFaster(int Years) {

		*this = DecreaseDateByYearsFaster(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date) {
		Date.Year -= 10;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void DecreaseDateByOneDecade() {
		*this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByDecades(short Decades, clsDate& Date) {

		for (short i = 0; i < Decades; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}

		return Date;
	}

	void DecreaseDateByDecades(short Decades) {
		*this = DecreaseDateByDecades(Decades, *this);
	}

	static clsDate DecreaseDateByDecadesFaster(short Decades, clsDate& Date) {

		Date.Year -= Decades * 10;

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) {
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void DecreaseDateByDecadesFaster(short Decades) {
		*this = DecreaseDateByDecadesFaster(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date) {
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury() {
		*this = DecreaseDateByOneCentury(*this);
	}

	clsDate DecreaseDateByOneMillennium(clsDate& Date) {
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium() {
		*this = DecreaseDateByOneMillennium(*this);
	}
	//Gergorian : 
	//0:Sun, 1 :Mon, 2:Tue, 3:Wed ...etc.
	static short DayOfWeekOrder(short day, short month, short year) {
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + 12 * a - 2;
		//Gergorian : 
		//0:Sun, 1 :Mon, 2:Tue, 3:Wed ...etc.
		return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
	}

	static short DayOfWeekOrder(clsDate Date) {
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	static string DayShortName(short dayOfWeekOrder) {
		string days[] = { "Sun" , "Mon" , "Tur" , "Web" , "Thu" , "Fri" , "Sat" };
		return days[dayOfWeekOrder];
	}

	static bool IsEndOfWeek(clsDate Date) {
		return DayOfWeekOrder(Date) == 0 || DayOfWeekOrder(Date) == 6;
	}

	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date) {
		return IsEndOfWeek(Date);
	}

	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date) {
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndOfWeek(clsDate Date) {
		return DayOfWeekOrder(Date) == 1 ? 0 : 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilEndOfWeek() {
		return DaysUntilEndOfWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date) {
		return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day;
	}

	short DaysUntilEndOfMonth() {
		return DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate Date) {
		return NumberOfDaysInYear(Date.Year) - NumberOfDayFromBeginingOfTheYear(Date);
	}

	short DaysUntilEndOfYear() {
		return DaysUntilEndOfYear(*this);
	}

	// vaction days without weekend
	static int CalculateVacationDays(clsDate StartDate, clsDate EndDate, bool IsIncludeWeekEnd = false) {

		int VactionDays = 0;
		while (IsDateBeforeDate2(StartDate, EndDate)) {

			if (IsBusinessDay(StartDate) || IsIncludeWeekEnd) {
				VactionDays++;
			}

			StartDate = IncreaseDateByOneDay(StartDate);
		}

		return VactionDays;
	}

	int CalculateVacationDays(clsDate EndDate, bool IsIncludeWeekEnd = false) {
		return CalculateVacationDays(*this, EndDate, IsIncludeWeekEnd);
	}

	static clsDate CalculateVacationReturnDate(clsDate StartDate, int VacationDays) {

		while (IsWeekEnd(StartDate)) {
			StartDate = IncreaseDateByOneDay(StartDate);
		}

		int WeekEndCounter = 0;

		for (short i = 0; i < VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(StartDate))
				WeekEndCounter++;

			StartDate = IncreaseDateByOneDay(StartDate);
		}

		while (IsWeekEnd(StartDate)) {
			StartDate = IncreaseDateByOneDay(StartDate);
		}

		return StartDate;
	}

	clsDate CalculateVacationReturnDate(int VacationDays) {
		return CalculateVacationReturnDate(*this, VacationDays);
	}

	enDateCompare compareDates(clsDate date1, clsDate date2) {
		if (IsDateAfterDate2(date1, date2))
			return enDateCompare::After;
		else if (IsDateEqualDate2(date1, date2))
			return enDateCompare::Equal;
		else
			return enDateCompare::Before;
	}

	static bool IsValidDate(clsDate Date) {
		return !(Date.Month < 1 || Date.Month > 12 || Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year));
	}

	bool IsValid() {
		return IsValidDate(*this);
	}

	static void PrintMonthCalendar(short Month, int Year) {

		short DayOrder = DayOfWeekOrder(1, Month, Year);
		short Day = 1;

		cout << "_______________" << getMonthName(Month) << "_______________\n\n";
		cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		for (short i = 0; i < DayOrder; i++)
		{
			cout << "     ";
		}

		for (short i = 1 + DayOrder; Day <= NumberOfDaysInMonth(Month, Year); i++)
		{
			if (Day > 9)
				cout << Day++ << "   ";
			else
				cout << Day++ << "    ";

			if (i % 7 == 0)
				cout << endl;
		}

		cout << "\n_________________________________\n";

	}

	static string DateToString(clsDate Date)
	{
		return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString() {
		return DateToString(*this);
	}

	void PrintMonthCalendar() {
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(int Year) {

		cout << "_________________________________\n\n";
		cout << "          Calender - 2022\n\n";
		cout << "_________________________________\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

	}

	void PrintYearCalendar() {
		PrintYearCalendar(_Year);
	}

	static void Print(clsDate Date) {
		cout << DateToString(Date);
	}

	void Print() {
		Print(*this);
	}
};
