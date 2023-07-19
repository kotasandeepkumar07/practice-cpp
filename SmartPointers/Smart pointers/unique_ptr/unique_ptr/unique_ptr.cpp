// unique_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Test
{
private:
	int m_i;

public:
	int j;
	Test(int i) { m_i = i; j = 20; }
	~Test() { }
};
 
void func(std::unique_ptr<Test> p1)
{
	cout << p1->j << endl;	 
}

void main()
{

	//Declaration
	std::unique_ptr<Test>p(new Test(10));

	////for array objects
	//std::unique_ptr<Test[]>p(new Test(10));

	//// without using new, Introduced in C++ 14
	//std::unique_ptr<int>ptr1 = std::make_unique<int>(12); 

	

	//Doesnt allow to be assigned to another pointer, single ownership
	func(p); //syntax error
	//std::unique_ptr<Test>p2  = p;  //syntax error


	//allows using Move function where move constructor is called 
	std::unique_ptr<Test>p3 = std::move(p); 
	//cout << p->j << endl; 
	//cout << p3->j << endl; 



	//release is used to release to a raw pointer 
	//Test *res = p3.release();
	//cout << res->j << endl;

	Test *ptr1 = p3.get();
	cout << p3->j << endl;



	////reset is used to reset the pointer, return void
	// p3.reset();

}
