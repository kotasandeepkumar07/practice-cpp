

/**************************************** Macros are dangerous:*******************************************************/
// Never use them with arguments 


//#include "stdafx.h"
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//#define Square(x)  x*x
//
//void main()
//{
//	int n = 100 / Square(5);
//	cout << n << endl; //expected is 4 but it returns 100 
//
//	vector<int> a;
//}
//


/**************************************** Templates:*******************************************************/


// Generic Function (Class) is a function which works the same way irrespective of the data types passed as arguments.
// The Generic functions are achieved using the keyword Template, 
// This is in one way overloading a function with different data types of arguments passed


//Templated classes are never compiled. It acts as only a replica for a new class. 
// Whenever we create the object for the template class the class gets compiled 


/******************************************** Basic Programme   ***********************************************************/

//In the example below the add functions works same for both int and float types without any issues,
// which can't happen without template because we need to explicitly tell the compiler the return type of the function 
// and the parameters are also should be of same type.
//In the below example we can add only either int or float types not both (without templates)
// x in the following example is generic(common, universal) data type and add is an generic function or template function.
// The function definition should immediately followed by template declaration(no other statements should come in between)


//#include "stdafx.h"
//#include <iostream>
//using namespace std;
//
//// declaration of template 
//template <typename x>  // template <class x>    // both are correct 
//void add(x a, x b)
//{
//	x c =  a+b;
//	cout<<c<<endl;
//}
//
//void  main()
//{
//	add<double>(1.56, 2.78);
//	add(2,4);	
//}


/********************************  Function with two Generic Types **************************************************/
  
//#include "stdafx.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename x>   // two generic types "x", "y"
//void add(x a, x b)
//{
//	x c = a + b;
//	cout<< c <<endl;
//}
//
//void  main()
//{
//	//add(1.56, 6);
//	//add(6, 1.5); //add(int, double)
//	add(2, 4);	
//	add('a', 'b');
//	std::string s1 = "Hello";
//	std::string s2 = "world";
//	add(s1, s2); //does not work 
//	add(string("hello"), string("world123"));
//}


/********************************  Overloading template function **************************************************/
//
//#include "stdafx.h"
//#include <iostream>
//
//template <class x, class y>   
//void  add(x a, y b)
//{
//	x c =  a+b;
//	cout<<"I am a Template class"<<endl;
//	cout<<c<<endl;
//}
//
//void add(int c, int d) // overloaded template function (this works for only int types)
//{
//	int sum = c+d;
//	cout<<"I am not a Template class"<<endl;
//	cout<<sum<<endl;
//}
//
//
//void  main()
//{
//	add(1.56, 2.78);
//	add(2, 4);	// this will not call template function add (it calls overloaded function add)
//}





/***************************************** Overloading Template  **************************************************/


#include "stdafx.h"
#include <iostream>

//template <class x, class y, class z>
//void  add(x a, y b, z c, x d)
//{
//	//x c =  a+b;
//	cout<<"I am "<<endl;
//	cout<<c<<endl;
//}
//
//template <class x, class y, class z> // template is overloaded
//void add (x a, y b, z c)
//{
//	x sum = a+b+c;
//	cout<<"i am overloaded Template"<<endl;
//	cout<<sum<<endl;
//}


//template <class str> // template is overloaded
//void add(str a, str b)
//{
//	str sum = a + b;
//	cout << "i am overloaded Template" << endl;
//	//cout << sum << endl;
//}
//
//void  main()
//{
//	//add(1.56, 2.78);
//	//add(2,4);	
//	//add(1,2,3);// this will call overloaded template 
//
//	add("hello", "world");
//}


/**************************************  Restrictions on Template Overloading  ****************************************/

// 1)  Unlike functions, The template can't be overloaded using different data types of arguments 
//	   (though same number of parameters)
// when compiled :     'add' : template function has already been defined


#include "stdafx.h"
#include <iostream>
using namespace std;

//
//template <class x, class y>   
//void add(x a, y b)
//{
//	x c =  a+b;
//	cout<<"I am a Template class"<<endl;
//	cout<<c<<endl;
//}
//
//template <class k,class z> 
//void add (k b, z c)
//{
//	k sum = b+c;
//	cout<<"i am overloaded Template"<<endl;
//	cout<<sum<<endl; 
//}
//
//
//void  main()
//{
//	add(1.56, 2.78);
//	add(2,4);	
//
//}



/**************************************  class Template  ****************************************/


#include "stdafx.h"
#include <iostream>

//template <class T>
//class Item
//{
//private:
//	T data;
//public:
//	Item():data(0) {}
//
//	void SetData(T nValue)
//    { 
//        data = nValue;
//    }
//
//    T GetData() const
//    {
//        return data;
//    }
//
//    void PrintData()
//    {
//        cout << data;
//    }
//};
//
//void main()
//{
//	Item<int> item1;
//	item1.SetData(10);
//	item1.PrintData();
//
//	Item<float> item2;
//	item2.SetData(30);
//	item2.PrintData();
//}

//template <typename T>
//void fun(const T&x)
//{
//	static int count = 0;
//	cout << "x = " << x << " count = " << count << endl;
//	++count;
//	return;
//}
//
//int main()
//{
//	fun<int>(1); //fun(int a)
//	cout << endl; //output x = 1, count = 0
//
//	fun<int>(1);
//	cout << endl; //output x = 1, count = 1;
//
//	fun<double>(1.1); // func(int double)
//	cout << endl; ////output x  = 1.1 count = 0
//
//	return 0;
//}

#include <iostream>
using namespace std;
#include <string>

template <typename T, typename T1>
T1 max(T x, T1 f)
{
	
	T1 f = static_cast<T1>(x);
	return f;

	//return (x > y) ? x : y;
}
int main()
{
	int i = 10;
	float a;
	max(i, a);

	//cout << max(3, 7) << std::endl; // 7
	//cout << max(3.0, 7.0) << std::endl; //7
	//cout << max(3, 7.0) << std::endl; //
	return 0;
}


//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//template<class T, class U>
//class A  
//{
//	T x;
//	U y;
//	static int count;
//};
//
//int main()  
//{
//	A<char, char> a;
//	A<int, int> b;
//
//	//cout << sizeof(a) << endl; 
//	cout << sizeof(b) << endl;
//	return 0;
//}



#include <iostream>
using namespace std;

//template <int i>
//void fun();
//
//int main()
//{
//
//	//func();
//	//fun<10>();
//	//fun<10>();
//	//func<int>(10)
//	return 0;
//}