#include "clsMember.h"

clsMember::clsMember(std::string Name) {
	BuildMember(Name, EmptyEmail, EmptyPhone);
}
clsMember::clsMember(std::string Name, std::string Email, std::string Phone) {
	BuildMember(Name, Email, Phone);
}
clsMember::~clsMember(){
	std::cout << "Member " << MyName << " was deleted." << std::endl;
}
bool clsMember::BuildMember(std::string Name, std::string Email, std::string Phone) {
	MyName = Name;
	MyEmail = Email;
	MyPhone = Phone;
	std::cout << "Member " << MyName << " was created.\nEmail: " << MyEmail << "\nPhone: " << MyPhone << std::endl;
	return false;
}

bool clsMember::ItemExists(std::string Item, int Set) {
	switch (Set) {
	case 0:
		return !MyDiets.count(Item);
	case 1:
		return !MyFoodAllergies.count(Item);
	case 2:
		return !MyPetAllergies.count(Item);
	default:
		break;
	}
	std::cout << "No proper set selected." << std::endl;
	return true;
}
bool clsMember::Add(std::string Item, int Set) {
	if (ItemExists(Item, Set)) {
		std::string SetName = "";
		switch (Set) {
		case 0:
			MyDiets.insert(Item);
			SetName = "diets";
			break;
		case 1:
			MyFoodAllergies.insert(Item);
			SetName = "food allergies";
			break;
		case 2:
			MyPetAllergies.insert(Item);
			SetName = "pet allergies";
			break;
		default:
			return true;
		}
		std::cout << Item << " was added to the list of " << SetName << "." << std::endl;
		return false;
	}
	std::cout << "Item already exists." << std::endl;
	return true;
}
std::string clsMember::Get(size_t Item, int Set) {
	std::set<std::string>::iterator it;
	std::string SetName = "";
	
	switch (Set) {
		case 0:
			SetName = "diets";
			if (Item >= MyDiets.size()) {
				std::cout << "Only " << MyDiets.size() << " items in the list." << std::endl;
				return "ERROR";
			}
			it = MyDiets.begin();
			for (size_t i = 0; i <= Item; ++i, ++it);
			break;
		case 1:
			SetName = "food allergies";
			if (Item >= MyFoodAllergies.size()) {
				std::cout << "Only " << MyFoodAllergies.size() << " items in the list." << std::endl;
				return "ERROR";
			}
			it = MyFoodAllergies.begin();
			for (size_t i = 0; i <= Item; ++i, ++it)
			break;
		case 2:
			SetName = "pet allergies";
			if (Item >= MyPetAllergies.size()) {
				std::cout << "Only " << MyPetAllergies.size() << " items in the list." << std::endl;
				return "ERROR";
			}
			it = MyPetAllergies.begin();
			for (size_t i = 0; i <= Item; ++i, ++it);
			break;
		default:
			return "ERROR";
	}
	std::cout << *it << std::endl;
	return *it;
}
bool clsMember::Change(std::string Item, std::string Correction, int Set) {	
	if (!Remove(Item, Set)) {
		if (!Add(Correction, Set)) {
			std::cout << "Succesfully changed " << Item << " for " << Correction << "." << std::endl;
			return false;
		}
	}
	std::cout << "Failed to change " << Item << " for " << Correction << "." << std::endl;
	return true;
}
bool clsMember::Remove(std::string Item, int Set) {
	if (!ItemExists(Item, Set)) {
		std::string SetName = "";
		switch (Set) {
		case 0:
			MyDiets.erase(Item);
			SetName = "diets";
			break;
		case 1:
			MyFoodAllergies.erase(Item);
			SetName = "food allergies";
			break;
		case 2:
			MyPetAllergies.erase(Item);
			SetName = "pet allergies";
			break;
		default:
			return true;
		}
		std::cout << Item << " was removed from the list of " << SetName << "." << std::endl;
		return false;
	}
	std::cout << "Item does not exist." << std::endl;
	return true;
}

bool clsMember::EmailExists() {
	if (MyEmail != EmptyEmail) {
		return false;
	}
	std::cout << "No email set yet." << std::endl;
	return true;
}
bool clsMember::PhoneExists() {
	if (MyPhone != EmptyPhone) {
		return false;
	}
	std::cout << "No phone set yet." << std::endl;
	return true;
}

std::string clsMember::GetName() {
	return MyName;
}
bool clsMember::ChangeName(std::string Name) {
	MyName = Name;
	return false;
}

