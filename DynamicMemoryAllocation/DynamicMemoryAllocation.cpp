// DynamicMemoryAllocation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include "malloc.h"
#include "string.h"

//Dynamic memory allocation is the practice of assigning memory locations to variables
// during execution of the program by explicit request of the programmer

//All the Dynamic memory allocations go to heap and they have to be freed by the user, 
//otherwise memory cant be occupied by other variables



//***************************************  Malloc:  ******************************************//


//  1) It takes only one parameter that is the size of memory that is to be allocated dynamically 
//	2) It returns void pointer, so it is to be casted to type of the pointer that we are assigning it to 
//	3) when used this function, the pointer points to garbage values initially.
//	4) Memory allocated should be freed after the task is been done , 
	  //otherwise it cant be accessed for any other purpose and goes waste
//	5) delete can be used along with malloc, though it dosent give any compilation error it cant be used (results in undefined behaviour)

// 6) On failure, malloc() returns NULL where as new throws bad_alloc exception.

//7)malloc() allows to change the size of buffer using realloc() while new doesn’t

/*
void main(int argc, char* argv[])
{
	int *p = (int *) malloc(10* sizeof(int));
	cout<<*p<<endl;
	free(p);
}
*/

//************************* creating class object using malloc instead of new ****************************//

/*
class Base
{

public:

	Base() {cout<<"constructor called"<<endl;}
};

void main()
{
	Base *obj = (Base *)malloc(sizeof(Base)); //the constructor is not called by default, should be called explicitly
	Base(); //calling constructor
	obj->~Base(); //calling destructor
}
*/




// ************************************** calloc: ************************************************************************/

//  1) It takes two parameters the first is number of elements  and the second is size of element
//	2) It returns void pointer, so it is to be casted to type of the pointer that we are assigning it to 
//	3) When used this function  the pointer by default is initialized to  zeros 

/*

void main(int argc, char* argv[])
{
	int a = 10;
	int *p = (int *) calloc(10, 10* sizeof(int));//here 10 blocks of memory is allocated,where each block has size of 10* sizeof(int)
	free(p);
}

*/


//************************************************  realloc: **********************************************************************/


// 1) It is used to reallocate the memory allocated before . 

/*
int main()
{
	char *str;
	
	// Initial memory allocation 
	str = (char *) malloc(7);
	strcpy(str, "Sandeep");
	cout<<"string is   "<<str<<"        Address is      "<<&str<<endl	;


	// Reallocating memory 
	str = (char *) realloc(str, 1);
//	strcat(str, "kota");
	cout<<"string is   "<<str<<"    Address is      "<<&str<<endl	;
	
	free(str);
	
	return(0);
}
*/



//************************************  C++ style of dynamic allocation    ******************************************************

// In c++ , the dynamic memory allocation is done using the key word "new" and memory is deleted using the keyword "delete"
// we use a pointer to allocate the memory dynamically because the, 
// memory is not known as it is created on the heap(which is not a sequential storage)contains 
// Hence pointer contains the address of the memory allocated

/*
void main()
{

	int * p = new int; //memory is dynamically allocated to an integer
	*p  = 10 ; //storing a value 10 to allocated location
	delete p; // it deletes the memory allocated by p;
	cout<<*p<<endl;
	p = 0;    // on using delete the memory is freed, but still the pointer is pointing to some other location, hence it is good practice to assign to zero


// for an array of unknown size

	int *ptr = new int[10]; // here the integer array of size 10 is allocated(the value 10 can be passed dynamically from user input)
	delete[] ptr ; // delete syntax for pointer pointing to array.
	ptr = 0; 
}

*/



/******************************************    Memory leaks  *********************************************************************/

// The reasons for memory leaks is, 

// 1. If a pointer is used for allocating memory dynamically and
//	  if it is not deleted using 'delete' command, the pointer dies, once the function(in which we declared function)
//	  ends and the memory is still existing, the address of which is not known. This causes memory leaks

/*
void main()
{
	int *p = new int;
}
*/


// 2. When the pointer pointing a dynamically allocated memory is replaced with the other variable,
//    the pointer now points to new memory and the old memory is not pointed and its address cant be found.

/*
void main()
{
	int i = 20;

	int *p = new int;  // memory is allocated dynamically
	*p = 10;		   // value 10 is stored in that location
	cout<<*p<<endl;	   // it prints 10
	

	p = &i;         // p is pointing to adress of i
	cout<<*p<<endl; // it prints 20 i.e. the p is now pointing towards 'i' and it has lost address to old memory whose address is not known 

}
*/


