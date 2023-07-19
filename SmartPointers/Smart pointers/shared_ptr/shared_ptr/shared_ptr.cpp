// shared_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;





//1. Transfer of ownership : The follwing program crashes if we use autor_ptr in place of shared_ptr as auto_ptr transfers total owner ship 
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
//	cout << p1->j << endl;
//
//} //strong count :1   //as p1 is dead
//
//void main()
//{
//	std::shared_ptr<Test>p(new Test(10)); //strong count: 1
//	func(p);
//	cout << p->j << endl;
//}




//2. Auto_ptr Cant be used to created array of objects :  When we create array of objects using smart pointers, the default implementation calls delete instead of 
//  delete[], the shared_ptr provides a privision to tell the compiler to use delete[] and there is no such option using autor_ptr

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
//	auto sptr1 = std::make_shared<Test[3]>(); //(new Test[5]);//,
//		//[](Test* p) { delete[] p; }); //works fine 
//
//
//	sptr1.get()[0];
//
//	//std::aut<Test> sptr1
//	
//
//}




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


//
//////****************************************** Issue 2  *************************************************************/
////// When there is cyclic reference of classes 
//
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
//	shared_ptr<A> sptrA(new A); //Strong Ref Count of sptrA is 1
//	sptrB->m_sptrA = sptrA;  //Strong Ref Count of sptrA is 2   
//	sptrA->m_sptrB = sptrB;  //strong Ref Count of sptrB is 2
//} 
////Both go out of scope when main ends but dont get deleted because their reference count is still one and memory is not released
//
//
//




//functions supported by shared_ptr 
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
//void main()
//{
//	std::shared_ptr<Test>p(new Test(10));
//
//	//get
//	//Test *test  = p.get();
//	//cout << test->j << endl;
//	//cout << p->j << endl;
//
//
//	//reset
//	//p.reset();
//	//cout << p->j << endl;
//
//	//std::shared_ptr<Test>q = p;
//	//cout << q->j << endl;
//
//	//use_count 
//	//int i = p.use_count();
//}


class DataObject
{
public:
	DataObject();
	virtual  void Open() {}

};

class FileDataObject : public DataObject
{
public:
	FileDataObject();
	virtual  void Open() {}

};

class TreeProxy
{
public:
	DataObject *m_pDataObject;
	virtual void OpenData(DataObject &obj) 
	{ 
		m_pDataObject = &obj;
	}
};

class ChildTreeProxy : public TreeProxy
{
public:
	std::shared_ptr<FileDataObject> m_pFileDataObject;
	virtual void OpenData(DataObject &obj) 
	{ 
		TreeProxy::OpenData(obj);
		//m_pFileDataObject = std::make_shared<FileDataObject>(dynamic_cast<FileDataObject*>(&obj));
	}
};

void main()
{
	DataObject *m_pDataObject = new DataObject();

	//FileDataObject *m_pFileDataObject = new FileDataObject();

	//std::shared_ptr<DataObject> m_pDataObject(new DataObject());
	//std::shared_ptr<FileDataObject> m_pFileDataObject = make_shared<DataObject>();
	//m_pFileDataObject = std::make_shared<FileDataObject>(m_pDataObject);
	//FileDataObject *m_pFileDataObject = new FileDataObject();
	//FileDataObject *test = dynamic_cast<FileDataObject *>(m_pDataObject);


	std::shared_ptr<FileDataObject> m_pFileDataObject = std::make_shared<DataObject>();





}