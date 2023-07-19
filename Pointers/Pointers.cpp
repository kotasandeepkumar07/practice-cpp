// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"


void  main(int argc, char* argv[])
{
	for(int i=0; i<argc; i++)
	{
		cout<<argv[i]<<endl;
	}


/*	int nValue = 10;
	int *a = new int; // dynamic allocation
	a = &nValue;
/*	delete a;
	a = NULL;

	cout<<*a<<endl;

//	delete a;         // Delete the content of memory 
//	a = 0;			  // Free the memory

//	int *array = new int[10]; 
//	delete []a;


	char  *p = "hello" ;
	char  *q = p;
	
	cout<<p++<<'\t';
	cout<<p++<<"\t";
	cout<<p++;


	cout<<p<<"\n"<<q<<endl;
	//q = "good";
	//cout<<p<<"\n"<<q<<endl;
*/


	int *a[2];
	 int a[0] = 1 ;
	 int a[1] = 2;
	 int a[2] = 3;

	 cout<<a[0]<<"\n"<<a[1]<<"\n"<<a[2]<<endl;

/*
	char *ch[2];

	ch[0] = "hau";
	ch[1] = "fgsdg";
	ch[2] = "sdg";
	cout<<ch[0]<<endl;
	cout<<ch[1]<<endl;
	cout<<ch[2];
*/

/*
	int *p ;
	int nValue =10;
	int value = 3 ;
	p =&nValue;
	cout<<*(p+1) <<endl;

*/
}






/*class singleton
{
public:
    void print()
    {

		cout<<"Hello"<<endl;
    }
    int a;
}singleton;
 */
/*void main()
{
	int a=1, b=3 ;
	cout<<a*b<<endl;

	
    //singleton s;  #cannot define a new instant like this anymore.
 /*   singleton.a=5;
    cout<<singleton.a<<endl;
    singleton.print();

}
*/

/*
class Singleton 
{
private:	
	static Singleton instance();   
	
private:
	Singleton(){}
	
public:
	   static Singleton getInstance() 
	   {
		   if (instance == null)
			   instance = new Singleton();
		   return instance;
	   }


};

*/

/******************************************** 
class Kid
{
private:
	static Kid *m_kidInstance;
static	int i;
	
private:
		Kid(){}
public:
	static Kid* Instance()
    {
		i =10;
        if (m_kidInstance == NULL)

            m_kidInstance = new Kid();

        return (m_kidInstance);
    }

	int func()
	{
		i = 20;
		return 2;
	}
};
Kid* Kid::m_kidInstance = NULL; 

int Kid:: i =0;

void main()
{

	Kid *obj = Kid::Instance();
	obj->func();
	
}
*/

/*
void main()
{
	int	*p ;
	int	i = a[10];
	p	=	&i;
	cout<<p<<endl;	
}
*/

/***************************************************************ALOK********************************************************/

//****************pass by value VS pass by reference*************************

/*

void calculate(int &a,int &b)
{
	a= a+b;
}
void main()
{
	int a,b;
	a=5;
	b=3;
	cout<<a<<"\t"<<b<<endl;
	calculate(a,b);
	cout<<a<<"\t"<<b;
}
*/

//***********************pointer arithmatics**********************
/*
void main(void)
{
	int nValue = 7;
	int *pnPtr = &nValue;
	cout << pnPtr << endl;
	cout << (pnPtr+1) << endl;
	cout << (pnPtr+2) << endl;
	cout << (pnPtr+3) << endl;
}
*/


/*

void main()
{
	int i[3]={1,2,3};
	int j[3]={4,5,6};
	int *p ,*p1;
	char *str = "hello";
	p = i;
	p1 = j;
	cout<<p<<endl<<p1<<endl;
	cout<<(p-p1)<<endl;
	cout<<sizeof(i)<<endl;
	cout<<sizeof(p)<<endl;
	cout<<sizeof(str)<<endl<<strlen(str)<<"\t";
}
*/



//*********************reference**********************************

/*

void main()
{
	int nValue =5;
	int nValue1 =6;
	//int nValue2  =7;
	int &nRef = nValue;
	//const int &nRef1 =nValue2;
	nRef = nValue1;
	cout<<nValue<<endl;
	cout<<nRef<<endl;
	//cout<<nRef1<<endl;
}
*/

/*

int main()
{
   int a = 320;
   char *ptr;
   ptr =( char *)&a;
   printf("%d ",*ptr);
   return 0;
}
*/


/*
int main()
{
    float a=3.14;
    char *j;
    j = (char*)&a;
    printf("%d\n", *j);
   return 0;
}
*/



//*****************************pointer to function***********************

//typedef void (*funptr)(int,int);

/*
void add(int i,int j)
{
	cout<<i<<"+"<<j<<"="<<i+j<<endl;
}


void  substraction(int i,int j)
{
	cout<<i<<"-"<<j<<"="<<i-j<<endl;
}


void main()
{

	void (*fp) (int i, int j);
	fp = &add;
	fp(1,2);

	
	/*funptr ptr;
	ptr = &add;
	ptr(2,3);
	ptr =&substraction;
	ptr(4,3);
	cout<<&add<<"\t"<<add<<endl;

}

	*/

