// Strucutres.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"




//******************************************  Declaration *******************************************************************//

//	Structure is user defined data type which encapsulates all the data types together.
//	A structure should end with a semicolon similar to class
//	myStruct is the name of the structure, it is not compulsory to have the name for a structure
//  we can't initialize the values to the member variable inside a structure declaration.

/*

typedef struct myStruct 
{
//	int RollNo = 10;			//error illegal pure syntax, must be '= 0'

	int RollNo ;
	char sName;
	char sGrade;
	void func() { cout<<"Hello"<<endl;}
}s3;

//	s2 = {10, 's', 'n'}, s1;   // 1 way to create the object of the structure. 
								  Many objects can be created with a comma separation between them. 
								  The members can be initialized also (like for s2 object)


void main()
{	
	//myStruct s3, s4;		//2nd way of creating object
//	myStruct *s3 = NULL;	// object of pointer type
 
//	s1.RollNo = 10;
//	(*s3).func();

//	cout<<s2.RollNo<<endl;
}
*/


//*********************************************** R and D **********************************************/

// 1) When we have structure with both name and object. They do their normal job
// 2) we can't have a structure  without a name. (if at all we want so we have to add "typedef" keyword before it)
// 3) when we add "typedef" keyword(in a structure without name) we can use the the object as a
	// return type or as an object of structure
// 4) when we have both structure name and object for a structure and "typedef" is attached to it then 
//    we can't create object at the end of structure(after closing paranthesis)

/*
 struct  mystruct
{
	
	int RollNo;
	char sName;
	char sGrade; 
	void func(){ cout<<"Hello"<<endl;}
} s1;  



mystruct add()
{
	mystruct obj;
	return (obj);
}



void main()
{
	s1.func();
}
*/



//*********************************************** Structure Padding **************************************************************//

// There is a disadvantage in using structure 
// The  memory is always allocated in multiples of 4(for a 32 bit machine) irrespective of data type of members

// In the following program the expected output is ( 4bytes(int) + 1byte(char) )
//  which is 5 Bytes but the output is 8 bytes because inside a structure the memory is always allocated in multiples of 4
// so for int allocates 4 bytes first and then one more 4 bytes irrespective of data type hence output is 8 bytes.

// in order to resolve this we have to use a macro  "Pragma pack" so that it allocates normally 

/*

struct  mystruct
{

  bool        bFlag1; 
  short		  usNumber;
  bool        bFlag2;
  int         nNumber;
  bool        bFlag3;
  int		  k;
  bool		  b;
} s1;  


void main()
{
	cout<<sizeof(s1)<<endl;
}

/*	if  b is the member of a structure and obj is the object of a structure
	  Expression		What is evaluated								Equivalent
	*************	 ************************						*****************
		obj.b			Member b of object obj								----------	
		obj->b			Member b of object pointed by obj					(*obj).b
		*obj.b			Value pointed by member b of object obj				*(obj.b)
*/




//*******************************************   BASICS  *****************************************************************

/*
struct Student
{
	int roll_no;
	int marks;
	char name[25];
	char branch[15];

	struct Date
	{
		int date;
		int month;
		int year;

	}birthday;
}s1;


void main(int argc, char* argv[])
{
//	Student s1 = {1,2,"sandeep", "EEE"}; // way to initialize the members of a structure
//	s1.roll_no = 123;
//	cout<<s1.roll_no<<endl;

	s1.birthday.date = 100; // way to access nested structure members
}

 */
//*******************************************   BASICS  *****************************************************************


struct Student
{
	int roll_no;
	int marks;
	char name[25];
	char branch[15];

	Student() 
	{ 
		cout<<"constructor"<<endl;
		roll_no = 123;
	}

	~Student(){};

}s1;


void main()
{
	Student obj;
	cout<<obj.roll_no<<endl;
	obj.marks = 10;
	cout<<obj.marks<<endl;

}

