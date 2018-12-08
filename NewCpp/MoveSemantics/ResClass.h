#pragma once
#include <string>
#include <iostream>

class ResClass// :	public ResParent
{
public:
	std::string _name;
	ResClass(std::string name);
	ResClass(const ResClass & rc);

	ResClass& operator=(const ResClass& other)
	{
		if (&other != this)
		{

			this->_name = other._name;
			std::cout << "ResClass assign-copy-open. name: " << _name << " address: " << this << "\n";
		}
		return *this;
	}

	virtual ~ResClass() 
	{
		std::cout << "ResClass d-tor. name: " << _name << " address: " << this << "\n";
	};

	ResClass(ResClass&& r) :_name(std::move(r._name))
	{
		std::cout << "ResClass move-ctor. name: " << _name << " address: " << this << "\n";
	}

	ResClass& operator=(ResClass&& r)
	{
		if (this != &r)
		{
			_name = std::move(r._name);
			r._name.clear();
			//	cout << "copy assigning " << name << endl;
		}
		return *this;
	}

};

