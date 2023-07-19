// Ellipsis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdarg>



//Introduction 
/*
1. we know the number of parameters a function will take must be known in advance but 
2. C++ provides a special specifier known as ellipsis (aka “…”) that allow us to pass variable number of arguments to any function
3. Syntax:  return_type function_name(argument_list, ...)
4. Functions like Printf, Scanf uses ellipsis inside of them 

Rules:
	a. Functions that use ellipsis must have at least one non-ellipsis parameter.
	b. Any arguments passed to the function must match the argument_list parameters first 
	c. The ellipsis (which are represented as three periods in a row) must always be the last parameter in the function
	d. Think it like an array that holds any additional parameters 
	e. we should include <cstdarg> to use ellipsis 
*/

//
//double findAverage(int count, ...)
//{
//	double sum = 0;
//
//	// We access the ellipsis through a va_list, so let's declare one
//	va_list list;
//
//	// We initialize the va_list using va_start.  The first parameter is
//	// the list to initialize.  The second parameter is the last non-ellipsis
//	// parameter.
//	va_start(list, count);
//
//	// Loop through all the ellipsis arguments
//	for (int arg = 0; arg < count; ++arg)
//		// We use va_arg to get parameters out of our ellipsis
//		// The first parameter is the va_list we're using
//		// The second parameter is the type of the parameter
//		sum += va_arg(list, int);
//
//	// Cleanup the va_list when we're done.
//	va_end(list);
//
//	return sum / count;
//}





void add(int a, int b)
{

	std::cout << "Normal Function";
}


void add(int a, ...)
{
	std::cout << "ellipsis";
}



int main()
{
	//std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
	//std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';

//Reasons why Ellipsis are dangerous

	// They avoid type checking 
	//std::cout << findAverage(6, 1, 2.5, 3, 4, 5, 6) << '\n'; //returns grabage ?? because it avoids type 
	//checking and when we retrieve value using va_arg in the above function, 
	//it tries to retrieve only fisrt 4 bytes and hence the result is garbage


	//This also returns grabage, because we passed only 4 arguments and the rest 2 arguments are garbage from stack 
	//std::cout << findAverage(6, 1, 2, 3, 4) << '\n';

	add(2, 2.6);
}

// To know more 
// https://www.learncpp.com/cpp-tutorial/714-ellipsis-and-why-to-avoid-them/

