
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
	/*
	int (*fp) (int a);     
	fp = myfunc;      
	cout << fp(5) ;
	*/

	int (*fp) (int a, int b);     
	fp = &myfunc;      
	cout << fp(5,8) ;
}


