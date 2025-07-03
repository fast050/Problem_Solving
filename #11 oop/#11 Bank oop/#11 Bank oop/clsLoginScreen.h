#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static bool _Login()
    {
        bool LoginFaild = false;
        int LoginFailCount = 0;

        string Username, Password;
        do
        {
           
            if (LoginFaild)
            {
                LoginFailCount++;
                cout << "\nInvlaid Username/Password!\n";
                cout << "You have " + to_string(3 - LoginFailCount) + " Trials to login.\n\n";
            }

            if (LoginFailCount == 3) {
                cout << "\nYou are Locked after 3 failed trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
