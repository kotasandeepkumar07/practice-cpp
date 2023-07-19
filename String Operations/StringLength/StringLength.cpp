// StringLength.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"
#include "string.h"


int strlength(char *string)
{	
	int nlength =0;
	while(*string)
	{
		string++;
		nlength++;
	}
	return nlength;
}

void main(int argc, char* argv[])
{
	int j =  strlength("sandeep");
	cout<<j<<endl;
}
