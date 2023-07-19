// TEST.cpp : Defines the entry point for the console application.
//

/*
#include "stdafx.h"
#include "iostream.h"
#include "string.h"
#include <vector>
/*
using namespace std;
//******************************************* Finding string length ***************************************************

// string length, string reversal, string comparision, string copy, finding substring of a string
/*

#include "stdafx.h"
#include "iostream.h"
#include "string.h"


int strlength(char *string)
{

	for(int nlength =0; *string != '\0'; string++)
	{
		nlength++;
	}
	return nlength;
}

/*	char *p=s;

	while(*p!='\0')
	{
		p++;
	}
	return(p-s);

}  */

/*

void main(int argc, char* argv[])
{
	int j =  strlength("sandeep");

	cout<<j<<endl;
}
*/



//******************************************* Reversing a string ***************************************************//

/*
#include "stdafx.h"
#include "iostream.h"
#include "string.h"


int findlength(char *str)
{
	int length;
	for(length =0; *str!='\0'; str++)
	{
		length++;
	}
	return length;
}



void main()
{
	char str[100];
	cout<<"please Enter the string to be reversed"<<endl;
	cin>>str;

	int len = findlength(str);
	int j = len-1;

	for (int i =0; i<j; i++)
	{
		char temp = str[i];
		str[i]    = str[j];
		str[j]	  = temp;
		j--;
	}
	cout<<"Reversed string is"<<str<<endl;

}
*/


//*************************************** STRING COMPARISION ******************************************************//

/*
#include "stdafx.h"
#include "iostream.h"
#include "string.h"

void main()
{
	char str1[100];
	char str2[100];
	
	cout<<"Enter First String"<<endl;
	cin>>str1;

	cout<<"Enter Second String"<<endl;
	cin>>str2;
	int i =0;

	if(strlen(str1) != strlen(str2))
	{
		cout<<"strings are not same"<<endl;
	}
	else
	{
		for(int i=0; i<strlen(str1); i++)
		{
			if(str1[i] != str2[i])
			{
				cout<<"string are not same"<<endl;
			}

			else if( str1[i] == str2[i] )
			{
				cout<<"string are equal"<<endl;
			}
		}
	}

}

  */


//*************************************** SWAPPING TWO STRINGS WITHOUT USING TEMP ******************************************************//


/*

#include "stdafx.h"
#include "iostream.h"
#include "string.h"

void main()
{
	char str1[100];
	char str2[100];

	cout<<"enter string1"<<endl;
	cin>>str1;
	cout<<"string 1 before swapping     "<<str1<<endl;

	cout<<"enter string2"<<endl;
	cin>>str2;
	cout<<"string 2 before swapping     "<<str2<<endl;

	for(int i =0; i<10;i++)
	{
		str1[i] = str1[i]+str2[i];
		str2[i] = str1[i]-str2[i];
		str1[i] = str1[i]-str2[i];
	}

	cout<<"string 1 after swapping     "<<str2<<endl;
	cout<<"string 2 after swapping     "<<str1<<endl;
}

/*

int main()
{
	extern const int &ri;
	return 0;
}
*/

/*
void main()
{
	int array[4] = {1,2,3,4} ;


	for(int i =0, int j=3; i<j;  i++, j--)
	{
		
         array[i] = array[j];

		 cout<<array[i]<<endl;
	}

}*/


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


singleton *singleton::instance = NULL;

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
}

  */


//********************************** copy constructor and assignment operator ********************************/

/*
class Base
{
private:
		char *str;
public:

	Base(char *s) 
	{ 
		str = new char[sizeof(s)];
		strcpy(str, s);
	}
	Base(const Base& obj);
};


Base::Base(const Base& obj)
{
//	str = new char[sizeof(obj.str)];
//	*str = *obj.str;
}

void main()
{
	Base obj("sandeep");
  Base obj1	=  obj;

//	Base *obj =  new Base("sandeep");
//	Base *obj1	=  obj;

}
*/


/*

class Base
{
private :
		char *str;
public:

	Base(char *s) 
	{ 
		str =  new char[10];
		strcpy(str, s);
	}
	Base(const Base& ob) 
	{
		str = new char[sizeof(ob)];
		*str = *ob.str;
	}

	char *getChars(){ return str; }

	~Base()
	{
		delete str;
	}

	Base& operator=(const Base &p)
	{
		str = new char[sizeof(p)];
		*str = *p.str;
		
		return *this;
	}
};

void main()
{
	Base obj("hi");
	Base obj1 = obj;

	Base obj2("");
	obj = obj2;

}
*/



/*
void main()
{
	char ch = 'A';
	
	cout<<ch<<endl;
}

  */


