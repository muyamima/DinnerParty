#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <string>
#include <map>
#include <iostream>

class clsZone
{
protected:
	std::string MyName;	//Zone Name.
	std::map<std::string, clsZone*> Donors;	//Zones that can donate to this one.
	std::map<std::string, clsZone*> Acceptors;	//Zones that can accept zones from this one.
	bool LinkExists(std::string ZoneName, bool DA);	//Returns false if link exists. Donors (0), acceptors (1).
public:
	clsZone();
	clsZone(std::string ZoneName); //Name.
	~clsZone();
	
	std::string GetName();	//Returns my name.
	bool AddLink(clsZone& Zone, bool DA);	//Add a link with another zone. Donors (0), acceptors (1).
	clsZone* GetLink(size_t Item, bool DA);	//Returns address of a zone at a specific place, if exists. Donors (0), acceptors (1).
	bool RemoveLink(clsZone& Zone, bool DA);	//Remove a link with another zone. Donors (0), acceptors (1).
	size_t GetMapCount(bool DA);	//Returns the number items in map. Donors (0), acceptors (1).
};
#endif // !ZONE_H_INCLUDED