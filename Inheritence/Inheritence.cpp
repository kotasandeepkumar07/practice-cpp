// Inheritence.cpp : Defines the entry point for the console application.
//
//
//#include "stdafx.h"
//#include "iostream.h"

#include "stdafx.h"
#include <iostream>

using namespace std;


//*********************************   Simple(Single Inheritence)    ***************************************//

/*
class Base
{
void function() {};
};

class Derived: Base
{

};

void main()
{

}
*/

//*********************************  (Multilevel Inheritence) ***************************************//
/*
class Base
{

};

class Derived : public Base
{


};

class Derved1 : public Derived
{

};

*/

//******************************************  (Hierarchical)   ***********************************************************//

/*
class Base
{

};

class Derived : public  Base
{

};

class Derived1 : public Base
{

};


void main()
{
}


*/

//*********************************************** (Multiple)   ***************************************************//

//
//class Base 
//{
//	void function() {};
//};
//
//class Derived 
//{
//
//};
//
//class Derived1 : Base, Derived
//{
//
//};
//void main()
//{
//
//}



//  *********************************  (Hybrid) ************************************************* //

//  Combination of above  four types of inheritances //






// *********************************  Derived class taken as (public) from Base class **************************************** //

//  1) Private Members of Base class can't be accessed in derived class
//  2) Public, private, protected Members of Base class become 
//	   public  private and  protected  members of derived class respectively

/*

#include "stdafx.h"
#include "iostream.h"

class CBase
{
public:
int a;
void func1()  {};
private:
int  b;
void funcn2() {};

protected:
int c;
void func3()  {};

};

class CDerived : public CBase
{

public :
CDerived()
{
a = 0; // ok
//	b = 0; // error  because it is private to base class
c = 0; // ok
}
};

void main()
{
CDerived obj;
obj.func1();

}

*/

//  *********************************  Derived class taken as (Private) from Base class ********************************** //

// 1) If we do not specify how a derived class is getting derived from base class , by default it is private
// 2) Private Members of Base class can't be accessed in derived class
// 3) Public, private & protected Members of Base class become 
//	  private members of derived class 

/*
#include "stdafx.h"
#include "iostream.h"

class CBase
{
public:
int a;
void func1()  {};
private:
int  b;
void funcn2() {};

protected:
int c;
void func3()  {};

};

class CDerived : public CBase
{

public:
CDerived()
{
a = 0; // ok
//		b  =0; // error
c = 0; // ok
}
};




void main()
{
CDerived obj;
obj.func1();

}
*/

//  *********************************  Derived class taken as (Protected) from Base class ************************************* //

// 1) Private Members of Base class can't be accessed in derived class
// 2) Public, private & protected Members of Base class become 
//	  Protected, Private & Protected members of derived class respectively

/*\=-
#include "stdafx.h"
#include "iostream.h"

class CBase
{
public:
int a;
void func1()  {};
private:
int  b;
void funcn2() {};

protected:
int c;
void func3()  {};

};

class CDerived : protected CBase
{

public:

CDerived()
{
a = 0; // ok
//		b  =0; // error
c = 0; // ok
}
};

void main()
{
//	CDerived obj;
//	obj.func1();

}
*/


//  *********************************  Order in which contructor & destructor gets called when inherited  ***************** //

//  1) When we are trying to create the object of Most derived class: 
//     Constructor : The constructor of base class is called first and then the immediate derived one and so on
//	   Destructor  : The destructor  of most derived class is called first and then goes up until base class 


//#include "stdafx.h"
//#include <iostream>


//class CBase
//{
//public:
//	CBase()
//	{
//		cout<< "base constructor"<<endl;
//	}
//
//	~CBase()
//	{
//		cout<< "base destructor"<<endl;
//	}
//};
//
//class CDerived
//{
//public:
//
//	CDerived()
//	{
//		cout<< "derived constructor"<<endl;
//	}
//
//
//	~CDerived()
//	{
//		cout<< "derived destructor"<<endl;
//	}
//
//};
//
//
//class CChild : public CBase, public CDerived
//{
//public:
//
//	CChild()
//	{
//		cout << "Child constructor" << endl;
//	}
//
//
//	~CChild()
//	{
//		cout << "Child destructor" << endl;
//	}
//
//};
//
//
//
//
//void main()
//{
//	CChild obj;
//
////	CDerived *p = new CDerived();
////	delete p;
//}


