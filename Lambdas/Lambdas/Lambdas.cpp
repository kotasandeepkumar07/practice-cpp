// Lambdas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


/*************************************  Basic Definition  ************************************/
/*
Fundamental Definition  : A lambda is an expression  that returns a function object 

Expression is something which returns a value for example :
	5+2 is an expression as it returns value 7 
	"int i" is not an expression as it does not return a value
	Lambda is an expression as it returns a  function object 

*/


/*************************************  Function pointer  ************************************/
/*
Function pointer
	It is a data type whose value points to a particular function
	Like regular pointers, function pointers do not point to data so it can't be dereferenced

Example:
	void (*myprocess)(int);
	myprocess = std::exit;

	myprocess(42); //here it looks as if myprocess is a function but its a function pointer 

	myprocess is a function pointer. 
	Now our function pointer can be used to point to any function which takes a single integer and returns void

Operator overloading
	Any method which starts with operator followed by a symbol are called operator overload operators
	Example : operator+(const T& obj)

Function call operators
	Any method with the exact name "operator()" is called function call operator
	Example :	void operator()()
				bool operator()(int i)
				double operator()(int i, int j)

/*



/*************************************  Function Object  ************************************/
/*

Function object data type
	A class or a struct with a function call operator method. (A class which implements operator())

Function Object
	An instance of the function object data type. (Simply the object of the class that defines operator())
	Its a callable object
	It can recieve parameters
	It can have return types
	Its called similar to normal functions

When we call a function object, this means that we are invoking the function call operator ( operator()  )


Example:

class Ginger
{
	void operator()(std::string strName);
};

void main()
{
	Ginger ginger;
	ginger.operator()("hello");

	ginger("hello"); //this call goes to operator() inside the Ginger class, it looks like if ginger is a function 
}

There is no term functor in standard c++. When they use functor it means they are referring to function object or function object data type

Functor -> its nothing but function object 
Function pointer -> pointer which refers to function rather than pointing to data 
Function object data type -> A class or a struct with a function call operator method. (A class which implements operator())
Function object -> An instance of the function object data type. (Simply the object of the class that defines operator())
std::function -> Added in C++ 11, container, holds a single function pointer or a function object 
*/




/************************************************  lambda Syntax  **************************************************************/
/*

A lambda expression is a syntactic shortcut for a functor, so you can use lambda expressions to replace functors

syntax :  [ captures ] (parameters) -> returnTypesDeclaration { lambdaStatements; }

[ captures ]: 
	a. The capture clause, also known as the lambda introducer, 
	specifies which outside variables are available for the lambda function 
	and whether they should be captured by value (copying) or by reference
	b. They can be empty 

( parameters ): 
	This is the optional parameters list, also known as the lambda declarator. 
	You can omit the parameters list if you want a function that takes zero arguments

-> returnTypeDeclaration: 
	This is the return type. Most of the time, compilers can deduce the return type of the 
	lambda expression when you have zero or one return statement.

{ lambdaStatements; }: This is the lambda body. 
	The statements within the lambda body can access the captured variables and the parameters


				[ capture clause ] (parameters) -> return-type
				{
					definition of method
				}

Example:

	int main()
	{
		int x = 42;
		auto mylambda = [x] () {  cout << x << endl;}
	}


Few more details
	auto mylamb = [] () { return 17; }

Everything on the right of the = symbol is part of lambda expression
Expression is first evaluated and then mylamb is initialized

A "closure" is simply a function object which is returned from evaluation of Lambda expression
mylamb contains closure 

*/