/*

class cl
{
	int i;
public:
	void set_i(int j) { i=j; }
	int get_i() { return i; }
};



int main()
{
	cl ob[3] = { cl(1), cl(2), cl(3) };


	for(int i=0; i<3; i++)
	{
		cout << ob[i].get_i() << "\n";
	}

	return 0;
}

*/
/*
class A
{
private:
	int m_i;

public:

	A() { } 
	void print(int i) { m_i = i;}

};

void main()
{
	vector <A> vect;
	A *p = new A;
	p->print(10);
	vect.push_back(*p);

	vect.at(0);

}
*/


//************ allow on heap only**/////

/*
class Test
{

public:
	static Test* instance;
	static Test* GetInstance();

private:

	Test() {};

};


Test* Test::instance = NULL;

Test* Test::GetInstance()
{
	instance = new Test;
	cout<<"new instance"<<endl;
	return instance;

}



void main()
{
	Test ob2;

	Test *ob1;
	ob1 = Test::GetInstance();

}
*/


//******** allow only on stack and not on heap *********/

/*

class Test
{
	void* operator new (size_t)
	{ 
		void *p = NULL;
		return p;
	}

public:

	int getvalue () {return 10;}


public:
	Test() {};

};

void main()
{
	Test ob2;
	Test *ob1 = new Test;
	int j = ob1->getvalue();
	cout<<j<<endl;
}

*/
/*
void main()
{
	int i = 769;

	int x = (i >> (8*1)) & 0xff ; // to know value in the 1st byte
	int x = (i >> (8*2)) & 0xff ; // to know value in the 2nd byte
	cout<<x<<endl;
}


union  Test 
{
	int i ;
	char ch[4];
	Test(){ i = 10;}
};


void main()
{
	Test obj;
	cout<<obj.i<<endl;
}
*/

/*
class Base
{

public:

	void print() { cout<<"i am base"<<endl;}

};


class  Derived : public Base
{
public:
	void print() { cout<<"i am derived"<<endl;}

};


void main()
{

	Base *b = new Base ;

	Derived *d =  new Derived;

//	Derived *p = dynamic_cast <Derived *> (b);
	Base *p = dynamic_cast <Base *> (d);
	p->print();

}
*/

/*
class B 
{
public:
	virtual	void print() {cout<<"base"<<endl;}

};
class D : public B 
{
public:
	void print() {cout<<"derived"<<endl;}
};

class X
{

};

int main()
{
  D* d = new D;

  B* b = new B;

  B* p = d; //upcasting is easy -- no harm


//  D* n = dynamic_cast <D *> (b); ///down casting is dangerous 

 // n->print();

 X* x = dynamic_cast<X*>(d); // ERROR - Won't compile

  return 0;
}
*/


/*
class Singleton
{
private:
	Singleton() {}
public:
	static Singleton* Instance;
	static Singleton* GetInstance();

};

Singleton* Singleton::Instance = NULL;

Singleton* Singleton::GetInstance()
{
	if(Instance == NULL)
	{
		Instance = new Singleton();
		cout<<"New Instance"<<endl;
		return Instance;
	}
	else
	{
		cout<<"Old Instance"<<endl;
		return Instance;
	}
}

void main()
{
	Singleton *obj;
	obj = Singleton::GetInstance();

	Singleton *obj2;
	obj2 = Singleton::GetInstance();
}


*/

/*

class Base
{
private:
		char *str;
public:

	Base(char *s) 
	{ 
		str = new char[sizeof(s)];
		strcpy(str, s); 
		cout<<str<<endl;
	}

	Base(const Base& obj)
	{
		cout<<"copy constructor"<<endl;
		str = new char[sizeof(obj)];
		*str = *obj.str;
	}

	Base& operator=(const Base&obj)
	{
		cout<<"Assignment operator"<<endl;
		str = new char[sizeof(obj)];
		*str = *obj.str;
		return *this;
	}
	
};

	void function (Base str)
	{
		cout<<"I will crash after this"<<endl;
	}


void main()
{
	Base obj1("");;
	Base obj2 = obj1;

	Base obj3("hi");
	obj1 = obj3;

	Base str("hi");
	function(str);// program crush

}

class Base
{
public:
	void call() {cout<<"hi"<<endl;}

};

void main()
{

	std::auto_ptr<Base>p(new Base);
	p->call();
}*/


/*
class Base
{
public:

	void  Get() {cout<<"getfunction"<<endl;}

};

class Derived : public Base
{
public:
		void  Get1() {cout<<"getfunction1"<<endl;}
	
};


void main()
{

	Base *b = new Base;
	Derived *d =  new Derived;

	//downcasting dangerous

	Base *pb = (Base *)(d);
	pb->Get1();

}

*/


