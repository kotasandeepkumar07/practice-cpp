// Type casting is required when the variable to which we are assigning values is of different
// data type from the data type from which we are retrieving the value



//https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast

/************************************************   Implicit Conversion ********************************************************/

// conversion that happens between the standard data types such as 
// int to float, float to double etc , 
// how ever there are certain issues while converting from float to int, double to int etc and this is shown by compiler as warning


#include "stdafx.h"
#include <iostream>

using namespace std;


//void main()
//{
//	int a = 4;
//	float b = 9.56;
//	double c = 5.66766;
//
//	int val = (int)b; //warning C4244: 'initializing' : conversion from 'float' to 'int', possible loss of data
//}


/************************************************   Explicit Conversion ********************************************************/
//  the Explicit type casting will convert pointer of any type to another type and which might some times lead to 
//  run-time error or a unexpected result.

//
//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//class CDummy 
//{
//   
//};
//
//class CAddition 
//{
//	int x,y;
//public:
//	CAddition (int a = 9, int b = 8) { x=a; y=b; }
//	int result() { return x+y;}
//};
//
//void  main () 
//{
//	CDummy d;
//	CAddition * padd;
//	padd = (CAddition*) &d;
//	int k = padd->result();
//	cout << k;
//}



/************************************************  dynamic_cast *********************************************************/

// Unlike implicit casting, the explicit casting will look for proper conversions, 
// dynamic_cast is used in case of pointers and reference objects only.
// Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested class.

// syntax "dynamic_cast <type-id>(expression)"  
//The type-id must be a pointer or a reference to a previously defined class type or a "pointer to void
//The expression must be a pointer if type-id is a pointer, or an l-value if type-id is a reference.



#include "stdafx.h"
#include <iostream>

using namespace std;
//
//class Base 
//{ 
//public:
//  virtual void dummy() {} 
//};
//
//
//class Derived /*: public Base*/
//{
//
//};
//
//void main()
//{
//	Base b1;
//	Derived d1;
//
//	
//	Derived* d2 = dynamic_cast<Derived *>(&b1);		 // DownCasting -- This is danegerous
//													// Typecasting a base class pointer b1 to  derived type 
//													//This is caught by dynamic cast
//												
//	
//	Base *b2 = dynamic_cast<Base*>(&d1);        //UpCasting -- This is safe
//												//Typecasting a derived class pointer d1 to base class 
//}



/************************************************  static_cast  *************************************************************/

// In general a Derived class pointer can be casted to a Base class but not vice versa, This can be possible using static_cast
// static_cast can also be used to perform conversions explicitly defined in classes, as well as to perform standard conversions between fundamental types (implicit casts)
// static_cast conversions are not as safe because static_cast does no run-time type check


// Basics of static_cast

//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//class Base 
//{ 
//public:
//	void Add() { }
//	void TakeObject(Base &obj);
//
//};
//class Derived : public Base
//{
//	
//};
//
//
//void Base::TakeObject(Base &obj)
//{
//	obj.
//
//}
//
//
//
//void main()
//{
//	Base	*b1 = NULL;
//	Derived *d1 = NULL;
//	
//	Derived* d2 = static_cast<Derived *>(b1);		// Down Casting -- This is dangerous
//													// Typecasting a base class pointer b1 to  derived type 
//													// In fact this should be an exception which is not caught by static_cast 	
//
//	Base* b2 = static_cast<Base *>(d1);				//UpCasting -- This is safe
//	d2->TakeObject(*b2);							//Typecasting a derived class pointer d1 to base class
//
//	//char ch; int a = 56;   // Typecasting an integer to character
//	//ch = (char)a;
//	//cout<<ch<<endl;
//} 


//#include <iostream> 
//using namespace std;
//class Base 
//{
//};
//class Derived : private Base { // Inherited private/protected not public 
//};
//int main()
//{
//	Derived d1;
//	Base* b1 = (Base*)(&d1); // allowed which actually should give error 
//	Base* b2 = static_cast<Base*>(&d1); // static_cast cathces this 
//	return 0;
//}


