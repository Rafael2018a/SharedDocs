// UniformInit.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Resource.h"
using namespace std;

class ResourceWithCtor
{
public:
	ResourceWithCtor(string s)	
	{	
		cout << "ctor" << '\n';
	};
	string name;
	int age;
};

class ResourceWithCtor2args
{
public:
	ResourceWithCtor2args(string s, int n)	
	{	
		cout << "ctor" << '\n';
	};
	string name;
	int age;
};

class ResourceWithoutCtor
{
public:
	string name;
	int age;
};

//Resource::Resource(): 

int _tmain(int argc, _TCHAR* argv[])
{
	// direct
	{
		ResourceWithCtor r("");
		ResourceWithCtor r1{ "" };
		ResourceWithCtor;
		
		ResourceWithoutCtor rwc;
		ResourceWithoutCtor rwc1{};
		
		ResourceWithCtor2args rwc2{ "", 1 };
		ResourceWithCtor2args { "", 1 }; // init without variable....

	}
	// by copy
	{
		ResourceWithoutCtor rwc1 = {};
		ResourceWithoutCtor rwc3 = { "", 1}; // direct init of memebers (can't be done if ctor exists)
		//ResourceWithoutCtor rwc2 = (); wont compile

		ResourceWithCtor r = ("");
		ResourceWithCtor r1 = "";
		ResourceWithCtor r2 = { "" };

		ResourceWithCtor2args rr = { "", 1 };
		//ResourceWithCtor2args rr = ( "", 1 ); won't compile
	}

	// init array
	{
		int v[] = { 1, 2, 3 };
		int * vp = new int[]{1, 2, 3};
	}

	return 0;
}

