// Friend.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>



//***************************** Friend Function ************************************//

	//1. Friend function is the only function which can access private members of a class.
	//2. It can be declared public or private to that class.
	//3. This function cant be accessed using objects of the class as this is not the member function of the class.
	//4. It is just a normal function
	//5. It is also useful when we want to access private members of two different classes in the same function
	//6. Friend function dosent recognize the APIs of the same class i.e. we cant directly access the functions without the use of object of the class.

//class Base
//{
//private:
//	int m_nval;
//public:
//	Base() { m_nval = 30;}
//	friend void add();
//};
//
//
//void main(int argc, char* argv[])
//{
//	add();
//}
//
//
//void add()
//{
//	Base obj;
//	obj.m_nval
//	//cout<<obj.m_nval<<endl;
//}



/************************** resetting a class member variable ************************************/

//class A
//{
//private:
//	int m_nValue;
//public:
//	void Setvalue(int i) { m_nValue = i; }
//	friend void reset(A& obj);
//};
//
//void reset(A& obj)
//{
//	obj.m_nValue = 0;
//}
//
//void main()
//{
//	A obj;
//	obj.Setvalue(10);
//	reset(obj);
//}


/**********************  overloading + operator using friend function to add two objets of same class *****************/
class Cents
{
private:
	int m_nCents;
public:
	Cents(int value) { m_nCents = value; }
	int getcents() { return m_nCents; }
	friend Cents operator+(Cents&obj1, Cents&obj2);
};


Cents operator+(Cents&obj1, Cents&obj2)
{
	return Cents(obj1.m_nCents + obj2.m_nCents);
}


void main()
{
	Cents obj1{ 1 };
	Cents obj2{ 2 };
	Cents sum  = obj1 + obj2;
	int value = sum.getcents();
	int i = 10;
}

//****************************************  Friend Class  **********************************************//
//class Derived;
//
//class Base
//{
//private:
//	int m_nval1;
//public:
//	Base() {}
//
//	friend class Derived;
//};
//
//class Derived
//{
//private:
//	int m_nval2;
//public:
//	Derived() {}
//};
//
//void main()
//{
//	Derived obj;
//	obj.m_nval1;
//}



//
//class Test
//{
//private:
//	int i;
//public:
//	void func() {}
//	friend void sum();
//};
//
//void sum()
//{
//	Test obj;
//	obj.i = 6;
//
//}
//void main()
//{
//
//}