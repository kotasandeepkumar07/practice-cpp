// Swap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"


int main(int argc, char* argv[])
{
 const int size = 6;
	char a[size]={'p','e','d','d','e','k'};
	for(int i=0;i<(size/2);i++)
	{    
		   char temp=a[i];
	        a[i]=a[size-i-1];
			a[size-i-1]=temp;
	}

	for(i=0;i<size;i++)
	{ 	
		cout<<a[i]<<endl;	
	}
	
/*	for(i=0;i<size;i++)
	{ 	if a[i]=a[size-i];
	    cout<<" pallindrome"<<endl;
		else a[i]=a[size-i];
		cout<<"nt a pallindrome"<<endl;
	}*/


/*	for( i=2;i<4;i++)
	{
	        a[i]=a[3-i];
			cout<<a[i];
	}*/
		//cout<<a[0];

	return 0;



/*
    int a=5;
	int b=2;
    a=a+b;
	b=a-b;
	a=a-b;

    
	cout<<"a is "<<a<<endl;
	cout<<"b is "<<b<<endl;*/
	
}
