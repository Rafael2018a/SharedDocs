#pragma once
#include <string>
#include <iostream>

class ResClass// :	public ResParent
{
public:
	std::string _name;
	ResClass();
	ResClass(std::string name);
	ResClass(const ResClass & rc);
	ResClass(ResClass && rc);
	ResClass& operator=(const ResClass& other);
	ResClass& operator=(ResClass&& other);
	std::string GetId() const;

	//ResClass();
	virtual ~ResClass();
};

