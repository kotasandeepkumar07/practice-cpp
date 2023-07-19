
//********* overloading function differ only in number of arguments passed  ***********//

//#include "StdAfx.h"
//#include <iostream>
//using namespace std;




//void sum(int i) 
//{
//  cout << "One parameter" << endl <<  i << endl;
//}
//
//void print(int a, int b) 
//{
//  cout << "Two parameters" <<endl << a << endl<< b << endl;
//}
//
//
//int main()
//{
//  print(10);
//  print(100,200);
//
//  return 1;
//}








//**********  overloading function differ only in data type of arguments passed  ***********//

//#include "stdafx.h"
//#include <iostream>
//using namespace std;
//
//
//void print(int i) 
//{
//  cout << "integer type " << endl <<  i << endl;
//}
//void print(double a) 
//{
//  cout << "Double type " << endl << a << endl;
//}
//
//
//void main()
//{
//   print(10);
//   print(100.235);
//}



//******** overloading function differ in both no of arguments passed &  data type of arguments passed *********//

//
//#include "stdafx.h"
//#include <iostream>
//using namespace std;


//void print(int i) 
//{
//  cout << "Integer type " << endl <<  i << endl;
//}
//void print(double a, double b) 
//{
//  cout << "Double type " << endl << a << endl << b << endl;
//}
//
//
//void main()
// {
//  print(10);
//  print(100.123, 200.456);
//}
//
//



#include "StdAfx.h"
#include <iostream>
#include <vector>


//polymorphism - multiple forms 
//	static or compile time
//	Dynamic or runtime polymorphism


//name manglingy


using namespace std;
class CBase
{
public:
	
	CBase()
	{
		cout<< "base constructor"<<endl;
	}
	
	virtual ~CBase()
	{
		cout<< "base destructor"<<endl;
	}
};

class CDerived : public CBase
{
public:
	
	CDerived()
	{
		cout<< "derived constructor"<<endl;
	}
	
	
	~CDerived()
	{
		cout<< "derived destructor"<<endl;
	}
};

void main()
{	
	CBase* p = new CDerived();


	delete p;
}
