// VirtualFunctions.cpp : Defines the entry point for the console application.
//


//**********************************************  Need for Virtual Functions ********************************************************//

//

//#include <iostream>
//using namespace std;
//
//class CBase
//{
//public:
//	CBase(){}
//
//	void Getname()	 {cout<< "I am Base"<<endl;}
//	void Getvalue()  {cout<<"I have 10"<<endl;}
//};
//
//
//class CDerived : public CBase
//{
//
//public:
//	CDerived(){}
//	
//	void Getname()  {cout<< "I am Derived"<<endl;}
//	void Getvalue() { cout<<"I have 12"<<endl;}
//};
//
//
//void  main(int argc, char* argv[])
//{
////	1)creating a derived class object (It will call derived class functions only)
//	//CDerived obj;						
//	//obj.Getname();			
//	//obj.Getvalue();	// calling through simple object
//	//CDerived &rderived = obj;			rderived.Getname();		rderived.Getvalue();// calling through refernce type of object
//	//CDerived *pderived = &rderived;		pderived->Getname();	pderived->Getvalue();//calling using pointer type of object
//
//
////	Note: 2) We can't create derived class object to call base class functions (Important)
//	//CDerived *rderived = new CBase() ; //throws error
//
//
// //	3) creating a base class objects (It will call base class functions only)
//
//	/*CBase obj;
//	obj.Getname();			
//	obj.Getvalue();*/
//
//	//CBase &rbase = obj;		rbase.Getname();	rbase.Getvalue();					
//	//CBase *pbase = &rbase;  pbase->Getname();	pbase->Getvalue();
//
//	
////	Note: 4) We can create base class object to call derived class functions(Important)
//	CBase *pbase = new CDerived() ; //ok.   
//	pbase->Getname();
//
//// Here there is no syntax error. The compiler will take it , but it will still call base class function even 
////  though the pointer points to derived class
//// This gives rise to concept of  "Virtual functions " i.e to call a derived class function 
////  using base class pointer(which points to derived class)
////	pbase->Getname(); //calls base function
//
//}




//************************************************  Virtual Functions  **************************************************************//



// It is used by simply adding the "virtual" keyword before the function. 
// It says the compiler to look for such functions(which has virtual key word attached to it) in the derived versions

// output: i am Derived

//#include "stdafx.h"
//#include <iostream>
//using namespace std;
//
//class CBase
//{
//public:
//    virtual const char* GetName() { return "i am  Base"; }
//	int i;
//};
// 
//class CDerived: public CBase
//{
//public:
//    virtual const char* GetName() { return "i am Derived"; }// Actually speaking the virtual keyword is not necessary in derived class
//};
// 
//
//void  main(int argc, char* argv[])
//{
//    //CBase rBase = new  CDerived();	// here base pointer is pointing to derived class hence it should call derived class function
//   // cout<< rBase->GetName() << endl;
//
//	CBase obj;
//	cout << sizeof(obj) << endl;
//
//}




//********************************* Virtual Functions (Return type of the functions should be same) ********************************//


//#include "stdafx.h"
//#include <iostream>
//
//class CBase
//{
//public:
//    virtual int GetValue() { return 5; }
//};
// 
//
//class CDerived: public CBase
//{
//public:
//	virtual int GetValue() override { return 6; } // throws an syntax error 
//};
//
//
//void  main(int argc, char* argv[])
//{
//}



//***************************************** Need for Virtual Destructors ******************************************************//


// Problem:  when a base class pointer is deleted as below it goes to the base class destructor and deletes it.
// but the pointer object of base class is actually pointing to derived class hence  it should also called derived class destructor 
// when we do not make base class destructor virtual , it will not look in to the derived versions.

// Remedy: make the base destructor virtual

//  output without virtual destructor: base constructor, derived constructor,  base destructor
//  output with    virtual destructor: base constructor, derived constructor,  base destructor, derived destructor

// Note: Actually speaking the derived class destructor has to be called first and then base class ,
//		but,  when base class pointer is created pointing to derived class and it is deleted , 
//	it goes to base class destructor and then derived class destructor

//
#include "stdafx.h"
#include <iostream>

//using namespace std;
//class CBase
//{
//public:
//	
//	CBase()
//	{
//		cout<< "base constructor"<<endl;
//	}
//	
//	virtual ~CBase()
//	{
//		cout<< "base destructor"<<endl;
//	}
//};
//
//class CDerived : public CBase
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
//};
//
//void main()
//{	
////	CDerived *p = new CDerived();
////	delete p;
//
//	CDerived objDerived;
//	//CBase *p = new CDerived();
//	CBase &p = objDerived;
//	
//	//delete p;
//}



