// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/**********************************************  1.  Non-modifying sequence operations  ****************************************************/

/*

std::all_of  : Test condition on all elements in range
std::any_of : Test if any element in range fulfills condition
std::none_of : Test if no elements fulfill condition
std::for_each : Apply function to range
std::find : Find value in range
std::find_if : Find element in range
std::find_if_not : Find element in range(negative condition)
std::find_end : Find last subsequence in range
std::find_first_of : Find element from set in range
std::adjacent_find : Find equal adjacent elements in range
std::count : Count appearances of value in range
std::count_if : Return number of elements in range satisfying condition
std::mismatch : Return first position where two ranges differ
std::equal : Test whether the elements in two ranges are equal
std::is_permutation : Test whether range is permutation of another
std::search : Search range for subsequence
std::search_n : Search range for element
*/



int main()
{

	std::vector<int> vec = { 2, 4, 6, 8 };

	 //std::all_of  : Test condition on all elements in range - 
	bool bval = std::all_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }); //return true only if all elements satisfy condition


	//std::any_of : Test if any element in range fulfills condition
	bool bval1 = std::any_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }); //return true if atleast one elemnet satisfy the condition


	//std::none_of : Test if no elements fulfill condition
	vec.push_back(9);
	bool bval2 = std::none_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });//return true if all the elements dont satisy the condition




	//std::for_each : Apply function to range
	std::for_each(vec.begin(), vec.end(), [](int x) { cout<< x << endl; }); // Applies to each element in range given 


	//std::find : Returns an iterator to the first element in the range [first,last) that compares equal to val. 
	//If no such element is found, the function returns last.
	std::vector<int>::iterator it = vec.begin();
	it = std::find(vec.begin(), vec.end(), 6);
	if (it != vec.end())
		std::cout << "Element found in myvector: " << *it;
	else
		std::cout << "Element not found in myvector: " << *it;



	//std::find : Returns an iterator to the first element in the range [first,last) that returns the true 
	//If no such element is found, the function returns last.
	std::vector<int>::iterator it1 = vec.begin();
	it1 = std::find_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 1; }); //Here we get iterator to the last elemnet as it return true (for value 9)
	if (it1 != vec.end())
		std::cout << "Element found in myvector: " << *it1;
	else
		std::cout << "Element not found in myvector: " << *it1;



	//std::find_end : Find last subsequence in range
	std::vector<int> v{ 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };
	std::vector<int>::iterator result;
	std::vector<int> t1{ 1, 2, 3 };
	result = std::find_end(v.begin(), v.end(), t1.begin(), t1.end()); //returns an iterator to the first element of the sequence appearing last
																// it returns 8 here because the 3rd sequence 1, 2, 3, 4 begins at position 8
	if (result == v.end()) 
	{
		std::cout << "sequence not found\n";
	}
	else
	{
		std::cout << "last occurrence is at: "
			<< std::distance(v.begin(), result) << "\n"; 
	}


	//std::adjacent_find : Find equal adjacent elements in range
	std::vector<int> v = { 1, 2, 3, 4, 56, 56 };
	auto it = std::adjacent_find(v.begin(), v.end()); //returns an iterator to the first element which are repeating in the given range (first 56 in thi case)


	std::string str = "Learn CPP EveryDay";
	std::string str1 = "EveryDay";

	auto it  = std::search(str.begin(), str.end(), str1);
	cout << it - str.begin() << endl;

																		
	int i = 10;
}

