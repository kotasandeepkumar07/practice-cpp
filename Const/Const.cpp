// Const.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>

using namespace std;
/*
class Test
{
public:
void add(const int i) const ;

};

void Test::add(const int k) const
{
cout<<k<<endl;
}


void main()
{
Test obj;
obj.add(5);

}
*/

/*
 const objects can only call const APIs and cant call normal APIs
 Normal objects  can call both normal and const APIs
*/


//class Base
//{
//public:
//	 int m_i;
//
//	Base() :m_i(4){}
//
//public:
//	void Test()
//	{
//
//	}
//	void func() const
//	{
//
//	}
//};
//
//void main()
//{
//	const Base obj;
//	obj.Test(); //error
//	obj.func();
//
//	Base obj1;
//	obj1.func();
//	obj1.Test();
//
//	obj.m_i;
//
//}

//#include "StdAfx.h"
//#include <iostream>

//using namespace std;
//class Test
//{
//public:
//	int add();
//
//	Test(int a, int b)
//	{
//		m_i = a;
//		m_j = b;
//	}
//
//private:
//	int m_i, m_j;
//
//};
//
//int Test::add()
//{
//	static int nval = m_i + m_j ;
//
//	return nval;
//}
//
//
//void main()
//{
//	Test obj(4, 6); 
//	int a = obj.add();
//
//	Test obj2(1, 5);
//	int b =  obj2.add();
//
//	cout << a << b << endl;
//
//}
//
//



//const vs constexpr

//1
//void main()
//{
//	int i = 5;
//	const int  j = 10;
//	
//
//	//Compile time constant
//	constexpr float pi = 3.14;
//
//
//	//Run time constant 
//	int nval;
//	cin >> nval;
//	const int k = nval;
//}


//
//constexpr int func_constexpr(int X, int Y)
//{
//	return(X*Y);
//}
//
//int func(int X, int Y)
//{
//	return(X*Y);
//}	
//
//
//void main()
//{
//	int array1[func_constexpr(10, 20)]; // OK - func_constexpr() can be evaluated at compile time.
//	int array2[func(10, 20)]; // ERROR - func() is not a constexpr function.
//}




/******************* NULL vs nullptr ******************************/

//using namespace std;
//
//void  fun(int N) 
//{ 
//	cout << "fun(int)";
//}
//
//void fun(char* s) 
//{ 
//	cout << "fun(char *)"; 
//}
//
//int main()
//{
//	fun(NULL);
//
//	//int x = NULL;
//
//	return 0;
//}

/************************************** Assert vs Static Assert **************************************/



//#include <cassert>
//void main()
//{
//	int n = sizeof(long); //4 bytes
//
//	assert(sizeof(long) == 8);
//	static_assert(sizeof(long) == 8, "long must be 8 bytes");
//
//}




//template <class T, int Size>
//class Vector 
//{
//	// Compile time assertion to check if 
//	// the size of the vector is greater than 
//	// 3 or not. If any vector is declared whose 
//	// size is less than 4, the assertion will fail 
//	static_assert(Size > 3, "Vector size is too small!");
//
//	T m_values[Size];
//};
//
//int main()
//{
//	Vector<int, 4> four; // This will work 
//	Vector<short, 2> two; // This will fail 
//
//	return 0;
//}





//void main()
//{
//	//Compile time constant
//	constexpr float pi = 3.14;
//
//	//Run time constant 
//	int value;
//	cin >> value;
//	const int k = value;
//
//
//	constexpr Test obj(40);
//	static_assert(obj.getvalue(), "10");
//}
//
//
//
//
//class Test
//{
//private:
//	 int m_ID{};
//public:
//	constexpr Test(int id) : m_ID(10)
//	{
//		
//	}
//	constexpr int getvalue() const { return m_ID; }
//	
//};



#include <cassert>
#include <iostream>

using namespace std;

struct Box
{
    double width{ 0.0 };
    double height{ 0.0 };
    double length{ 0.0 };
};

struct Product
{
    virtual ~Product() = default;

    virtual Box getBox() const noexcept = 0;
};

struct Notebook : public Product
{
    Box getBox() const noexcept override
	{
        return { .width = 30.0, .height = 2.0, .length = 30.0 };
    }
};

struct Flower : public Product
{
    Box getBox() const noexcept override
	{
        return { .width = 10.0, .height = 20.0, .length = 10.0 };
    }
};

bool canFit(const Product& prod, const Box& minBox)
{
    const auto box = prod.getBox();
    return box.width < minBox.width&& box.height < minBox.height&&
        box.length < minBox.length;
}

int main() {
    Notebook nb;
    Box minBox{ 100.0, 100.0, 100.0 };
    assert(canFit(nb, minBox));
}