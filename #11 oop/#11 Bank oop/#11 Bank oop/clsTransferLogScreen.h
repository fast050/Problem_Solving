#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

using namespace std;

class clsTransferLogScreen : clsScreen
{

private:

	static void _PrintTransferLog(clsBankClient::stTransferLogRecord TransferLogRecord) {
		cout << "\t";
		cout << "| " << setw(23) << left << TransferLogRecord.Date;
		cout << "| " << setw(8)  << left << TransferLogRecord.TransferFromAccountNumber;
		cout << "| " << setw(8)  << left << TransferLogRecord.TransferToAccountNumber;
		cout << "| " << setw(8)  << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.TransferFromBalance;
		cout << "| " << setw(10) << left << TransferLogRecord.TransferToBalance;
		cout << "| " << setw(14) << left << TransferLogRecord.userName;
		cout << "\n";
	}


public:

	static void ShowTransferLogScreen() {

		_DrawScreenHeader("Trasnfer Log Screen");
		vector <clsBankClient::stTransferLogRecord> TransferLogList = clsBankClient::GetTrasnferLogList();


		cout << "\t________________________________________________________________________________________________________\n";
		cout << "\t| Date/Time              "<< "| s.Acct  "<< "| d.Acct  " << "| Amount  " << "| s.Balance " << "| d.Balance " << "| User\n";
		cout << "\t________________________________________________________________________________________________________\n\n";


		if (TransferLogList.size() > 0) {
		
		   for (clsBankClient::stTransferLogRecord& log : TransferLogList) {
			   _PrintTransferLog(log);
		   }
		}else
			cout << "\t\t\t\tNo Trasnfer Log Available In the System!";

		cout << "\n\n\t________________________________________________________________________________________________________\n";

	}


};