//***********************************  Virtual Constructor ********************************************************//

//  Like Virtual Destructor, there exists no "Virtual Constructor" 

// 1) The v-table gets created when compiler sees the word virtual (after the object is instantiated) which happens inside the constructor   
//	  that means we are trying to create the v-table before creating the object(so not possible)

// 2) The main purpose behind creating the Virtual function is to ask the compiler to check if there are any derived versions of the function, 
//	  but constructor of base class will never be used in derived class, so no need of making it virtual.

/*
#include "stdafx.h"
#include "iostream.h"

class CBase
{

public:

virtual	CBase() //compile error
{
cout<< "base constructor"<<endl;
}

};

class CDerived : public CBase
{
public:

CDerived()
{
cout<< "derived constructor"<<endl;
}

};

void main()
{
CBase *p = new CDerived();
}

*/

//***************** "v table" OR "virtual function table" OR  "virtual method table" OR "dispatch table"******************************//



// There exists a V Table for each class that has a virtual function or a "derived class" derived from class(which has virtual function)
// The virtual table will have so many entries as many as number of virtual functions
// There is a pointer called "v pointer" which is a real pointer which points  to the v table of the class for which object has been created.


// for following example. There exists 
// 3 v tables for Base, D1, D2
// Each v table has 3 entries ( as there are total 3 virtual functions)
// the v pointer will point to D1 v table(because its object is created)
// when we call function1  here, it will call function1 of D1 (as this is the latest one in that table)
// when we call function2  here, it will call function2 of Base (as this is the latest one in that table)

//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//    virtual void function1() {cout<<"I am function1 in base"<<endl;}
//    virtual void function2() {cout<<"I am function2 in base"<<endl;}
//	  virtual void function3() {cout<<"I am function3 in base"<<endl;}
//
//};
//
//class D1: public Base
//{
//public:
//    virtual void function1() { cout<<"I am Derived1"<<endl;}
//};
//
//class D2: public Base
//{
//public:
//    virtual void function2() {cout<<"I am Derived2"<<endl;}
//};
//
//
//void main()
//{
//	//D1 obj;
// //   Base *p1 = &obj; 
// //   p1->function1();
//	//p1->function2();
//	//p1->function3();
//
//
//    D2 obj1;
//    Base *p2 = &obj1;																								// output::: I am function1 in base, I am Derived2, I am function3 in base (as function is latest in D2 vtable)
//    p2->function1();
//	p2->function2();
//	p2->function3();
//
//
//	// the v pointer will point to D1 v table(because its object is created)
//	// when we call function1  here, it will call function1 of D1 (as this is the latest one in that table)
//	// when we call function2  here, it will call function2 of Base(as this is the latest one in that table)
//}




//********************************* "Abstract Class (Pure Virtual or Abstract Function)"*********************************************//

// Pure Virtual or Abstract Function is a function that has no body. This is achieved by just equating the function to zero.
//Any class containing pure virtual function is called an Abstract class.

//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//
//class Base //abstract class
//{
//	virtual void get() = 0; //pure virtual function so Base is now an abstract class
//};
//
//void main()
//{
//	//Base obj; // throws an error, we cant create object of a class containing pure virtual function.
//}
//



//********************************* " Need for Abstract Class (Pure Virtual or Abstract Function)" ***********************************//

// The main reason behind creating such function is:
// In the below example the functions are not called in Derived2 class, still the compiler doesn't throw error
// because it calls the base class functions, which is actually wrong(because we created the object of derived2 class)

// output :  I am base  hi



//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//	void GetName() { cout<< "I am base" <<endl;};
//	virtual void speak() /*{cout<<"hi Base"<<endl ;}*/  = 0;
//};
//
//class Derived1: public Base
//{
//public:
//	void GetName() { cout<< "I am Derived 1" <<endl; };
//	virtual void speak() {cout<<"hi Derived1"<<endl ;}  //= 0;
//
//};
//
//class Derived2: public Base
//{
//public:
//	virtual void speak() {cout<<"hi Base"<<endl ;} 
//};
// 
//void main()
//{
//	Derived2 obj; 
//	obj.GetName();
//	obj.speak();
//}