//**************************  Adding,Changing and Hiding Members in derived classes ******************************** //


// 1) When we try to call a function which is not in derived class using derived class object. 
//    It will call base class function(if exists) from which the derived class is derived

//
//class Employee
//{
//protected:
//    int &m_nValue;
// 
//public:
//	Employee(int nValue) : m_nValue(nValue)
//    {
//		m_nValue = nValue;
//    }
// 
//    void Identify() { cout << "I am a Base" << endl; }
//	 int GetValue(int j) { return m_nValue; }
//};
//
//
//class Manager : public Employee
//{
//public:
//	int m_nBonus;
//	Manager(int nValue) :Employee(nValue)
//    {
//
//    }
//	void Identify() { cout << "I am a Derived one" << endl; }
//	int GetValue() { return (m_nValue + m_nBonus); }
//};
//
//
//void main()
//{
//	/*Employee cBase(5);
//    cout << "cBase has value " << cBase.GetValue() << endl;
//
//	Manager cDerived(5);
//    cout << "cDerived has value " << cDerived.GetValue() << endl;
//
//	Employee obj(5);
//	obj.Identify();*/
//
//	Manager obj1(8);
//	obj1.Identify();
//	//obj1.GetValue(2);
//}


// Note:
// usually if we derive a class from base class publicly.
// The public, private and protected of base class becomes public , private and protected members in the derived class, 
// It means that the protected data cant be accessed outside the class

// example:

//#include "stdafx.h"
//#include "iostream.h"

//class CBase
//{
//public:
//		int a;
//		void func1()  {};
//private:
//		int  b;
//		void funcn2() {};
//		
//protected:
//		int c;
//		void func3()  
//		{
//			cout << "i am function3" << endl;
//		};	
//};
//
//
//
//class CDerived : protected CBase
//{
//public:
//	CDerived(){ }
//	CBase::func3;
//};
//
//
//void main()
//{
//	CDerived obj;
//	obj.func3(); 
//}



// Follow up : Now we can change the access specifier of the base members when derived so that they can be accessed outside
// Example :

/*
#include "stdafx.h"
#include "iostream.h"


class CBase
{
public:
	int a;
	void func1()  {};

private:
	int  b;
	void funcn2() {};

protected:
	int c;
	void func3()  {};

};

class CDerived : protected CBase
{
public:
	CDerived(){ }
	CBase::func3 ; // Making the base class function as public which was actually supposed to be protected(in the derived class)
	//	CBase::funcn2 ; // can't be taken because private can never be accessed whatever be the method
};

void main()
{
	CDerived obj;
	obj.func3(); // ok
}
*/


//*****************************************  Inheritence Ambiguity ************************************************* //

// 1) When a class is derived from two base classes(multiple inheritance) and if we try to call the function 
//    which is in two base classes using the derived class object.
//	  there occurs an error saying ambiguous call( because compiler does not know which class function it should call)
//	  To Resolve the issue simply mention the ("class name::function name") while calling it using the derived class object




//#include "stdafx.h"
//#include "iostream.h"


//class CBase
//{
//public:
//	int a;
//	void func1()  {};
//};
//
//
//class CDerived1 : public CBase
//{
//public:
//	CDerived1() {}
//	void print() { cout<<" I am derived1"<<endl; }
//};
//
//
//
//class CDerived2 : public CBase
//{
//public:
//
//	CDerived2() {}
//	void print() 
//	{ 
//		cout<<" I am derived2"<<endl; 
//	}
//};
//
//
//class CChild : public CDerived1, public  CDerived2
//{
//public:
//	CChild(){ }
//};
//
//
//void main()
//{
//	CChild obj;
//	//obj.print();
//	obj.CDerived2::print();
//}



//**************************************** Diamond Problem (VIRTUAL INHERITANCE) *********************************************//

//Best Example https://www.youtube.com/watch?v=7APovvvftQs


