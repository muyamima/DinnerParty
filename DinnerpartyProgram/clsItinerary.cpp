#include "clsItinerary.h"

clsItinerary::clsItinerary(size_t Courses){
	NoOfCourses = 3;
}
clsItinerary::~clsItinerary(){
}

bool clsItinerary::CheckCourse(clsZone* Course) {
	return !MyCourses.count(Course);
}

bool clsItinerary::AddCourse(clsZone* Course, clsNode* Node) {
	if (CheckCourse(Course)) {
		MyCourses.insert(std::pair<clsZone*, clsNode*>(Course, Node));
		std::cout << "Node added." << std::endl;
		return false;
	}
	std::cout << "Could not add the course, a node is already assigned." << std::endl;
	return true;
}
clsNode* clsItinerary::GetCourse(clsZone* Course) {
	if (!CheckCourse(Course)) {
		return MyCourses[Course];
	}
	std::cout << "No node yet assigned for that course." << std::endl;
	return NULL;
}
bool clsItinerary::ChangeCourse(clsZone* Course, clsNode* Node) {
	if (!RemoveCourse(Course)) {
		if (!AddCourse(Course, Node)) {
			std::cout << "Node succesfully changed." << std::endl;
			return false;
		}
	}
	std::cout << "Failed to change node." << std::endl;
	return true;
}
bool clsItinerary::RemoveCourse(clsZone* Course) {
	if (!CheckCourse(Course)) {
		MyCourses.erase(Course);
		std::cout << "Course was removed." << std::endl;
		return false;
	}
	std::cout << "No course assigned yet." << std::endl;
	return true;
}