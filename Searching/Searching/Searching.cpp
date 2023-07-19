// Searching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


/*
Searching Algorithms are designed to check for an element or retrieve an element from any data structure where it is stored. 
Based on the type of search operation, these algorithms are generally classified into two categories
	1. Sequential Search: In this, the list or array is traversed sequentially and every element is checked. For example: Linear Search.
	2. Interval Search: These algorithms are specifically designed for searching in sorted data-structures. 
		These type of searching algorithms are much more efficient than Linear Search as they repeatedly target the center of the search structure 
		and divide the search space in half. For Example: Binary Search.
*/


/********************************************************** Linear Search ***********************************************************/
//The time complexity of below algorithm is O(n).

//int LinearSearch(int arr[], int narraysize, int nTobeSearched)
//{
//	int nIndex = -1;
//	for (int i = 0; i < narraysize; i++)
//	{
//		if (arr[i] == nTobeSearched)
//		{
//			nIndex = i;
//			break;
//		}
//	}
//
//	return nIndex;
//}
//
//void main()
//{
//	int arr[10] = { 2, 5, 7, 8, 4, 3 };
//
//	int narraysize = sizeof(arr) / sizeof(arr[0]);
//	int nElementtobeSearched = 7;
//	int nIndex = LinearSearch(arr, narraysize, nElementtobeSearched);
//
//	if (nIndex == -1)
//		cout << "Element not found<<endl" << endl;
//	else
//		cout << "Element found at Index " << nIndex << endl;
//}


/********************************************************** Binary Search ***********************************************************/

// To Perform Binary Search the List/Array has to be sorted one.
//The time complexity of below algorithm is O(logn). Its because after every iteration the problem becomes half 
// so if there are n elemnets after 1st iteration the elements left are n/2 and next (n/2)/2, so lets assume that after k iterations the elemenst becomes 1
// so n/2^k = 1. So n  =  2^k, Applying log on both sides logn base 2  = k  SO there fore 

//
//int BinarySearch(int arr[], int nFirstEle, int nLastEle, int nTobeSearched)
//{
//	int nIndex = -1;
//
//	while (nFirstEle < nLastEle)
//	{
//		//to find element even if there are even number of elements in the array
//		//int nMidIndex = nFirstEle +  (nLastEle - nFirstEle) / 2;
//		int nMidIndex = (nFirstEle + nLastEle)/ 2;
//
//
//		if (nTobeSearched == arr[nMidIndex])
//			return nMidIndex;
//
//		//if element value is less than the value 
//		// at the middle index it means the value is in the 
//		//1st half of the array so move the last element to middle
//		if (nTobeSearched < arr[nMidIndex])
//		{
//			nLastEle = nMidIndex - 1;
//		}
//
//		//if element value is more than the value 
//		// at the middle index it means the value is in the 2nd half 
//		//of the array so move the 1st element to middle
//		if (nTobeSearched > arr[nMidIndex])
//		{
//			nFirstEle = nMidIndex + 1;
//		}
//	}
//
//	return nIndex;
//}
//
//
//
//void main()
//{
//	int arr[10] = { 2, 5, 7, 8, 20, 40 };
//
//	int narraysize = sizeof(arr) / sizeof(arr[0]);
//	int nElementtobeSearched = 7;
//	int nIndex = BinarySearch(arr, 0, narraysize - 1, nElementtobeSearched);
//
//	if (nIndex == -1)
//		cout << "Element not found<<endl" << endl;
//	else
//		cout << "Element found at Index " << nIndex << endl;
//}


/************************************************************ Search for a Substring in a string ******************************************************/

bool FindSubString(char *strFullString, char* strSubString)
{
	string strParent =strFullString;
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
				bfound =  true;
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
	char *pFullstring = "Testing";
	char *pSubString = "ing";

	bool bPresent  = FindSubString(pFullstring, pSubString);

	if (bPresent)
		cout << "Found " << endl;
	else
		cout << "Not Found " << endl;

}