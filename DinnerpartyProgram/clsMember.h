#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

class clsAddress;
class clsTeam;

#include <string>
#include <set>
#include <iostream>

class clsMember
{
private:
	const std::string EmptyEmail = "No email set.";
	const std::string EmptyPhone = "No phone set.";
	std::string MyName;	//Name of the member.
	std::string MyEmail;	//Member email address.
	std::string MyPhone;	//Member telephone address.
	std::set<std::string> MyDiets;	//Member special diet.
	std::set<std::string> MyFoodAllergies;	//Food allergies for this member.
	std::set<std::string> MyPetAllergies;	//Pet allergies for this member.
	clsTeam* MyTeam;	//Team which I'm a member of.
	clsAddress* MyAddress;	//Member address.

	bool ItemExists(std::string Item, int Set);	//False if item exists.
	bool Add(std::string Item, int Set);	//Add item to set. Diet 0, food 1, pet 2.
	std::string Get(size_t Item, int Set); //Return item. Place, set
	bool Change(std::string Item, std::string Correction, int Set);	//Change item. 
	bool Remove(std::string Item, int Set); //Remove item.

	bool EmailExists();	//False if email does not exist.
	bool PhoneExists(); //False if phone does not exist.

public:
	clsMember(std::string Name);	//Name.
	clsMember(std::string Name, std::string Email, std::string Phone);	//Name, email and phone.
	~clsMember();
	bool BuildMember(std::string Name, std::string Email, std::string Phone);	//Name, email and phone.

	std::string GetName();	//Return members name.
	bool ChangeName(std::string Name);	//Change members name.
	
	bool AddEmail(std::string Email); //Add member email.
	std::string GetEmail();	//Return members email.
	bool ChangeEmail(std::string Email);	//Change members email.
	bool RemoveEmail();	//Remove member email.

	bool AddPhone(std::string Phone);//Add member phone.
	std::string GetPhone();	//Return members phone.
	bool ChangePhone(std::string Phone);	//Change members phone.
	bool RemovePhone();//Remove member phone.
	
	bool AddDiet(std::string Item);	//Add a diet.
	std::string GetDiet(int Item);	//Return members diets.
	bool ChangeDiet(std::string Item, std::string Correction); //Change a diet.
	bool RemoveDiet(std::string Item); //Remove item from diets.
	size_t GetDietCount();	//Number of diets.

	bool AddFoodAllergie(std::string Item);	//Add a food allergie.
	std::string GetFoodAllergie(int Item);	//Return members food allergies.
	bool ChangeFoodAllergie(std::string Item, std::string Correction); //Change a food allergie.
	bool RemoveFoodAllergie(std::string Item); //Remove item from food allergies.
	size_t GetFoodAllergiesCount();	//Number of food allergies.

	bool AddPetAllergie(std::string Item);	//Add a pet allergie.
	std::string GetPetAllergie(int Item);	//Return members pet allergies.
	bool ChangePetAllergie(std::string Item, std::string Correction); //Change a pet allergie.
	bool RemovePetAllergie(std::string Item); //Remove item from pet allergies.
	size_t GetPetAllergiesCount();	//Number of pet allergies.
	
	bool AddTeam(clsTeam* Team);	//Add members team.
	clsTeam* GetTeam();	//Return members team.
	bool ChangeTeam(clsTeam* Team);	//Change members team.
	bool RemoveTeam();	//Remove members team.

	bool AddAddress(clsAddress* Address);	//Add members address.
	clsAddress* GetAddress();	//Return members adress.
	bool RemoveAddress();	//Remove members address.
};
#endif // !MEMBER_H_INCLUDED