// It should ideally call derived2 class functions but calls base class functions.

//********************************* " Resolution of above problem "*********************************************//

/*
The above problem can be solved just by adding a pure virtual function to the base class which must be
definitely over ridden in derived class other wise the compiler will not allow to create the object of the derived class
output: I am Derived2

so the main aim in using pure virtual function is that, the derived class  "MUST" override pure virtual function
without skipping. irrespective of other functions

we cant instantinate object of a abstract class , but we can use pointers and references to it.
*/


/*

#include "stdafx.h"
#include "iostream.h"


class Base
{
public:

void GetName() { cout<< "I am base" <<endl;}
virtual void speak() = 0;
};

class Derived1: public Base
{
public:
void GetName() { cout<< "I am Derived 1" <<endl; }
virtual void speak() = 0;

};

class Derived2: public Base
{
public:
void GetName() { cout<< "I am Derived 2" <<endl; }
virtual void speak(){ cout<<"hi"<<endl ;}

};

void main()
{
Derived2 obj; // compiler will not allow to create object of this class unless the pure virtual function is overridden
obj.GetName();

Base obj; // will fail
Base *p'  // can be used

}

*/


//***********************************   If the pure virtual function is not overridden in the derived class ,it also becomes a abstract class (object cant be created) **************//


//class Base
//{
//public:
//    virtual void show() = 0;
//};
// 
//class Derived : public Base 
//{ 
//
//};
// 
//int main(void)
//{
//	//Base obj;
//
//    Derived q;
//    return 0;
//}
//



//********************************* We can provide the definition for pure virtual function *************************//

/* Though we can create the definition(allowed only outside the class) of the pure virtual function, still we cant call it as
	we cant create object of it
	*/


/*
class Base
{
public:
Base(){}
virtual	void add() = 0;
};

void Base::add()
{

};

void main()
{

}

*/

/************************************ Interface class  ***********************************************************/


// This is an extension to the Abstract class where all the functions are pure virtual. 
// The reason behind this class is same as abstract class. 

// All the functions in the base class are to be present in all the derived classes whose object is needed by the user
// (at least they should be declared,though not implemented)


/*
#include "stdafx.h"
#include "iostream.h"

class Base
{
public:

virtual void GetName() = 0;
virtual void speak() = 0;
};

class Derived1: public Base
{

public:
void GetName() { cout<< "I am Derived 1" <<endl; }
virtual void speak() = 0;

};

class Derived2: public Base
{

public:
void GetName() { cout<< "I am Derived 2" <<endl; }
virtual void speak(){ cout<<"hi"<<endl ;}

};

void main()
{


}
*/


/*
class Base
{
public:
virtual void add()
{
}
};

class Derived : public Base
{
public:
virtual void add()
{
}
virtual void sub() {}
};


void main()
{

Base *p = new Derived;
p->sub();

}
*/


/*
class B
{
public:
B(const string& ss)
{
cout << "B constructor\n";
f(ss);
}
virtual void f(const string&)
{
cout << "B::f\n";
}
};

class D : public B
{
public:
D(const string & ss) :B(ss)
{
cout << "D constructor\n";
}
void f(const string& ss)
{
cout << "D::f\n"; s = ss;
}
private:
int i;
};


void main()
{
D d("Hello");
}

*/

using namespace std;
//class Employee
//{
//private:
//	 int m_nSalary;
//public:
//	Employee(int nSalary)
//	{
//		m_nSalary = nSalary;
//	}
//	int GetSalary() const   
//	{
//		return m_nSalary;
//	}
//};
//
//void main()
//{
//	Employee obj(100);
//	int nval = obj.GetSalary();
//	cout << nval << endl;
//}



//Question 3
#include <iostream> 
class Base
{
public:
	virtual ~Base() = 0; // Pure virtual destructor 
};

Base::~Base()
{
	std::cout << "Pure virtual destructor is called";
}

class Derived : public Base
{
public:
	~Derived(){ std::cout << "Derived destructor is called"; }
};

int main()
{
	Base *b = new Derived();
	delete b;
	return 0;
}




//Question 6
//
//int fun(int x = 0, int y = 0, int z)
//{
//	return (x + y + z);
//}
//
//int main()
//{
//	cout << fun(10);
//	return 0;
//}


//Question 7

//int fun(int = 0, int = 0);
//
//int main()
//{
//	cout << fun(5);
//	return 0;
//}
//
//int fun(int x, int y) { return (x + y); }


