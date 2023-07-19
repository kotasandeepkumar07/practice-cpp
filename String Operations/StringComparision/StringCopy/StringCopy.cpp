// StringCopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"
#include "string.h"



void main(int argc, char* argv[])
{
	char *str1 = new char;
	
	cout<<"Enter the String to be copied"<<endl;
	cin>>str1;

	int strlength = strlen(str1);

	char *str2 = new char(strlen(str1));
	for (int i=0; i<strlength; i++)
	{
		str2[i] = str1[i];
	}

	str2[i] = '\0';
	cout<<"string2 after copying"<<"\t"<<str2<<endl;
}




/*

void stringcopy(char *str1, char *str2)
{
	while(*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
}

void main()
{
	char s1[] = "";
	char s2[10] = "sand";
	stringcopy(s1, s2);
	cout<<s1<<endl;
}
*/