/*
 1) The problem below is also called as "Diamond Problem"

 Diamond Problem:

 1. Whenever a class is derived from two base classes which are in turn derived from one base class.
 If we are trying to create object of most derived class it would first call the most base class and one of its parent then
 again most base class and second parent class. In this aspect  the base class is called twice which is undesirable.

 2.	If we call the base class function using child object, it throws an error saying ambiguous call.

 Resolve: To resolve the issue simply derive the two parent classes virtually from most base class so that only one copy of most base class is created.


 without Virtual key word
 output : I am Base Constructor , I am Derived1 Constructor, I am Base Constructor , I am Derived2 Constructor, I am Child Constructor


 with	Virtual key word
 output : I am Base Constructor , I am Derived1 Constructor, I am Derived2 Constructor, I am Child Constructor(because "virtual" keyword allows to create only one object)
 Note: Virtual keyword has to be given for both the classes
 */

#include "stdafx.h"
#include <iostream>

using namespace std;


class CBase
{
public:

	CBase() { cout << "I am Base Constructor" << endl; }

	void func1(){ cout << "I am Base func1" << endl; }
	void func2(){ cout << "I am Base func2" << endl; }

};


class CDerived1 : public  virtual CBase
{
public:

	CDerived1() { cout << "I am Derived1 Constructor" << endl; }
	void print() { cout << " I am derived1" << endl; }

	void func1()
	{
		cout << "I am CDerived1 func1" << endl;
	}
};


class CDerived2 : public  virtual CBase
{
public:
	CDerived2() { cout << "I am Derived2 Constructor" << endl; }
	void print() { cout << " I am derived2" << endl; }

	void func2()
	{
		cout << "I am CDerived2 func2" << endl;
	}
};


class CChild : public CDerived1, public  CDerived2
{
public:
	CChild() { cout << "I am Child Constructor" << endl; }

};


void main()
{
	CChild obj;

}



/*class  B
{
	public:
		B() { cout << "I am B Constructor" << endl; }
};


class C
{
	public:
		C() { cout << "I am C Constructor" << endl; }
};


class A : public B,  public C
{
	public:
		A() { cout << "I am A Constructor" << endl; }
};*/


//class A
//{
//public:
//	int i;
//
//private:
//	int j;
//
//protected:
//	int k;
//};
//
//class B : private A
//{
//	//i is private to B
//	//j is private to A
//	//k is priavte to B
//	B()
//	{
//		i = 10;
//		j = 10;
//		k = 10;
//	}
//};


/***************************************************************** Pure Virtual Destructor can exist ***********************************************/



//#include <iostream> 
//class Base
//{
//public:
//	virtual ~Base() = 0; // Pure virtual destructor 
//
//	virtual void add() = 0;
//};
//
//Base::~Base()
//{
//	std::cout << "Pure virtual destructor is called";
//}
//
//class Derived : public Base
//{
//public:
//	~Derived(){}
//};
//
//int main()
//{
//	Base *b = new Derived();
//	delete b;
//	return 0;
//}

//void main()
//{
//	//Test obj;
//	//obj.sum(10);
//
//	//A obj;
//	//obj.i = 10;
//
//	//A Obj2 = obj;//copy constructor
//
//	//A Obj3;
//	//Obj3 = obj; //Assignment Operator
//
//	//.obj3 + obj;
//
//	//cout << sizeof(obj) << endl;
//
//	//CChild obj; //stack 
//
//	//CChild  *pChild = new CChild; //heap 
//
//	//obj.func1();  //error if virual is not used above  CChild::func1' is ambiguous
//
//	//int *p = new int;
//	//delete p;
//
//	//*p = 10;
//
//
//}





//class A
//{
//public:
//	
//
//
//};
//
//inline A Test()
//{
//	B::add();
//}
//
//class B
//{
//public:
//	static void add()
//	{
//
//	}
//};
//
//void main()
//{
//
//
//}



//class base 
//{
//
//public:
//	base() {}
//
//private:
//	int private1, private2; 
//
//public: 
//	int public1, public2;
//
//protected:
//	int protected1, protected2;
//};
//
//
//class derived : public base
//{
//	int derived1;
//
//public:
//	derived()
//	{
//		public1 = 0;
//		//private1 = 0;
//		protected1 = 0;
//	}
//};
//
//class child : public derived
//{
//	int child1;
//
//public:
//	child()
//	{
//		public1 = 0;
//		//private1 = 0;
//		protected1 = 0;
//	}
//
//};
//
//
//int main()
//{
//	base baseobj;
//	baseobj.public1 = 10;
//	baseobj.private1 = 10;
//	baseobj.protected1 = 10;
//
//	return 0;
//}