// SmartPointers.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <memory>
#include <vector>


#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

using namespace std;

/*

Problems with Normal pointers 

  1. If a normal pointer is used to allocate the space on the heap (using new) it should be deleted manually
	  otherwise it causes memory leaks
  2. Even if we delete the pointer, sometimes it may happen that the code between the allocating the pointer and 
		delete might give exception and code may not reach the delete statement and the pointer doesn't gets deleted

Smart pointers

  1. It is pointer that can manage dynamically allocated memory 
  2. It owns the memory when a pointer is dynamically allocated and the memory is released automatically 
		when it goes out of scope

  Types of smart pointers:

  1. auto_ptr
  2. shared_ptr
  3. weak_ptr
  4. unique_ptr


*/

//****************************** problem with Normal pointers **************************************************/

// In the following program the " delete p " statement is never deleted as it crashes in divide function.
//	so with normal pointers even though we delete the  pointer it may not reach it .

//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



//void divide()
//{
//	int i =10;
//	int j = 0;
//	int res = i/j;
//}
//
//void Test(int *p1)
//{
//	delete p1;
//}
//
//
//
//void main()
//{
//	 int *p = new int[10000000];
//	 //p[0] = 100;
//	 ////divide();
//	 //Test(p);
//	 //int i = p[0];
//
//
//	 //return;
//	 //delete p;
//}



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
//
//};
//
//void func(auto_ptr<Test> temp)
//{
//
//}
//
//void main()
//{
//	Test *normalptr = new Test(10);
//	cout << normalptr->m_a << endl;
//
//	auto_ptr<Test> p(new Test(14));
//	func(p);
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
	because the once auto_ptr is assigned to another auto_ptr the original one 
	will loose the control and hence prints garbage value

    If func(p) is not called then output printed by  cout<<p->j<<endl;  is 20 

*/


//
//class Test
//{
//private:
//	int m_i; 
//
//public:
//	int j;
//	Test(int i) { m_i = i; j = 20; }
//	~Test() { }
//};
//
//void func(std::auto_ptr<Test> p1)
//{
//	cout<<p1->j<<endl;	
//}
//
//void main()
//{
//	std::auto_ptr<Test>p (new Test(10));
//	func(p);
//	cout<<p->j<<endl;	
//}




//*********************************** Issue 2  ***************************************************************
/*
auto_ptr cant be used for deleting array of objects as the auto_ptr by default calls delete and 
not delete [], hence auto_ptr cant be used for array type of objects

The same problem exists with shared_ptrs also but using shared_ptr we have a provision for telling the compiler to use delete[] instead of delete 
like in the following last line of program

*/


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
//	//std::auto_ptr<Test> p(new Test); // program runs properly
//	std::auto_ptr<Test> p1(new Test[3]); //program crashes
//
//	std::auto_ptr<Test> sptr1(new Test[5],
//		[](Test* p) { delete[] p; }); //syntax error 
//}


//****************************************** Issue 3  ***************************************************************//

// The auto_ptr cant be used with STL like vector, list, map, etc.





//****************************************** shared_ptr ************************************************************//

/*
1. Multiple shared pointers can refer to a single object and when the last shared pointer goes out of scope,
memory is released automatically.
2. make_shared is a macro useful in using the shared_ptr effectively
3. when ever shared_ptr is used, it internally maintains a reference count. if it assigned to another shared_ptr
the count becomes 2 and so on. this count is known as strong reference
4. we can find out the number of shared_ptrs referring to the resource by just getting the reference count by calling use_count( ).
5. shared_ptr releases the associated resource by calling delete by default.
6. If an array of objects are created, then user can call his own destructor to delete them.
	shared_ptr<int> shptr(new int, Del()) // the second argumnet can be user defined

7. The shared_ptr is thread safe. It means
	1. The control block which maintains the count of number of shared pointers is thread safe i.e. any number of threads can access
		same shared_ptr and its internally atomic and taken care
	2. The resource that shared_ptr is holding is not thread safe

get( ) : To get the resource associated with the shared_ptr.
reset( ) : To yield the ownership of the associated memory block. If this is the last shared_ptr owning the resource, 
				then the resource is released automatically.
unique: To know whether the resource is managed by only this shared_ptr instance.
operator bool: To check whether the shared_ptr owns a memory block or not. Can be used with an if condition.

Prefer using Make_shared for creating shared_ptr

1st way 
std::shared_ptr<int> sp1(new int(10));

2nd way
std::make_shared<int> sp2 = std::make_shared<int>(10); //Here only one allocation is done


1. The heap allocations are costly and time taking (2 allocations are happening in the 1st way)
		1. new int(10) - creating a memory on heap 
		2. control block i.e. the shared_ptr sp1 is assigned with newly created heap memory
2. There can be a failure in creating shared_ptr sp1 after the memory is allocated for int and hence that memory will be leaked 
*/



