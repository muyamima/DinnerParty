/*
This is a program to import an excel table containing info about different teams.
Shuffle the team.
Send out emails.
*/

class ZoneManipulator;

#include <iostream>
#include <fstream>
#include <list>

#include "windows.h"
#include "clsZone.h"
#include "clsMember.h"
#include "clsAddress.h"
#include "clsTeam.h"
#include "clsNode.h"
#include "clsItinerary.h"
#include "ZoneManipulator.h"
#include "StringConditioner.h"
#include "LineParser.h"
#include <fstream>

std::map<std::string, clsZone> Zones;	//Map of Zones
std::map<std::string, clsZone> Courses;	//Map of Courses
std::list<clsMember> Members;
std::list<clsAddress> Addresses;
std::list<clsTeam> Teams;
std::list<clsNode> Nodes;
std::list<clsItinerary> Itinerarys;

int main(int argc, char** argv){
	std::string Input;
	std::vector<std::string> InputVector;
	do {
		std::getline(std::cin, Input);

		//Input = StringConditioner::All(Input);

		LineParser::Parse(Input, InputVector);

		if (InputVector[0] == "Testthis.") {
			std::cout << "Woop Woop" << std::endl;
			Sleep(1000);
			return 0;
		}

/*		std::vector<std::string> Values;
		int NoValues;


		for (int i = NoValues; i >= 0; --i) {
			std::cout << Values[i] << "," << std::endl;
		}
		*/
		if (Input == "/?") {
			std::cout << "Zone: Edit zones.\n" <<
				"Course: Edit courses.\n" <<
				"Member: Edit members.\n" <<
				"Team: Edit teams.\n" <<
				"Address: Edit addressses.\n" <<
				"Node: Edit nodes.\n" <<
				"Itinerary: Edit itineraries.\n" <<
				"Load: Load a file.\n" <<
				"Mix: Run the algotrithm.\n" <<
				"Typ \"Exit\" to exit." << std::endl;
		}
		else if (Input == "Zone") {
//			ZoneManipulator(Zones);
			std::cout << Input << " Zone."<< std::endl;
		}
		else if (Input == "Course"){
			std::cout << Input << " Course." << std::endl;
		}
		else if (Input == "Member") {
			std::cout << Input << " Member." << std::endl;
		}
		else if (Input == "Address") {
			std::cout << Input << " Address." << std::endl;
		}
		else if (Input == "Node") {
			std::cout << Input << " Node." << std::endl;
		}
		else if (Input == "Itinerary") {
			std::cout << Input << " Itinerary." << std::endl;
		}
		else if (Input == "Load") {
			std::cout << Input << " Load." << std::endl;
		}
		else if (Input == "Mix") {
			std::cout << Input << " Mix." << std::endl;
		}
		else {
			std::cout << Input << "<- wtf." << std::endl;
//			std::cout << "Type /? for help." << std::endl;
		}
	} while (Input != "Exit");
	std::cout << "Exiting main..." << std::endl;
	_sleep(1000);
	return 0;
}