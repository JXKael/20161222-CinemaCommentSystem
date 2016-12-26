#include <iostream>
#include <string>
#include <cstddef>
#include "..\Data\ParameterString.h"
using namespace std;

#ifndef PAGE_H
#define PAGE_H

enum EPage
{
	welcome
};

class Page
{
public:
	Page() : title(""){}
	~Page(){ title.clear(); }
protected:
	string title;
public:
	virtual void SetTitle(string title) = 0;
	virtual void Show() = 0;
	virtual void WaitInput() = 0;
	virtual void Input(const int input) = 0;
};

#endif