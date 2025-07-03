#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

class clsListCurrenciesScreen : public clsScreen
{


private:
	static void _PrintCurrencyLine(clsCurrency Currency) {
        cout <<setw(8) << left << "" << "| " << left << setw(30) << left << Currency.Country();
        cout << "| " << setw(9) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(9) << left << Currency.Rate();
     }

public:
    static void ShowListCurrenciesScreen() {

        system("cls");
        vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
        _DrawScreenHeader("Currencies List Screen" , "("+ to_string(vCurrency.size()) + ") " + "Currency.");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << ""<< "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(9) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(9) << "Rate";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                _PrintCurrencyLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



    }

};

