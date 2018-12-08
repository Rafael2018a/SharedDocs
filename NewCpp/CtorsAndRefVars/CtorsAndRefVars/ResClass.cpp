#include "stdafx.h"
#include "ResClass.h"

using namespace std;

//ResClass::ResClass()
//{
//}


ResClass::~ResClass()
{
	cout << "ResClass virtual dtor. name: " << _name << " address: " << this << "\n";
}

ResClass::ResClass(string name) : _name(name)//, ResParent(name)
{
	cout << "ResClass ctor. name: " << _name << " address: " << this << "\n";
}

ResClass::ResClass(const ResClass & rc) : _name(rc._name)//, ResParent(rc._name)
{
	cout << "ResClass copy-ctor. name: " << _name << " address: " << this << "\n";
}

ResClass::ResClass(ResClass && rc): _name(move(rc._name))
{
	cout << "ResClass move-ctor. name: " << _name << " address: " << this << "\n";
}

