#ifndef ZONEMANIPULATOR_H_INCLUDED
#define ZONEMANIPULATOR_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "clsZone.h"

class ZoneManipulator
{
private:
	std::map<std::string, clsZone>& Map; //Reference to the map used.
	bool ZoneExists(std::string Name);	//Returns false if zone with that name exists.

	bool Running(int argc, char** argv);  //Running the manipulator.

public:
//	ZoneManipulator();
	ZoneManipulator(std::map<std::string, clsZone>& MapRef);
	~ZoneManipulator();

	size_t GetZonesTotal();	//Returns total number of zones.
	bool AddZone(std::string Name);	//Add a zone to the map.
	bool RemoveZone(clsZone& Zone);	//Remove a zone from the map.
	bool RemoveZone(std::string Name); //Remove a zone from the map.
	clsZone* GetZone(size_t Item = 0);	//Get pointer to zone at the place of int.
	clsZone* GetZone(std::string Name);	//Get pointer to zone with name Name.
	void ListZoneDA(clsZone& Zone, bool DA);	//List the names of the donors (0) or acceptors (1) of a zone.
	void ListZoneDA(std::string Name, bool DA);	//List the names of the donors (0) or acceptors (1) of a zone.
	bool AddConnection(clsZone& Donor, clsZone& Acceptor);	//Add a connection between first (donor) and second (acceptor).
	bool AddConnection(std::string Donor, std::string Acceptor);	//Add a connection between first (donor) and second (acceptor).
	bool RemoveConnection(clsZone& Donor, clsZone& Acceptor);	//Remove a connection between first (donor) and second (acceptor).
	bool RemoveConnection(std::string Donor, std::string Acceptor);	//Remove a connection between first (donor) and second (acceptor).
};
#endif // !ZONEMANIPULATOR_H_INCLUDED