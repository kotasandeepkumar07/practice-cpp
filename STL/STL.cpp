

//************************************   STANDARD TEMPLATE LIBRARY  ************************************************//

/*
The Standard Template Library is a collection(Library) of classes that provide
	templated containers,
	algorithms,
	iterators.

The upside is that you can take advantage of these classes without having to write and debug the classes yourself
The STL contains many different container classes that can be used in different situations

The container classes fall into three basic categories:
		1.Sequence containers,
		2.Associative containers,
		3.Container adapters

1. Sequence containers

	These are the classes that maintain the ordering of elements in the container.
	A defining characteristic of sequence containers is that you can choose where to insert your element by position.

	Example : Array

	STL contain 3 Sequence containers

	a. Vector

		1.vector class in the STL is a dynamic array capable of growing as needed to contain its elements
		2.The vector class allows random access to its elements via operator[]
		3.Inserting and removing elements from the end of the vector is generally fast.

	b. Deque(pronounced as DECK)

		1.The deque class (pronounced “deck”) is a double-ended queue class,
			implemented as a dynamic array that can grow from both ends

	c. List

		1.A list is a special type of sequence container called a doubly linked list
			where each element in the container contains pointers that point at the next and previous elements in the list.
		2.Lists only provide access to the start and end of the list — there is no random access provided.


2. Associative Containers

	These contains are containers that automatically sort their inputs
	By default, associative containers compare elements using operator<.

	a. Set

		1.A set is a container that stores unique elements, with duplicate elements disallowed.
		  The elements are sorted according to their values.

	b. Multiset

		1.A multiset is a set where duplicate elements are allowed.

	c. Map

		1. A map (also called an associative array) is a set where each element is a pair, called a key/value pair.
		2. The key is used for sorting and indexing the data, and must be unique. The value is the actual data.

	d. Multimap

		1. A multimap (also called a dictionary) is a map that allows duplicate keys.
		2. Real-life dictionaries are multimaps: the key is the word, and the value is the meaning of the word.
		3. All the keys are sorted in ascending order, and you can look up the value by key.
		4. Some words can have multiple meanings, which is why the dictionary is a multimap rather than a map.


3. Container Adapters

	They dont contain iterators associated with them
	Container adapters are special predefined containers that are adapted to specific uses.
	The interesting part about container adapters is that you can choose which sequence container you want them to use.

  a. stack

	   1. A stack is a container where elements operate in a LIFO (Last In, First Out) context,
			where elements are inserted (pushed) and removed (popped) from the end of the container.
	   2. Stacks default to using deque as their default sequence container (which seems odd, since vector seems like a more natural fit), but can use vector or list as well.

  b. queue

	   1. A queue is a container where elements operate in a FIFO (First In, First Out) context,
			where elements are inserted (pushed) to the back of the container and removed (popped) from the front. Queues default to using deque, but can also use list.

  c. priority queue

	   1. priority queue  is a type of queue where the elements are kept sorted (via operator<).
			When elements are pushed, the element is sorted in the queue. Removing an element from the front returns the highest priority item in the priority queue.

*/





///////////////////////Vector/////////////////////////////////////////////
/*
unsigned int size(); -----------Returns the number of elements in a vector
push_back(type element); -------Adds an element to the end of a vector
bool empty();-------------------Returns true if the vector is empty
void clear();-------------------Erases all elements of the vector
type at(int n);-----------------Returns the element at index n, with bounds checking
*/

