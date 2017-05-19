#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class clsTeam;
class clsZone;
class clsAddress;

#include <vector>

//#include "clsTeam.h";

class clsNode
{
private:
	size_t MaxGuests;
	clsTeam* MyHost;
	std::vector<clsTeam*> MyGuests;
	clsZone* MyCourse;

	size_t FindGuest(clsTeam* Guest);
	bool AddGuest(clsTeam* Guest);

public:
	clsNode(clsTeam* Host, clsZone* Course);
	~clsNode();

	clsTeam* GetHost();	//Get Host
//	clsAddress* GetAddress();	//Get address
	bool AddGuests(clsTeam* Guest1, clsTeam* Guest2);
	clsTeam* GetGuest(size_t Item);	//Get a guest
	bool ChangeGuest(clsTeam* Guest, clsTeam* Replacement); //Change one guest for another.
	size_t GetGuestCount();	//Number of guests.
//	bool AddCourse(clsZone*);	//Add the course.
	clsZone* GetCourse();	//Get Course
};
#endif // !NODE_H_INCLUDED