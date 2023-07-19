// Inline.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



//for more info  //https://www.geeksforgeeks.org/difference-between-inline-and-macro-in-c/?ref=rp


//Prefer inline function when a developer feels that calling a function takes more time than executing it such as simply print statments 
//All the functions inside a class are inline be default

/*Inline functions provide following advantages :

1) Function call overhead doesn’t occur.
2) It also saves the overhead of push / pop variables on the stack when function is called.
3) It also saves overhead of a return call from a function.
4) When you inline a function, you may enable compiler to perform context specific optimization on the body of function.Such optimizations are not possible for normal function calls.Other optimizations can be obtained by considering the flows of calling context and the called context.
5) Inline function may be useful(if it is small) for embedded systems because inline can yield less code than the function call preamble and return.

Inline function disadvantages :
1) The added variables from the inlined function consumes additional registers, After in - lining function if variables number 
		which are going to use register increases than they may create overhead on register variable resource utilization.
		This means that when inline function body is substituted at the point of function call, 
		total number of variables used by the function also gets inserted.So the number of register going to be used for the variables will also get increased.
		So if after function inlining variable numbers increase drastically then it would surely cause an overhead on register utilization.
2) If you use too many inline functions then the size of the binary executable file will be large, because of the duplication of same code.
3) Too much inlining can also reduce your instruction cache hit rate, thus reducing the speed of instruction fetch from that of cache memory to that of primary memory.
4) Inline function may increase compile time overhead if someone changes the code inside the inline function then all the calling location has to be recompiled
	because compiler would require to replace all the code once again to reflect the changes, otherwise it will continue with old functionality.
5) Inline functions may not be useful for many embedded systems.Because in embedded systems code size is more important than speed.
6) Inline functions might cause thrashing because inlining might increase size of the binary executable file.Thrashing in memory causes performance of computer to degrade.*/

//***************************************** Macro vs inline ******************************************************//
/*
#define  add(a,b) a+b  //macro


inline int add(int a, int b)   //inline function
{
	return a+b;
}

void main(int argc, char* argv[])
{	
	cout<<add(4,5)<<endl;
	cout<<add(10,20)<<endl;
}

*/
/*
void main(int argc, char* argv[])
{

	int i, j;
	bool flag = true;
	if(flag)
	cout<<add(i,j)<<endl;
}
*/


//****************************************  Advantage with inline over macro **********************************************//

// In the Below Example the expected output is 16( 4*4) which we can get on using a inline function.
// when we use a macro the result is 25(5*5) which is not desired output. 
// Note : We can't debug a macro to see what is happening

//C++ compiler checks the argument types of inline functions and necessary conversions are performed correctly.
//Preprocessor macro is not capable for doing this.One other thing is that the macros are managed by preprocessor and 
//inline functions are managed by C++ compiler

 #define DOUBLE(X) X*X 


inline int Doublethevalue(int x) 
{
	return x*x;
};



void main()
{
	int y = 3;
	int j = DOUBLE(++y);	
	cout<<j<<endl;
}