/*
class Base
{
public:
	int m_i;

	Base(int i) { m_i =i;} 

virtual	void func() 
	{
		
		cout<<m_i<<endl;

	}

};

class Derived :public Base
{
	int m_j;

public:
	Derived(int i, int j):Base(i)
	{
		m_j = j;
	}

	void func() 
	{	
		cout<<m_i<<m_j<<endl;

	}
};

void somefunc(Base obj)
{
	obj.func();

}


void main()
{
	Derived obj(10, 30);

	somefunc(obj);
}
*/

/*
class Base
{
public:

	const int empid ;
	int salary;
	void func()   {};
	Base(): empid(10) { salary = 10;}

};



void main()
{
	const Base obj;
	obj.func();

}
*/



/*

#include <stdio.h>      // printf 
#include <assert.h>     // assert 

void print_number(int* myInt) 
{
  assert (myInt!=NULL);
  printf ("%d\n",*myInt);
}

int main ()
{
  int a=10;
  int * b = NULL;
  int * c = NULL;

  b=&a;

  print_number (b);
  print_number (c);

  return 0;
}
*/
/*
class Base
{

public:

	Base() {}

private:

	~Base() {}
};



class Derived : public Base
{
	Derived ()  {}
};

void main()
{
}
*/

//**************************************  Random Number Generation ********************************//

/*
int  Randomgen()
{
	int nfirstval = 2334;
	static unsigned int nFinalval = 1;
	nFinalval = ((6 * nFinalval) + 236);
	int nRes = nFinalval/3 ;
	return nRes;
}


void main()
{
	for(int i = 0; i <70; i++)
	{
		int n  = Randomgen();
		cout<<n<<endl;
	}
}

*/



/*
class Base {};
class Derived: public Base {};
int main()
{
   Derived d;
   // some other stuff
   try 
   {
       // Some monitored code
       throw d;
   }
   	catch(Base b) 
	{ 
        cout<<"Caught Base Exception";
	}

    catch(Derived d) 
	{  //This catch block is NEVER executed
        cout<<"Caught Derived Exception";
	}

  
   return 0;
}

/*

void Xhandler(int test) throw()
{
//	if(test==0) throw test; // throw int
	if(test==1) throw 0; // throw char
//	if(test==2) throw 123.23; // throw double
}

int main()
{
	cout << "start\n";
	try
	{
		Xhandler(1); // also, try passing 1 and 2 to Xhandler()
	}
	catch(int)
	{
		cout << "Caught an integer\n";
	}
	catch(char)
	{
		cout << "Caught char\n";
	}
	catch(double)
	{
		cout << "Caught double\n";
	}

	catch(...)
	{
		cout << "Caught unknown\n";
	}

	cout << "end";
	return 0;
}
*/

/*
class Base
{
public:
	static int i;
	int temp;
};

int Base::i = 10;

void main()
{
	Base obj;
	obj.temp ;

}


*/

/*

class Base
{
public:
	int i;
	Base() { i = 0;}
	void add() const;
	void sub(){};
};


void Base::add() const 
{
	int j = i;
	cout<<j<<endl;

}

void main()
{

const Base obj;
	obj.add();
	obj.sub();
}
*/


/*
 
class P 
{
public:
   void print()  { cout <<" Inside P"; }
};
  
class Q : public P 
{
public:
   void print() { cout <<" Inside Q"; }
};
  
class R: public Q 
{ 
};


class S: public R
{ 
};

  
int main(void)
{
  S r; 
  r.print();
  return 0;
}
*/
/*

class Test
{
private:
    ~Test() {}
friend void destructTest(Test* );
};
 
// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
}
 
int main()
{
    // create an object
    Test *ptr = new Test;
 
    // destruct the object
    destructTest (ptr);
 
    return 0;
}
*/


#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>

#define MAX_THREADS  32

// The function getrandom returns a random number between 
// min and max, which must be in integer range.
#define getrandom( min, max ) (SHORT)((rand() % (int)(((max) + 1) - \
                               (min))) + (min))

void main( void );                    // Thread 1: main 
void KbdFunc( void  );               // Keyboard input, thread dispatch
void BounceProc( void * MyID );      // Threads 2 to n: display 
void ClearScreen( void );            // Screen clear 
void ShutDown( void );               // Program shutdown 
void WriteTitle( int ThreadNum );    // Display title bar information 

HANDLE  hConsoleOut;                 // Handle to the console 
HANDLE  hRunMutex;                   // "Keep Running" mutex 
HANDLE  hScreenMutex;                // "Screen update" mutex
int     ThreadNr;                    // Number of threads started 
CONSOLE_SCREEN_BUFFER_INFO csbiInfo; // Console information 


