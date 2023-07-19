// miscellaneous.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"


//********************************* implementation of atoi **************************************//
int myAtoi(char *str)
{
    int res = 0;
 
    // Iterate through all characters of input string and update result
    for (int i = 0; str[i] != '\0'; ++i)
	{
        res = res*10 + str[i] - '0';
	}
     return res;
}
 
// Driver program to test above function
int main()
{
    char str[] = "89789";
    int val = myAtoi(str);
	cout<< val <<endl;
	return 0;
}