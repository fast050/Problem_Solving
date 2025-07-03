#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "string"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{

private:
	static void _PrintClientCard(clsBankClient Client) {
		cout << "Client Card:\n";
		cout << "_____________________\n";
		cout << "Full Name   : " << Client.FullName() <<"\n";
		cout << "Acc. Number : " << Client.AccountNumber() << "\n";
		cout << "Balance     : " << Client.AccountBalance << "\n";
		cout << "_____________________\n\n";
	}
	
	static clsBankClient _FindTransferClient(string AccountNumberMessage) {
		string AccountNumber = clsInputValidate::ReadString(AccountNumberMessage);
		clsBankClient ClientTransfer = clsBankClient::Find(AccountNumber);

		while (ClientTransfer.IsEmpty()) {
			AccountNumber = clsInputValidate::ReadString("\nClient is Not Exist! , try other Account Number: ");
			ClientTransfer = clsBankClient::Find(AccountNumber);
		}

		return ClientTransfer;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadNumber<float>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadNumber<double>();
		}
		return Amount;
	}

public :
	static void ShowTransferScreen() {
	
		_DrawScreenHeader("Transfer Screen");
		
		 clsBankClient ClientTransferFrom = _FindTransferClient("Please Enter Account Number to Transfer From: ");
		 cout << "\n";
		 _PrintClientCard(ClientTransferFrom);

		 clsBankClient ClientTransferTo = _FindTransferClient("Please Enter Account Number to Transfer To: ");
		 cout << "\n";
		 _PrintClientCard(ClientTransferTo);

		 float Amount = ReadAmount(ClientTransferFrom);

		 char answer = clsInputValidate::ReadChoiceYesNo("Are you sure you want to perform this operation");
		 if (answer == 'Y' || answer == 'y') {
			
			 if (ClientTransferFrom.Transfer(Amount, ClientTransferTo , CurrentUser.UserName)) {
				 cout << "Transfer done successfully\n";
				 _PrintClientCard(ClientTransferFrom);
				 cout << "\n";
				 _PrintClientCard(ClientTransferTo);
			 }
			 else
			 {
				 cout << "Transfer failed \n";
			 }
		 }
		 else
		 {
			 cout << "Transfer failed \n";
		 }
	
	}

};

