// auto_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


//************************************* auto_ptr *********************************************************/

// In the follwing program the destrcutor is not called when we create a object of normal pointer 
// The destructor gets called when auto_ptr is used, so that the memory deallocation is proper


//class Test
//{
//
//public:
//	int m_a;
//
//public:
//	Test(int a = 0) : m_a(a)
//	{
//	}
//	~Test()
//	{
//		cout << "Calling destructor" << endl;
//	}
//
//};
//
//void main()
//{
//
//	/*Test *normalpptr = new Test(10);
//	cout << normalpptr->m_a << endl;*/
//
//	auto_ptr<Test> p(new Test(5));
//	cout << p->m_a << endl;
//}





// output with normal pointer   "Division error"
// In the below program, as there was an exception in func() the pointer will not be reaching the destructor 

// output with auto_ptr			 "Division error, i am destructor "	
// As all local objects belonging to the try block are destroyed, p goes out of scope and it releases the 
//associated memory.

//class Test
//{
//private:
//	 int m_i;
//public:
//	 Test(int i) { m_i = i;}
//	 ~Test() 
//	 { 
//		 cout<<"i am destructor"<<endl; 
//	 }	 
//};
//
//void func()
//{
//	int a=10, b =0, c;
//	
//	if(b == 0)
//	{
//		throw "Division not possible" ;
//	}
//		
//	c = b/a;
//	return;
//}
//
//void main()
//{
//	try
//	{
//		Test *p = new Test(10);
//		std::auto_ptr<Test>p(new Test(10));
//		func();
//	}
//
//	catch(...)
//	{
//		cout<<"Division error"<<endl;
//	}
//
//	int i;
//	cin >> i;
//}
//


//******************************* Issues with auto_ptr ***********************************************/





//******************************* Issue 1  ***************************************************************/
/*

auto_ptr transfers its ownership when it is assigned to another auto_ptr and if the destination auto_ptr dies out,
the control will not be coming back to source auto_ptr and it again leads to crash

In the below example if func(p) is called in the main then output is 20 and -5657378 (expected 20 and 20)
becuase the once auto_ptr is assigned to another auto_ptr the original one
will loose the control and hence prints garbage value

If func(p) is not called then output printed by  cout<<p->j<<endl;  is 20

*/



class Test
{
private:
	int m_i; 

public:
	int j;
	Test(int i) { m_i = i; j = 20; }
	~Test()
	{
		cout << "destructor";
	}
};

void func(std::auto_ptr<Test> p1)
{
	cout<<p1->j<<endl;	 //p1 will die here
}

void main()
{
	std::auto_ptr<Test>p (new Test(10));
	//func(p); 

	std::auto_ptr<Test>p2 = p;

	cout<<p->j<<endl;	//program asserts or prints grabage 



	int i;
	cin >> i;
}




//*********************************** Issue 2  ***************************************************************
/*
auto_ptr cant be used for deleting array of objects as the auto_ptr by default calls delete and
not delete [], hence auto_ptr cant be used for array type of objects

The same problem exists with shared_ptrs also but using shared_ptr we have a provision for telling the compiler to use delete[] instead of delete
like in the follwing last line of program

*/

//
//class Test
//{
//public:
//
//	Test() {}
//	~Test()
//	{	
//		cout<<"I am Detsructor"<<endl;	
//	}
//};
//
//void main()
//{
//	//std::auto_ptr<Test> p(new Test); // program runs propoerly
//	std::auto_ptr<Test> p1(new Test[3]); //program crashes
//
//	/*std::auto_ptr<Test> sptr1(new Test[5],
//		[](Test* p) { delete[] p; }); //syntax error */
//
//	//std::shared_ptr<Test> sptr1(new Test[5],
//	//	[](Test* p) { delete[] p; }); //syntax error 
//
//}


//****************************************** Issue 3  ***************************************************************//

// The auto_ptr cant be used with STL like vector, list, map, etc.

