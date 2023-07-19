// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



/***************************************************************Sorting *****************************************
No Sorting algorithm which requires comparision  takes any time less than omega(nlogn) 
*/



/*************************************************************** Selection Sort *******************************************************/
/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) 
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) 
from the unsorted subarray is picked and moved to the sorted subarray.

arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64  

Complexity is O(n^2) for Best, Average and Worst cases 
*/



//void swap(int *p1, int *p2)
//{
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//void main()
//{
//	int arr[] = { 23, 56, 1, 98, 34 };
//	int nMinIndex = -1;
//	int nNumofElements = sizeof(arr) / sizeof(arr[0]);
//
//	cout << "Before Sorting" << endl;
//	for (int k = 0; k < nNumofElements; k++)
//	{
//		cout << arr[k] << endl;
//	}
//
//
//	for (int i = 0; i < nNumofElements; i++)
//	{
//		nMinIndex = i;
//		for (int j = i + 1; j < nNumofElements; j++)
//		{
//			if (arr[j] < arr[nMinIndex])
//			{
//				nMinIndex = j;
//			}
//			swap(&arr[nMinIndex], &arr[i]);
//		}
//	}
//
//	cout << "After Sorting" << endl;
//
//	for (int k = 0; k < nNumofElements; k++)
//	{
//		cout << arr[k] << endl;
//	}
//}
//


/*************************************************    Bubble sort ***********************************************************

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

Third Pass:
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.


Adaptive:
	Since Bubble Sort takes O(n) as Best case and O(n*n) as worst case it is said to be adaptive
	Basically adaptive in nature based on the elements

Stable:
	Yes it is stable because it does not change the sequence of values if there is an element with same value 

*/


//void main(int argc, char* argv[])
//{
//	int array[] = { 7, 5, 2, 4, 3, 9 };
//	int nNumofElements = sizeof(array) / sizeof(array[0]);
//
//	cout << "Before Sorting" << endl;
//	for (int k = 0; k < nNumofElements; k++)
//	{
//		cout << array[k] << endl;
//	}
//
//	for (int i = 0; i < nNumofElements - 1; i++)
//	{
//		for (int j = 0; j < nNumofElements-1-i; j++)
//		{
//			if(array[j] > array[j+1])
//			{
//				int temp = array[j];
//				array[j] = array[j+1];
//				array[j+1] = temp;
//			}
//		}
//	}
//
//
//
//	/*To Make Bubble sort as adaptive:
//	i.e. checking if array is already sorted and disallowing to go further if already sorted
//	we do this by using a special flag */
//	for (int i = 0; i < nNumofElements - 1; i++)
//	{
//		for (int j = 0; j < nNumofElements - 1 - i; j++)
//		{
//			int nFlag = 0;
//
//			if (array[j] > array[j + 1])
//			{
//				int temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//				nFlag = 1;
//			}
//
//			if (nFlag == 1) break;  //if flag has not changed then it means there was not even a single 
//			//swap and hence already is already sorted, we can reduce the time from O(n*n) to o(n)
//		}
//	}
//
//
//	cout << "After Sorting" << endl;
//	for (int k = 0; k < nNumofElements; k++)
//	{
//		cout<<array[k]<<endl;
//	}
//}




using namespace std;

/***************************************************** Insertion sort **************************************************/

/*
	Insertion basically starts from index 1, From value 4 in the follwing example and tries to place it in its location 
	After 1st iteration the result will be 4, 7, 1, 9, 2
	In Next iteration we choose 1 and then place it in its location , The result would be 1,4,7,9,2

	Adaptive: 

*/

//int main()
//{
//	int A[] = { 7, 4, 1, 9, 2 };
//	int n = sizeof(A) / sizeof(A[0]);
//
//	for (int i = 1; i < n; i++)
//	{
//		int x = A[i]; //start from 1st Index
//		int j = i - 1;  // Start Comparing the 1st index with 0 index on wards
//
//		while (j > -1 && A[j] > x)
//		{
//			A[j + 1] = A[j]; //move current element to next element if its greater than the index we chose
//			j--; //do it for all elements in the array
//		}
//
//		A[j + 1] = x; //place the original element we choose as all the elemnets have been move to next places
//	}
//
//	return 0;
//}


