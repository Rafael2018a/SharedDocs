#include "stdafx.h"
#include <sstream>
#include "ResClass.h"

using namespace std;

ResClass::~ResClass()
{
	cout << "ResClass virtual dtor. " << GetId() << "\n";
		//_name << " address: " << this << "\n";
}

ResClass::ResClass()
{
	_name = "noname";
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

ResClass & ResClass::operator=(const ResClass& other)
{
	if (&other != this)
	{
		this->_name = other._name;
		std::cout << "ResClass assign-copy-open. name: " << _name << " address: " << this << "\n";
	}
	return *this;
}

ResClass& ResClass::operator=(ResClass&& other)
{
	if (&other != this)
	{

		this->_name = move(other._name);
		std::cout << "ResClass assign-move. name: " << _name << " address: " << this << "\n";
	}
	return *this;
}

string ResClass::GetId() const
{
	stringstream ss;
	ss << "Instance name: " << _name << ", address: " << this << "\n";
	return ss.str();


}

