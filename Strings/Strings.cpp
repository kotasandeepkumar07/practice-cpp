// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "string.h"
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

/*
void main()
{
	char str[] = "hello";

//	str = "hi" ; //not possible

	cout<<sizeof(str)<<endl;  //6 it is size of array (size of 5 characters)
	cout<<strlen(str)<<endl;  //5 it dosent include  \0 
	cout<<str[5]<<endl;		  // prints null character



	char *s = "abcde";
	cout<<sizeof(s)<<endl;  //4 it is size of pointer 
	cout<<strlen(s)<<endl;  //5 it is size of 5 chars



	s = str; // a char array can be made to point to a char pointer

	strcpy(str, s);  //need strcpy to copy a character pointer to a character array



	char p[5] = { 'a', 'e', 'i', 'o', '\0' }; // \0 has to be given when a individiaul character is given in character array

	cout<<sizeof(p)<<endl;
}
*/

//****************************  length of a string ****************************//

/*
void main(int argc, char* argv[])
{
	char *str = new char;
	cout<<"Please Enter the String"<<endl;
	cin>>str;

	int nCount = 0;
	while(*str)
	{	
		str++;
		nCount++;
	}

	cout<<"String Length is"<<"\t"<<nCount<<endl;	
}
*/


//****************************  string  reversal ****************************//

/*
void main()
{
	char *str = new char;
	cout<<"Enter string to be reversed"<<endl;
	cin>>str;

	int i = strlen(str);
	int nlen = i-1;

	for(int j=0; j<nlen ; j++, nlen--)
	{
		char temp = str[nlen];
		str[nlen] = str[j];
		str[j]    = temp;
	}
	cout<<"String after reversal is "<<str;
}
*/




//****************************  counting number of words in a string ****************************//

/*
void main()
{
	//char *str =  new char;

	char str[100];
	cout<<"Enter the string"<<endl;
	cin>>str;

//	int nlen = strlen(str);
	int ncount = 0;
	for(int i=0; str[i]!= '\0' ; i++)
	{
		if(str[i] == ' ')
		{
			ncount++;
		}
	}
	cout<<ncount<<endl;
}
*/



//****************************  string concatenation ****************************//
// add null character after concatenation otherwise it concatenates and prints garbage after that 

/*
void main()
{

	char *mainstring = new char;
	char *substring  = new char;


	cout<<"Enter main string"<<endl;
	cin>>mainstring;

	cout<<"Enter string to be concatenated"<<endl;
	cin>>substring;

	int nmainstrlen = strlen(mainstring);
	int nsubstrlen = strlen(substring);

	for(int i=0; i<nsubstrlen; i++)
	{
		mainstring[nmainstrlen++] = substring[i];
	}
	mainstring[nmainstrlen] = '\0';

	cout<<mainstring<<endl;
}
*/


//***************************  to check if  a string is  a pallindrome *********************************//

/*
int main()
{
	char *str = new char;
	cout<<"Enter the string"<<endl;
	cin>>str;

	int nlen = strlen(str);
	nlen =  nlen-1;	
	for(int i =0; str[i]!= '\0'; i++)
	{
		if(str[i] == str[nlen-i])
		{	
			continue;
		}

		if(str[i] != str[nlen-i])
		{	
			cout<<"	not a pallindrome"<<endl;
			return 0;
		}
	}
	cout<<"	pallindrome"<<endl;
	return 1;
}
*/

class Solution
{
public:

	//Longest Substring Without Repeating Characters
	int lengthOfLongestSubstring(string s)
	{
		if (s.length() == 0)return 0;
		if (s.length() == 1)return 1;

		string substr = s.substr(0, 1);
		int length = 0;

		for (int i = 1; i < s.length(); i++)
		{
			if (substr.find(s[i]) == std::string::npos)
			{

				substr += s[i];
				length = substr.length();
			}
			else
			{

			}
		}
		return length == 0 ? substr.length() : length;
	}


	//Remove Duplicate Letters
	string removeDuplicateLetters(string s)
	{
		vector<int> cand(256, 0);
		vector<bool> visited(256, false);

		for (char c : s)
			cand[c]++;
		string result = "0";

		for (char c : s)
		{
			cand[c]--;

			if (visited[c]) continue;

			while (c < result.back() && cand[result.back()])
			{
				visited[result.back()] = false;
				result.pop_back();
			}

			result += c;
			visited[c] = true;
		}
		return result.substr(1);
	}




};




void main()
{
	Solution s;
	s.lengthOfLongestSubstring("qrsvbspk");
	//s.removeDuplicateLetters("cbacdcbc");
}