// Question 8

//class A
//{
//public:
//	void show()
//	{
//		cout << "Hello from A \n";
//	}
//};
//
//class B : public virtual A
//{
//public:
//	void show()
//	{
//		cout << "Hello from B \n";
//	}
//};
//
//class C : public virtual A
//{
//};
//
//class D : public B, public C
//{
//};
//
//int main()
//{
//	D object;
//	object.show();
//}


// Question 9


//class AB
//{
//	//int a, b;
//public:
//	virtual void fn(){}; // size 12
//};
//
//class C : public AB
//{
//	//int c;
//public:
//	virtual void fn(){}; //size 8
//};

//int main() 
//{
//	cout << sizeof(C);
//}


//// Question 10
//class Base
//{
//public:
//	//virtual void Add() { cout << "Base Add"; }
//	virtual ~Base(){}
//};
//
//class Derived
//{
//public:
//	//virtual void Add1() { cout << "Derived Add"; }
//	virtual ~Derived(){}
//};
//
//class C12 
//{
//public:
//	virtual void MotherqMethod() {}
//};
//
//
//class Mother : public C12 {
//public:
//	virtual void MotherMethod() {}
//	//int mother_data;
//};
//
//class Father {
//public:
//	virtual void FatherMethod() {}
//	//int father_data;
//};
//
//class Child : public Mother, public Father, public C12 {
//public:
//	virtual void ChildMethod() {}
//	//int child_data;
//};

//int main()
//{
//	//Child obj;
//	//obj.Add();
//	//obj.Base::Add();
//	cout << sizeof(Child);
//}



// Question 12
//class Base
//{
//public:
//	virtual void show() { cout << " In Base n"; }
//};
//
//class Derived : public Base
//{
//public:
//	void show() { cout << "In Derived n"; }
//};
//
//int main(void)
//{
//	Base *bp = new Derived;
//	bp->show();
//
//	Base &br = *bp;
//	br.show();
//
//	return 0;
//}

//// Question 13
//class Base  
//{
//public:
//	Base()    { cout << "Constructor: Base" << endl; }
//	virtual ~Base()   { cout << "Destructor : Base" << endl; }
//};
//
//class Derived : public Base 
//{
//public:
//	Derived()   { cout << "Constructor: Derived" << endl; }
//	~Derived()  { cout << "Destructor : Derived" << endl; }
//};
//
//int main()
//{
//	Base *Var = new Derived();
//	delete Var;
//}


#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

//int main()
//{
//	int nServers;
//	cin >> nServers;
//
//	std::map<std::string, std::string> mapServers;
//	std::string strServerName;
//	std::string strIpAdd;
//
//	for (int i = 0; i < nServers; i++)
//	{
//		std::cin >> strServerName;
//		std::cin >> strIpAdd;
//		mapServers.emplace(strServerName, strIpAdd);
//	}
//
//	std::map<std::string, std::string>::iterator it;
//
//
//	int nNumofQueries;
//	cin >> nNumofQueries;
//	std::string strServer1;
//
//
//	for (int i = 0; i < nNumofQueries; i++)
//	{
//		std::cin >> strServer1;
//
//		it = mapServers.begin();
//		while (it != mapServers.end())
//		{
//			if (it->first == strServer1)
//			{
//				cout << it->second << "\n";
//			}
//
//			it++;
//		}
//	}
//
//	return 0;
//}

//int main(int argc, char *a[])
//{
//	int nNoElements;
//	cin >> nNoElements;
//
//	if (nNoElements < 2 || nNoElements > 1000)
//	{
//		return 0;
//	}
//
//	int *nElements = new int[nNoElements];
//	int nValue;
//
//	for (int i = 0; i < nNoElements; i++)
//	{
//		cin >> nValue;
//		nElements[i] = nValue;
//	}
//
//
//	for (int i = 0; i < nNoElements; i++)
//	{
//		for (int j = 0; j < (nNoElements - 1); j++)
//		{
//			if ( nElements[i] >  nElements[j] )
//			{
//				int temp = nElements[i];
//				nElements[i] = nElements[j];
//				nElements[j] = temp;
//			}
//		}
//	}
//
//	int nMaxdiff = nElements[0] - nElements[nNoElements - 1];
//	cout << nMaxdiff << endl;
//
//	delete[]nElements;
//	nElements = NULL;
//
//}

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//void main()
//{
//	vector<string> vect;
//	vect.push_back("abc");
//	vect.push_back("Test");
//	vect.erase(std::remove(vect.begin(), vect.end(), "xyz"), vect.end());
//}


