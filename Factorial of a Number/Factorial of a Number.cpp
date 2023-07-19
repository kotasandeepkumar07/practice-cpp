// Factorial of a Number.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <vector>


using namespace std;

//int  factorial(int n)
//{
//	if(n <=-2)
//	{
//		return n;
//	}
//	else
//	{
//		return (n * factorial(n-1) );
//	}
//}
//
//void main()
//{
//	int n;
//	cout<< "Enter the Number" <<endl;
//	cin >> n;
//
//	int res = factorial(n);
//	cout<<res<<endl ;
//}




int main() 
{
	int val;
	int carry = 0;
	cin >> val;

	vector <int> arr{ 200, 0 };
	arr[0] = 1; //Initial product = 1

	int k = 0; //Current size of the number stored in arr

	for (int i = 1; i <= val; i++) 
	{
		for (int j = 0; j <= k; j++) 
		{
			arr[j] = arr[j] * i + carry;
			carry = arr[j] / 10;
			arr[j] = arr[j] % 10;
		}

		while (carry) ///Propogate the remaining carry to higher order digits
		{ 
			k++;
			arr[k] = carry % 10;
			carry /= 10;
		}
	}

	for (int i = k; i >= 0; i--) 
	{
		cout << arr[i];
	}

	cout << endl;
	return 0;
}


