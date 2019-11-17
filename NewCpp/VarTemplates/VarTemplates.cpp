// VarTemplates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template <typename T>
auto ShowArg(T t) -> int  // must return non-void. you can't expand function tempalte with void.
{
	std::cout << t << "\n";
	return 0;
}

template <typename ... Args> 
void pass(Args ...) {}

template <typename ... Args> 
void expand(Args&& ... args)
{
	pass(ShowArg(args)...);
}

// ======================================
//template <typename FirstArg>
//void RecursiveShowArgs(FirstArg fa) {};
void RecursiveShowArgs() {};

template <typename FirstArg, typename ... Args>
void RecursiveShowArgs(FirstArg first, Args ... args)
{
	std::cout << first << "\n";
	RecursiveShowArgs(args...);
}

int main()
{

	expand("hi", "hello");

	std::cout << "==========================\n";

	RecursiveShowArgs("hi", "hello");

    return 0;
}

