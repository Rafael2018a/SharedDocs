// PerfectFwd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <type_traits>

template <typename T>
void Foo(T&& t)
{
	bool isRv = std::is_rvalue_reference<T>::value;
	bool isLv = std::is_lvalue_reference<T>::value;

	if (isRv)
		std::cout << "rval ref\n";
	else
		if (isLv)
			std::cout << "lval ref\n";
		else
			std::cout << "not a ref\n";

	bool isRv1 = std::is_rvalue_reference<decltype(t)>::value;
	bool isLv1 = std::is_lvalue_reference<decltype(t)>::value;

	decltype(t) x;
	auto a = std::forward<T>(t);
	
	int s=0;

	a = s;
	//	decltype(typename std::forward<T>)::value t;

}


int main()
{
	int x = 10;
	Foo(x);
	//Foo(10);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
