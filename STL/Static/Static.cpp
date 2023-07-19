// Static.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"


/*
1.	static key word makes the variable value a fixed one through out the program
2.	used when doesn't want the value of a variable to be changed 
3.	Static variables are not associated with any object and hence,
4.	They can be directly called using the "class name followed by ":" operator"
5.  The value to the static variables is assigned even before the constructor is called.

*/

/*

class Base
{

public:
	Base(){}	
	static int a; 
};


int Base::a = 20;  // initializing static variable

void main()
{
//	cout<<Base::a<<endl; //way to access static variables
	cout<<Base::a<<endl;
//	Base obj;
//	cout<<obj.a <<endl;
}

*/


/***************************************** Retaining the value *************************************************************/

// In the following example variable 'a' is assigned to 10 and then incremented so out put is 11 (when first time called from main)
// the output should be same (11) even for the second call because 'a' is assigned to 10, but 
// as 'a' is a static variable, it retains its value and then incremented accordingly.


/*
class Base
{
public:
	Base(){}	
	static int a; 
	void add();
};

void Base::add()
{
	static int a = 10;
	a++;
	cout<<a<<endl;
}

void main()
{
	Base obj;
	obj.add(); // output is 11
	obj.add(); // output is 12
}
*/



//example 2 


/*

class Base
{
  public:
  static int s_nValue;
};
  
int Base::s_nValue = 1;
	
void main()
{
	Base cFirst;
	cFirst.s_nValue = 2;

	Base cSecond;
	cSecond.s_nValue = 10;

	Base cThird;
	cout<<cThird.s_nValue<<endl;

	cout<<Base::s_nValue<<endl;
}
*/




/***************************************  static member functions *****************************************************/

//  A static member functions of the class can only access static member variables of the class, it is beacuse there is 
// no this pointer 
/*

class Base
{
public:
	Base(){};
	static add() { cout<<"hi"<<endl;}
};

void main()
{

}

Base::add();

*/

//************************************  An object of a class can be static *******************************************//

// static object of a class can call both static and non static members functions of the class.
// but a const object of the class can only call const memeber functions

/*
class Base
{
public:
	Base() {}
	void add() {cout<<"hi"<<endl;}
};


void main()
{
	static Base obj; //works fine 
	obj.add();
}
*/



//********************************* Global values behave same as static **************************************//

/*
int m_iglobal = 0;

class test
{
public:
	test(){}
	int func()
	{ 
		m_iglobal = m_iglobal+1 ;
		return m_iglobal;
	}

};


void main()
{
	test obj;
	obj.func();
	obj.func();
	cout<<obj.func()<<endl;

	test obj1;
	cout<<obj1.func()<<endl;
}
*/