/**********************************  overcoming the problems of auto_ptr using shared_ptr ******************************************/

//1. Transfer of ownership : The following program crashes if we use autor_ptr in place of shared_ptr as auto_ptr transfers total ownership 
//  Shared_ptr when passed to a function, it maintains the count and deletes the objects based on the count

//class Test
//{
//private:
//	int m_i; 
//
//public:
//	int j;
//	Test(int i) { m_i = i; j = 20; }
//	~Test() { }
//};
//
//void func(std::shared_ptr<Test> p1) //strong count: 2    // as p and p1 are poining to same location
//{
//	cout<<p1->j<<endl;	
//} //strong count :1   //as p1 is dead
//
//void main()
//{
//	std::shared_ptr<Test>p; (new Test(10)); //strong count: 1
//	func(p);
//	cout<<p->j<<endl;	 
//}

//2. Auto_ptr Cant be used to created array of objects :  When we create array of objects using smart pointers,
//the default implementation calls delete instead of 
//  delete[], the shared_ptr provides a privision to tell the compiler to use delete[] and there is no such option using autor_ptr
//
//class Test
//{
//public:
//
//	Test() {}
//	~Test()
//	{	
//		cout<<"I am Detsructor"<<endl;	//this gets called 5 times
//	}
//};
//
//void main()
//{
//	//std::auto_ptr<Test> sptr1(new Test[5],
//	//	[](Test* p) { delete[] p; }); //syntax error 
//
//	std::shared_ptr<Test> sptr1(new Test[5],
//		[](Test* p) { delete[] p; }); //works fine 
//}

//3. auto_ptr cant be used with vectors, maps, lists e.t.c



//4. constructors should match destructors : From c++17 onwards, the default delete[] is called for array objects
//std::shared_ptr <int > ap(new int[10]); //Destructs using delete
//
//std::shared_ptr <int> ap(new int[10], std::default_delete<int[]>()); //Destructs using delete[]
//std::shared_ptr <int[] > ap(new int[10]); // Destructs using delete[]



//************************************** Issues with shared_ptr ***********************************************/



//****************************************** Issue 1  *************************************************************/
/*

shared_ptr<int> sptr1(p)  - Strong Ref Count 1  
shared_ptr<int> sptr2(p)  - Strong Ref Count 1  //as both sptr1 and sptr2 are different 

After main ends 

sptr1 goes out of scope and hence the count becomes 0 and memory block point pointed by sptr1 or p goes out of scope

sptr2 also goes out of scope and when tries to delete the memory block the programs crashes as it is already deleted

Never try to create a shared_ptr from naked pointers

*/

//void main()
//{
//	int* p = new int;
//	shared_ptr<int> sptr1(p);
//	shared_ptr<int> sptr2(p);
//}



////****************************************** Issue 2  *************************************************************/
// When there is cyclic reference of classes 

