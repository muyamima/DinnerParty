#include "clsNode.h"

clsNode::clsNode(clsTeam* Host, clsZone* Course){
	MyHost = Host;
	MyCourse = Course;
	MaxGuests = 3;
}
clsNode::~clsNode(){
}

size_t clsNode::FindGuest(clsTeam* Guest) {
	std::vector<clsTeam*>::iterator it;
	size_t i = 0;
	for (it = MyGuests.begin(); it == MyGuests.end(); ++it, ++i) {
		if (*it == Guest) {
			break;
		}
	}
	return i;
}
bool clsNode::AddGuest(clsTeam* Guest) {
	if (MyGuests.size() < MaxGuests) {
		MyGuests.push_back(Guest);
		return false;
	}
	return true;
}

clsTeam* clsNode::GetHost() {
	return MyHost;
}
/*clsAddress* clsNode::GetAddress() {
	return MyHost->GetAddress();
}*/
bool clsNode::AddGuests(clsTeam* Guest1, clsTeam* Guest2) {
	if (AddGuest(Guest1)) return true;
	if (AddGuest(Guest2)) return true;
	return false;
}
clsTeam* clsNode::GetGuest(size_t Item) {
	if (GetGuestCount() > Item) return MyGuests[Item];
	return NULL;
}
bool clsNode::ChangeGuest(clsTeam* Guest, clsTeam* Replacement) {
	if (FindGuest(Guest) != GetGuestCount()) {
		MyGuests[FindGuest(Guest)] = Replacement;
		return false;
	}
	return true;
}
size_t clsNode::GetGuestCount() {
	return MyGuests.size();
}
clsZone* clsNode::GetCourse() {
	if (MyCourse) return MyCourse;
	return NULL;
}