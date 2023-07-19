// Initializers.cpp : Defines the entry point for the console application.
//

#include "string.h"
#include "stdafx.h"

#include "stdio.h"
#include "iostream.h"


#include "StdAfx.h"
#include "iostream.h"


class Something
{
public:
    int m_nValue;
	
    Something() 
	{ 
		m_nValue = 0; 
	}
	
    void ResetValue() 
	{
		m_nValue = 0;
	}

    void SetValue(int nValue) 
	{
		m_nValue = nValue;
	}
	
    int GetValue() const
	{ 
		return m_nValue;
	}
};

void main()
{
    const Something cSomething; // calls default constructor

	
//    cSomething.m_nValue = 5; // violates const
//    cSomething.ResetValue(); // violates const
 //   cSomething.SetValue(5); // violates const
	cout<<cSomething.GetValue()<<endl;	
}