//class B;
//class A
//{
//public:
//	A() : m_sptrB(nullptr) { };
//	~A()
//	{
//		cout << " A is destroyed" << endl;
//	}
//	shared_ptr<B> m_sptrB;
//};
//
//
//class B
//{
//public:
//	B() : m_sptrA(nullptr) { };
//	~B()
//	{
//		cout << " B is destroyed" << endl;
//	}
//	shared_ptr<A> m_sptrA;
//};
//
//
////***********************************************************
//void main()
//{
//	shared_ptr<B> sptrB(new B); //Strong Ref Count of sptrB is 1
//
//	shared_ptr<A> sptrA(new A); //Strong Ref Count of sptrA is 1
//
//	sptrB->m_sptrA = sptrA;  //Strong Ref Count of sptrB is 2   
//
//	sptrA->m_sptrB = sptrB;  //strong Ref Count of sptrA is 2
//
//} 
//Both go out of scope when main ends but don't get deleted because their reference count is still
//one and memory is not released


 


//******************************************************** weak_ptr ***************************************************************************//
/*	
 1. To create a weak_ptr someone should already hold the resource like a shared_ptr
 2. It doesnot allow operators like -> * to be used with them as they are not the owners of the resource
 3. The answer is to create a shared_ptr out of a weak _ptr and use it.

 //Creation

 1. A weak pointer constructor takes a shared pointer as one of its parameters. 
 2. Creating a weak pointer out of a shared pointer increases the weak reference counter of
 the shared pointer (Here shared pointer is sharing its resource  with another pointer, weak pointer here)
 3. Strong reference of the shared pointer goes to 0, then the resource is released irrespective of the weak reference value
 4. So, if a resource shared by shared pointer goes out of scope, then weak pointer just goes out of scope 

 5. To check if a whether a weak pointer is pointing to a valid resource, there are two ways

	a. Call the use_count( ) method to know the count.  // this method returns the strong reference count and not the weak reference.
	b. Call the expired( ) method //check if resource exists

6. To get a shared_ptr from a weak_ptr call lock( ) or directly casting the weak_ptr to shared_ptr
7. reset() is used to release the resource

 */

 //void main( )
 //{
 //shared_ptr<Test> sptr( new Test ); //shared pointer: strong ref count : 1 
 //weak_ptr<Test> wptr(sptr); // strong ref count : 1 & Weak ref count : 1
 //weak_ptr<Test> wptr1 = wptr; // Strong ref count : 1 & Weak ref count : 2
 //}



 //class Test
 //{
 //public:
	// Test(int a = 0) : m_a(a)
	// {
	// }
	// ~Test()
	// {
	//	 cout << "Calling destructor" << endl;
	// }
 //public:
	// int m_a;
 //};



 //void main()
 //{
	// shared_ptr<Test> sptr(new Test); //shared pointer: strong ref count : 1 
	// weak_ptr<Test> wptr(sptr);// strong ref count : 1 & Weak ref count : 1
	// shared_ptr<Test> sptr2 = wptr.lock(); //strong ref count : 2 & Weak ref count : 1
 //}



/*********************************    Cyclic reference issue is resolved using the weak_ptr      ***************************************/

class B;
class A
{
public:
	A() : m_a(5)  { };
	~A()
	{
		cout << " A is destroyed" << endl;
	}
	void PrintSpB();
	weak_ptr<B> m_sptrB;
	int m_a;
};
class B
{
public:
	B() : m_b(10) { };
	~B()
	{
		cout << " B is destroyed" << endl;
	}
	weak_ptr<A> m_sptrA;
	int m_b;
};

void A::PrintSpB()
{
	if (!m_sptrB.expired())
	{
		cout << m_sptrB.lock()->m_b << endl;
	}
}

void main()
{
	shared_ptr<B> sptrB(new B); //Strong ref for B: 1
	shared_ptr<A> sptrA(new A); //Strong ref for A: 1
	sptrB->m_sptrA = sptrA; //Strong ref for A: 1  & Weak ref for A: 1
	sptrA->m_sptrB = sptrB; //Strong ref for B: 1  & Weak ref for B: 1


	//Here the counts are 1 when we use weak_ptrs as members
	int Acount = sptrA.use_count();
	int Bcount = sptrB.use_count();

}

//After main ends  : There will not be any problem even when the weak reference count is more than '0', only strong ref count matters 

// strong ref for A is 0 & Weak ref for A: 1
// strong ref for B is 0 & Weak ref for B: 1


/********************************  custom shared_ptr class  ***********************************************************/

