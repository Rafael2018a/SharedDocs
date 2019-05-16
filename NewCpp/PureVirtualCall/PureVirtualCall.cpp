// PureVirtualCall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class NoNPolymorphicClass {};

class ParentClass
{
public:
	ParentClass();
	virtual string GetInstanceName() = 0;
	virtual void virt1(){ return; };
};

class ChildClass : ParentClass
{
public:
	ChildClass()
	{
		puts("Child class");
		return;
	}
	string GetInstanceName() override;
	void virt1() override { return; };
	int childOnlyField;
};

void EmitObjectName(ParentClass * p)
{

	cout << p->GetInstanceName() << endl;
}

ParentClass::ParentClass()
{ 
	cout << typeid(this).name() << "\n";
	cout << typeid(*this).name() << "\n";

	EmitObjectName(this); 
};

string ChildClass::GetInstanceName()
{
	return string("");
}

class P
{
public:
	P() { std::cout << "P" << endl; }
};

class C : P
{
public: 
	C() { std::cout << "C" << endl; }
};


int _tmain(int argc, _TCHAR* argv[])
{
	//set_terminate([]() 
	//{ 
	//	std::cout << "set_terminate Unhandled exception\n"; 
	//	std::abort();
	//});
	//set_unexpected([]() 
	//{ 
	//	std::cout << "set_unexpected Unhandled exception\n";  
	//});

	//C c1;

	NoNPolymorphicClass& npc = NoNPolymorphicClass();
	string s = typeid(npc).name();


	ChildClass c123; // this will cause 'pure virtual called'


	return 0;
}

