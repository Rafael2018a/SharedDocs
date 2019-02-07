// learnTemplates.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <type_traits>
#include <algorithm>

class C1 {};
class C2 {};

template<typename T>
bool IsEqual(T lhs, T rhs, C1)
{
	return true;
}

template<typename T>
bool IsEqual(T lhs, T rhs)
{
	//typedef std::conditional< true, C1, std::true_type>::type xType;
	//using xType = std::conditional<  true, C1, std::true_type>::type;
	using xType = std::conditional< std::is_floating_point<T>::value, C1, std::true_type>::type;
	return IsEqual(rhs, lhs, xType());
		
	return true;
}



class Widget 
{
public:
	void * pImpl;
};
// swap<> specialization
namespace std
{
	template<>
	void swap<Widget>(Widget& a, Widget& b)
	{
			std::swap(a.pImpl, b.pImpl); // to swap Widgets, swap their
	} // pImpl pointers; this won’t	compile
}

int main()
{
	bool b = IsEqual(1.0, 0.1);

	int x = 0, y = 1;


	std::swap(x, y);
    return 0;
}

