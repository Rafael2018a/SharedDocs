#pragma once

class Widget
{
private:
	struct Impl;
	Impl * pImpl;
public:
	void Publish();
	Widget();
	//~Widget();
};

