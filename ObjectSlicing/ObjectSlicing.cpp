// ObjectSlicing.cpp : Defines the entry point for the console application.
//
/*

Object slicing is a concept where additional attributes of a derived class object is sliced to form a base class object.
It doesn't occur when pointers or references to objects are passed as function arguments since both 
	the pointers are of the same size.

Object slicing will be noticed when pass by value is done for a derived class object for a function accepting 
		base class object.
it could be prevented by making the base class function pure virtual there by disallowing object creation.


Reason :

 The reason for this is the base class will have only space allocated to its members and when base class 
 object is passed to a function in derived class it omits the derived class members because the base class cant 
 accomodate the derived class members due to lack of space

 Remedy: 1. Pass the object as a refernce or a pointer unlike value 
		 2. By making the base clas pure virtual which will not allow to create the base class object

*/
#include "stdafx.h"
#include <iostream>

using namespace std;


class Base 
{
        int data1;
        int data2;
    
public:
        Base(int a, int b)
		{
            data1 = a;
            data2 = b;
        }

        virtual void display()
		{
            cout << "I am Base class" << endl;
        }
};

class Derived : public Base 
{
        int data3;
    
public:
        Derived(int a, int b, int c) : Base(a, b) 
		{
            data3 = c;
        }

        void display() 
		{
            cout << "I am Derived class" << endl;
        }
};

void somefunc ( Base obj )
{
    obj.display();
}

int main()
{
    Base b(10, 20);
    Derived d(100, 200, 300);

    somefunc(b);
    somefunc(d);

  return 0;
}


//Object slicing happens when a derived class object is assigned to a base class object, 
//  additional attributes of a derived class object are sliced off to form the base class object.

/*

class Base
{

protected:
		int m_i;

public:
    Base(int a)     { m_i = a; }
    virtual void display()
    { 
		cout << "I am Base class object, i = " << m_i << endl; 
	}
};
 
class Derived : public Base
{
    int m_j;

public:
    Derived(int a, int b) : Base(a) { m_j = b; }
    virtual void display()
    { 
		cout << "I am Derived class object, i = "<< m_i << ", m_j = " << m_j << endl; 
	}
};
 
/*
// Global method, Base class object is passed by value
void somefunc (Base obj)
{
    obj.display();
}
 
int main()
{
    Base b(33);
    Derived d(45, 54);
    somefunc(b);
    somefunc(d);  // Object Slicing, the member j of d is sliced off
    return 0;
}


///////////using pointers


void somefunc (Base *objp)
{
    objp->display();
}
 
int main()
{
    Base *bp = new Base(33) ;
    Derived *dp = new Derived(45, 54);
    somefunc(bp);
    somefunc(dp);  // No Object Slicing
    return 0;
}

*/

/*
class Base
{
public:
	Base() {}
	virtual void add() {cout<<"base"<<endl;}

};

class Derived : public Base
{
public:
	Derived() {} 
	virtual void add() {cout<<"derived"<<endl;}


};


void main()
{
	Derived obj;
	obj.add();
}
*/