//*********************dynamic memory allocation*********************

/*void main()
{
	int nValue = 5;
	int nValue1;
	int *pnValue1;
	pnValue1 = &nValue1;
	int *pnValue = new int;
	//*pnValue = 10;
	cout<<pnValue<<endl;
	pnValue = &nValue;
	cout<<nValue<<"\t"<<pnValue<<"\t"<<pnValue1<<endl;
	//delete pnValue;
	//*pnValue = 15;
	//cout<<*pnValue;
	//if(pnValue == NULL)
	//{cout<<"a";}
}*/



//**********************pointer & const***************************

/*
void main()
{


//constant pointer 
	//The Value ponted by that pointer can be changed by not the pointer i.e. pointer cant be made to point to some other value

	int nValue = 5;
	int *const pnPtr = &nValue;
	pnPtr++;
//	int val =10; 
//	*pnPtr = &val; //throws an error because we are trying to change pointer 
//	*pnPtr =20 ;  //fine because the value of the pointer is changed rather than point
//	cout<<*pnPtr<<"\t"<<endl; 


	//pointer to a constant 
		// The value of the pointer can be chnaged and not the value it is pointing to.

/*	int nValue = 5;
	const int *pnPtr1 = &nValue;
//	*pnPtr1 = 20; //throws an error because we are trying to change the value the pointer is pointing to
	int i = 100; 
	pnPtr1 = &i; //works fine because the pointer value is changed (by making it to pint to som other value)

	cout<<*pnPtr1<<"\t"<<endl; //*pnPtr1<<

}	*/



//********************************** NULL POINTER  *******************************************/
/*
int main(void)
{
  int number = 0;                 
  int *pointer = NULL;
  //number = 10;
  cout<<"number's address:" << &number<<endl;            
  cout<<"number's value:" << number<<endl;

  return 0;
}

*/

//********************************  Void Pointer   ************************************************

/*
void main()
{
	int nValue = 1;
	double dValue =1.1;
	char sValue = 'a';

	void *vnPtr;
	void *vdPtr;
	void *vsPtr;

	vnPtr =&nValue;
	vdPtr =&dValue;
	vsPtr =&sValue;

	cout<<*(int *)vnPtr<<"\t"<<*(double *)vdPtr<<"\t"<<*(char *)vsPtr<<endl;
}
*/



//***************************  pointer to pointer   ****************************************************

/*
int main (int argc, char *argv[]) 
{
	cout << "name of program " << *argv << '\n';
	return 0;
}


void main()
{
	int n =5;

	int *ptr1,**ptr2;
	ptr1 = &n;
	ptr2 =&ptr1;
	cout<<"\t"<<*ptr2<<"\t"<<**ptr2<<endl; 
}
*/



//***************************address of overloaded function******************************************


/*
#include "stdafx.h"
#include "iostream.h"

int myfunc(int a)
{
	return a;
}
int myfunc(int a, int b)
{
	return a*b;
}
void  main()
{
	int (*fp) (int a, int b);     
	fp = myfunc;      
	cout << fp(5,5);
}
*/


//*************************  this pointer  *********************************************

/*
class test
{
public:
	int a;
	test()
	{
		this->a=5;
	}
};
void main()
{
	test t;
	cout<<t.a;
}

*/

//***************************************************************************************
/*void main()
{
	char  *p = "hello" ;
//	char *p = {'h','e','l','l','o'};
	char  *q = p;
	cout<<p<<endl<<q<<endl;
}
*/



//*****************************************************************************************

/*
void main()
{
	int  *p;
	double  *d;
	p =  reinterpret_cast <int *>(d);
}
*/



/*
void main()
{

//constant pointer :The Value pointed by that pointer can be changed but not the pointer i.e. pointer cant be made to point to some other value					//I will point to the same address , do whatver you want to do with the value am pointing to.

int nValue = 5;
int *const pnPtr = &nValue;
int val =10; 
pnPtr = &val; //throws an error because we are trying to change pointer 
*pnPtr =20 ;  //fine because the value of the pointer is changed rather than pointer
cout<<*pnPtr<<"\t"<<endl; 


//pointer to a constant : The value of the pointer can be chnaged and not the value it is pointing to.
/*
int nValue = 5;
const int *pnPtr1 = &nValue;
//*pnPtr1 = 20; //throws an error because we are trying to change the value the pointer is pointing to
int i = 100; 
pnPtr1 = &i; //works fine because the pointer value is changed (by making it to pint to som other value)
cout<<*pnPtr1<<"\t"<<endl; //*pnPtr1<<

}
*/

/*
void main()
{

/*
	int i = 10;
	int * const p = &i;


//	p++; // np
	int j = 40;
//	p = &j;  //np
	*p = 50;  //p
*/



/*	
	int i = 10;
	const int *p = &i;
//	*p = 30; //np
	int j = 40;
	p = &j; //p
	p++// p
*/	

	/*
	int i = 10;
	int &j= i;
	
	int k = 50;
	j = k ;
	
	j++;
	j++;
	i++;

	cout<<j<<endl; //52
	cout<<i<<endl; //52

};*/

