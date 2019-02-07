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
	ResClass& operator=(const ResClass& other);
	ResClass& operator=(ResClass&& other);

	//ResClass();
	virtual ~ResClass();
};

