#include "ZoneManipulator.h"

ZoneManipulator::ZoneManipulator(std::map<std::string, clsZone>& MapRef):Map(MapRef){
	std::cout << "Starting Zone Manipulator." << std::endl;
//	Running(0, );
}
ZoneManipulator::~ZoneManipulator(){
	std::cout << "Exiting Zone Manipulator." << std::endl;
}

bool ZoneManipulator::Running(int argc, char** argv) {
	return false;
}


bool ZoneManipulator::ZoneExists(std::string Name) {
	if (Map.find(Name)== Map.end())	{
		return true;
		std::cout << Name << ": Zone not found in the zone list." << std::endl;
	}
	else {
		return false;
	}
}

size_t ZoneManipulator::GetZonesTotal() {
	std::cout << "Total zones: " << Map.size() << "." << std::endl;
	return Map.size();
}

bool ZoneManipulator::AddZone(std::string Name) {
	if (ZoneExists(Name)) {
		clsZone NewZone(Name); 
		Map[Name] = NewZone;
		return false;
	}
	else {
		std::cout << "Item with name: " << Name << " already exists in the map." << std::endl;
		return true;
	}
}

bool ZoneManipulator::RemoveZone(clsZone& Zone) {
	if (!ZoneExists(Zone.GetName())) {
		size_t Donors = Zone.GetMapCount(false);
		size_t Acceptors = Zone.GetMapCount(true);

		for (size_t i = 0; i <= Donors; ++i) {
			Zone.RemoveLink(Zone, false);
		}
		for (size_t i = 0; i <= Acceptors; ++i) {
			Zone.RemoveLink(Zone, true);
		}
		Map.erase(Zone.GetName());
		return false;
	}
	else {
		std::cout << "No item with name: " << Zone.GetName() << " found in the map." << std::endl;
		return true;
	}
}
bool ZoneManipulator::RemoveZone(std::string Name) {
	return RemoveZone(*GetZone(Name));
}

clsZone* ZoneManipulator::GetZone(size_t Item) {
	if (Item <= GetZonesTotal()) {
		std::map<std::string, clsZone>::iterator it;
		it = Map.begin();
		for (size_t i = 0; i < Item; ++i, ++it) {}
		return &it->second;
	}
	else {
		std::cout << "Only " << GetZonesTotal() << " items in the zone list; " << Item << " is to big." << std::endl;
		return NULL;
	}
}
clsZone* ZoneManipulator::GetZone(std::string Name) {
	if (!ZoneExists(Name)) {
		return &Map.find(Name)->second;
	}
	else{
		std::cout << "No item with name: " << Name << " found in the map." << std::endl;
		return NULL;
	}
}

void ZoneManipulator::ListZoneDA(clsZone& Zone, bool DA) {
	std::string ListName = "";
	std::string List = "";
	size_t DACount = Zone.GetMapCount(DA);

	if (!DA) {
		ListName = "donor";
	}
	else {
		ListName = "acceptor";
	}
	for (size_t i = 0; i <= DACount; ++i) {
		List = List + "\t" + Zone.GetLink(i, DA)->GetName();
	}
		std::cout << "Members in the " << ListName << " list:" << std::endl << List << std::endl;
}
void ZoneManipulator::ListZoneDA(std::string Name, bool DA) {
	ListZoneDA(*GetZone(Name), DA);
}

bool ZoneManipulator::AddConnection(clsZone& Donor, clsZone& Acceptor) {
	if (ZoneExists(Donor.GetName())) {
		std::cout << "Donor does not exist." << std::endl;
		return true;
	}
	if (ZoneExists(Acceptor.GetName())) {
		std::cout << "Acceptor does not exist." << std::endl;
		return true;
	}
	if (!ZoneExists(Donor.GetName()) && !ZoneExists(Acceptor.GetName())) {
		Donor.AddLink(Acceptor, true);
		Acceptor.AddLink(Donor, false);
		std::cout << "Successfully added a link from " << Donor.GetName() << " towards " << Acceptor.GetName() << "." << std::endl;
		return false;
	}
	return true;
}
bool ZoneManipulator::AddConnection(std::string Donor, std::string Acceptor) {
	if (ZoneExists(Donor)) {
		clsZone NewZone(Donor);
		Map[Donor] = NewZone;
	}
	if (ZoneExists(Acceptor)) {
		clsZone NewZone(Acceptor);
		Map[Acceptor] = NewZone;
	}
	return AddConnection(*GetZone(Donor), *GetZone(Acceptor));
}

bool ZoneManipulator::RemoveConnection(clsZone& Donor, clsZone& Acceptor) {
	if (ZoneExists(Donor.GetName())) {
		std::cout << "Donor does not exist." << std::endl;
		return true;
	}
	if (ZoneExists(Acceptor.GetName())) {
		std::cout << "Acceptor does not exist." << std::endl;
		return true;
	}
	if (!ZoneExists(Donor.GetName()) && !ZoneExists(Acceptor.GetName())) {
		Donor.RemoveLink(Acceptor, true);
		Acceptor.RemoveLink(Donor, false);
		std::cout << "Successfully removed a link from " << Donor.GetName() << " towards " << Acceptor.GetName() << "." << std::endl;
		return false;
	}
	return true;
}
bool ZoneManipulator::RemoveConnection(std::string Donor, std::string Acceptor) {
	if (ZoneExists(Donor)) {
		std::cout << "Donor does not exist." << std::endl;
		return true;
	}
	if (ZoneExists(Acceptor)) {
		std::cout << "Acceptor does not exist." << std::endl;
		return true;
	}
	return RemoveConnection(*GetZone(Donor), *GetZone(Acceptor));
}