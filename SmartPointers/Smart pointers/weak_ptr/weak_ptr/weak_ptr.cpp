// weak_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test
{
public:

	Test() {}
	~Test()
	{	
		cout<<"I am Detsructor"<<endl;	//this gets called 5 times
	}
};

void main( )
{
	shared_ptr<Test> sptr( new Test ); //shared pointer: strong ref count : 1 
	weak_ptr<Test> wptr(sptr); // strong ref count : 1 & Weak ref count : 1
	weak_ptr<Test> wptr1 = wptr; // Strng ref count : 1 & Weak ref count : 2
}



/*********************************    Cyclic reference issue is resolved using the weak_ptr      ***************************************/
//
//class B;
//class A
//{
//public:
//	A() : m_a(5)  { };
//	~A()
//	{
//		cout << " A is destroyed" << endl;
//	}
//	void PrintSpB();
//	weak_ptr<B> m_sptrB;
//	int m_a;
//};
//class B
//{
//public:
//	B() : m_b(10) { };
//	~B()
//	{
//		cout << " B is destroyed" << endl;
//	}
//	weak_ptr<A> m_sptrA;
//	int m_b;
//};
//
//void A::PrintSpB()
//{
//	if (!m_sptrB.expired())
//	{
//		cout << m_sptrB.lock()->m_b << endl;
//	}
//}
//
//void main()
//{
//	shared_ptr<B> sptrB(new B); //Strong ref for B: 1
//	shared_ptr<A> sptrA(new A); //Strong ref for A: 1
//	sptrB->m_sptrA = sptrA; //Strong ref for A: 1  & Weak ref for A: 1
//	sptrA->m_sptrB = sptrB; //Strong ref for B: 1  & Weak ref for B: 1
//}

//After main ends  : There will not be any problem even when the weak reference count is more than '0', only strong ref count matters 

// strong ref for A is 0 & Weak ref for A: 1
// strong ref for B is 0 & Weak ref for B: 1

