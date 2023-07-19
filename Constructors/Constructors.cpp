
#include "StdAfx.h"
#include <vector>
#include <iostream>
using namespace std;

// 1. Constructors are the special member functions of a class with the same name as class
// 2. Constructors gets called every time  an object of that class is created.
// 3. The same rules applies to constructors also in case of access specifiers as applied to other member functions of class.

// 4, There can be any number of constructors for a class (they should be overloaded)
// 5. The compiler generates a default constructor automatically only if a class defines no constructors.
// 6. Constructors can be defined inline, volatile, to the class declaration.

// 7. Constructors cannot be declared with the keyword virtual, static,  const
// 8. References and pointers cannot be used on constructors  because their addresses cannot be taken.


//9. You can prevent the compiler from generating an implicit default constructor by defining it as deleted :
//class Box
//{
//	Box() = delete;
//};

/**************************************  basics ******************************************************************/

/*
#include "stdafx.h"
#include "iostream.h"


class Base 
{
	
public:
	int i ;

	Base(){};


//  inline	 Base(){};           // ok

//	volatile Base();			// ok



	//Base() const ;			// error  :  'const' 'this' pointer is illegal for constructors/destructors
								// Reason :	 The reason for a const function is to initialize a const object.
								//			 but When we create a const object, Normal Constructor is enough to initialize it hence const Constructor is not needed.
								//			 Moreover a const function will not allow any value(class member's) to be changed inside it.
								//			 So constructor cant be used for initilization (which is the main purpose of constructor)
								//			 if it is made const

	//static	Base()  ;		// error :  'inline' is the only legal storage class for constructors
								   Reason:	'Constructor can't be static because static members of the class are not associated with 
											 object of the class where as constructor itself is a function which gets called when obj is created.

	//virtual Base();			// error :	'inline' is the only legal storage class for constructors
											'Virtual functions are those functions that we wanted to use in the derived class that are prsent
											 in the derived class but the constructor is unique to each class (as it has the same name as class name)
	
};


void main()
{
	Base obj;
	cout<<obj.i<<endl;;
}

*/

/**********************  Difference between Initialization and assigning *****************************/

//Constructors play a very important role in initializing the values to class member variables.
// in both the cases in the following example the output is same. 
// The initialization and assignment doesn't make difference in case of normal member variables and
// would matter when we do for a const or ref type of variables

/*

#include "stdafx.h"
#include "iostream.h"


class Base 
{
public:
	int i;
//	Base() { i =9;}	//Assigning       // ok 
	Base():i(9){}	//Initializing	  // ok	

};

void main()
{
	Base obj;
	cout<<obj.i<<endl;;
} 
*/



/*********************************** Initializing a const or ref type of member variables ***********************************/

/*


#include "stdafx.h"
#include "iostream.h"


class Base 
{
	
public:
	const int i;
	int &b;
	int d;

//	Base() { i = 9, b = i;}	 // assigning cant be done here because the compiler need these two types of variables to be initialized 
							// before it goes to the definition of the constructor.
							// Compiler throws an error


	Base():i(9),b(d){}     // Initialization  should be done , This works fine 

	
};

void main()
{
	Base obj;
	cout<<obj.i<<endl;;
} 


*/




/***************************************  Behaviour of Constructor in case of Derived classes  **************************************/


// The base class member variables can be initialized in the derived class in the following way i.e 
//  by using name of the base class for that particular variable

//#include <iostream>
////using namespace std;
//
//class Base
//{
//public:
//    int m_nValue;
//	
//    Base(int nValue=8): m_nValue(nValue)
//	{ 
//		cout<<"Base Constructor";
//	}
//};
//
//
//class Derived: public Base
//{
//public:
//    double m_dValue;
//	
//    Derived(double dValue=0.0, int nValue = 9): m_dValue(dValue), Base(nValue)
//	{ 
//		cout<<"Derived Constructor"<<endl;
//	} 
//};
//
//
//void main()
//{
//	Derived obj;
//	cout<<obj.m_nValue<<endl;
//}
//


//*****************  Creation of object using new (on heap) and not allowing normal object (on stack) ***************//

//can be achieved using private destructor and to delete pointer object a function is exposed in which obj is deleted

//
//#include "stdafx.h"
//#include <iostream>
//
//class Test
//{
//private:
//    ~Test() { /*cout<<"iam in destructor"<<endl;*/}
//friend void destructTest(Test* ptr );
//
//};
// 
//// Only this function can destruct objects of Test
//void destructTest(Test* ptr)
//{
//    delete ptr;
//}
// 
//int main()
//{
//    // create an object
//    Test *ptr = new Test;
//    // destruct the object
//    destructTest (ptr);
//    return 0;
//
//	Test obj; //Compile Error, as destructor cant be accessed since destructor is private
//}

 

//**************  Creation of object normal object (on stack) and not allowing using new (on heap) ***************//
//simply over load new operator which will not allow us to use 'new ' operator 


//#include "stdafx.h"
//#include <iostream>
//
//class Test
//{
//private:
//
//	void* operator new(size_t)
//	{
//		void *p;
//		return p;
//	}
//};
//
//void main()
//{
//   // Test *ptr = new Test; //not possible
//	Test obj; //possible
//}



/****************************  calling constructor from constructor will cause runtime stack overflow ***********************/

//#include "stdafx.h"
//#include <iostream>
//
//class Test
//{
//public:
//	Test()
//	{
//		Test();
//	}
//
//};
//
//
//void main()
//{
//	Test obj;
//}



/*************************************************  Delegating Constructors    ***************************************************/

#include "stdafx.h"
#include <iostream>



class test
{
private:
	int m_nDivisor;
	int m_x;
	int m_y;
	int age;

public:
	test(int divisor, int x, int y, int z) :test(divisor) //delegating work to other constructor so that it can concentrate on its own work
		//and also it need not repeat the work of delegating constructor 
	{
		if (x + y < z) return; //its job is to check if the sum of x and y is greater than z
	}

	test(int divisor)
	{
		if (divisor <= 0) return; //its job is to check if divisor is less that or equal to 0
	}
};


void main()
{
	test obj(3, 4, 5, 6);
	test obj1{ 3, 4, 5, 6 };
}

//
//class Test
//{
//public:
//	int m_x, m_y, m_z;
//
//	Test()
//	{
//		Init();
//	}
//
//	Test(int x, int y, int z)
//	{
//		Init();
//		m_z = z;
//	}
//
//	void Init()
//	{
//		m_x = 0;
//		m_y = 0;
//	}
//
//
//};
//
//void main()
//{
//
//
//}





//class Test
//{
//public:
//	int m_x, m_y, m_z;
//
//	Test()
//	{
//		m_x = 0;
//		m_y = 0;
//	}
//
//	Test(int x, int y, int z) : Test()
//	{
//		m_z = z;
//	}
//
//};
//
//void main()
//{
//}



//class Test
//{
//public:
//	int m_x, m_y, m_z;
//
//	Test()
//	{
//		m_x = 0;
//		m_y = 0;
//	}
//
//	Test(int x, int y, int z) : Test()
//	{
//		m_x = x;
//		m_y = y;
//		m_z = z;
//	}
//
//};
//
//void main()
//{
//	vector<Test> vobj;
//
//	Test t1(10, 20, 30);
//	vobj.push_back(t1);
//
//	vobj.push_back(Test(11, 12, 13));
//	vobj.emplace_back(1, 2, 3);
//}
//