//void main()
//{
//	int nElemnets;
//	cin >> nElemnets;
//
//	string strInput;
//	string *a = new string[nElemnets];
//
//	for (int i = 0; i < nElemnets; i++)
//	{
//		cin >> strInput;
//		a[i] = strInput;
//	}
//
//	string temp;
//	for (int i = 0; i < nElemnets - 1; i++)
//	{
//		for (int j = i + 1; j < (nElemnets); j++)
//		{
//			if (a[i] >  a[j])
//			{
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < nElemnets; i++)
//	{
//		cout << a[i];
//		if ( i != nElemnets -1 )
//			cout<< endl;
//	}
//
//	delete[]a;
//	a = NULL;
//}


//class Stack
//{
//private:
//	int nTop;
//	int nMax;
//
//public:
//	char nArry[1];
//	Stack(int max) { nTop = -1; nMax = max; }
//	void Push(char ch);
//	char Pop();
//	int GetMax() { return nMax; }
//};
//
//void Stack::Push(char ch)
//{
//	if (nTop == GetMax() - 1)
//	{
//		cout << "stack is full" << endl;
//	}
//	else
//	{
//		nArry[nTop] = ch;
//		nTop++;
//	}
//}
//
//char Stack::Pop()
//{
//	char ret = ' ';
//	if (nTop == -1)
//	{
//		cout << "stack is empty" << endl;
//		return ret;
//	}
//	else
//	{
//		nTop--;
//		ret = nArry[nTop];
//	}
//
//	return ret;
//}
//
//int main(int argc, char *a[])
//{
//	string strInput;
//	cin >> strInput;
//
//	int nLength = strInput.length();
//
//	Stack stack(nLength);
//
//	for (int i = 0; i < strInput.length(); i++)
//	{
//		stack.Push(strInput[i]);
//	}
//
//	for (int i = 0; i < strInput.length(); i++)
//	{
//		char c = stack.Pop();
//		cout << c;
//	}
//
//	return 0;
//}


using namespace std;

//class Stack
//{
//private:
//	int nTop;
//	int nMax;
//
//public:
//	int *nArry;
//
//	Stack(int max) { nTop = -1; nMax = max; nArry = new int[nMax]; }
//	void Push(int nNum);
//	int Pop();
//	int GetMax() { return nMax; }
//};
//
//void Stack::Push(int nNum)
//{
//	if (nTop == nMax - 1)
//	{
//		cout << "Stack is full";
//	}
//	else
//	{
//		nTop++;
//		nArry[nTop] = nNum;
//	}
//}
//
//
//int Stack::Pop()
//{
//	int n = -1;
//
//	if (nTop == -1)
//	{
//		cout << "Stack is empty";
//	}
//	else
//	{
//		n = nArry[nTop];
//		nTop--;
//	}
//
//	return n;
//}
//
//int GetLength(int nNumber)
//{
//	int nval = 0;
//	while (nNumber > 0)
//	{
//		nNumber = nNumber / 10;
//		nval++;
//	}
//
//	return 	nval;
//}
//
//int main(int argc, char *a[])
//{
//	int nElements;
//	cin >> nElements;
//	Stack s(nElements);
//
//	string str = std::to_string(nElements);
//	int nLength = GetLength(nElements);
//	int nval;
//	for (int i = 0; i < nLength; i++)
//	{
//		nval = str[i] - '0';
//		s.Push(nval);
//	}
//
//	int nOp;
//	for (int i = 0; i < nLength; i++)
//	{
//		nOp = s.Pop();
//		cout << nOp;
//	}
//
//	return 0;
//}
//

//
//int main(int argc, char *a[])
//{
//	int nNumber;
//	cin >> nNumber;
//	if (nNumber < 0 || nNumber > 1000)
//		return -1;
//
//	for (int i = 1; i < (nNumber + 1); i++)
//	{
//		for (int j = 1; j < (nNumber + 1); j++ )
//		{
//			cout << i << " ";
//		}
//
//		if (i != nNumber)
//			cout << endl;
//	}
//
//	return 0;
//}

using namespace std;