/*

#include "stdafx.h"
#include "iostream.h"
#include <vector>


using namespace std;


void main()
{
	vector<int> vect;
	for (int nCount=0; nCount < 6; nCount++)
		vect.push_back(10 - nCount); // insert at end of array

	for (int nIndex=0; nIndex < vect.size(); nIndex++)
		cout << vect[nIndex] << " ";

	cout << endl;
}

  */


  ///////////////////////Deque/////////////////////////////////////////////

  /*
  #include "stdafx.h"
  #include <iostream>
  #include <deque>

  void main()
  {
	  using namespace std;

	  deque<int> deq;

	  for (int nCount=0; nCount < 3; nCount++)
	  {
		  deq.push_back(nCount); // insert at end of array
		  deq.push_front(10 - nCount); // insert at front of array
	  }

	  for (int nIndex=0; nIndex < deq.size(); nIndex++)
	  {
		  cout << deq[nIndex] << " "<<endl;
	  }
  }
  */


  //***********************************  ITERATOR  **************************************************************/
  /*

  1. An Iterator is an object that can traverse (iterate over) a container class without
	   the user having to know how the container is implemented.

  2. With many classes (particularly lists and the associative classes),
	   iterators are the primary way elements of these classes are accessed.

  3. An iterator is best visualized as a pointer to a given element in the container,
		  with a set of overloaded operators to provide a set of well-defined functions:


  Operator											Meaning
  ---------------------------------------------------------------------------------------------------
	  *			Dereferencing the iterator returns the element that the iterator is currently pointing at.

	  ++			Moves the iterator to the next element in the container.

	  == !=		To determine if two iterators point to the same element.
					  To compare the values that two iterators are pointing at, deference the iterators first,
					  and then use a comparison operator.

	  =			Assign the iterator to a new position (typically the start or end of the container’s elements).
					  To assign the value of the element the iterator is point at, deference the iterator first,
					  then use the assign operator.

  -----------------------------------------------------------------------------------------------------------

   4. Each container includes four basic member functions for use with Operator=:

  begin()----- returns an iterator representing the beginning of the elements in the container.
  end()------- returns an iterator representing the element just past the end of the elements.
  cbegin()---- returns a const (read-only) iterator representing the beginning of the elements in the container.
  cend()------- returns a const (read-only) iterator representing the element just past the end of the elements.



  */


  //*********************************************  vectors ******************************************//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "stdlib.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>  
#include <iomanip>
#include <sstream>
#include <thread>
#include <mutex>
#include <fstream>
#include <set>
#include <map>
#include <stack>

using namespace std;

//assign 
//void main()
//{
//	vector<int> vec;
//	for(int i=0; i<10; i++)
//	{	
//		vec.push_back(i);
//		cout<<vec[i]<<endl;
//	}
//
//	cout << vec.size() << endl;
//	cout << vec.capacity() << endl;
//
//	//vector<int>::iterator *it;
//}

//void main()
//{
//	/*std::map<int, string> Employee;
//	std::pair<std::map<int, string>::iterator, bool> it = Employee.insert(pair<int, string>(1, "Test"));
//	it= Employee.insert(pair<int, string>(1, "abc"));
//
//	Employee[1] = "hello";
//
//	std::multimap<int, string> Employee1;
//	Employee1.insert(pair<int, string>(1, "Test"));
//	Employee1.insert(pair<int, string>(2, "Test"));
//	Employee1.insert(pair<int, string>(1, "abc"));
//
//	std::multimap<int, string> e2;*/
//	//e2[1] 
//	
//
//	/*multimap<int, string>::iterator it = Employee1.begin();
//	it->second = "hello";
//	while (it != Employee1.end())
//	{
//		string strname = it->second;
//		int ID = it->first;
//		it++;
//	}*/
//
//}

//
//#include <algorithm>  
//#include <cmath>  
//#include <iostream>  
//#include <functional>  
//using namespace std;
//
//int main()
//{
//	int x = 5; 
//	int y = 10;
//
//	function<int(void)> f = [x, y] {return x + y; }; 
//
//	cout << f() << endl;
//}




//#include <map>
//class Test
//{
//public:
//	int m_nVal1{};
//	int m_nVal2{};
//
//	bool operator < (const Test& obj1) const
//	{
//		return (obj1.m_nVal1 < this->m_nVal1 && obj1.m_nVal2 < this->m_nVal2);
//	}
//	bool operator == (const Test& obj1) const
//	{
//		return (obj1.m_nVal1 == this->m_nVal1&& obj1.m_nVal2 == this->m_nVal2);
//	}
//};



//bool FindmapElement(std::map< Test, std::string>& mymap, const Test& Obj) 
//{
//	std::map< Test, std::string>::iterator it = mymap.begin();
//	while (it != mymap.end())
//	{
//		if (it->first == Obj)  //O(n) O(nlogn)
//			return true;
//		it++;
//	}
//}

