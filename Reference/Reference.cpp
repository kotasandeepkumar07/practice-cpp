// Reference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*
class A
{
public:

	int m_i;

	A()
	{

	}
	A(int i) 
	{ 
		m_i = i;
	}
	int getvalue()
	{
		return m_i;
	}

	A(const A& obj)
	{
		m_i = obj.m_i;
	}

	A& operator=(A& obj)
	{
		A obj4;
	
		obj4.m_i = obj.m_i;
		return obj4;
	}

};


void main()
{
	A obj1(10);
	A obj2 = obj1;


	A obj3;
	A obj4;
	obj4 = obj3 = obj1;

	cout<<obj3.m_i<<endl;
	cout<<obj4.m_i<<endl;

}*/






//return by value     ---we cant return by value 
// return by reference   --we cant return a reference to a local object inside a function
// return using this pointer //


//class Test
//{
//public:
//	int m_i;
//	Test() : m_i(0){}
//	int& Increment(int a);
//};
//
//
//int& Test::Increment(int a)
//{
//	a = a + 1;
//	/*m_i++;*/
//	return a;
//
//}
//
//
//void main()
//{
//	Test obj;
//	int x = 4;
//	obj.Increment(x);
//	int a = x;
//
//
//	int z = obj.Increment(x) = 5;
//
//	cout << a << endl;
//	cout << z << endl;
//}


//int n = 10;
//int test();
//
//
//int main() 
//{
//	int x = test();
//	cout << x <<endl;
//	return 0;
//}
//
//
//int test() 
//{
//	int p = 10;
//	return p;
//}

//#include <iostream>
//using namespace std;
//
//int i;
//
//class A
//{
//public:
//	~A()
//	{
//		i = 10;
//	}
//};
//
//int& foo()
//{
//	i = 3;
//	A ob;
//	return i;
//}
//
//int main()
//{
//	cout << foo() << endl;
//	return 1;
//}




int fun(int &x)
{
    return x;
}
int main()
{
    cout << fun(10);
    return 0;
}