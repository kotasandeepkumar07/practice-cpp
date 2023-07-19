 // SingletonClass.cpp : Defines the entry point for the console application.
//

/*

  Reason for Private Constructor: 

		The reason for making a constructor private is restricting any one else to create the object, 
		becuase to create a object we need a constructor

  Reason for static method:

		If the method is a normal method then it has to be called using object and there is no object exists to call,
		The primary reason of using this function is to create object.

  Reaosn for static member variable:

		As it is for sure that we have to use static method, we have to use static member variable because
		a normal variable cant be used in a static method.

		The static variable will retain its value where as a normal variable will not.



  */

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <thread>


using namespace std;

//class Singleton
//{
//private:
//    static bool instanceFlag;
//    static Singleton *single;
//	Singleton()
//    {
//        //private constructor
//    }
//
//public:
//    static Singleton* getInstance();
//    void method();
//
//
//
//    ~Singleton()
//    {
//        instanceFlag = false;
//    }
//};
//
//
//bool Singleton::instanceFlag = false;
//Singleton* Singleton::single = NULL;
//
//Singleton* Singleton::getInstance()
//{
//    if(! instanceFlag)
//    {
//        single = new Singleton();
//        instanceFlag = true;
//        return single;
//    }
//    else
//    {
//        return single;
//    }
//}
//
//void Singleton::method()
//{
//	int a = 9;
//	a++;
//    cout << a << endl;
//}
//
//int main()
//{
//    Singleton *sc1,*sc2;
//    sc1 = Singleton::getInstance();
//    sc1->method();
//    sc2 = Singleton::getInstance();
//    sc2->method();
//	
//    return 0;
//}
//



/*
class Singleton
{
private:
	Singleton(){}

public:
    static Singleton* instanceFlag;
    static Singleton* getInstance();
};


Singleton* Singleton::instanceFlag = NULL;

Singleton* Singleton::getInstance()
{
    if(instanceFlag == NULL)
    {
        instanceFlag = new Singleton();
		cout<<"New Instance"<<endl ;
        return instanceFlag;
    }
  else
  {
	cout<<"old Instance"<<endl ;
     return instanceFlag;

  }
}


int main()
{
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
	cout<<"present"<<endl;


    sc2 = Singleton::getInstance();
	cout<<"Done!!"<<endl;

    return 0;
}

*/




//
//class singleton 
//{
//	
//private:
//	static singleton* m_statusvariable;
//
//public:
//	static singleton* GetInstance();
//
//protected:
//
//	singleton(){};
//
//};
//
//singleton*  singleton::m_statusvariable = NULL;
//singleton* singleton::GetInstance()
//{
//	if( m_statusvariable == NULL )
//	{
//		cout<<"checking attendance"<<endl;
//		m_statusvariable = new singleton;
//		return m_statusvariable;
//	}
//
//	else 
//	{
//		cout<<"done"<<endl;
//		return m_statusvariable;
//	}
//	
//}
//
//
//
//void main()
//{
//
//	singleton* obj1;
//	obj1 = singleton::GetInstance();
//	cout<<"present"<<endl;
//
//	singleton* obj2;
//	obj2 = singleton::GetInstance();
//
//
//}
//
//
//







//*******************************  singleton to restrict to 2 instances *******************************/
/*
class singleton
{
private:
	singleton(){}

public:
	static singleton * instance;
	static singleton * getinstance();
	static int count ;

};


singleton* singleton::instance = NULL;

int singleton::count = 0;


singleton *singleton::getinstance()
{
	if(count <2)
	{
		if(instance == NULL)
		{
			instance =  new singleton();
			cout<<"new instance"<<endl;
			count++;
			return instance;
		}

		cout<<"old instance"<<endl;
		count++;
		return instance;
	}

	else
	{
		return NULL;
	}
}

void main(void)
{
	singleton *s1, *s2, *s3;
	s1 = singleton::getinstance();
	s2 = singleton::getinstance();
	s3 = singleton::getinstance();

	if(s3 == NULL)
	{
		cout<<"no more than 2"<<endl;
	}
}*/


//************************************  //early initalization (to avoid multithreaded problems) *********************//

/*

class singleton
{
private:
	singleton() { }

public:

	static singleton* instance;
	static singleton* getinstance();

};

singleton* singleton::instance = new singleton; 

singleton* singleton::getinstance()
{
	if(instance == NULL)
	{
		cout<<"new instance"<<endl;
		instance= new singleton;
		return  instance;
	}
	cout<<"old instance"<<endl;
	return instance;
}


void main()
{
	singleton *s1, *s2;
	s1 = singleton::getinstance();
	s2= singleton::getinstance();
}
*/