//int main(int argc, char *a[])
//{
//	int nNumbers;
//	cin >> nNumbers;
//
//	if (nNumbers < 2 || nNumbers > 1000)
//	{
//		return 0;
//	}
//	int *arr = new int[nNumbers];
//
//	int nValue = 0;
//	for (int i = 0; i < nNumbers; i++)
//	{
//		cin >> nValue;
//		arr[i] = nValue;
//	}
//
//	int temp;
//
//	for (int i = 0; i < nNumbers; i++)
//	{
//		for (int j = 0; j < nNumbers - 1; j++)
//		{
//			if (arr[j] > arr[i])
//			{
//				temp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = temp;
//			}
//
//		}
//	}
//
//	int nMaxdiff = arr[nNumbers - 1] - arr[0];
//	cout << nMaxdiff << endl;
//	
//	delete[]arr;
//	arr = NULL;
//
//	return 0;
//}



//int main()
//{
//	int y[] = new int[5];
//
//	int nNums;
//	cin >> nNums;
//
//	int *arry = new int[nNums];
//	int nValue = 0;
//	for (int i = 0; i < nNums; i++)
//	{
//		cin >> nValue;
//		arry[i] = nValue;
//	}
//
//	int nIndex = -1;
//	for (int i = 0; i < nNums; i++)
//	{
//		for (int j = 0; j < nNums - 1; j++)
//		{
//			if (arry[j] == arry[i])
//			{
//				nIndex = arry[i];
//			}
//		}
//	}
//	
//	cout << nIndex;
//
//	return 0;
//}


//using namespace std;
//#include <string>
//#include <algorithm>
//
//
//class Stack
//{
//private:
//	int nTop;
//	int nMax;
//	std::vector<string> vect;
//	vector<string> vDuplicate;
//	int m_nMax;
//
//public:
//	Stack(int nMax) { nTop = -1; m_nMax = nMax;}
//	void push(string str);
//	int GetTop() { return nTop; }
//	int GetMax() { return m_nMax; }
//	int GetSize() { return vect.size(); }
//
//	vector<string> GetDuplicate() {
//		return vDuplicate;}
//
//	vector<string> GetOriginal() {
//		return vect;
//	}
//};
//
//void Stack::push(string str)
//{
//	vector<string>::iterator it= vect.begin();
//
//	if (GetTop() == GetMax() - 1)
//	{
//		cout << "stack is full" ;
//	}
//	else
//	{
//		nTop++;
//		it = find(vect.begin(), vect.end(), str);
//		if ( it != vect.end() )
//		{
//			vDuplicate.push_back(str);
//		}
//		else
//		{
//			vect.push_back(str);
//		}
//	}
//}
//
//int main(int argc, char *a[])
//{
//	int nInputs;
//	cin >> nInputs;
//
//	string str;
//	vector<int> vect;
//
//	for (int i= 0; i < nInputs; i++)
//	{
//		int nStrings;
//		cin >> nStrings;
//
//		string *arry = new string[nStrings];
//		Stack s(nStrings);
//
//		int nRepeated = 0;
//		for (int i = 0; i < nStrings; i++)
//		{
//			cin >> str;
//			s.push(str);
//		}
//
//
//		vector<string> vOr;
//		vOr = s.GetOriginal();
//
//		vector<string> vDup;
//		vDup = s.GetDuplicate();
//
//
//		string str;
//
//		for (int i = 0; i < vOr.size(); i++)
//		{
//			for (int l = 0; l < vDup.size(); l++)
//			{
//				str = vDup[l];
//				vOr.erase(std::remove(vOr.begin(), vOr.end(), str), vOr.end());
//			}
//		}
//
//
//		int nOutput = vOr.size();
//		vect.push_back(nOutput);
//
//	}
//
//	for (int i = 0; i < vect.size(); i++)
//	{
//		cout << vect[i];
//		if (i != vect.size() - 1)
//			cout << endl;
//	}
//
//	return 0;
//}

//int main(int argc, char *a[])
//{
//	int n;
//	int t1 = 0, t2 = 1, nextTerm = 0;
//	cout << "Enter the number of terms: ";
//	cin >> n;
//	cout << "Fibonacci Series: ";
//	for (int i = 1; i <= n; ++i)
//	{
//		// Prints the first two terms.
//		if (i == 1)
//		{
//			cout << " " << t1;
//			continue;
//		}
//		if (i == 2)
//		{
//			cout << t2 << " ";
//			continue;
//		}
//
//		nextTerm = t1 + t2;
//		t1 = t2;
//		t2 = nextTerm;
//
//		cout << nextTerm << " ";
//	}
//
//	return 0;
//}

