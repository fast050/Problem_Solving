#pragma once

#include<iostream>
#include<vector>

using namespace std;

class clsString
{
	string _Value;

public:
	clsString() {
		_Value = "";
	}

	clsString(string Value) {
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	__declspec(property(put = SetValue, get = GetValue)) string Value;

	static vector<string> SplitText(string text, string delimeter) {

		int pos = string::npos;
		vector<string> vWords;

		while ((pos = text.find(delimeter)) != string::npos) {

			string word = text.substr(0, pos);

			if (word != "") {
				vWords.push_back(word);
			}

			text.erase(0, word.length() + delimeter.length());
		}

		if (text != "")
			vWords.push_back(text);

		return vWords;
	}

	static short CountWords(string text) {
		vector<string> words = SplitText(text, " ");
		return words.size();
	}

	short CountWords() {
		return CountWords(_Value);
	}

	static void PrintFirstCharacters(string text) {

		bool isFirst = true;

		for (short i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && isFirst) {
				cout << text[i] << endl;
			}

			isFirst = (text[i] == ' ') ? true : false;
		}

	}

	void PrintFirstCharacters() {
		PrintFirstCharacters(_Value);
	}

	static string UpperFirstLetterForEachWord(string text) {
		bool isFirst = true;

		for (short i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && isFirst) {
				text[i] = toupper(text[i]);
			}

			isFirst = (text[i] == ' ') ? true : false;
		}

		return text;
	}

	void UpperFirstLetterForEachWord() {
		_Value = UpperFirstLetterForEachWord(_Value);
	}

	static string LowerFirstLetterForEachWord(string text) {
		bool isFirst = true;

		for (short i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && isFirst) {
				text[i] = tolower(text[i]);
			}

			isFirst = (text[i] == ' ') ? true : false;
		}

		return text;
	}

	void LowerFirstLetterForEachWord() {
		_Value = LowerFirstLetterForEachWord(_Value);
	}

	static string ToUpperLetters(string text) {

		for (short i = 0; i < text.length(); i++)
		{
			text[i] = toupper(text[i]);
		}

		return text;
	}

	void ToUpperLetters() {
		_Value = ToUpperLetters(_Value);
	}

	static string ToLowerLetters(string text) {

		for (short i = 0; i < text.length(); i++)
		{
			text[i] = tolower(text[i]);
		}

		return text;
	}

	void ToLowerLetters() {
		_Value = ToLowerLetters(_Value);
	}

	static char InvertLetter(char letter) {
		return isupper(letter) ? tolower(letter) : toupper(letter);
	}

	static string InvertAllLetters(string text) {

		for (short i = 0; i < text.length(); i++)
		{
			text[i] = InvertLetter(text[i]);
		}

		return text;
	}

	void InvertAllLetters() {
		_Value = InvertAllLetters(_Value);
	}

	static short CountCapitalLettersInText(string text) {

		int count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (isupper(text[i]))
				count++;
		}

		return count;
	}

	short CountCapitalLettersInText() {
		return CountCapitalLettersInText(_Value);
	}

	static short CountSmallLettersInText(string text) {

		int count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (islower(text[i]))
				count++;
		}

		return count;
	}

	short CountSmallLetterInText() {
		return CountSmallLettersInText(_Value);
	}

	short length() {
		return _Value.length();
	}

	static short CountLetterInText(string text, char letter, bool isCaseSenstive = false) {

		int count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (isCaseSenstive) {
				if (text[i] == letter)
					count++;
			}
			else
			{
				if (tolower(text[i]) == tolower(letter))
					count++;
			}

		}

		return count;
	}

	short CountLetterInText(char letter, bool isCaseSenstive = false) {
		return CountLetterInText(_Value, letter, isCaseSenstive);
	}

	static bool IsVowel(char letter) {
		char vowelLetters[5] = { 'a' , 'e', 'i' , 'u' , 'o' };

		for (short i = 0; i < 5; i++) {
			if (tolower(letter) == tolower(vowelLetters[i]))
				return true;
		}

		return false;
	}

	static short CountVowelLetterInText(string text) {
		int count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (IsVowel(text[i]))
				count++;
		}

		return count;
	}

	short CountVowelLetterInText() {
		return CountVowelLetterInText(_Value);
	}

	static void PrintVowelLetterOnlyInText(string text) {

		for (short i = 0; i < text.length(); i++)
		{
			if (IsVowel(text[i]))
				cout << text[i];
			else
				cout << " ";
		}
	}

	void PrintVowelLetterOnlyInText() {
		PrintVowelLetterOnlyInText(_Value);
	}

	static void PrintEachWordInText(string text) {

		vector<string> vWords = SplitText(text, " ");

		for (string& word : vWords) {
			cout << word << endl;
		}
	}

	void PrintEachWordInText() {
		PrintEachWordInText(_Value);
	}

	static string TrimLeftText(string text) {

		int pos = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
			{
				pos = i;
				break;

			}
		}

		return text.erase(0, pos);
	}

	void TrimLeftText() {
		_Value = TrimLeftText(_Value);
	}

	static string TrimRightText(string text) {
		int pos = text.length();

		for (short i = text.length() - 1; i >= 0; i--)
		{
			if (text[i] == ' ') {
				pos = i;
				break;
			}
		}

		return text.erase(pos, text.length());
	}

	void TrimRightText() {
		_Value = TrimRightText(_Value);
	}

	static string TrimText(string text) {
		text = TrimLeftText(text);
		text = TrimRightText(text);

		return text;
	}

	void TrimText() {
		_Value = TrimText(_Value);
	}

	static string JoinString(vector<string> vWords, string delimeter) {

		string text = "";

		for (string& Word : vWords) {
			text += Word + delimeter;
		}

		return text.substr(0, text.length() - delimeter.length());
	}

	static string ReverseString(string text) {

		vector<string> vWords = SplitText(text, " ");
		vector<string>::iterator iter = vWords.end();
		string reverseText;

		while (iter != vWords.begin()) {
			--iter;
			reverseText += *iter + " ";
		}



		return reverseText.substr(0, reverseText.length() - 1);
	}

	void ReverseString() {
		_Value = ReverseString(_Value);
	}

	static string ReplaceWordInText(string text, string oldWord, string newWord) {

		int oldWordPos = string::npos;

		while ((oldWordPos = text.find(oldWord)) != string::npos) {
			text.replace(oldWordPos, oldWord.length(), newWord);
		}


		return text;
	}

	void ReplaceWordInText(string oldWord, string newWord) {
		_Value = ReplaceWordInText(_Value, oldWord, newWord);
	}

	static string RemovePunctuationFromText(string text) {

		string resultText = "";

		for (short i = 0; i < text.length(); i++)
		{
			if (!ispunct(text[i]))
				resultText += text[i];
		}

		return resultText;
	}
};