/*
class singleton
{
protected:
	singleton() {}
public: 
	static int count;
	static singleton * instance;
	static singleton * getinstance();
};

singleton * singleton::instance = NULL;
int singleton::count = 1;
singleton * singleton ::getinstance()
{
	cout<<"count is"<<count<<endl;
	if(count <= 2)
	{
		if(instance == NULL)
		{
			instance =  new singleton();
			cout<<"new instance"<<endl;
			count++;
			return instance;

		}
		count++;
		cout<<"old instance"<<endl;
		return instance;
	}

	return NULL;
}

void main()
{
	singleton *s1, *s2, *s3;
	s1 = singleton::getinstance();
	s2 = singleton::getinstance();

	s3 = singleton::getinstance();
	if(s3 == NULL) { cout<< "returned null"<<endl; }

}

*/

//class singleton
//{
//private:
//	singleton() {}
//	static singleton *Instance;
//
//public:
//	static singleton* GetInstance();
//};
//
//singleton* singleton::Instance = NULL;
//
//
//singleton* singleton::GetInstance()
// {
//	 if (!Instance)
//	 {
//
//		 cout << "new instance" << endl;
//		 Instance = new singleton();
//		 return Instance;
//	 }
//	 else
//	 {
//		 return Instance;
//	 }
//
//	 return NULL;
// }
//
//void main()
//{
//	singleton *ps1, *ps2;
//	ps1 = singleton::GetInstance();
//	ps2 = singleton::GetInstance();
//}

//
//class singleton
//{
//private:
//	singleton() {}
//	static singleton *Instance;
//
//public:
//	static singleton* OpenFile();
//};
//
//singleton* singleton::Instance = NULL;
//
//singleton* singleton::OpenFile()
//{
//	if (!Instance)
//	{
//		cout << "File opened" << endl;
//		Instance = new singleton();
//		return Instance;
//	}
//	else
//	{
//		cout << "File  is already open" << endl;
//		return Instance;
//	}
//
//	return NULL;
//}
//
//void main()
//{
//	singleton *ps1, *ps2;
//	//ps1 = singleton::OpenFile();
//	//ps2 = singleton::OpenFile();
//
//	fstream file;
//	file.open("D:\\logfile.txt", ios::out);
//	file.write("line1",100);
//	file.open("D:\\logfile.txt", ios::out);
//	file.write("line2", 100);
//
	//std::thread first(&singleton::OpenFile);
	//first.join();
//
//	//std::thread second(&singleton::OpenFile);
//	//second.join();
//
//	//std::thread second(singleton::OpenFile());
//
//}



//Aim : Create 1 single object of that class

//class singleton
//{
//private:
//	singleton() {}
//public:
//	static singleton* GetInstance();
//	static singleton* Instance;
//};
//
//singleton* singleton::Instance = new singleton();
//
//singleton* singleton::GetInstance()
//{
//	if (Instance == NULL)
//	{
//
//
//		//Instance = new singleton;
//		//cout << "new instance" << endl;
//		return Instance;
//	}
//	else
//	{
//		cout << "old instance" << endl;
//		return Instance;
//	}
//
//	return NULL;
//}
//
//void main()
//{
//	singleton* s1;
//	s1 = singleton::GetInstance();
//
//	//singleton* s2;
//	//s2 = singleton::GetInstance();
//
//}


#include <thread>
#include <chrono>
#include  <mutex>
#include <atomic>
//using namespace std;
//
//	class Singleton
//	{
//	private:
//		Singleton() {};
//		static Singleton* pInstanceObj;
//		static int i;
//		static mutex _m;
//
//	public:
//		~Singleton() 
//		{ 
//			if (pInstanceObj) 
//				delete pInstanceObj;
//		};
//
//		static Singleton* GetInstance()
//		{
//		
//			//  The technique of using two if judgement statements here is called double check lock; 
//			//the advantage is that only when the judgement pointer is empty can it be locked.
//		 //  Avoid locking every time the GetInstance method is called. After all, the cost of locking is a little high.
//			lock_guard<mutex> lock(_m);
//			if (pInstanceObj == nullptr)
//			{
//				pInstanceObj = new Singleton();
//				return pInstanceObj;
//			}
//				
//			else
//				return pInstanceObj;
//		}
//	};
//
//Singleton* Singleton::pInstanceObj = nullptr;
//
//
//void main()
//{
//	Singleton *ptr1 = Singleton::GetInstance();
//	Singleton *ptr2 = Singleton::GetInstance();
//
//}






#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex _mymutex;
using namespace std;

class Singleton
{

private:
	Singleton() {}
	static Singleton* m_hInstance;

public:
	static Singleton* getInstance()
	{
		std::lock_guard<std::mutex> lg(_mymutex);
		if (m_hInstance == nullptr)
		{
			m_hInstance = new Singleton();
		}
		return m_hInstance;
	}
};

Singleton* Singleton::m_hInstance = nullptr;


void threadFunc(int id)
{
	Singleton* ptr = Singleton::getInstance();
	cout << ptr << " " << id << endl;
}

int main()
{

	std::thread th[10];

	for (int i = 0; i < 10; i++)
	{
		th[i] = std::thread(threadFunc, i);
	}

	for (int i = 0; i < 10; i++)
	{
		th[i].join();
	}
}