/************************************************  const_cast  *************************************************************/
// This type of casting manipulates the constness of an object, either to be set or to be removed

// 1. To change the const parameter. In the below example we are removing the constness of the char c and passing to print function.


//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//void print (char * str)
//{
//    *str = 'd';
//    cout << *str << endl;
//}
// 
//void main()
//{
//	const char c = 's';
//
//	//print(&c); 
//    print(const_cast<char*>(&c)); // it prints d and s in the output.
//
//	//print(&c);// the output without typecasting is d and d
//    cout << c << endl; // it prints d in the output	
//}





// 2. To change the value inside a const function . which is not possible without typecasting.
#include "stdafx.h"
#include <iostream>

using namespace std;

//class Base 
//{
//public:
//	void setNumber( int num ) {number = num;};
//	void printNumber() const;
//private:
//   int number;
//};
//
//void Base::printNumber() const 
//{
//	cout <<"value of number before is"<< number<<endl;
//
//	// trying to modify the value of num inside the const function 
//	//( this )->number--; //error l-value specifies const object
//
//
//	//the value can be changed by typecasting using const_cast which removes the constness of the function
//	//output is 8 and 7
//	const_cast< Base *>(this)->number--;
//	cout<<"value of number after is"<< number<<endl;
//}
//
//void main() 
//{
//	Base X;
//	X.setNumber( 8 );
//	X.printNumber();
//}




/************************************************  reinterpret_cast   *************************************************************/

//The reinterpret_cast operator can be used for conversions such as char* to int*, or One_class* to Unrelated_class*, which are inherently unsafe.
//The result of a reinterpret_cast cannot safely be used for anything other than being cast back to its original type.
//The reinterpret_cast operator converts a null pointer value to the null pointer value of the destination type
// reinterpret_cast preserves the bit pattern after conversion while static_cast doesn't


//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//#include "malloc.h"
//
//
//class A {};
//class B {};
//
//
//void main()
//{
//	A * a = new A;
//	B * b = reinterpret_cast<B*>(a); // this should ideally throw a compile error because the two classes are not at all related
//}



//*************************************  typeid ****************************************************//

// The typeid operator allows the type of an object to be determined at run time.

//#include "stdafx.h"
//#include <iostream>
//#include "typeinfo.h"
//
//using namespace std;
//
//
//class A
//{
//public:
//	virtual void call() {}
//
//};
//
//class B: public A
//{
//public:
//
//};
//
//
//void main()
//{
//	int *p;
//	A obj;
//	cout<<typeid(obj).name()<<endl; //output: class A
//
//	cout<<typeid(p).name()<<endl;//   output: int *
//	cout<<typeid(*p).name()<<endl;//   output: int 
//
//	A *t = new B;
//
//	cout<<typeid(t).name()<<endl;
//}


/*
static cast

1. it is almost same as implicit cast (basic casting operations)
2. can do both upcasting (converting derived to base --implicit cast) and down casting(converting from base to derived--need a special conversion)
3. it is done at compile time and no run time check exists.
4. not safe
5. It can only be performed of the class are linked (inheritance)


Dynamic cast

1. It has runtime check on the objects it is casting.
2. it returns null if there is no proper object type
3. it cast only be done if the object(that is to be converted is of polymorphic class --need to have virtual functions)

*/
//
//#include <iostream> 
//using namespace std;
//int main()
//{
//	float f = 3.5;
//
//	// using cast operator 
//	int b = static_cast<int>(f);
//
//	cout << b;
//}
//
//
//#include <iostream> 
//using namespace std;
//
//int main()
//{
//	double x = 1.2;
//
//	// Explicit conversion from double to int 
//	int sum = (int)x + 1;
//
//	cout << "Sum = " << sum;
//
//	return 0;
//}