//class A
//{
//private:
//	int i;
//
//public:
//	A(int iVal): i(iVal) { cout<<" A's constructor"<<endl; }
//	~A() { cout<<" A's destructor"<<endl; }
//
//	void display() { cout<<" i is"<< i << endl; }
//
//};

//
//template<class T>
//class MyShared_ptr
//{
//
//private:
//	T *m_ptr;
//	A *ptr;
//public:
//	MyShared_ptr(T *p) { m_ptr = p;  cout << " constructor of MyShared_ptr is called"; }
//	~MyShared_ptr() { cout << " Destructor of MyShared_ptr is called"; }
//
//	void Test() { };
//
//	T* operator->() 
//	{
//		return m_ptr;
//	}
//
//	T& operator*()
//	{
//		return *m_ptr;
//	}
//
//};

//void main()
//{
//	MyShared_ptr<int> obj(new int());
//	*obj = 10;
//	obj.Test();
//
//	//MyShared_ptr<A> obj1(new A(10));
//	//obj1.Test();
//	//obj1->display();
//
//}



//****************************************** unique_ptr ************************************************************/
/*
1.	The unique_ptr  overcomes the problems (issue 1 above)  of the auto_ptr i.e the ownership of resource always 
		lies with only one pointer 
2.	A unique_ptr cant be assigned to another unique_ptr directly (copy assignment and copy construction is not possible) 
3.  But this can be achieved using std::move   function
4.  The unique_ptr class provides the specialization to create an array of objects which calls delete[ ] 
		instead of delete when the pointer goes out of scope (issue 2 of auto_ptr)
5.	The interface that unique_ptr provides is very similar to the ordinary pointer but no pointer arithmetic is allowed.
6.  unique_ptr provides a functions  called release()----(just yields the ownership and does not destroy the resource ) 
		and reset()----(destroys the resource).
7. It can be used inside containers and algorithms of the STL
8. It can have a parameterized deleter as a second argument - std::unique_ptr<T, Deleter> 
	This can be useful when we are using std::unique_ptr for a file, then we can use customized Deleter for closing the file 
 */


/*
class Test
{
private:
	int m_i;

public:
	int j;
	Test(int i) { m_i = i; j = 20; }
	Test() { };
};


void main()
{

	std::unique_ptr<Test> p(new Test[6]); // syntax for allocating array of objects
	unique_ptr<Test> p2(p);  // it is not allowed 
	std::unique_ptr<Test> p2(std::move(p)); // way to copy the unique_ptr
	cout<<p->j<<endl;
}
 */





 //****************************************** Concurrency of smart pointers ************************************************************/
 /*
 1. The control block of a shared_ptr is thread safe
	When multiple threads access the same shared_ptr then the operation is atomic (thread safe) i.e. when n threads access resources
	the resource is deleted only after counter comes to 0


 2. The underlying resource is not thread safe

 If same shared_ptr is used by 2 threads thread1 and thread2 then
 The underlying is not thread safe in the sense, if the resource is passed to a thread1 by reference and that thread deletes
 the resource then if thread2 tries to access the resource, there will be an undefined behaviour

 Solution:
	If we want to make the underlying resource also thread safe then we need to synchronize or use atomic operations 
	From c++20 : we have std::atomic_shared_ptr and std::atomic_weak_ptr which by default are thread safe (both control block and resource)

 */


 //****************************************** Owner semantics ************************************************************/
  /*
  
  func(value)
	func is an independent owner of the resource 
	Deletes the resource at the end of the func automatically

  func(pointer *)
	Borrow the resource - It doesn't mean its the transfer of ownership, It is just a handle for owner
	The resource could be empty -  check the pointer as it could be null
	Must not delete - as func is not owner

  func(reference &)
	Borrow the resource - It doesn't mean its the transfer of ownership, It is just a handle for owner
	The resource could not be empty 
	Must not delete - as func is not owner

  func(std::unique_ptr)
	func is an independent owner of the resource
	Deletes the resource at the end of the func automatically

  func(std::unique_ptr)
	func is a shared owner of the resource
	May delete the resource at the end of the func automatically

  */