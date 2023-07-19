// CopyEllision.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//Copy elision(or Copy omission) is a compiler optimization technique that avoids unnecessary copying of objects. 
//Now a days, almost every compiler uses it

/*
The program below calls default constructor and not copy constructor 

Ideally  B ob = "copy me"; is broken down by compiler as B ob = B("copy me") and it should call copy constructor but modern compiler makes the call as

B ob("copy me"); thus calls default constructor


*/

using namespace std;

class B
{
public:
	B(const char* str = "\0") //default constructor 
	{
		cout << "Constructor called" << endl;
	}

	B(const B &b)  //copy constructor 
	{
		cout << "Copy constructor called" << endl;
	}
};

int main()
{
	B ob = "copy me";
	return 0;
}



// Return value optimization (RVO) is a compiler optimization that involves eliminating the temporary object 
//created to hold a function's return value

//class C 
//{
//public:
//	C() {}
//	C(const C&) { std::cout << "A copy was made.\n"; }
//};
//
//C f()
//{
//	return C();
//}
//
//int main() {
//	std::cout << "Hello World!\n";
//	C obj = f();
//	return 0;
//}

//
//
//
//// Depending on the compiler 
//
//// output can be  any of the follwing 
//
///*
//Hello World!
//A copy was made.
//A copy was made.
//
//Hello World!
//A copy was made.
//
//Hello World!
//*/