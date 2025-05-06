#pragma once

#include <iostream>	
#include <cstdlib>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:

	enum enCharType {
		SmallLetter = 1,    // Represents lowercase letters (ASCII 97 to 122).
		CapitalLetter = 2,   // Represents uppercase letters (ASCII 65 to 90).
		Digit = 3,
		SpecialCharacter = 4,// Represents special characters (ASCII 33 to 47).
		MixCapitalSmallLetter = 5,// Generate a random digit (ASCII codes 48 to 57).
		MixCharacterWithoutSpecialCharacter = 6
	};
	
	static int RandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}

	static char GetRandomCharacter(enCharType type) {

		if (type == MixCapitalSmallLetter) {
			type = (enCharType)RandomNumber(1, 2);
		}

		if (type == MixCharacterWithoutSpecialCharacter) {
			type = (enCharType)RandomNumber(1, 3);
		}

		switch (type)
		{
		case clsUtil::SmallLetter:
			return char(RandomNumber(97, 122));
		case clsUtil::CapitalLetter:
			return char(RandomNumber(65, 90));
		case clsUtil::Digit:
			return char(RandomNumber(48, 57));
		case clsUtil::SpecialCharacter:
			return char(RandomNumber(33, 47));
		default:
			return char(RandomNumber(65, 122));
		}
	}

	static string GenerateWord(enCharType type, short charSize) {

		string word = "";

		for (short i = 0; i < charSize; i++)
		{
			word += GetRandomCharacter(type);
		}

		return word;
	}

	static string GenerateKey(enCharType type) {
		return GenerateWord(type, 4) + "-"+
			GenerateWord(type, 4)+ "-"+
			GenerateWord(type, 4)+ "-"+
			GenerateWord(type, 4);
	}
	
	static void GenerateKeys(enCharType type, short numberOfKeys) {

		for (short i = 1; i <= numberOfKeys; i++)
		{
			cout << "key [" << i << "] : " << GenerateKey(type) << endl;
		}
	}

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static void Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	static void Swap(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}

	static void Swap(string& a, string& b) {
		string temp = a;
		a = b;
		b = temp;
	}

	static void Swap(clsDate& date1, clsDate& date2) {
	
		clsDate temp = date1;
		date1 = date2;
		date2 = temp;
	}

	static void ShuffleArray(int Arr[], int ArrSize) {

		for (short i = 0; i < ArrSize; i++)
		{
			Swap(Arr[RandomNumber(0 , ArrSize - 1)], Arr[RandomNumber(0, ArrSize - 1)]);
		}

	}

	static void ShuffleArray(string Arr[], int ArrSize) {

		for (short i = 0; i < ArrSize / 2; i++)
		{
			Swap(Arr[RandomNumber(0, ArrSize - 1)], Arr[RandomNumber(0, ArrSize - 1)]);
		}

	}

	static void FillArrayWithRandomNumbers(int Arr[], int ArrSize, int RandomNumberFrom, int RandomNumberTo) {
		for (short i = 0; i < ArrSize; i++)
		{
			Arr[i] = RandomNumber(RandomNumberFrom, RandomNumberTo);
		}
	
	}

	static void FillArrayWithRandomWords(string Arr[], int ArrSize, enCharType WordType , short lengthOfWord) {
		for (short i = 0; i < ArrSize; i++)
		{
			Arr[i] = GenerateWord(WordType , lengthOfWord);
		}
	}

	static void FillArrayWithRandomKeys(string Arr[], int ArrSize, enCharType WordType) {
		for (short i = 0; i < ArrSize; i++)
		{
			Arr[i] = GenerateKey(WordType);
		}
	}

	static string Tabs(int Tabs) {

		string tab = "";
		for (short i = 0; i < Tabs; i++)
		{
			tab +=" ";
		}

		return tab;
	}

	static string EncryptText(string Text, int EncryptionKey) {
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, int EncryptionKey) {
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

};

