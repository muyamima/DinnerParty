#ifndef STRINGCONDITIONER_H_INCLUDED
#define STRINGCONDITIONER_H_INCLUDED

#include <string>

namespace StringConditioner
{
	std::string LTrim(std::string String, char Trimmer = ' ');	//Trim left end of string.
	std::string RTrim(std::string String, char Trimmer = ' ');	//Trim right end of string.
	std::string Trim(std::string String, char Trimmer = ' ');	//Trim both ends of string.

	std::string ToLower(std::string String);	//All lower.
	std::string ToUpper(std::string String);	//Cap first.
	std::string ToUpperAfterSpace(std::string String); //Cap every letter after space.

	std::string Reduce(std::string String, char Trimmer = ' ');	//Take out double spaces.

	std::string Unwrap(std::string String, char Wrapper = '"'); //Take away first and last place quotes.
	
	std::string All(std::string String, char Trimmer = ' '); //Everything.
	std::string ReduceTrim(std::string String, char Trimmer = ' ');	//Reduce then trim.
	std::string TrimCap(std::string String, char Trimmer = ' ');	//Trim then capitalise.
	std::string TrimCapAS(std::string String, char Trimmer = ' ');	// Trim then cap after space.
};
#endif // !STRINGCONDITIONER_H_INCLUDED