//void main()
//{
//	Test obj1;
//	obj1.m_nVal1 = 10;
//	obj1.m_nVal2 = 30;
//
//	Test obj;
//	obj.m_nVal1 = 100;
//	obj.m_nVal2 = 200;
//
//
//	std::map< Test, std::string> mymap;
//	mymap.insert({ obj1, "1st" });
//	mymap.insert({ obj, "2nd" });
//
//
//	Test Obj2;
//	Obj2.m_nVal1 = 10;
//	Obj2.m_nVal2 = 50 ;
//
//	
//	/*if (FindmapElement(mymap, Obj2))
//		cout << "found" << endl;
//	else
//		cout << "not found" << endl;*/
//}
//
//





/**********************************  Algorithms ****************************************/


#include <algorithm>
#include <random>
#include <numeric>
using namespace std;


//void Print(const std::vector<int>& vec)
//{
//	for (auto val : vec)
//	{
//		cout << val << "  ";
//	}
//
//	cout << endl;
//}






/*********************************************  Algorithms ******************************************************/

int main()
{


	/******************  Sorting ***************************/

		//std::vector<int> vec = { 8, 3, 4, 6, 7, 9, 1 };
		//std::cout << "Original vector " << endl;
		//Print(vec);


	//std::sort
		//std::sort(vec.begin(), vec.begin() + 3);
		//std::cout << "vector after sort " << endl;
		//Print(vec);


	////std::partial_sort
	//	std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
	//	std::cout << "vector after partial_sort " << endl;
	//	Print(vec);
	//
	//
	////nth_element
	//	std::nth_element(vec.begin(), vec.begin()+2, vec.end());
	//	std::cout << "vector after nth_element " << endl;
	//	Print(vec);












	/************************  Numeric Algorithms ****************************/

		/*std::vector<int> vec = { 8, 8, 53, 44, 36, 87, 95, 12 };
		std::cout << "Original vector " << endl;
		Print(vec);*/


		////std::count	
		//	int n = std::count(vec.begin(), vec.end(), 8);
		//	std::cout << "8 occurs "<< n  << " times" << endl;
		//
		//
		////std::accumulate
		//	int sum = std::accumulate(vec.begin(), vec.end(), 0);
		//	std::cout << "Sum of elements is " << sum << endl; 


		//std::partial_sum
			//std::vector<int> vecResult(vec.size());
			//std::partial_sum(vec.begin(), vec.end(), vecResult.begin());
			//std::cout << "Vector after  partial_sum is" << endl; 
			//Print(vecResult);


		//std::adjacent_difference
			//std::vector<int> vecResult(vec.size());
			//std::adjacent_difference(vec.begin(), vec.end(), vecResult.begin());
			//std::cout << "Vector after  adjacent_difference is" << endl; 
			//Print(vecResult);









		/**************  Querying Algorithms ********************************/

			//std::vector<int> vec = { };
			//std::cout << "Original vector " << endl;
			//Print(vec);


		////std::all_of // true
		//	bool bVal = std::all_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
		//	bVal ? cout << "All elements are even" : cout << "Not all elements are even" << endl;
		//
		//
		////std::any_of //false
		//	bool bval1 = std::any_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
		//	bval1 ? cout << "atleast one elemnst is even" : cout << "no element is even" << endl;
		//
		//
		//
		////std::none_of //true
		//	bool bVal2 = std::none_of(vec.begin(), vec.end(), [](int i) { return i % 10 == 0; });
		//	bVal2 ? cout << "None of the elemnets are divisible by 10" : cout << "Atleast one element is divisible by 10" << endl;




			//Querying on 2 Ranges
			//std::vector<int> first = { 8, 53, 44, 36, 87, 95, 12 };
			//std::cout << "first vector " << endl;
			//Print(first);
			//
			//std::vector<int> second = { 8, 53, 44, 36, 87, 12, 95 };
			//std::cout << "second vector " << endl;
			//Print(second);


		//std::equal
			//bool bEqual = std::equal(first.begin(), first.end(), second.begin(), second.end());
			//bEqual ? cout << "Both containers are equal" : cout << "Both containers are not equal" << endl;


		//std::is_permutation
			//bool bEqual1 = std::is_permutation(first.begin(), first.end(), second.begin(), second.end());
			//bEqual1 ? cout << "Both containers have same elements" : cout << "Both containers doesn't contain same elements" << endl;



		//std::mismatch
			//pair< vector<int>::iterator, vector<int>::iterator > mispair;
			//mispair = std::mismatch(first.begin(), first.end(), second.begin(), second.end());
			//cout << "The returned value from 1st container is : ";
			//cout << *mispair.first << endl;
			//cout << "The returned value from 2nd container is : ";
			//cout << *mispair.second << endl;



		/************************  Searching a value ****************************/

			/*std::vector<int> vec = { 8, 53, 44, 23, 95, 94, 12, 103 };
			std::cout << "Original vector " << endl;
			Print(vec);*/


			//std::find
				//auto it  = std::find(vec.begin(), vec.end(), 23);
				//it != vec.end() ? cout << "Element found at position" << it - vec.begin() : cout << "Element not found" << endl;


			//std::adjacent_find
				//auto it1 = std::adjacent_find(vec.begin(), vec.end());
				//it1 != vec.end() ? cout << "element found at position " << it1 - vec.begin() : cout << "element not found" << endl;


			//std::upper_bound
				//auto it3 = std::upper_bound(vec.begin(), vec.end(), 93);
				//cout << *it3 << endl;


			//std::lower_bound();
				//auto it1 = std::lower_bound(vec.begin(), vec.end(), 94);
				//cout << *it1 << endl;


			//std::search
				//vector<int> first = { 1, 2, 3, 4, 5, 6, 7 };
				//vector<int> second = { 3, 5, 4 };
				//std::cout << "first vector " << endl;
				//Print(first); 
				//std::cout << "second vector " << endl;
				//Print(second);

				//auto it  = std::search(first.begin(), first.end(), second.begin(), second.end());
				//it != first.end() ? cout << "vector2 is present at index " << (it - first.begin()) : cout << "vector2 is not present in vector1";


			//std::max_element
				//auto it =  std::max_element(vec.begin(), vec.end());
				//cout << "Max Element is " <<  *it << endl;


			//std::min_element
				/*auto it1 = std::min_element(vec.begin(), vec.end());
				cout << "Min Element is " << *it1 << endl;*/








				/***************************  Permutations ***************************************/

					/*std::vector<int> vec = { 8, 53, 44, 36, 87, 95, 12 };
					std::cout << "Original vector " << endl;
					Print(vec);*/

					//std::rotate
						//std::rotate(vec.begin(), vec.begin()+3, vec.end());
						//std::cout << "vector After rotate " << endl;
						//Print(vec);


					//std::shuffle
						/*std::shuffle(vec.begin(), vec.end(), std::random_device());
						std::cout << "vector After shuffle " << endl;
						Print(vec);*/


						//std::reverse
							//std::reverse(vec.begin(), vec.end());
							//std::cout << "vector After reverse " << endl;
							//Print(vec);


						//std::next_permutation
							//std::next_permutation(vec.begin(), vec.end());
							//std::cout << "vector After next_permutation " << endl;
							//Print(vec);


						//std::prev_permutation
							//std::prev_permutation(vec.begin(), vec.end());
							//std::cout << "vector After prev_permutation " << endl;
							//Print(vec);


	/*std::map<__int64, __int64> mymap;

	for (__int64 i = 0; i < 100000000; i++)
	{
		mymap[i] = i;
	}

	for (auto const& i : mymap)
	{
		cout << i.first << i.second << endl;
	}


	int a = 0;*/


	/*ifstream infile("D:\\data.txt");

	int sum = 0;
	int maxvalue = 0;
	std::set<long> myset;

	for (string line = ""; getline(infile, line); )
	{
		if (line.empty())
		{
			myset.insert(sum);
			sum = 0;
		}

		sum = sum + std::atoi(line.c_str());
	}

	auto it = myset.begin();
	std::advance(it, myset.size() - 3);
	auto result = std::accumulate(it, myset.end(), 0);

	if (infile.is_open())
		infile.close();*/


//-------------------------Day 2-------------------------
	
	//{
	//	ifstream infile("D:\\Data-2.txt");
	//	int firstvalue = 0;
	//	int secondvalue = 0;
	//	int sum = 0;
	//	int iterationsum = 0;
	//	int count = 0;

	//	for (string line = ""; getline(infile, line); )
	//	{
	//		istringstream iss(line);
	//		string s;
	//		firstvalue = 0;
	//		secondvalue = 0;
	//		count++;


	//		if (line.empty())
	//			continue;

	//		while (getline(iss, s, ' '))
	//		{

	//			if (s == "A" || s == "a" || s == "B" || s == "b" || s == "C" || s == "c")
	//			{
	//				if (s == "A" || s == "a" || s == "x" || s == "X")
	//				{
	//					firstvalue = 1; //A
	//				}
	//				else if (s == "B" || s == "b" || s == "y" || s == "Y")
	//				{
	//					firstvalue = 2;	 //B
	//				}
	//				else
	//				{
	//					firstvalue = 3; //C

	//				}
	//			}


	//			//if (s == "X" || s == "x" || s == "Y" || s == "y" || s == "Z" || s == "z")
	//			//{
	//			//	if (s == "x" || s == "X")
	//			//	{
	//			//		if (firstvalue == 3)
	//			//		{
	//			//			iterationsum = 6 + 1;
	//			//		}
	//			//		else if (firstvalue == 1)
	//			//		{
	//			//			iterationsum = 3 + 1;
	//			//		}
	//			//		else
	//			//		{
	//			//			iterationsum = 0 + 1;
	//			//		}
	//			//	}
	//			//	else if (s == "y" || s == "Y")
	//			//	{
	//			//		if (firstvalue == 1)
	//			//		{
	//			//			iterationsum = 6 + 2;
	//			//		}
	//			//		else if (firstvalue == 2)
	//			//		{
	//			//			iterationsum = 3 + 2;
	//			//		}
	//			//		else
	//			//		{
	//			//			iterationsum = 0 + 2;
	//			//		}
	//			//	}
	//			//	else if (s == "z" || s == "Z")
	//			//	{
	//			//		if (firstvalue == 2)
	//			//		{
	//			//			iterationsum = 6 + 3;
	//			//		}
	//			//		else if (firstvalue == 3)
	//			//		{
	//			//			iterationsum = 3 + 3;
	//			//		}
	//			//		else
	//			//		{
	//			//			iterationsum = 0 + 3;
	//			//		}
	//			//	}
	//			//}			

	//			if (s == "X" || s == "x" || s == "Y" || s == "y" || s == "Z" || s == "z")
	//			{
	//				if (s == "x" || s == "X")
	//				{
	//					if (firstvalue == 3) //sci
	//					{
	//						iterationsum = 2;  //Roc
	//					}
	//					else if (firstvalue == 2) //paper
	//					{
	//						iterationsum = 1;
	//					}
	//					else
	//					{
	//						iterationsum = 3;
	//					}
	//				}
	//				else if (s == "y" || s == "Y")
	//				{
	//					if (firstvalue == 3)
	//					{
	//						iterationsum = firstvalue + 3;  //C - Z
	//					}
	//					else if (firstvalue == 2)
	//					{
	//						iterationsum = firstvalue + 3; //B - Y
	//					}
	//					else
	//					{
	//						iterationsum = firstvalue + 3; //A - X
	//					}
	//				}
	//				else if (s == "z" || s == "Z")
	//				{
	//					if (firstvalue == 1)  //Rock 
	//					{
	//						iterationsum = 6 + 2; //Paper
	//					}
	//					else if (firstvalue == 3) //Sci
	//					{
	//						iterationsum = 6 + 1; //Rock
	//					}
	//					else //paper
	//					{
	//						iterationsum = 6 + 3; //Sci
	//					}
	//				}
	//			}
	//		}
	//		sum = sum + iterationsum;
	//	}


	//	if (infile.is_open())
	//		infile.close();
	//}



//---------------Day 3 ---------------------------
	//ifstream infile("D:\\Data-3-1.txt");
	//std::map<char, int> mymap
	//{
	//	{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8},
	//	{'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17},
	//	{'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26},

	//	{'A', 27}, {'B', 28}, {'C', 29}, {'D', 30}, {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34},
	//	{'I', 35}, {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40}, {'O', 41}, {'P', 42}, {'Q', 43},
	//	{'R', 44}, {'S', 45}, {'T', 46}, {'u', 47}, {'V', 48}, {'W', 49}, {'X', 50}, {'Y', 51}, {'Z', 52}
	//};


	//int nTotalSum = 0;


	////---------------------------1st---------------------------
	///*for (string line = ""; getline(infile, line); )
	//{
	//	if (line.empty())
	//		continue;

	//	string sFirstHalf = line.substr(0, line.length() / 2);
	//	string sSecondHalf = line.substr(line.length() / 2, line.length());

	//	for (int i = 0; i < sFirstHalf.length(); i++)
	//	{
	//		if (sSecondHalf.find(sFirstHalf[i]) != string::npos)
	//		{
	//			auto it = mymap.find(sFirstHalf[i]);
	//			if (it != mymap.end())
	//			{
	//				nTotalSum = nTotalSum + it->second;
	//				break;
	//			}
	//		}
	//	}
	//}*/

	//



	//	//---------------------------2nd-------------------------- -

	//int nCount = 3;
	//
	//int nsum = 0;
	//std::vector<std::string> myvec{};
	//for (string line = ""; getline(infile, line); )
	//{
	//	/*if (line.empty())
	//	{
	//		continue;
	//	//}*/

	//	if (myvec.size() == 3)
	//	{
	//		for (int i = 0; i < myvec[0].size(); i++)
	//		{
	//			int n1 = myvec[1].find(myvec[0][i]);
	//			int n2 = myvec[2].find(myvec[0][i]);

	//			if (n1 > -1 && n2 > -1)
	//			{
	//				auto it = mymap.find(myvec[0][i]);
	//				if (it != mymap.end())
	//				{
	//					nsum = nsum + it->second;
	//					myvec.clear();
	//					myvec.push_back(line);
	//					break;
	//				}
	//			}
	//		}
	//	}
	//	else
	//	{
	//		myvec.push_back(line);
	//	}
	//		
	//		
	//}

	//if (myvec.size() == 3)
	//{
	//	for (int i = 0; i < myvec[0].size(); i++)
	//	{
	//		int n1 = myvec[1].find(myvec[0][i]);
	//		int n2 = myvec[2].find(myvec[0][i]);

	//		if (n1 > -1 && n2 > -1)
	//		{
	//			auto it = mymap.find(myvec[0][i]);
	//			if (it != mymap.end())
	//			{
	//				nsum = nsum + it->second;
	//				myvec.clear();
	//				break;
	//			}
	//		}
	//	}
	//}

	//if (infile.is_open())
	//	infile.close();


//--------------------------------------------Day 4-------------------------------
	/*ifstream infile("D:\\Data-4.txt");
	for (string line = ""; getline(infile, line); )
	{
		istringstream iss(line);
		string s;

		while (getline(iss, s, ','))
		{
		
		}
	}

	if (infile.is_open())
		infile.close();*/


	//--------------------------------------------Day 5-------------------------------
		//ifstream infile("D:\\Data-5.txt");


		//std::vector<std::stack<char>> myvec;
		//myvec.reserve(9);
		//
		////stack 1
		//std::stack<char> sTemp1;
		//sTemp1.push('B');
		//sTemp1.push('W');
		//sTemp1.push('N');
		//myvec.push_back(sTemp1);

		////stack 2
		//std::stack<char> sTemp2;
		//sTemp2.push('L');
		//sTemp2.push('Z');
		//sTemp2.push('S');
		//sTemp2.push('P');
		//sTemp2.push('T');
		//sTemp2.push('D');	
		//sTemp2.push('M');
		//sTemp2.push('B');
		//myvec.push_back(sTemp2);


		////stack 3
		//std::stack<char> sTemp3;
		//sTemp3.push('Q');
		//sTemp3.push('H');
		//sTemp3.push('Z');
		//sTemp3.push('W');
		//sTemp3.push('R');
		//myvec.push_back(sTemp3);

		////stack 4
		//std::stack<char> sTemp4;
		//sTemp4.push('W');
		//sTemp4.push('D');
		//sTemp4.push('V');
		//sTemp4.push('J');
		//sTemp4.push('Z');
		//sTemp4.push('R');
		//myvec.push_back(sTemp4);

		////stack 5
		//std::stack<char> sTemp5;
		//sTemp5.push('S');
		//sTemp5.push('H');
		//sTemp5.push('M');
		//sTemp5.push('B');
		//myvec.push_back(sTemp5);

		////stack 6
		//std::stack<char> sTemp6;
		//sTemp6.push('L');
		//sTemp6.push('G');
		//sTemp6.push('N');
		//sTemp6.push('J');
		//sTemp6.push('H');
		//sTemp6.push('V');
		//sTemp6.push('P');
		//sTemp6.push('B');
		//myvec.push_back(sTemp6);


		////stack 6
		//std::stack<char> sTemp7;
		//sTemp7.push('J');
		//sTemp7.push('Q');
		//sTemp7.push('Z');
		//sTemp7.push('F');
		//sTemp7.push('H');
		//sTemp7.push('D');
		//sTemp7.push('L');
		//sTemp7.push('S');
		//myvec.push_back(sTemp7);

		////stack 7
		//std::stack<char> sTemp8;
		//sTemp8.push('W');
		//sTemp8.push('S');
		//sTemp8.push('F');
		//sTemp8.push('J');
		//sTemp8.push('G');
		//sTemp8.push('Q');
		//sTemp8.push('B');
		//myvec.push_back(sTemp8);

		////stack 8
		//std::stack<char> sTemp9;
		//sTemp9.push('Z');
		//sTemp9.push('W');
		//sTemp9.push('M');
		//sTemp9.push('S');
		//sTemp9.push('C');
		//sTemp9.push('D');
		//sTemp9.push('J');
		//myvec.push_back(sTemp9);


		//part 1
		//std::vector<int> myvec1;
		//for (string line = ""; getline(infile, line); )
		//{
		//	istringstream iss(line);
		//	string s;

		//	while (getline(iss, s, ' '))
		//	{
		//		myvec1.push_back(std::stoi(s));
		//	}

		//	for (int i = 0; i < myvec1[0]; i++)
		//	{

		//		char ch = myvec[myvec1[1] - 1].top();
		//		myvec[myvec1[2] - 1].push(ch);
		//		myvec[myvec1[1] - 1].pop();
		//	}

		//	myvec1.clear();
		//}

		//std::string str{};
		//for (int i = 0; i < myvec.size(); i++)
		//{
		//	str = str + (myvec[i].top());
		//}



		////part 2
		//std::vector<int> myvec1;
		//for (string line = ""; getline(infile, line); )
		//{
		//	istringstream iss(line);
		//	string s;

		//	while (getline(iss, s, ' '))
		//	{
		//		myvec1.push_back(std::stoi(s));
		//	}

		//	std::vector<char> vTemp;
		//	for (int i = 0; i < myvec1[0]; i++)
		//	{
		//		char ch = myvec[myvec1[1] - 1].top();
		//		vTemp.push_back(ch);
		//		myvec[myvec1[1] - 1].pop();
		//	}

		//	std::reverse(vTemp.begin(), vTemp.end());
		//	for (int i = 0; i < vTemp.size(); i++)
		//	{
		//		myvec[myvec1[2] - 1].push(vTemp[i]);
		//	}

		//	vTemp.clear();
		//	myvec1.clear();
		//}

		//std::string str{};
		//for (int i = 0; i < myvec.size(); i++)
		//{
		//	str = str + (myvec[i].top());
		//}


		//if (infile.is_open())
		//	infile.close();


//--------------------------------------------Day 6-------------------------------
	/*ifstream infile("D:\\Data-6.txt");
	int answer = 0;

	for (string line = ""; getline(infile, line); )
	{
		for(int i = 0; i < line.length(); i++)
		{
			std::string str = line.substr(i, 14);
			bool bvalue = false;
			for(int nchar = 0; nchar < str.length(); nchar++)
			{
				if( std::count(str.begin(), str.end(), str[nchar]) > 1)
				{
					bvalue = true;
					break;
				}
			}


			if (!bvalue)
			{
				answer = 14 + i;
				break;
			}
				
		}
	}

	if (infile.is_open())
		infile.close();*/
	
}





