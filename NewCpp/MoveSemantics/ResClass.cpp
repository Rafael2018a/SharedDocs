#include "stdafx.h"
#include "ResClass.h"

using namespace std;

//ResClass::ResClass()
//{
//}
//
//
//ResClass::~ResClass()
//{
//}

ResClass::ResClass(string name) : _name(name)
{
	cout << "ResClass ctor. name: " << _name << " address: " << this << "\n";
}

ResClass::ResClass(const ResClass & rc) : _name(rc._name)
{
	cout << "ResClass copy-ctor. name: " << _name << " address: " << this << "\n";
}


