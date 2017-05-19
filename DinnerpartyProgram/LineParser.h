#ifndef LINEPARSER_H_INCLUDED
#define LINEPARSER_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

#include "StringConditioner.h"
namespace LineParser
{
	int Parse(std::string String, std::vector<std::string>& Container, std::vector<char> Delimiter = { ';', ' ','-','/','\n','\0' });	//Break up input into seperate arguments.
};
#endif // !LINEPARSER_H_INCLUDED