/*************************************  Capture Clause  ************************************/
/*

int main()
{
	int x;
	auto mylamb = [x] () mutable { return ++x; }
}

By Value:
	1. Capture is by const value
	2. only variable on the local scope or "this" can be captured
	3. X in the above code is captured by value, so even if goes out of scope by the time lambda uses there is no problem
	4. mutable keyword is needed just before the body, if we are about to modify any captured variable as they are passed as const value and can't be modified directly
	5. We can have any number of variables in the capture list  
	6. we can use the follwing syntax to capture all values by value 
		auto mylamb = [=] () mutable { return ++x; }


int main()
{
	int x;
	auto mylamb = [&x] () mutable { return ++x; }
}

By reference:
	1. an & indicates that x is captured by reference as in the above example.
	2. we cant have an r-value reference, we can only have l-value reference
	3. X in the above code is captured by reference, so if  x goes out of scope by the time lambda uses then its a big problem
	4. we can use the follwing syntax to capture all values by reference
		auto mylamb = [&] ()  { return ++x; }
	

Generalized capture:It was introduced in c++ 14
	
	capture is initialized by value 
		[vara = 10]
		[varb =x]

	capture is initialized by reference
		[&varc = y] //here y must be delcared in the local scope

	capture is initialized by move
		[varD = std::move(z)]  //move occurs when lambda expression is evaluated
*/


/*************************************  Capture Clause for classes ************************************/
/*
	C++11
		[this]
		captures this pointer by value
		Here if we modify  member variable of class using this - It will be updated 
		default capture of this pointer by value has been deprecated starting c++20

	C++14
		[self = *this] //generalized capture
		captures this pointer by value, intializes a new variable
		Here if we modify  member variable of class using self - It will be just a copy and original value remains same

	C++17
		[*this]
		captures *this object by value

*/

/*************************************  Parameter list ************************************/
/*
	C++11:
		Default parameters were not allowed

	C++14:
		parameters can have a data type of auto
		Default parameters are supported

*/

/*************************************  Return type deduction ************************************/
/*
C++11:
	If there is more than one return type then we must specify the return type

C++14:
	If there is more than one return statement they must deduce to same data type or it must be specified
	In the follwing example, either double or int is returned based on the condititon. In this case it is mandatory to mention the
	return type. If we give it as double then int will also be converted to double
	If the both are int or both are double then, its not necessary to have return type

	auto mylamb = [] (bool bvalue) -> double 
	{ 
		if(bvalue) return 3;
		else return 3.5;
	}
 */


 /*************************************  C++20 syntax  ************************************/
 /*

	[capture clause] <template parameters> (parameter list) specifier exception attribute -> return type requires { body }
 
 template parameters: Added in C++20
	//both are same
	(auto && . . . args)
	<typename . . . Ts>(Ts && . . . args)

specifier:
	mutable (C++11)
	constexpr (c++17)
	conteval (c++20)

exception:
	noexcept

attribute:
	functions can have attributes before the return type like 
		nodiscard, deprecated, noreturn (but this feature is not availbe for lambdas yet)

requires:
	used to add a contraint on body
	example : requires std::copyable<T>

 */


#include <vector>
#include <algorithm>
#include <map>
 /*************************************  Difference between function pointer and  lambda ************************************/
 /*
 
 Example 1:

//return the count of numbers greater than 5 in the vector
std::vector<int> vec{ 1,5,8,9,2 };

//using function pointer
bool MyCount(int i)
{
	return i > 5;
}
int countA  = std::count_if(vec.begin(), vec.end(), &MyCount);

//using lambda 
int countB = std::count_if(vec.begin(), vec.end(), [](int i) { return i > 5; });

Example 2:

//uisng lambda - This would not have been possible with function pointers because passing ch is difficult 
				where as its easy with lambda with help of capture clause
int count_string_starting_with_given_char(std::vector<std::string> &data, char ch)
{
	return std::count_if(data.begin(), data.end(), [ch](const std::string& str) {
		str[0] == ch; });
}



// without using lambda expression 
class mycompare
{
public:
	bool operator()(std::string str1, std::string str2) const
	{
		return str1 > str2;
	}
};

//using lambda expression
auto mylamb = []( std::string& str1,  std::string& str2) {return str1 > str2; };


void main()
{
	//without using lambda
	//std::map<std::string, int, mycompare> myMap;

	//using lambda
	std::map<std::string, int, decltype(mylamb)> myMap;

	myMap.insert({ "Sandeep", 32 });
	myMap.insert({ "Ravali", 31 });

	for (auto i : myMap)
		std::cout << i.first << "   "<< i.second << std::endl;
}

*/
