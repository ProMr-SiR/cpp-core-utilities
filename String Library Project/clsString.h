#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;
	char _Char;

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void setValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}

	// ################[1]#####################
	static void PrintFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		cout << "\nFirst Letters of this string: \n";

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}
	void PrintFirstLetterOfEachWord()
	{
		 PrintFirstLetterOfEachWord(_Value);
	}
	// ################[2]#####################
	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	string UpperFirstLetterOfEachWord()
	{
		return UpperFirstLetterOfEachWord(_Value);
	}
	// ################[3]#####################
	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	string LowerFirstLetterOfEachWord()
	{
		return LowerFirstLetterOfEachWord(_Value);
	}
	// ################[4]#####################
	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	string UpperAllString()
	{
		UpperAllString(_Value);
	}
	// ################[5]#####################
	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	string LowerAllString()
	{
		return LowerAllString(_Value);
	}
	// ################[6]#####################
	static char InvertLetterCase(char Ch1)
	{
		return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
	}
	char InvertLetterCase()
	{
		return InvertLetterCase(_Char);
	}
	// ################[7]#####################
	static short CountWords(string S1)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				Counter++;
			}
			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	};
	// ################[8]#####################
	static string InvertAllStringLetterCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	string InvertAllStringLetterCase()
	{
		return InvertAllStringLetterCase(_Value);
	}
	// ################[9]#####################
	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;
			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountLetters()
	{
		return CountLetters(_Value);
	}
	// ################[10]#####################
	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}
	// ################[11]#####################
	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}
	// ################[12]#####################
	static short CountLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}

			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}
	short CountLetter()
	{
		return CountLetter(_Value, _Char);
	}
	// ################[13]#####################
	static char isVowelLetter(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}
	char isVowelLetter()
	{
		return isVowelLetter(_Char);
	}
	// ################[14]#####################
	static short CountVowels(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isVowelLetter(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}
	// ################[16]#####################
	static void PrintAllVowelsLetterInstring(string S1)
	{
		cout << "\nVowels in string are:   ";
		for (short i = 0; i < S1.length(); i++)
		{
			if (isVowelLetter(S1[i]))
				cout << S1[i] << "    ";
		}
	}
	void PrintAllVowelsLetterInstring()
	{
		PrintAllVowelsLetterInstring(_Value);
	}
	// ################[17]#####################
	void PrintEachWordInString(string S1)
	{
		string delim = " "; // delimiter

		cout << "\nYour string wrords are: \n\n";
		short pos = 0;

		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length()); /* erase() until
			positon and move to next word. */
		}
		if (S1 != "")
		{
			cout << S1 << endl; // it print last word of the string.
		}
	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}
	// ################[18]#####################
	static vector<string> SplitString(string S1, string Delim = ",")
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length()); /* erase() until
			positon and move to next word. */
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}
	vector<string> SplitString()
	{
		return SplitString(_Value);
	}
	// ################[19]#####################
	// ################[20]#####################
	// ################[21]#####################
	// ################[22]#####################
	// ################[23]#####################


	__declspec(property(get = GetValue, put = setValue)) string Value;
};