/***************************************************** Quick sort **************************************************/
/*


*/


//void swapNums(int *p1, int *p2)
//{
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//int Partition(int a[], int l, int h)
//{
//	
//	int pivot = a[l];
//	int i = l;
//	int j = h;
//	do
//	{
//		do 
//		{ 
//			i++; 
//		} while (a[i] <= pivot);
//
//		do 
//		{ 
//			j--; 
//		} while (a[j] > pivot);
//
//		if(i < j)
//			swapNums(&a[i], &a[j]);
//	} while (i < j);
//
//	swapNums(&a[l], &a[j]);
//	return j;
//}
//
//
//void quicksort(int A[], int l, int h)
//{
//	if (l < h)
//	{
//		int j = Partition(A, l, h);
//		quicksort(A, l, j-1);
//		quicksort(A, j + 1, h);
//	}
//}
//
//void main()
//{
//	int A[] = { 3, 6, 1, 2, 9, 5, 7, 8 };
//	int nEelments = sizeof(A) / sizeof(A[0]);
//	quicksort(A, 0, nEelments );
//
//	for (int i = 0; i < nEelments; i++)
//		cout << A[i] << endl;
//}


using namespace std;
#include <vector>

//class Solution
//{
//public:
//	std::vector<int> res;
//	std::vector<int> sortArray(vector<int>& nums)
//	{
//		if (nums.size() == 0)  res;
//		MergeSort(nums, 0, nums.size()-1);
//		return nums;
//	}
//
//	void MergeSort(vector<int>& nums, int l, int h)
//	{
//		if (l < h)
//		{
//			int mid = l + (h - l) / 2;
//			MergeSort(nums, l, mid);
//			MergeSort(nums, mid + 1, h);
//			Merge(nums, l, mid, h);
//		}
//	}
//
//
//	void Merge(vector<int>& nums, int l, int m, int h)
//	{
//		int i = l, j = m + 1;
//		int k = l;
//		vector<int> temp(nums.size());
//
//		while (i <= m && j <= h)
//		{
//			if (nums[i] < nums[j])
//				temp[k++] = nums[i++];
//			else
//				temp[k++] = nums[j++];
//		}
//
//		for (; i <= m; i++)
//		{
//			temp[k++] = nums[i];
//		}
//
//		for (; j <= h; j++)
//		{
//			temp[k++] = nums[j];
//		}
//
//		for(int index = l; index <= h; index++)
//		{
//			nums[index] = temp[index];
//		}
//
//	}
//};






//void Merge(int A[], int l, int mid, int h)
//{
//	int i = l;
//	int j = 
//
//
//
//}
//
//void MergeSort(int A[], int l, int h)
//{
//	int mid = l + h / 2;
//
//	MergeSort(A, l, mid);
//	MergeSort(A, mid+1, h);
//
//	Merge(A, l, mid, h);
//}
//
//
//
//void main()
//{
//	int A[] = { 3, 6, 1, 2, 9, 5, 7, 8 };
//	int nEelments = sizeof(A) / sizeof(A[0]);
//	MergeSort(A, 0, nEelments );
//
//	for (int i = 0; i < nEelments; i++)
//		cout << A[i] << endl;
//}





class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		std::vector<int> res(nums1.size(), 0);

		int i = 0;
		int j = 0;
		int k = 0;

		while (i < m && j < n)
		{
			if (nums1[i] < nums2[j])
				res[k++] = nums1[i++];
			else
				res[k++] = nums2[j++];
		}

		for (; i < m; i++)
		{
			res[k++] = nums1[i];
		}


		for (; j < n; j++)
		{
			res[k++] = nums2[j];
		}

		for (int i = 0; i < nums1.size(); i++)
		{
			nums1[i] = res[i];
		}

	}
};


void main()
{
	//vector<int> arr{ 5, 2, 3, 1};
	//Solution s;
	//s.sortArray(arr);

	vector<int> arr{ 1, 2, 3, 0,0,0 };
	vector<int> arr1{ 2,5,6 };
	Solution s;
	s.merge(arr, 3, arr1, 3);

}