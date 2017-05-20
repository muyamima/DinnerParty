#include "clsTeam.h"

clsTeam::clsTeam() {
	BuildTeam(NULL, NULL);
	std::cout << "Empty team created." << std::endl;
}
/* clsTeam::clsTeam(clsMember* Member) {
	BuildTeam(Member, NULL);
	std::cout << "Team with " << Member->GetName() << " created." << std::endl;
} */
clsTeam::clsTeam(clsMember* Member1, clsMember* Member2){
	BuildTeam(Member1, Member2);
	std::cout << "Team with " << Member1->GetName() << " and " << Member2->GetName() << " created." << std::endl;
}
clsTeam::~clsTeam() {
	if (MyMembers.size() == 0) {
		std::cout << "Empty team was deleted." << std::endl;
	}
	else {
		std::string MemberNames = MyMembers[0]->GetName();
		if (MyMembers.size() > 2) {
			for (size_t i = 1; i <= MyMembers.size() - 2; i++) {
				MemberNames += ", " + MyMembers[i]->GetName();
			}
		}
		if (MyMembers.size() > 1) {
			MemberNames += " and " + MyMembers[MyMembers.size() - 1]->GetName();
		}
		std::cout << "The team of " << MemberNames << " was deleted." << std::endl;
	}
}
bool clsTeam::BuildTeam(clsMember* Member1, clsMember* Member2) {
	MaxExtraMembers = 1;

	if (MyMembers.size() == 0) {
		if (!Member1) {
			AddMember(Member1);
		}
		if (!Member1) {
			AddMember(Member2);
		}
		return false;
	}
	std::cout << "There are already " << MyMembers.size() << " members in this team." << std::endl;
	return true;
}

bool clsTeam::MemberExists(size_t Item) {
	if (Item > MyMembers.size()) {
		if (MyMembers[Item]) {
			return false;
		}
		std::cout << "Null pointer at " << Item << "." << std::endl;
		return true;
	}
	std::cout << "There are only " << MyMembers.size() << " members." << std::endl;
	return true;
}
bool clsTeam::AddMember(clsMember* Member) {
	if (MyMembers.size() < MaxTeamSize) {
		MyMembers.push_back(Member);
		std::cout << Member->GetName() << " was added to the team." << std::endl;
		return false;
	}
	std::cout << "Only " << MaxTeamSize << " members allowed in one team." << std::endl;
	return true;
}
clsMember* clsTeam::GetMember(size_t Item) {
	if (!MemberExists(Item)) {
		return MyMembers[Item];
	}
	return NULL;
}
bool clsTeam::ChangeMember(clsMember* Member, size_t Item) {
	if (!MemberExists(Item)) {
		MyMembers[Item] = Member;
		return false;
	}
	return true;
}
bool clsTeam::RemoveMember(size_t Item) {
	if (!MemberExists(Item)) {
		MyMembers.erase(MyMembers.begin() + Item);
		return false;
	}
	return true;
}

