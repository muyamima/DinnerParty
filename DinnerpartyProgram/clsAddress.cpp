#include "clsAddress.h"

clsAddress::clsAddress(clsMember* Owner){
	MyOwner = Owner;
	std::cout << "Address for " << MyOwner->GetName() << " created." << std::endl;
}

//Remove address from owner.
clsAddress::~clsAddress(){
	std::cout << "Address for " << MyOwner->GetName() << " removed." << std::endl;
}

bool clsAddress::PetExists(std::string Pet) {
	if (MyPets.find(Pet) == MyPets.end()) {
		return true;
		std::cout << Pet << " was not found in the list of pets at " << MyOwner->GetName() << "'s address." << std::endl;
	}
	else {
		return false;
	}
}

std::string clsAddress::GetAddress() {
	std::cout << MyAddress << "." << std::endl;
	return MyAddress;
}
void clsAddress::ChangeAddress(std::string Address) {
	MyAddress = Address;
	std::cout << "Address was change to: " << MyAddress << "." << std::endl;
}
std::string clsAddress::GetAddInfo() {
	std::cout << MyAdditionalInfo << "." << std::endl;
	return MyAdditionalInfo;
}
void clsAddress::ChangeAddInfo(std::string AddInfo) {
	MyAdditionalInfo = AddInfo;
	std::cout << "Additional info was change to: " << MyAdditionalInfo <<"." << std::endl;
}
void clsAddress::RemoveAddInfo() {
	ChangeAddInfo("");
	std::cout << "Additional info erase." << std::endl;
}

bool clsAddress::AddPet(std::string Pet) {
	if (PetExists(Pet)) {
		std::cout << Pet << " was added to the list of pets at the address of " << MyOwner->GetName() << "." << std::endl;
		MyPets.insert(Pet);
		return false;
	}
	else {
		return true;
	}
}
std::string clsAddress::GetPet(size_t Item) {
	std::set<std::string>::iterator it = MyPets.begin();
	for (size_t i = 0; i < Item; ++i, ++it) {}
	std::cout << *it << "." << std::endl;
	return *it;
}
bool clsAddress::ChangePet(std::string Pet, std::string Correction) {
	if (!PetExists(Pet)) {
		RemovePet(Pet);
		AddPet(Correction);
		std::cout << Pet << " was changed into " << Correction << std::endl;
		return false;
	}
	else {
		return true;
	}
}
bool clsAddress::RemovePet(std::string Pet) {
	if (!PetExists(Pet)) {
		MyPets.erase(Pet);
		std::cout << "Pet: " << Pet << " removed from " << MyOwner->GetName() << "'s address." << std::endl;
		return false;
	}
	else {
		return true;
	}
}
size_t clsAddress::GetPetsCount() {
	std::cout << "There are " << MyPets.size() << " pets at " << MyAddress << "." << std::endl;
	return MyPets.size();
}

clsZone* clsAddress::GetZone() {
	return MyZone;
	std::cout << MyAddress << " is in " << MyZone->GetName() << "." << std::endl;
}
void clsAddress::ChangeZone(clsZone* Zone) {
	MyZone = Zone;
	std::cout << "Zone of " << MyAddress << " was changed to " << MyZone->GetName() << "." << std::endl;
}
clsMember* clsAddress::GetOwner() {
	return MyOwner;
	std::cout << MyAddress << " is owned by " << MyOwner->GetName() << "." << std::endl;
}
void clsAddress::ChangeOwner(clsMember* Owner) {
	MyOwner = Owner;
	std::cout << "Owners of " << MyAddress << " was changed to " << MyOwner << "." << std::endl;
}