//
//void main()
//{
//	int nNum;
//	cin >> nNum;
//
//	int nOriginalNum = nNum;
//
//	int nRev = 0;
//	int nDigit = 0;
//	do
//	{
//		nDigit = nNum % 10;
//		nRev = (nRev * 10) + nDigit;
//		nNum = nNum / 10;
//	} while (nNum != 0);
//
//	int nReverseNumber = nRev;
//
//	cout << nOriginalNum << endl;
//	cout << nReverseNumber << endl;
//}

//using namespace std;
//
//int main(int argc, char *a[])
//{
//	int nNumbers;
//	cin >> nNumbers;
//
//	vector<int> vNumbers;
//	int nValue;
//
//	for (int i = 0; i < nNumbers; i++)
//	{
//		cin >> nValue;
//		vNumbers.push_back(nValue);
//	}
//
//	vector<int> vRange;
//	int nRange = 0;
//
//	for (int i = 0; i < 2; i++)
//	{
//		cin >> nRange;
//		vRange.push_back(nRange);
//	}
//
//	int nRange1 = vRange[0];
//	int nRange2 = vRange[1];
//
//	vNumbers.erase(vNumbers.begin() + nRange1 -1, vNumbers.begin() + nRange2);
//
//	cout << vNumbers.size();
//	for (int i = 0; i < vNumbers.size(); i++)
//	{
//		cout << vNumbers[i];
//	}
//}

//#include <algorithm>
//
//using namespace std;
//
//int main(int argc, char *a[])
//{
//	int nValues;
//	cin >> nValues;
//
//	vector <int> vect;
//	int nValue;
//	for (int i = 0; i < nValues; i++)
//	{
//		cin >> nValue;
//		vect.push_back(nValue);
//	}
//
//	std::sort(vect.begin(), vect.end());
//	std::reverse(vect.begin(), vect.end());
//
//	for (int i = 0; i < nValues; i++)
//	{
//		cout << vect[i];
//			
//		if (i != nValues - 1)
//			cout << " ";
//	}
//		
//
//	return 0;
//}



#include <vector>

//void main()
//{
//
//	//std::vector<int> vec{ 10, 20, 30, 30, 20, 10, 10, 20 };
//	//std::cout << "Original vector :";
//	//for (int i = 0; i < vec.size(); i++)
//	//	std::cout << " " << vec[i];
//	//std::cout << "\n";
//
//	//// Iterator that store the position of last element 
//	//std::vector<int>::iterator pend;
//
//	//// std :: remove function call 
//	//pend = std::remove(vec.begin(), vec.end(), 20);
//
//	//// Print the vector after std :: remove 
//	//std::cout << "Range contains:";
//	//for (std::vector<int>::iterator p = vec.begin(); p != pend; ++p)
//	//	std::cout << ' ' << *p; std::cout << '\n';
//
//
//	//struct data
//	//{
//	//	data() {}
//	//	data(int n1, int n2, int n3) {}
//
//
//
//	//} sData;
//
//	//vector<data> vect1;
//
//	//data sData(10, 20, 30);
//	//vect1.push_back(1, 2, 3);
//
//	//vect1.emplace_back(1, 2, 3);
//
//	
//	/*vector<vector<int>> Test;
//
//	vector<any_of> vect;
//
//	vect.push_back(1);
//	vect.push_back(2);
//	vect.push_back(3);
//	vect.push_back(4);
//	vect.push_back(5);
//
//	Test.push_back(vect);*/
//
//	/*for (int i = 0; i < vect.size(); i++)
//	{
//		cout << vect[i] << " " << endl;;
//	}
//
//	cout << vect.capacity() << endl;
//
//	vect.erase(vect.begin(), vect.begin()+ 2);
//
//	cout << vect.capacity()<<endl;*/
//
//	//vector<int>::iterator it = (vect.begin() + 2);
//	//vect.erase(it);
//
//	//std::remove(vect.begin(), vect.end(), 1);
//
//	////vect.erase(std::remove(vect.begin(), vect.end(), 2), vect.end());
//	////vect.erase(vect.begin() , vect.begin() + 2);
//
//	//cout << endl;
//	//cout << vect.size();
//
//	//for (int i = 0; i < vect.size(); i++)
//	//{
//	//	cout << vect[i] << " ";
//	//}
//}