clsMember* clsTeam::GetPrimaryMember() {
	if (!MemberExists(0)) {
		std::cout << "Primary member: " << MyMembers[0]->GetName() << "." << std::endl;
		return MyMembers[0];
	}
	std::cout << "A primary member not assigned yet." << std::endl;
	return NULL;
}
bool clsTeam::ChangePrimaryMember(clsMember* Member) {
	if (!MemberExists(0)) {
		MyMembers[0] = Member;
		std::cout << "Primary member change to: " << MyMembers[0]->GetName() << "." << std::endl;
		return false;
	}
	MyMembers[0] = Member;
	return false;
}
clsMember* clsTeam::GetSecondaryMember() {
	if (!MemberExists(1)) {
		std::cout << "Secondary member: " << MyMembers[0]->GetName() << "." << std::endl;
		return MyMembers[1];
	}
	std::cout << "A secondary member not assigned yet." << std::endl;
	return NULL;
}
bool clsTeam::ChangeSecondaryMember(clsMember* Member) {
	if (!MemberExists(1)) {
		MyMembers[1] = Member;
		std::cout << "Secondary member change to: " << MyMembers[0]->GetName() << "." << std::endl;
		return false;
	}
	MyMembers[1] = Member;
	return false;
}
bool clsTeam::SwapPrimaryMember() {
	if (!MemberExists(0) && !MemberExists(1)) {
		clsMember* TempMember = MyMembers[0];
		MyMembers[0] = MyMembers[1];
		MyMembers[1] = TempMember;
		std::cout << "Primary and secondary swapped places." << std::endl;
		return false;
	}
	std::cout << "Primary and/or secondary member do not exist." << std::endl;
	return true;
}
bool clsTeam::AddOtherMember(clsMember* Member) {
	return AddMember(Member);
}
clsMember* clsTeam::GetOtherMember(size_t Item) {
	size_t MemberNr = 2;// +Item;

	if (!MemberExists(MemberNr)) {
		std::cout << "Extra member at place " << Item << ": " << MyMembers[MemberNr]->GetName() << "." << std::endl;
		return MyMembers[MemberNr];
	}
	std::cout << "No extra members have been assigned yet." << std::endl;
	return NULL;
}
bool clsTeam::ChangeOtherMember(clsMember* Member, size_t Item) {
	size_t MemberNr = 2;// +Item;

	if (!MemberExists(MemberNr)) {
		MyMembers[MemberNr] = Member;
		std::cout << "Extra member change to: " << MyMembers[MemberNr]->GetName() << "." << std::endl;
		return false;
	}
	return false;
}
bool clsTeam::RemoveOtherMember(size_t Item) {
	size_t MemberNr = 2;// +Item;

	if (!MemberExists(MemberNr)) {
		RemoveMember(MemberNr);
		std::cout << "Extra member was removed." << std::endl;
		return false;
	}
	return true;
}
size_t clsTeam::GetExtraMemberCount() {
	return MyMembers.size() - 2;
}

clsAddress* clsTeam::GetAddress() {
	if (MyMembers[0]) {
		std::cout << "The address for this team is " << MyMembers[0]->GetAddress() << "." << std::endl;
		return MyMembers[0]->GetAddress();
	}
	std::cout << "No primary member exists." << std::endl;
	return NULL;
}

bool clsTeam::SetItinerary(clsItinerary* Itinerary) {
	if (!MyItinerary) {
		MyItinerary = Itinerary;
		return false;
	}
	std::cout << "Itinerary already set." << std::endl;
	return true;
}
clsItinerary* clsTeam::GetItinerary() {
	if (MyItinerary) {
		return MyItinerary;
	}
	std::cout << "No itinerary set yet." << std::endl;
	return NULL;
}
bool clsTeam::ChangeItinerary(clsItinerary* Itinerary) {
	if (MyItinerary) {
		MyItinerary = Itinerary;
		std::cout << "Itinerary changed." << std::endl;
		return false;
	}
	SetItinerary(Itinerary);
	return true;
}

bool clsTeam::AddAdditionalTeam(clsTeam* Team) {
	if (!AdditionalTeam) {
		AdditionalTeam = Team;
		return false;
	}
	std::cout << "An additional team already exists." << std::endl;
	return true;
}
clsTeam* clsTeam::GetAdditionalTeam() {
	if (AdditionalTeam) {
		return AdditionalTeam;
	}
	std::cout << "No additional team assigned." << std::endl;
	return NULL;
}
bool clsTeam::ChangeAdditionalTeam(clsTeam* Team) {
	if (AdditionalTeam) {
		AdditionalTeam = Team;
		std::cout << "Additional team was changed yet." << std::endl;
		return false;
	}
	AddAdditionalTeam(Team);
	return true;
}
bool clsTeam::RemoveAdditionalTeam() {
	if (AdditionalTeam) {
		std::cout << "Additional team removed." << std::endl;
		return false;
	}
	std::cout << "No additional team assigned yet." << std::endl;
	return true;
}