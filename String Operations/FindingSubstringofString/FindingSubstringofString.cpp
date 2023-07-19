// FindingSubstringofString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>



#include<conio.h>
#include<stdio.h>
#include<string.h>

using namespace std;


//void main()
//{
//    
//	int len1,len2,i,cntr1,cntr2,flag=0;
//          char str1[50],str2[50];
//          //clrscr();
//          printf("Enter the main String and the substring:\n");
//          scanf("%s%s",str1,str2);
//          len1=strlen(str1);
//          len2=strlen(str2);
//
//          for(i=0;len2<=len1-i;i++)                     
//          {
//              for(cntr1=i,cntr2=0;  str1[cntr1]==str2[cntr2];  cntr1++,cntr2++);	
//			  {
//                 if(len2<=cntr2)
//                 {
//                   flag=1;
//                   printf("%s substring is present at %d location in string %s",str2,i+1,str1);
//                   break;
//                 }
//			  }
//          }
//
//          if(flag==0)
//          {
//             printf("%s substring is not present in string %s\n",str2,str1);
//          }
//}
//




bool FindSubString(char *strFullString, char* strSubString)
{
	string strParent = strFullString;
	string strChild = strSubString;
	int temp;
	bool bfound;

	for (int i = 0, j = 0; strParent[i] != '\0'; i++)
	{
		if (strParent[i] == strChild[j])
		{
			temp = i + 1;
			while (strParent[i] == strChild[j])
			{
				i++;
				j++;
			}

			if (strChild[j] == '\0')
			{
				bfound = true;
			}
			else
			{
				i = temp;
				temp = 0;
			}
		}
	}

	if (temp == 0)
		bfound = false;

	return bfound;
}

void main()
{
	char *pFullstring = "I am a boy out";
	char *pSubString = "oup";

	bool bPresent = FindSubString(pFullstring, pSubString);

	if (bPresent)
		cout << "Found " << endl;
	else
		cout << "Not Found " << endl;

}