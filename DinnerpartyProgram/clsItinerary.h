#ifndef ITINERARY_H_INCLUDED
#define ITINERARY_H_INCLUDED

class clsNode;
class clsZone;

#include <map>
#include <iostream>

class clsItinerary
{
private:
	size_t NoOfCourses; //Number of courses to allow.
	std::map<clsZone*, clsNode*> MyCourses; //Courses.
	bool CheckCourse(clsZone* Course);	//False if a given course is already present.

public:
	clsItinerary(size_t Courses = 3);
	~clsItinerary();
	
	bool AddCourse(clsZone* Course, clsNode* Node);	//Add a node for a given course.
	clsNode* GetCourse(clsZone* Course);	//Get the node for a given course.
	bool ChangeCourse(clsZone* Course, clsNode* Node);	//Change the node for a given course.
	bool RemoveCourse(clsZone* Course);	//Remove the node for a given course.
	
};
#endif // !ITINERARY_H_INCLUDED