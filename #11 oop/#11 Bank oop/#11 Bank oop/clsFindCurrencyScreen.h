#pragma once
#include<iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsFindCurrencyScreen : public clsScreen
{
private:

	enum enCurrencyFindChoice {
		eCode = 1, eCountry = 2
	};

	static short _ReadUserChoice() {
		cout << "Find By: [1] Code or [2] Country ?";
		short choice = clsInputValidate::ReadNumberBetween<short>(1, 2);

		return choice;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}


public:
	static void ShowFindCurrencyScreen() {

		_DrawScreenHeader("Find Currency Screen");

		enCurrencyFindChoice choice = (enCurrencyFindChoice)_ReadUserChoice();
		if (choice == eCode) {

			cout << "Please Enter Currency Code : ";
			clsCurrency Currency = clsCurrency::FindByCode(clsInputValidate::ReadString());
			

			if (Currency.IsCurrencyExist) {
				cout << "\nCurrency Found";
				_PrintCurrencyCard(Currency);
			}
		}
		else {
			cout << "Please Enter Currency Country : ";
			clsCurrency Currency = clsCurrency::FindByCountry(clsInputValidate::ReadString());

			if (Currency.IsCurrencyExist) {
				cout << "\nCurrency Found";
				_PrintCurrencyCard(Currency);
			}
		}

     }
};

