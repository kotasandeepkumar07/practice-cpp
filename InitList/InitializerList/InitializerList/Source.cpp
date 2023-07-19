#include <iostream>
using namespace std;

//////////////////////////////////////////////

// Syntax Example

//////////////////////////////////////////////

//class Base
//{
//private:
//	int value;
//public:
//	Base(int value) :value(value)
//	{
//		cout << "Value is " << value;
//	}
//};
//
//int main()
//{
//	Base il(10);
//	getchar();
//}



//////////////////////////////////////////////

// Error

//////////////////////////////////////////////



//class Base
//{
//public:
//	// parameterized constructor
//	Base(int x)
//	{
//		cout << "Base Class Constructor. Value is: " << x << endl;
//	}
//};
//
//class Derived :public Base
//{
//public:
//	// default constructor
//	Derived()
//	{
//		Base b(10);
//		cout << "Derived class' Constructor" << endl;
//	}
//};
//
//int main()
//{
//	Derived object_derived;
//	getchar();
//}


//////////////////////////////////////////////

// Corrected

//////////////////////////////////////////////


//class Base
//{
//public:
//	// parameterized constructor
//	Base(int x)
//	{
//		cout << "Base Class Constructor. Value is: " << x << endl;
//	}
//};
//
//class Derived :public Base
//{
//public:
//	// default constructor using initializer list
//	Derived() :Base(10)
//	{
//		cout << "Derived class' Constructor" << endl;
//	}
//};
//
//int main()
//{
//	Derived iobject;
//	getchar();
//}

