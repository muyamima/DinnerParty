#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

class clsAddress;
class clsItinerary;

#include <vector>
#include <iostream>
#include "clsMember.h"

class clsTeam
{
private:
	unsigned int MaxExtraMembers;
	unsigned int MaxTeamSize = 2 + MaxExtraMembers;
	std::vector<clsMember*> MyMembers;	//Team member pointers.
	clsItinerary* MyItinerary;	//Team itinerary pointer.
	clsTeam* AdditionalTeam;	//Slot for extra team in case of undiviseble # of teams.

	bool MemberExists(size_t Item); //False if member exists.
	bool AddMember(clsMember* Member); //Add a member.
	clsMember* GetMember(size_t Item);	//Get member info at size_t.
	bool ChangeMember(clsMember* Member, size_t Item); //Replace a member at size_t.
	bool RemoveMember(size_t Item);	//Remove a member at size_t.

public:
	clsTeam();
//	clsTeam(clsMember*);
	clsTeam(clsMember* Member1, clsMember* Member2);
	~clsTeam();
	bool BuildTeam(clsMember* Member1, clsMember* Member2);
	
	clsMember* GetPrimaryMember();	//Primary member info.
	bool ChangePrimaryMember(clsMember* Member);	//Replace primary member.
	//Add secondary member.
	clsMember* GetSecondaryMember();	//Secondary member info.
	bool ChangeSecondaryMember(clsMember* Member);	//Replace secondary member.
	//Remove secondary member.
	bool SwapPrimaryMember();	//Swap first and second member.
	bool AddOtherMember(clsMember* Member);	//Add an additional member
	clsMember* GetOtherMember(size_t Item);	//Get other member at int if exists.
	bool ChangeOtherMember(clsMember* Member, size_t Item);	//Replace an additional member.
	bool RemoveOtherMember(size_t Item);	//Remove an additional member.
	size_t GetExtraMemberCount();	//Get number of extra members.

	clsAddress* GetAddress();	//Get the teams address.
	
	bool SetItinerary(clsItinerary* Itinerary);	//Set team itinerary.
	clsItinerary* GetItinerary();	//Get the teams itinerary.
	bool ChangeItinerary(clsItinerary* Itinerary);	//Change the itinerary.
	
	bool AddAdditionalTeam(clsTeam* Team);	//Add an additional team.
	clsTeam* GetAdditionalTeam();	//Get additional team.
	bool ChangeAdditionalTeam(clsTeam* Team);	//Change additional team.
	bool RemoveAdditionalTeam();	//Remove additional team.
};
#endif // !TEAM_H_INCLUDED