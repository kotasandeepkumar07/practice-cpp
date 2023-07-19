// OperatorsinC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "string.h"

using namespace std;

//**************************************  Bitwise Operators ***********************************************//
/*

Operator		Symbol		Form		Operation

left shift		<<			x << y		all bits in x shifted left y bits
right shift		>>			x >> y		all bits in x shifted right y bits
bitwise NOT		~			~x	all		bits in x flipped
bitwise AND		&			x & y		each bit in x AND each bit in y
bitwise OR		|			x | y		each bit in x OR each bit in y
bitwise XOR		^			x ^ y		each bit in x XOR each bit in y




/*void main()
{
*/
/*	
left shift :

	1 is an integer which takes 4 bytes (32 bits) of memory and it is stored as
	00000000 00000000 00000000 00000001
	shifting the bits of i by 1 bit towards left 
	i is 2 now  becuase i << = 1 will make the bits as 00000000 00000000 00000000 00000010
	all the bits are moved 1 bit left and 0 is appended at the last 


	int i = 1;		 			 
	i = i << 1;		 
	cout<<i<<endl;  					
*/

/*
right shift : 

	stored as 00000000 00000000 00000000 00000001
	shifting the bits of i to right by 1 bit whihc becomes 00000000 00000000 00000000 00000000 and hence result is 0


	int i = 1;	
	i = i>> 1;		 
	cout<<i<<endl; 
	
*/

/* 
bitwise NOT

  00000000 00000000 00000000 00000100   is how the i is stored in memory
  this operation makes the i as 11111111 11111111 11111111 11111011  (flips if bit of an int value)
  output is 4294967291


	unsigned int i = 4;
	i = ~i;				
	cout<<i<<endl;		
*/

/*
bitwise AND

  Bit wise AND operation will do operation between each bit of a byte 

  0&0 = 0
  0&1 = 0
  1&0 = 0
  1&1 = 1;

  i is 00000000 00000000 00000000 00000001 = 1
  j is 00000000 00000000 00000000 00000010 = 2

  k is 00000000 00000000 00000000 00000000 = 0

	int i = 1;
	int j = 2;
	int k = i & j;
	cout<<k<<endl;    
*/

/*
bitwise OR

  Bit wise OR operation will do OR operation between each bit of a byte 

  0|0 = 0
  0|1 = 0
  1|0 = 1
  1|1 = 1;

  i is 00000000 00000000 00000000 00000001 = 1
  j is 00000000 00000000 00000000 00000010 = 2

  k is 00000000 00000000 00000000 00000011 = 3

	int i = 1;
	int j = 2;
	int k = i | j;
	cout<<k<<endl;    
*/

/*
bitwise XOR

  Bit wise OR operation will do XOR operation between each bit of a byte 

  0|0 = 1
  0|1 = 0
  1|0 = 0
  1|1 = 1;
logic is if both are same then result is zero else 1

  i is 00000000 00000000 00000000 00000001 = 1
  j is 00000000 00000000 00000000 00000010 = 2

  k is 00000000 00000000 00000000 00000011 = 3

	int i = 1;
	int j = 2;
	int k = i ^ j;
	cout<<k<<endl;    

}
*/

//************************  to get the set bits of an integer *************************************/
/*

int  setbits( int n )
{
	int count = 0;
	while(n)
	{
		count = count + (n&1);
		n  = n >> 1;
	}
	return count;
}

void main()
{
	int sb = setbits(7);
	cout<<sb<<endl;
}
*/



//**************************       Printing the bits of an integer         *********************************/

// setp 1 : left shift 1 by 7 so that we get 128 then n & 128 gives either 0 or 1;
// setp 2 : i = i / 2  so i = 64 the n & 64 gives either 0 or 1
// It continues for everyting and for 2 the value becomes 1;


void bin(unsigned n)
{
    unsigned i;
   for (i = 1 << 7; i > 0; i = i / 2) 
	{
        (n & i)? cout << 1 : cout << 0; //print 0 for everything except 2 for input 2 so it prints   0 0 0 0 0 0 1 0
	}
}

void main()
{
	bin(2);
}




//*************************  To  find the value in the nth byte of an integer *****************************//


//void main()
//{
//	int i = 128;
//	int x = (i >> (8*1)) & 0xff ; // to know value in the 1st byte
////	int x = (i >> (8*2)) & 0xff ; // to know value in the 2nd byte
//	cout<<x<<endl;
//}



//*********************************  size of operator **********************************************//
// sizeof operator is operator which return the size of the object or data type(user defined data type also)

/*
void main()
{
	cout<<sizeof(int)<<endl;  //syntax for data types
	int i;
	cout<<sizeof i<<endl; //for variables () is not compulsory
}
*/