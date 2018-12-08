// PureVirtualCall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

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
	EmitObjectName(this); 
};

string ChildClass::GetInstanceName()
{
	return string("");
}
int _tmain(int argc, _TCHAR* argv[])
{
	ChildClass c123; // this will cause 'pure virtual called'

	return 0;
}

