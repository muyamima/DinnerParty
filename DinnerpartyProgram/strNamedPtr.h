#ifndef NAMEDPOINTER_H_INCLUDED
#define NAMEDPOINTER_H_INCLUDED

class clsZone;

#include <string>

struct NamedPtr {
	std::string Name;
	clsZone* Pointer;
	friend bool operator< (const NamedPtr& One, const NamedPtr& Two) {		return One.Name<Two.Name;	}
};
#endif // !NAMEDPOINTER_H_INCLUDED