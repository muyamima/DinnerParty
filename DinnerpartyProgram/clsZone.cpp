#include "clsZone.h"

clsZone::clsZone() {}
//Create a zone with the name supplied.
//Add its own address to both maps.
clsZone::clsZone(std::string ZoneName){
	MyName = ZoneName;
//	Donors[ZoneName] = this;
//	Acceptors[ZoneName] = this;
	std::cout << "Zone " << MyName << " was created." << std::endl;
}
clsZone::~clsZone(){
	std::cout << "Zone " << MyName << " was removeded." << std::endl;
}

//Check if a name can actually be found in the selected map.
bool clsZone::LinkExists(std::string ZoneName, bool DA) {
	if (!DA) {
		if (Donors.find(ZoneName) == Donors.end()) {
			return true;
			std::cout << ZoneName << ": Zone not found in the donor list of " << MyName << "." << std::endl;
		}
		else {
			return false;
		}
	}
	else {
		if (Acceptors.find(ZoneName) == Acceptors.end()) {
			return true;
			std::cout << ZoneName << ": Zone not found in the acceptor list of " << MyName << "." << std::endl;
		}
		else {
			return false;
		}
	}
}

std::string clsZone::GetName() {
	std::cout << MyName << "." << std::endl;
	return MyName;
}

//Add a link to the item give to the selected map.
//Reporting success or failure.
bool clsZone::AddLink(clsZone& Zone, bool DA) {
	bool Failure = true;
	std::string ListName = "";

	if (!DA) {
		ListName = "donor";
		if (LinkExists(Zone.GetName(), DA)) {
			Donors[Zone.GetName()] = &Zone;
			Failure = false;
		}
	}
	else {
		ListName = "acceptor";
		if (LinkExists(Zone.GetName(), DA)) {
			Acceptors[Zone.GetName()] = &Zone;
			Failure = false;
		}
	}

	if (!Failure)	{
		std::cout << Zone.GetName() << " at " << &Zone << " was added to the " << ListName << " list of " << MyName << "." << std::endl;
	}
	else {
		std::cout << "Zone " << Zone.GetName() << " could not be added to the " << ListName << " list of " << MyName << ": Zone is already in the list." << std::endl;
	}
	return Failure;
}
//Get the address of items on a specific place in the map, either donors or acceptors.
//The iterator goes up as many times as the number supplied.
//Then returns the address at that place.
clsZone* clsZone::GetLink(size_t Item, bool DA) {
	std::map<std::string, clsZone*>::iterator it;
	if (!DA) {
		if (Item <= GetMapCount(DA)) {
			it = Donors.begin();
			for (size_t i = 0; i < Item; ++i, ++it) {}
		}
		else {
			std::cout << "Only " << GetMapCount(DA) << " items in the donor list; " << Item << " is to big." << std::endl;
		}
	}
	else {
		if (Item <= GetMapCount(DA)) {
			it = Acceptors.begin();
			for (size_t i = 0; i < Item; ++i, ++it) {}
		}
		else {
			std::cout << "Only " << GetMapCount(DA) << " items in the acceptor list; " << Item << " is to big." << std::endl;
		}
	}
	return it->second;
}

//Removing the link to the item given from the selected map.
//Reporting success or failure.
bool clsZone::RemoveLink(clsZone& Zone, bool DA) {
	bool Failure = true;
	std::string ListName = "";

	if (!DA) {
		ListName = "donor";
		if (!LinkExists(Zone.GetName(), DA)) {
			Donors.erase(Zone.GetName());
			Failure = false;
		}
	}
	else {
		ListName = "acceptor";
		if (!LinkExists(Zone.GetName(), DA)) {
			Acceptors.erase(Zone.GetName());
			Failure = false;
		}
	}

	if (!Failure) {
		std::cout << "Zone " << Zone.GetName() << " was removeded from the " << ListName << " list of " << MyName << "." << std::endl;
	}

	else {
		std::cout << "Could not delete " << Zone.GetName() << ": Zone not found in the " << ListName << " list of " << MyName << "." << std::endl;
	}
	return Failure;
}
size_t clsZone::GetMapCount(bool DA) {
	if (!DA) {
		std::cout << MyName << " has " << Donors.size() << "donors." << std::endl;
		return Donors.size();
	}
	else {
		std::cout << MyName << " has " << Acceptors.size() << "acceptors." << std::endl;
		return Acceptors.size();
	}
}