#pragma once
#include <string>
#include <iostream>

class ResClass// :	public ResParent
{
public:
	std::string _name;
	ResClass(std::string name);
	ResClass(const ResClass & rc);
	ResClass(ResClass && rc);

	ResClass& operator=(const ResClass& other)
	{
		if (&other != this)
		{

			this->_name = other._name;
			std::cout << "ResClass assign-copy-open. name: " << _name << " address: " << this << "\n";
		}
		return *this;
	}

	ResClass& operator=( ResClass&& other)
	{
		if (&other != this)
		{

			this->_name = move(other._name);
			std::cout << "ResClass assign-copy-open. name: " << _name << " address: " << this << "\n";
		}
		return *this;
	}

	//ResClass();
	virtual ~ResClass();
};

