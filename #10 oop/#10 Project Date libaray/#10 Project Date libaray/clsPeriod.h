#pragma once

#include<iostream>
#include "clsDate.h"

class clsPeriod
{

	clsDate _StartDate;
	clsDate _EndDate;

public:

	clsPeriod() {

	}

	clsPeriod(clsDate StartDate, clsDate EndDate) {
		_StartDate = StartDate;
		_EndDate = EndDate;
	}

	void SetStartDate(clsDate Date) {
		_StartDate = Date;
	}

	clsDate GetStartDate() {
		return _StartDate;
	}

	__declspec(property(get = GetStartDate, put = SetStartDate)) clsDate StartDate;

	void SetEndDate(clsDate Date) {
		_EndDate = Date;
	}

	clsDate GetEndDate() {
		return _EndDate;
	}

	__declspec(property(get = GetEndDate, put = SetEndDate)) clsDate EndDate;


	static bool IsPeriodsOverlap(clsPeriod Period1, clsPeriod Period2) {
		return !(clsDate::IsDateBeforeDate2(Period1.EndDate, Period2.StartDate) || clsDate::IsDateBeforeDate2(Period2.EndDate, Period1.StartDate));
	}

	bool IsPeriodsOverLap(clsPeriod Period) {
		return IsPeriodsOverlap(*this, Period);
	}

	static int PeriodLenghtInDays(clsPeriod Period, bool IncludeEndDay = false) {
		return clsDate::DifferentInTwoDates(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	int PeriodLenghtInDays(bool IncludeEndDay = false) {
		return PeriodLenghtInDays(*this, IncludeEndDay);
	}

	static bool IsDateWithInPeriod(clsPeriod Period, clsDate Date) {
		return !(clsDate::IsDateBeforeDate2(Date, Period.StartDate) || clsDate::IsDateAfterDate2(Date, Period.EndDate));
	}

	bool IsDateWithInPeriod(clsDate Date) {
		return IsDateWithInPeriod(*this, Date);
	}

	static int CalculatePeriodsOverlapDays(clsPeriod Period1, clsPeriod Period2) {

		if (!IsPeriodsOverlap(Period1, Period2))
			return 0;


		int counter = 0;

		if (clsDate::IsDateBefore(Period1.StartDate , Period2.EndDate)) {

			while (!clsDate::IsDateAfterDate2(Period2.StartDate , Period1.EndDate)) {

				counter++;
				Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);
			}

		}
		else
		{
			while (!clsDate::IsDateAfterDate2(Period1.StartDate , Period2.EndDate)) {

				counter++;
				Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);
			}
		}

		return counter;
	}

	int CalculatePeriodsOverlapDays(clsPeriod Period) {
		return CalculatePeriodsOverlapDays(*this, Period);
	}

	static void Print(clsPeriod Period) {
	
		cout << "Start Period : ";
		clsDate::Print(Period.StartDate);
		cout << "End Period : ";
		clsDate::Print(Period.EndDate);
	}

	void Print() {
		Print(*this);
	}

};