void main() // Thread One 
{
    // Get display screen information & clear the screen.
    hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );
    ClearScreen();
    WriteTitle( 0 );

    // Create the mutexes and reset thread count.
    hScreenMutex = CreateMutex( NULL, FALSE, NULL );  // Cleared 
    hRunMutex = CreateMutex( NULL, TRUE, NULL );      // Set 
    ThreadNr = 0;

    // Start waiting for keyboard input to dispatch threads or exit.
    KbdFunc();

    // All threads done. Clean up handles.
    CloseHandle( hScreenMutex );
    CloseHandle( hRunMutex );
    CloseHandle( hConsoleOut );
}

void ShutDown( void ) // Shut down threads 
{
    while ( ThreadNr > 0 )
    {
        // Tell thread to die and record its death.
        ReleaseMutex( hRunMutex );
        ThreadNr--;   
    }
    
    // Clean up display when done
    WaitForSingleObject( hScreenMutex, INFINITE );
    ClearScreen();
}

void KbdFunc( void ) // Dispatch and count threads.
{
    int         KeyInfo;

    do
    {
        KeyInfo = _getch();
        if ( tolower( KeyInfo ) == 'a' && 
             ThreadNr < MAX_THREADS )
        {
            ThreadNr++;
           _beginthread( BounceProc, 0, &ThreadNr );
            WriteTitle( ThreadNr );
        }
    } while( tolower( KeyInfo ) != 'q' );

    ShutDown();
}

void BounceProc( void *pMyID )
{
    char    MyCell, OldCell;
    WORD    MyAttrib, OldAttrib;
    char    BlankCell = 0x20;
    COORD   Coords, Delta;
    COORD   Old = {0,0};
    DWORD   Dummy;
    char    *MyID = (char*)pMyID;

    // Generate update increments and initial 
    // display coordinates.
    srand( (unsigned int) *MyID * 3 );

    Coords.X = getrandom( 0, csbiInfo.dwSize.X - 1 );
    Coords.Y = getrandom( 0, csbiInfo.dwSize.Y - 1 );
    Delta.X = getrandom( -3, 3 );
    Delta.Y = getrandom( -3, 3 );

    // Set up "happy face" & generate color 
    // attribute from thread number.
    if( *MyID > 16)
        MyCell = 0x01;          // outline face 
    else
        MyCell = 0x02;          // solid face 
    MyAttrib =  *MyID & 0x0F;   // force black background 

    do
    {
        // Wait for display to be available, then lock it.
        WaitForSingleObject( hScreenMutex, INFINITE );

        // If we still occupy the old screen position, blank it out. 
        ReadConsoleOutputCharacter( hConsoleOut, &OldCell, 1, 
                                    Old, &Dummy );
        ReadConsoleOutputAttribute( hConsoleOut, &OldAttrib, 1, 
                                    Old, &Dummy );
        if (( OldCell == MyCell ) && (OldAttrib == MyAttrib))
            WriteConsoleOutputCharacter( hConsoleOut, &BlankCell, 1,
                                         Old, &Dummy );

        // Draw new face, then clear screen lock 
        WriteConsoleOutputCharacter( hConsoleOut, &MyCell, 1, 
                                     Coords, &Dummy );
        WriteConsoleOutputAttribute( hConsoleOut, &MyAttrib, 1, 
                                     Coords, &Dummy );
        ReleaseMutex( hScreenMutex );

        // Increment the coordinates for next placement of the block. 
        Old.X = Coords.X;
        Old.Y = Coords.Y;
        Coords.X += Delta.X;
        Coords.Y += Delta.Y;

        // If we are about to go off the screen, reverse direction 
        if( Coords.X < 0 || Coords.X >= csbiInfo.dwSize.X )
        {
            Delta.X = -Delta.X;
            Beep( 400, 50 );
        }
        if( Coords.Y < 0 || Coords.Y > csbiInfo.dwSize.Y )
        {
            Delta.Y = -Delta.Y;
            Beep( 600, 50 );
        }
    }
    // Repeat while RunMutex is still taken. 
    while ( WaitForSingleObject( hRunMutex, 75L ) == WAIT_TIMEOUT );
}

void WriteTitle( int ThreadNum )
{
    enum { 
        sizeOfNThreadMsg = 80 
    };
    char    NThreadMsg[sizeOfNThreadMsg];

/*    sprintf_s( NThreadMsg, sizeOfNThreadMsg, 
               "Threads running: %02d.  Press 'A' "
               "to start a thread,'Q' to quit.", ThreadNum );*/
    SetConsoleTitle( NThreadMsg );
}

void ClearScreen( void )
{
    DWORD    dummy;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacter( hConsoleOut, ' ', 
                                csbiInfo.dwSize.X * csbiInfo.dwSize.Y, 
                                Home, &dummy );
}



