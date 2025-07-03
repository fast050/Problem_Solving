#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : public clsScreen
{

private:
	enum enCurrencyExchangeOption {
		eListCurrencies = 1, eFindCurrencies = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4,
		eMainMenu = 5
	};

 static short _ReadCurrencyExchangeMenuOption()
 {
	 cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5] ? ";
	 return clsInputValidate::ReadNumberBetween<short>(1, 5);
 }

 static void _GoBackToCurrencyExchangeMenu() {
 
	 cout << "\n\nPress any key to go back to Currency Exchange Menue...";
	 system("pause>0");
	 ShowCurrencyExchangeScreen();
 }

 static void _ShowListCurrenciesScreen() {
	 clsListCurrenciesScreen::ShowListCurrenciesScreen();
 }

 static void _ShowFindCurrenciesScreen() {
	 clsFindCurrencyScreen::ShowFindCurrencyScreen();
 }

 static void _ShowUpdateRateScreen() {
	 clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
 }

 static void _ShowCurrencyCalculatorScreen() {
	 clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
 }

 static void _ShowMainMenuScreen() {
	 //do nothing
 }

 static void _PerfromCurrencyExchangeMenuOption(enCurrencyExchangeOption option) {
 
	 switch (option)
	 {
	 case clsCurrencyExchangeScreen::eListCurrencies:
		 system("cls");
		 _ShowListCurrenciesScreen();
		 _GoBackToCurrencyExchangeMenu();
		 break;
	 case clsCurrencyExchangeScreen::eFindCurrencies:
		 system("cls");
		 _ShowFindCurrenciesScreen();
		 _GoBackToCurrencyExchangeMenu();
		 break;
	 case clsCurrencyExchangeScreen::eUpdateRate:
		 system("cls");
		 _ShowUpdateRateScreen();
		 _GoBackToCurrencyExchangeMenu();
		 break;
	 case clsCurrencyExchangeScreen::eCurrencyCalculator:
		 system("cls");
		 _ShowCurrencyCalculatorScreen();
		 _GoBackToCurrencyExchangeMenu();
		 break;
	 case clsCurrencyExchangeScreen::eMainMenu:
		 system("cls");
		 _ShowMainMenuScreen();
		 break;
	 default:
		 break;
	 }
 
 }

public:
	static void ShowCurrencyExchangeScreen() {
	
		system("cls");
		_DrawScreenHeader("\t Currency Exchange Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromCurrencyExchangeMenuOption((enCurrencyExchangeOption)_ReadCurrencyExchangeMenuOption());
	
	
	}


};

