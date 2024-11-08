#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	fstream myFile;

	myFile.open("MyFile.text", ios::out | ios::app);

	if (myFile.is_open()) {

		myFile << "This only is A Test";


		myFile.close();
	}

}