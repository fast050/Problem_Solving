#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen : public clsScreen
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


public:
	static void ShowUpdateCurrencyScreen() {

		_DrawScreenHeader("Update Currency Screen");

		cout << "Please Enter Currency Code: ";
		string Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		if (Currency.IsCurrencyExist)
		{
			cout << "\n";
			_PrintCurrencyCard(Currency);

			char choice = clsInputValidate::ReadChoiceYesNo("Are you sure you want to update the rate of this Currency");
			if (choice == 'Y' || choice == 'y') {
				cout << "\n\nUpdate Currency Rate: \n";
				cout << "___________________";
				cout << "\nEnter New Rate:";
				float NewRate = clsInputValidate::ReadNumber<float>();

				Currency.UpdateRate(NewRate);

				cout << "\nCurrency Rate Update Sccuessfully\n";

				_PrintCurrencyCard(Currency);
			}
			else {
				cout << "Currency Update Rate Cancel\n";
			}



		}
		else
			cout << "Currency is not Exist in System";

	}

};

