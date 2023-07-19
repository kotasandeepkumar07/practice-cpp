// Tuples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>

using namespace std;



int main()
{

	struct MyStruct
	{
		int a;
		string str;
		float f;
	};


	typedef std::tuple <int, char, float> tp;

	//tp tp1(1, 's', 2.45);
	//tp tp2{ 1, "sandeep", 2.45 };
	tp tp3 = make_tuple(1, 's', 2.45);


	cout << sizeof(tp) << endl;

	//number of elements
	//cout << "No of Elements are "<<tuple_size<tp>::value << endl;	


	//get elements out of a tuple
	cout << "First Element is "<<get<0>(tp3) << endl;
	cout << "Third Element is "<<get<2>(tp3) << endl;



	////set values
	get<0>(tp3) = 2;
	cout << "Modified first Element is " << get<0>(tp3) << endl;




	////using tie to get all values separately
	//int i_val;
	//char ch_val;
	//float f_val;
	//tie(i_val, ch_val, f_val) = tp3;



	////combine two tuples 
	//tuple <int, char, float> tup1(20, 'g', 17.5);
	//tuple <int, char, float> tup2(30, 'f', 10.5);

	//auto tup3 = tuple_cat(tup1, tup2);
}





