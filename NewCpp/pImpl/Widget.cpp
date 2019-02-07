#include "stdafx.h"
#include <iostream>
#include "Widget.h"
#include "Impl.h"


struct Widget::Impl
{
	std::string name;
	int x;
public:
	Impl() : name("PIMPLE")
	{};
	~Impl() 
	{};
};

void Widget::Publish() 
{
	std::cout << "Hi  " << this->pImpl->name << "\n";
}

Widget::Widget(): pImpl(new Impl)
{
}


//Widget::~Widget(){	delete pImpl;}

