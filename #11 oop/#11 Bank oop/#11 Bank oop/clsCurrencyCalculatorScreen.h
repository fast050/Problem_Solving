#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"

class clsCurrencyCalculatorScreen : public clsScreen
{

private:
	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}

	static clsCurrency _GetCurrencyByCode(string Message) {
		
		cout << Message;
		string Code = clsInputValidate::ReadString();
		
		while (!clsCurrency::IsCurrencyExist(Code)) {
		  cout << "Code is not Exist , Try other Code : ";
		  string Code1 = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		return Currency;
	}

	static float _ReadAmount() {
		cout << "Please Amount to Exchange : ";
		float Amount = clsInputValidate::ReadNumber<float>();

		return Amount;
	}

	static void _PrintConvertAmountToUSD(clsCurrency Currency ,float Amount) {
		cout << "\nConvert From " + Currency.CurrencyCode() + " To USD";
		cout << "\n_______________________________\n";
		_PrintCurrencyCard(Currency);
		cout << Amount << " " << Currency.CurrencyCode() << " = " << Currency.ConvertAmountToUSD(Amount) << " USD";
	}

	static void _PrintConvertFromCurrencyToOtherCurrency(clsCurrency CurrencyFrom , clsCurrency CurrencyTo, float Amount) {
		cout << "\nConvert From USD To:";
		cout << "\n_______________________________\n";
		_PrintCurrencyCard(CurrencyTo);
		cout <<  Amount <<" "<< CurrencyFrom.CurrencyCode() << " = " << CurrencyFrom.ConvertAmountToOtherCurrency(Amount, CurrencyTo) 
	<< " " << CurrencyTo.CurrencyCode();
	}

public:

	static void ShowCurrencyCalculatorScreen() {

		_DrawScreenHeader("Currency Calculator Screen");


		clsCurrency Currency1 = _GetCurrencyByCode("Please Enter Currency1 Code : ");
		clsCurrency Currency2 = _GetCurrencyByCode("Please Enter Currency2 Code : ");

		float Amount = _ReadAmount();

		_PrintConvertAmountToUSD(Currency1, Amount);

		if (clsString::LowerAllString(Currency2.CurrencyCode()) != "usd") {
		
			_PrintConvertFromCurrencyToOtherCurrency(Currency1 , Currency2, Amount);

			cout << "\n\n===================================================\n\n";
			cout << Amount << " " + Currency1.CurrencyCode() << " = " << Currency1.ConvertAmountToOtherCurrency(Amount, Currency2) << " " << Currency2.CurrencyCode();
			cout << "\n\n===================================================\n";
		}
	}


};

