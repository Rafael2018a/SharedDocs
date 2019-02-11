// learnTemplates.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <type_traits>
#include <algorithm>

using namespace std;

class C1 {};
//class C2 {};

template<typename T>
bool IsEqual(T lhs, T rhs, true_type)
{
	return true;
}
template<typename T>
bool IsEqual(T lhs, T rhs, false_type)
{
	return true;
}

template<typename T>
bool IsEqual(T lhs, T rhs)
{
	//typedef std::conditional< true, C1, std::true_type>::type xType;
	using xType = std::conditional< is_integral<T>::value, C1, std::true_type>::type;
	//using xType = std::conditional< std::is_floating_point<T>::value, C1, std::true_type>::type;
	//return IsEqual(rhs, lhs, xType());
		
	return IsEqual(lhs, rhs, conditional_t< is_floating_point<T>::value, true_type, false_type>{});
	return IsEqual(lhs, rhs, typename conditional< is_floating_point<T>::value, true_type, false_type>::type{});
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
	bool b = IsEqual(1, 0);

	int x = 0, y = 1;


	std::swap(x, y);
    return 0;
}

