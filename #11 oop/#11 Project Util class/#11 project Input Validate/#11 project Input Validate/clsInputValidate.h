#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsString.h"

class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short From, short To) {
		return !(Number < From || Number > To);
	}

	static bool IsNumberBetween(int Number, int From, int To) {
		return !(Number < From || Number > To);
	}

	static bool IsNumberBetween(float Number, float From, float To) {
		return !(Number < From || Number > To);
	}

	static bool IsNumberBetween(double Number, double From, double To) {
		return !(Number < From || Number > To);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		return !(clsDate::IsDateBefore(Date, From) || clsDate::IsDateAfterDate2(Date, To));
	}
    
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n") {
		int number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage) {
		int number = ReadIntNumber();

		while (!IsNumberBetween(number , From , To)) {
			cout << ErrorMessage;
			number = ReadIntNumber();
		}

		return number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again:\n") {
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage) {
		double number = ReadDblNumber();

		while (!IsNumberBetween(number , From , To)) {
			cout << ErrorMessage;
			number = ReadDblNumber();
		}

		return number;
	}

	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
};

