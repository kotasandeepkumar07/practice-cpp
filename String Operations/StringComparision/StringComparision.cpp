// StringComparision.cpp : Defines the entry point for the console application.
//

//*************************************** STRING COMPARISION ******************************************************//


#include "stdafx.h"
#include "iostream.h"
#include "string.h"


/*
void main()
{
	char str1[100];
	char str2[100];
	
	cout<<"Enter First String"<<endl;
	cin>>str1;

	cout<<"Enter Second String"<<endl;
	cin>>str2;
	int i =0;

	if(strlen(str1) != strlen(str2))
	{
		cout<<"strings are not same"<<endl;
	}
	else
	{
		for(int i=0; i<strlen(str1); i++)
		{
			if(str1[i] != str2[i])
			{
				cout<<"string are not same"<<endl;
			}

			else if( str1[i] == str2[i] )
			{
				cout<<"string are equal"<<endl;
			}
		}
	}
}
*/

int stringcomp(char *str1, char *str2)
{
	if(!(strlen(str1) == strlen(str2)))
	{
		return -1;
	}
	while(*str1 == *str2)
	{
		if(*str2 == '\0')
		{
			return 1;	
		}

		str1++;
		str2++;	
	}
		
	return -1;
}



void main()
{
	int retval = stringcomp("abc", "abc");
	if(retval == 1)
	{
		cout<<"equal"<<endl;
	}
	else
	{
		cout<<"not equal"<<endl;
	}
}