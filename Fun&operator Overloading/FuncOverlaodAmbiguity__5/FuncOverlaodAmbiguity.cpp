
#include "stdafx.h"
#include <iostream>

using namespace std;

//void print(int a) 
//{
//  cout <<"value of a is"<< endl <<  a << endl;
//}
//
//void print(double a)
//{
//	cout << "value of a is" << endl << a << endl;
//}
//
//void main()
//{
//	//print('A'); 
//	print(0);
//    //print(3.1546);
//}


//#include <iostream>  
//using namespace std;

void fun(int);
void fun(int &);

int main()
{
	int a = 10;
	fun(a); // error, which f()?  
	return 0;
}
void fun(int x)
{
	std::cout << "Value of x is : " << x << std::endl;
}
void fun(int &b)
{
	std::cout << "Value of b is : " << b << std::endl;
}





//
//#include<iostream>  
//using namespace std;
//
//void fun(int);
//void fun(float);
//
//void fun(int i)
//{
//	std::cout << "Value of i is : " << i << std::endl;
//}
//
//void fun(double j)
//{
//	std::cout << "Value of j is : " << j << std::endl;
//}
//
//int main()
//{
//	fun(12);
//	fun(1.2);
//	return 0;
//}
