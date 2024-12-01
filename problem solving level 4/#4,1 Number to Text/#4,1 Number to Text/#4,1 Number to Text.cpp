#include <iostream>
#include <string>


using namespace std;

string numberToText(long long number) {

    if (number < 20) {
    
        string arr[20] = { "" , "One" , "Two", "Three" , "Four", "Five", "Six", "Seven","Eight","Nine","Ten",
                         "Eleven","Twelve","Thirteen","Forteen","Fifteen" , "Sixteen","Seventeen","Eighteen","Nineteen" };

        return arr[number];
    }

    if (number >= 20 && number <= 99) {
    
        string arr[10] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return arr[number/10]+ " " + numberToText(number % 10);
    
    }

    if (number >= 100 && number <= 999) {

        string handred = ((number / 100) > 1) ? " Handreds " : " Handred ";

        return numberToText(number / 100) + handred + numberToText(number % 100);

    }

    if (number >= 1000 && number <= 999999) {

        string thousand = ((number / 1000) > 1) ? " Thousands " : " Thousand ";

        return numberToText(number / 1000) + thousand + numberToText(number % 1000);

    }

    if (number >= 1000000 && number <= 999999999) {

        string million = ((number / 1000000) > 1) ? " Millions " : " Million ";

        return numberToText(number / 1000000) + million + numberToText(number % 1000000);

    }


    if (number >= 1000000000 && number <= 999999999999) {

        string billion = ((number / 1000000000) > 1) ? " Billions " : " Billion ";

        return numberToText(number / 1000000000) + billion + numberToText(number % 1000000000);

    }

    return "";
   
}


int main()
{
    cout << numberToText(1000456);
    system("pause>0");
}