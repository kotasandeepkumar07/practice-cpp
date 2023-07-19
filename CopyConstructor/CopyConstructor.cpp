// CopyConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "string.h"


/************************************************************  rule of five  or rule of Three ***********************************************************/
/*
The rule of three and rule of five are rules of thumb in C++ for the building of exception - safe code and for formalizing rules on resource management.
The rule of three (also known as the Law of The Big Three or The Big Three) is a rule of thumb in C++ (prior to C++11) 
that claims that if a class defines any of the following then it should probably explicitly define all three:
	destructor
	copy constructor	
	copy assignment operator
*/


//*********************************************** Copy Constructor & Assignment Operator ****************************************//

// These are the two things that get invoked along with constructor and destructor when we instantiate a class
// Copy constructor is used to make a shallow copy (initialize) of each member from one object to the other(target object) 
//         even before memory is allocated for target object.
// Assignment operator is used to copy contents(assign) from one object to other(Target object) 
//                after both objects have been allocated with the memory.

/*
class MyClass
{
public:

	double dVal;
	char str;

public:
	MyClass(){ str = 'b'; cout<<"constructor"<<endl;};
	~MyClass(){cout<<"Destructor"<<endl;};
};


void main(int argc, char* argv[])
{
	//copy constructor (copying contents of obj1 to obj2 even before memory is allocated to obj2)
/*	MyClass obj1;
	MyClass obj2 = obj1; 
*/


//	MyClass obj3 = 	MyClass obj2 = obj1; // error (here we can't copy contents to more than one object from a source )


	//Assignment operator (copying contents of obj1 to obj2 after memory is allocated to obj2)
/*	MyClass obj1;
	MyClass obj2;
	obj2 = obj1;
*/

	/*
	MyClass obj1;
	MyClass obj2;
	MyClass obj3;
	obj3 = obj2 = obj1; // ok can copy to more than one object at once
	*/
	

//	MyClass::MyClass(const MyClass &obj): iVal(obj.iVal), dVal(obj.dVal) ;{}
//}





//*********************************  Problems with the default copy Constructor (which makes shallow copy) ******************************/

// CASE 1 : When object is of pointer type 


// There arises problems when we copy one object to other object in two cases

// case 1) When the object is a pointer type and the object is copied to other object. 
//    The target object starts pointing to same object data and when source object is deleted and if we try to delete the target object 
//    there arises  an exception  because the pointer is already deleted


// case 2) When an object(source) is pointed to a string and the object is copied to other(destination) 
//    if the destination object modifies the string, 
//    even the original sting gets modified (we might loose the original data). 


//*************************************************************************************************************

// CASE 2 When we pass an object as an argument (by value) to a function

// When we pass the object as a parameter to a function.
// when the function ends, the stack gets cleaned up and the object gets destroyed and 
// when it goes to the destructor it crashes because already the heap is destroyed and again we are trying to delete the object.

/*
class MyClass
{
public:

	char* str;
	MyClass(char* Charp)
	{
//		str = new char[sizeof(Charp)];
		str = new char[10];
		strcpy (str,Charp);
	}
	
	// destructor
	~MyClass() 
	{
		delete str;
	}
	
	MyClass ( MyClass& obj) 
	{
		str = new char;
		*str = *obj.str;
	}
};

//now we will write a function that receive a string object as an argument.
void function (MyClass str)
{
	cout<<"I will crash after this"<<endl;
}

void main ()
{
	MyClass str("hello");
	function(str);// program crush
}

 

//*******************************************************************************************************************************/
// CASE 3 When we use an object as a return type of a function



//*********************************************  User defined Copy Constructor ***********************************************************//

// In order to over come the disadvantages the user have to override the default constructor which makes a deep copy of the object
// If we over ride the copy constructor then we must also override default assignment operator.
// There are three cases where we need to override the default copy constructor 
// CASE 1 : When object is of pointer type 
// CASE 2 : When we pass an object as an argument (by value) to a function
// CASE 3 : When we return an object from a function.


/*

class A
{
public:

	char* str;
	A(char *a)
	{	
		strcpy(str,a);
	}
	~A()
	{
		delete str;
	} 
	A(const A &)
	{
		cout<<"copy";
	}

	void show(A a)
	{
		cout<<a.str<<endl;

	}
};


void main()
{
	A obj("hello");
	obj.show(obj);

	//A obj1 = obj;
}
*/




/*

class Line
{
   public:
      Line(int len);              // simple constructor
      Line( const Line &obj);	  // copy constructor
      ~Line();                    // destructor

   private:
      int *p;
};

// Member functions definitions including constructor
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // allocate memory for the pointer;
    p = new int;
    *p = len;
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    p = new int;
   *p = *obj.p; // copy the value
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete p;
}


int main( )
{

   Line *line = new Line(10);

   Line *l = line;
   delete line;
   delete l;

   return 0;
}
*/


/*

class Base
{
private :
		char *str;
public:

	Base(char *s) 
	{ 
		int x = strlen(s);
		str =  new char(x);
		strcpy(str, s);
	}
	Base(const Base& ob) 
	{
		cout<<"copy constructor"<<endl;
		str = new char[sizeof(ob)];
		*str = *ob.str;   //copy the content of the existing obj into new obj;
	}

	~Base()
	{
		delete str;
	}

	Base& operator=(const Base &p)
	{
	//	cout<<"Assignment operator"<<endl;
	//	str = new char[sizeof(p)];
	//	*str = *p.str;            
	//	return *this;
	}

};



void main()
{
	Base obj("hi");
	Base obj1 = obj;

//	func(obj1);
//	Base obj2("");
//	obj = obj2;
}
*/



//class Base
//{
//private:
//	int *m_len;
//
//public:
//	Base(int p) 
//	{ 
//		m_len = new int;
//		*m_len = p;
//	}		
//	
//	Base(const Base& obj)
//	{
//		m_len = new int;
//		*m_len  = *obj.m_len;
//	}
//};
//
//void main()
//{
//	Base *obj = new Base(4);
//	Base *obj1 = obj;
//}




class Test
{
private:
	int *m_ptr;

public:

	Test(const Test& obj)
	{
		int *ptr = new int;
		*ptr = *(obj.m_ptr);
	}

	Test& operator=(const Test& obj)
	{
		if (this != &obj)
		{
			m_ptr = new int;
			*m_ptr = *(obj.m_ptr);
			return *this;
		}
		return *this;
	}
};


void main()
{
	
}


