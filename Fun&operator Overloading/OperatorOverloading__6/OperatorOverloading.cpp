
//Syntax 

// Declaration : return_type operator op(argument_list)  
/*
return_type class_name :: operator op(argument_list)  
{
	 body of the function.  

}
*/

//we cant overload these opeartors . (dot)  ::  ?:  sizeof


//************************** Incrementing the complex number *************************//

/*
#include "stdafx.h"
#include "iostream.h"

class complex
{
int a,b;
public:
complex(){}
void read()
{
cout<<"Enter the Two Numbers:";
cin>>a>>b;
}

void display()
{
cout<<a<<"+i"<<b<<endl;
}

void operator++()
{
a=++a;
b=++b;
}
};


void main()
{
	complex obj;
	obj.read();
	++obj;
	cout << "Incremented Complex Number\n";
	obj.display();
}

*/


//********************  Adding two complex numbers (Overloading + operator)  *********************//////////


//#include "stdafx.h"
//#include "iostream.h"
//
//
//class complex
//{
//	int real, img;
//public:
//	complex() { }
//	complex(int a, int b);
//	complex operator +(complex);
//	void read();
//	void display();
//};
//
//complex::complex(int a, int b)
//{
//	real = a;
//	img = b;
//}
//
//void complex::read()
//{
//	{
//		cout << "\nEnter Real Part:";
//		cin >> real;
//		cout << "Enter Imaginary Part:";
//		cin >> img;
//	}
//}
//
//complex complex:: operator +(complex c1)
//{
//	complex c3;
//	c3.real = (this->real + c1.real);
//	c3.img = (this->img + c1.img);
//	return c3;
//}
//
//void complex::display()
//{
//	cout << "\nThe result is " << real << "+i" << img << endl;
//}
//
//int main()
//{
//	complex c1, c2, c3;
//	c1.read();
//	c2.read();
//	c3 = c1 + c2;
//	c3.display();
//	return 0;
//}
//
//
//
//
//

//#include "stdafx.h"
//#include <iostream>    
//using namespace std;
//class Test
//{
//private:
//	int num;
//public:
//	Test() : num(8){}
//
//	// Declaration : return_type operator op(argument_list) 
//	void operator ++()
//	{
//		num = num + 10;
//	}
//
//	void operator --()
//	{
//		num = num + 10;
//	}
//	void Print() 
//	{
//		cout << "The Count is: " << num;
//	}
//};
//
//int main()
//{
//	Test obj;
//	++obj;  // calling of a function "void operator ++()"   
			// calls Number::operator++(), i.e., calls Obj.operator++()
//	
//	--obj;
//	Test obj1;
//
//	obj = obj1 + 1;
//
//	obj.Print();
//	return 0;
//}


#include "stdafx.h"
#include<iostream>
using namespace std;

class NUM
{
public:
	int n;

public:
	void Setvalue(int x)
	{
		n = x;
	}

	void dispNum(void)
	{
		cout << "Number is: " << n;
	}

	NUM operator +(NUM obj)  //num1.operator+()
	{
		NUM x;  //create another object
		x.n = this->n + obj.n;
		return (x); //return object
	}


	Test obj(this);
};

int main()
{
	NUM num1, num2, sum;

	num1.Setvalue(10);
	num2.Setvalue(20);
	num1.n + num2.n;

	sum = num1 + num2; // NUM operator +()

		//// calls Number::operator++(), i.e., calls num1.operator+()

	sum.dispNum();
	cout << endl;


	return 0;
}


class Test
{
	Test(NUM &obj){}
};