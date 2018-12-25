// CtorsAndRefVars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "ResClass.h"

using namespace std;

class ResParent
{
private:

public:
	string _name;
	ResParent(string name);
	ResParent(const ResParent & rc);

	ResParent& operator=(const ResParent& other)
	{
		if (&other == this)
			return *this;

		this->_name = other._name;
		cout << "ResParent assign-copy-open. name: " << _name << " address: " << this << "\n";
		return *this;
	}
};


ResClass _resclass(string("GlobalResClass"));

ResClass & getClassByRef()
{
	return _resclass;
}

ResClass getClassByVal()
{
	return _resclass;
}

ResClass getLocalByVal()
{
	ResClass rc("local");
	return rc;
}

ResClass && getClassByMove()
{
	return ResClass("ByMove");
}

int main()
{
	//ResClass & rc1 = getClassByRef();
	//ResClass * pr = &rc1;
	//const ResClass & rc2 = getClassByVal();
	//ResClass rc3 = getClassByRef();
	//ResClass rc4 = getClassByVal();

	ResClass  & rc5 = getClassByMove();
	cout << rc5._name;
	//ResClass rc = "ano1";
	//ResClass rc2(rc);
	//rc2 = rc;

	//ResClass x("x");;
	//ResClass rc5 = x;
	getchar();
    return 0;
}

ResParent::ResParent(string name): _name(name)
{
	cout << "ResParent ctor. name: " << _name << " address: " << this << "\n";
}

ResParent::ResParent(const ResParent & rc): _name(rc._name)
{
	cout << "ResParent copy-ctor. name: " << _name << " address: " << this << "\n";
}
