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

void f(ResClass && x)
{
	cout << x._name;
	x._name = "";
	//	x._name = "";
}

void f1(int&& x)
{
	cout << x;
	x = 0;
}

void f2()
{
	int && z = 1;
	z = 2;
}

ResClass CreateResource()
{
	ResClass rc("rc2");
	return rc;
}
int main()
{

	ResClass rc = CreateResource();
	std::cout << rc.GetName() << "\n";


	//vector<ResClass> v;
	//v.reserve(10);
	//v.push_back(ResClass("element1"));

	//ResClass arr[1];
	////ResClass array[1];
	////array[0] = ResClass("I1");

	//for (auto a : v)
	//{
	//	std::cout << a.GetId() << "\n";
	//}

	//for (auto a = begin(v); a != end(v); a++)
	//{
	//	std::cout << a->GetId() << "\n";
	//}

	//for (auto a : arr) {}

	//for (auto a = begin(arr); a != end(arr); a++) {}

}

