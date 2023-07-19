// Pallindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//pallindrome is a string that looks same when reversed

//pallindrome for a number 
//void main()
//{
//	int num = 200;
//	int temp = num;
//	int rev = 0;
//	int digit = 0;
//	do
//	{
//		digit = num % 10;  //get reminder of the division in each iteration
//		rev = (rev * 10) + digit;
//		num = num / 10;  //this reduces the number by each digit
//
//	} while (num != 0);
//
//	cout << " The reverse of the number is: " << rev << endl;
//
//	if (temp == rev)
//		cout << " The number is a palindrome.";
//	else
//		cout << " The number is not a palindrome.";
//}











//pallindrome for strings 
//void main()
//{
//	char str[] = "aba";
//	bool bpallindrome = true;
//
//	for (int i = 0; i < strlen(str); i++)
//	{
//		if (str[i] != str[strlen(str) - i - 1])
//		{
//			bpallindrome = false;
//			break;
//		}
//	}
//
//	if (bpallindrome) 
//	{
//		cout<< str << " is not a palindrome" << endl;
//	}
//	else
//	{
//		cout << str << " is a palindrome" << endl;
//	}
//}
//



//using alogrithms
void main()
{
	string str = "sanas";

	if (str == string(str.rbegin(), str.rend()))
	{
		cout << "string is a palindrome" << endl;
	}
	else
	{
		cout << "string is not a palindrome" << endl;
	}

}