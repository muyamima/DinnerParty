#include "LineParser.h"

//Assumes string is already conditioned! Trim and reduce.
int LineParser::Parse(std::string String, std::vector<std::string>& Container, std::vector<char> Delimiter) {
	int Failed = 1;
	bool DQuoteOpen = 0;
//	bool SQuoteOpen = 0;
	std::string CurrentWord = "";
	char CurrentChar;
	std::vector<std::string> TempVector;

	for (size_t i = 0; i <= String.size(); ++i) {
		CurrentChar = String[i];

		if (CurrentChar == '\"') {
			if (!DQuoteOpen) {	DQuoteOpen = 1;	}
			else if (DQuoteOpen) { DQuoteOpen = 0;	}
		}
		if (CurrentChar == '\\') {	//\n, \t, \-escape.
			++i;
			switch (String[i]) {
			case 'n':
				CurrentChar = '\n';
				break;
			case 't':
				CurrentChar = '\t';
				break;
			default:
				break;
			}
		}
		if (!DQuoteOpen) {
			for each (char c in Delimiter) {
				if (String[i] == c || CurrentChar == '\"') {
					TempVector.push_back(StringConditioner::TrimCapAS(CurrentWord));
					CurrentWord = "";
					break;
				}

			}
		}
	CurrentWord += CurrentChar;
	}
	if (!DQuoteOpen) {
		Failed = 0;
		Container = TempVector;
	}
	return Failed;
}