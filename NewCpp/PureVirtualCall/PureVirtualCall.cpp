// PureVirtualCall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Parent
{
public:
	Parent();
	virtual string GetInstanceName() = 0;
};

class Child : Parent
{
public:
	string GetInstanceName() override;
};

void EmitObjectName(Parent * p)
{
	cout << p->GetInstanceName() << endl;
}

Parent::Parent()
{ EmitObjectName(this); };

string Child::GetInstanceName()
{
	return string("");
}
int _tmain(int argc, _TCHAR* argv[])
{
	Child c; // this will cause 'pure virtual called'

	return 0;
}