bool clsMember::AddEmail(std::string Email) {
	if (EmailExists()) {
		MyEmail = Email;
		return false;
	}
	std::cout << "Email already set." << std::endl;
	return true;
}
std::string clsMember::GetEmail() {
	if (!EmailExists()) {
		std::cout << MyEmail << "." << std::endl;
		return MyEmail;
	}
	return "";
}
bool clsMember::ChangeEmail(std::string Email) {
	if (!EmailExists()) {
		MyEmail = Email;
		return false;
	}
	return true;
}
bool clsMember::RemoveEmail() {
	if (!EmailExists()) {
		MyEmail = EmptyEmail;
		return false;
	}
	return true;
}

bool clsMember::AddPhone(std::string Phone) {
	if (PhoneExists()) {
		MyPhone = Phone;
		return false;
	}
	std::cout << "Phone already set." << std::endl;
	return true;
}
std::string clsMember::GetPhone() {
	if (!PhoneExists()) {
		std::cout << MyPhone << "." << std::endl;
		return MyPhone;
	}
	return "";
}
bool clsMember::ChangePhone(std::string Phone) {
	if (!PhoneExists()) {
		MyPhone = Phone;
		return false;
	}
	return true;
}
bool clsMember::RemovePhone() {
	if (!PhoneExists()) {
		MyPhone = EmptyPhone;
		return false;
	}
	return true;
}

bool clsMember::AddDiet(std::string Item) {
	return Add(Item, 0);
}
std::string clsMember::GetDiet(int Item) {
	return Get(Item, 0);
}
bool clsMember::ChangeDiet(std::string Item, std::string Correction) {
	return Change(Item, Correction, 0);
}
bool clsMember::RemoveDiet(std::string Item) {
	return Remove(Item, 0);
}
size_t clsMember::GetDietCount() {
	std::cout << MyDiets.size() << " diets.";
	return MyDiets.size();
}

bool clsMember::AddFoodAllergie(std::string Item) {
	return Add(Item, 0);
}
std::string clsMember::GetFoodAllergie(int Item) {
	return Get(Item, 0);
}
bool clsMember::ChangeFoodAllergie(std::string Item, std::string Correction) {
	return Change(Item, Correction, 0);
}
bool clsMember::RemoveFoodAllergie(std::string Item) {
	return Remove(Item, 0);
}
size_t clsMember::GetFoodAllergiesCount() {
	std::cout << MyFoodAllergies.size() << " food allergies.";
	return MyFoodAllergies.size();
}

bool clsMember::AddPetAllergie(std::string Item) {
	return Add(Item, 0);
}
std::string clsMember::GetPetAllergie(int Item) {
	return Get(Item, 0);
}
bool clsMember::ChangePetAllergie(std::string Item, std::string Correction) {
	return Change(Item, Correction, 0);
}
bool clsMember::RemovePetAllergie(std::string Item) {
	return Remove(Item, 0);
}
size_t clsMember::GetPetAllergiesCount() {
	std::cout << MyPetAllergies.size() << " pet allergies.";
	return MyPetAllergies.size();
}

bool clsMember::AddTeam(clsTeam* Team) {
	if (!MyTeam) {
		MyTeam = Team;
		std::cout << "Team added." << std::endl;
		return false;
	}
	std::cout << "A team has already been assigned." << std::endl;
	return true;
}
clsTeam* clsMember::GetTeam() {
	if (MyTeam) return MyTeam;
	std::cout << "No team has been assigned yet." << std::endl;
	return NULL;
}
bool clsMember::ChangeTeam(clsTeam* Team) {
	if (MyTeam) {
		MyTeam = Team;
		std::cout << "Team was changed." << std::endl;
		return false;
	}
	std::cout << "No team has been assigned yet." << std::endl;
	return true;
}
bool clsMember::RemoveTeam() {
		MyTeam = NULL;
		std::cout << "Team unassigned." << std::endl;
		return false;
}

bool clsMember::AddAddress(clsAddress* Address) {
	if (!MyAddress) {
		MyAddress = Address;
		std::cout << "Address added to " << MyName << "." << std::endl;
		return false;
	}
	std::cout << "An address was already added." << std::endl;
	return true;
}
clsAddress* clsMember::GetAddress(){
	if (MyAddress) return MyAddress;
	std::cout << "No address was added yet." << std::endl;
	return NULL;
}
bool clsMember::RemoveAddress() {
	MyAddress = NULL;
	std::cout << "Address removed from " << MyName << "." << std::endl;
	return false;
}