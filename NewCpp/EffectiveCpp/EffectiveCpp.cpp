// EffectiveCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

//================  item 5  ===================================

template<typename T>
class NamedObject {
public:
	// this ctor no longer takes a const name, because nameValue
	// is now a reference-to-non-const string. The char* constructor
	// is gone, because we must have a string to refer to.
	NamedObject(std::string& name, const T& value): nameValue(name), objectValue(value)
	{
	}
	// as above, assume no
	// operator= is declared
private:
	std::string& nameValue; // this is now a reference
	const T objectValue; // this is now const
};

//=============== item 5 end ================================

int main()
{
	std::string one("one");
	std::string two("two");
	int x = 10, y = 20;

	NamedObject<int> p(one, x);
	NamedObject<int> s(two, y);

	p = s;
    return 0;
}

