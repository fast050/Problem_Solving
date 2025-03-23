
#include <iostream>

using namespace std;

class clsPerson {

    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _PhoneNumber;



public : 

    clsPerson(int ID, string FirstName, string LastName, string Email, string PhoneNumber) {

        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _PhoneNumber = PhoneNumber;
    }

    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    string GetFirstName() {
        return _FirstName;
    }

    void SetLastName(string LastName) {
        _LastName = LastName;
    }

    string GetLastName() {
        return _LastName;
    }

    void SetEmail(string Email) {
        _Email = Email;
    }

    string GetEmail() {
        return _Email;
    }

    void SetPhoneNumber(string PhoneNumber) {
        _PhoneNumber = PhoneNumber;
    }

    string GetPhoneNumber() {
        return _PhoneNumber;
    }

    string GetFullName() {
        return _FirstName + " " + _LastName;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;
    __declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string PhoneNumber;
    __declspec(property(get = GetFullName)) string FullName;

    void SendEmail(string Subject, string Body) {

        cout << "The following message sent successfully to email: " << _Email << "\n";
        cout << "Subject: " << Subject << "\n";
        cout << "Body: " << Body << "\n\n";
    }

    void SendSMS(string Message) {

        cout << "The following SMS sent successfully to phone: " << _PhoneNumber << "\n";
        cout << Message << "\n\n";
    }

    void Print() {
    
        cout << "Info:\n";
        cout << "_____________________\n";
        cout << "ID       :" << _ID << "\n";
        cout << "FirstName:" << _FirstName << "\n";
        cout << "LastName :" << _LastName << "\n";
        cout << "FullName :" << FullName << "\n";
        cout << "Email    :" << _Email << "\n";
        cout << "Phone    :" << _PhoneNumber << "\n";
        cout << "_____________________\n\n";

    }
   
};

int main()
{
    clsPerson Person1(10, "Khalid", "Mohamed", "Khalid@gmail.com", "0514599925");
    Person1.Print();

    Person1.SendEmail("Hey Man", "I want to get out let go");
    Person1.SendSMS("Where Are u?");

    system("pause > 0");

}