#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"

using namespace std;

int main()
{

     clsDate Date1("30/11/2023");
	 clsDate Date2("19/4/2025");
	 clsDate Date3("17/4/2025");
	 clsDate Date4("25/4/2025");

	 clsPeriod Period1(Date1, Date2);
	 clsPeriod Period2(Date3, Date4);

	 clsDate TestDate("25/4/2025");

	 
	 //TestDate.PrintMonthCalendar();
	


	 Period1.Print();
     system("pause>0");
}