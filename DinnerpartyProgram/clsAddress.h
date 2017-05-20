#ifndef ADDRESS_H_INCLUDED
#define ADDRESS_H_INCLUDED

class clsZone;

#include <set>
#include <iostream>

#include "clsMember.h"
#include "clsZone.h"

class clsAddress
{
private:
	std::string MyAddress;	//Physical address.
	clsZone* MyZone;	//Zone this address is in.
	std::string MyAdditionalInfo = "";	//Additional info. e.g Door code.
	std::set<std::string> MyPets;	//Pets residing at this address.
	clsMember* MyOwner;	//Owner of this address.

	bool PetExists(std::string Pet);	//Returns false if pet is found.

public:
	clsAddress(clsMember* Owner);
	~clsAddress();

	std::string GetAddress();	//Get the physical address.
	void ChangeAddress(std::string Address);	//Change the physical address.
	std::string GetAddInfo();
	void ChangeAddInfo(std::string AddInfo);	//Change the additional info.
	void RemoveAddInfo();	//Remove the additional info.
	
	bool AddPet(std::string Pet);	//Add a pet to the pets list.
	std::string GetPet(size_t Item);	//Get the pet at certain place from list.
	bool ChangePet(std::string Pet, std::string Correction);	//Change name of a pet.
	bool RemovePet(std::string Pet);	//Remove a pet form the list.
	size_t GetPetsCount();	//Number of pets.

	clsZone* GetZone();	//Return zone of address.
	void ChangeZone(clsZone* Zone);	//Change zone of address.
	clsMember* GetOwner();	//Return owner of address.
	void ChangeOwner(clsMember* Owner); //Change owner of address.
};
#endif // !ADDRESS_H_INCLUDED