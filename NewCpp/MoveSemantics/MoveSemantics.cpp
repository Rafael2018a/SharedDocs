// MoveSemantics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ResClass.h"

using namespace std;

template <typename T>
void Ex()
{
	T v;
	T::value_type res1('a');
}

void f(  ResClass && x)
{
	cout << x._name;
	x._name = "";
//	x._name = "";
}

void f1( int&& x)
{
	cout << x;
	x = 0;
}

void f2()
{
	int && z = 1;
	z = 2;
}
int main()
{

	{
		vector<ResClass> v;
		v.reserve(10);

		// block a
		{
			ResClass rc("element 1");
			v.push_back(rc);
		}
		// block b
		{
			v.push_back(ResClass("element 2"));
		}
	}


	f(ResClass(""));
	f1(5);
	f2();
	return 0;
}

