
//********* overloading function differ in their return type  ***********//



//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//int print(int i) // const
//{
//  cout << "integer return type" << endl <<  i << endl;
//  return 0;
//
//}
//
//double print(int a)
//{
//  cout << "double return type" <<endl << a << endl;
//  return 0;
//}
//
//
//void main()
//{
//    print(10);
//    print(100);
//}
//


//********* overloading function differ because of their default arguments ***********//

#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int i) 
{
  cout << "Without Default Argument" << endl <<  i << endl;
}

void print(int i, int a  = 30)
{
	cout << "Without Default Argument" << endl << i << endl;
}


void print(int a = 30, bool c = false, int b = 100 )
{
	int k = a;
	bool btest = c;

  cout << "With Default Argument" <<endl << b<<  endl;
}


void main()
{
  //print();
  print(false);
  //print(10);
  //print(10, 10);
}












/*
class Test
{

public:
	Test() {}
private:
	~Test() {}
};


void main()
{
	Test obj; //error
	Test *p = new Test; //fine
}
*/