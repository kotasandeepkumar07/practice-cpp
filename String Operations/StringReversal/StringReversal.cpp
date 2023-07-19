// StringReversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"
#include "string.h"


int findlength(char *str)
{
	int length;
	for(length =0; *str!='\0'; str++)
	{
		length++;
	}
	return length;
}



void main()
{
	char *str = new char;
	cout<<"please Enter the string to be reversed"<<endl;
	cin>>str;

	int len = findlength(str);
	int j = len-1;					// to remove null character

	for(int i=0; i<j; i++, j--) // j should be reduced as to move forward from last
	{
		char temp = str[i];
		str[i]    = str[j];
		str[j]	  = temp;
	}
	cout<<"Reversed string is"<<str<<endl;
}












