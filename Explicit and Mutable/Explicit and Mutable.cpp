// Explicit and Mutable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>




//********************* without explicit key word *****************************//

/*
class Base
{
public:
	Base(int i){ cout<<i<<endl;}
};


void main(int argc, char* argv[])
{
//	Base obj = 3;       //ok
	Base obj(3);		//ok
	Base *p = new Base(3);	//ok
}
*/

//********************* using explicit key word *****************************//


class Base
{
public:
	explicit Base(int i){ cout<<i<<endl;}
};


void main(int argc, char* argv[])
{
	Base obj = 3;		//error
//	Base obj(3);		//ok
//	Base *p = new Base(3); //ok
	
}


//****************** without mutable keyword **********************************//

/*
class Base
{
private:
	int empid;
	int salary;


public:
	 void func() const ;
	 Base() {}

};

void Base::func() const
{
	empid++; //error as func is a constant , it will not allow any member variable to change its value

}

void main()
{

}
*/

//****************** using mutable keyword **********************************//
// mutable keyword allows a variable value to be modified inside a const function.

/*

class Base
{
private:

mutable	int empid;
	int salary;

public:
	 void func() const ;
	 Base() {}

};

void Base::func() const
{
	empid++; //works fine
}

void main()
{

}
*/