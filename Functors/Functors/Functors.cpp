// Functors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>


using namespace std;





//Example 1
//  We can use the follwing "increment" function to increase the value of each elemt in array by 1
// increment is a unary function and it can take only one argument, So if we want each element in array by 2 then 
// we need change the value of 1 to 2 in the follwing example or write a new overloaded function 
// so writing a new function for every new requirement is a problem and hence functors can come very handy here 

//int increment(int x) { return x + 1; }
//void main()
//{
//	int arr[5] = { 1, 2, 4, 5, 6 };
//	int nElements = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < nElements; i++)
//	{
//		std::transform(arr, arr + nElements, arr, increment);
//
//		for (int i = 0; i < nElements; i++)
//			cout << arr[i] << " ";
//	}
//}

/*
	A functor(or function object) is a C++ class that acts like a function
	Functors are most commonly used along with STLs
	Functors are called using the same old function call syntax.
	To create a functor, we create a object that overloads the operator().

	The line,
		MyFunctor(10);

	Is same as
		MyFunctor.operator()(10);

The line, transform(arr, arr+n, arr, increment(to_add)); is the same as writing below two lines,

	// Creating object of increment
		increment obj(to_add);

	// Calling () on object
		transform(arr, arr+n, arr, obj);


*/


class increment  //it is c++ class that acts like a function -> so basically increment is a functor here 
{
private:
	int m_nVal;

public:
	increment(int nValue) 
	{ 
		(m_nVal = nValue); 
	}
	int operator () (int arrValue)  //we overload operator () so that it can be called just like a function
	{
		return arrValue = arrValue + m_nVal;
	}
};

class inc
{
private:
	int val;
public:
	inc(int i) { val = i; }

	int operator () (int incval)
	{
		return val + incval;
	}
};


//
//
//void main()
//{
//	int arr[5] = { 1, 2, 4, 5, 6 };
//	int nElements = sizeof(arr) / sizeof(arr[0]);
//	int nvaluetoAdd = 5;
//
//	for (int i = 0; i < nElements; i++)
//	{
//		std::transform(arr, arr + nElements, arr, increment(5));
//
//		for (int i = 0; i < nElements; i++)
//			cout << arr[i] << " ";
//	}
//
//	increment(10);
//}


//Detail info on functors and callbacks
//https://stackoverflow.com/questions/2298242/callback-functions-in-c



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Print 
{
public:
	void operator()(int elem) const 
	{
		cout << elem << " ";
	}
};

int main() 
{
	std::vector<int> vect;
	for (int i = 1; i < 10; ++i) 
	{
		vect.push_back(i);
	}

	Print print_it;
	std::for_each(vect.begin(), vect.end(), print_it);
	cout << endl;
	return 0;
}

//template<class InputIterator, class Function>
//Function for_each(InputIterator first, InputIterator last, Function fn)
//{
//	while (first != last) {
//		fn(*first);
//		++first;
//	}
//	return fn;      // or, since C++11: return move(fn);
//}
//
