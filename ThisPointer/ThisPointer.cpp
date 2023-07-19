// ThisPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base
{
public:
	Base() 
	{ 
		m_nvalue = 10;
		this->add();
	}

	~Base() { cout<<"Destructor is called"<<endl; }
	void func() {  delete this; }
	void add() { cout<<"hi"<<endl;}
	int m_nvalue;
};


void main(int argc, char* argv[])
{
	Base *p = new Base;
	p->func();
	p->add();
	cout<<p->m_nvalue<<endl;

	delete p;

//	Base obj;
//	obj.func();
}
