
//****************************** Making a function as friend of another class ***********************************//
/*
#include "StdAfx.h"
#include "iostream.h"


class CRectangle 
{
    int width, height;
public:
	int area () {return (width * height);}
	void setvalues (int a, int b)
	{
	width = a;
	height = b;
	}	
	friend CRectangle duplicate (CRectangle);
};

CRectangle duplicate (CRectangle rectparam)
{
	CRectangle rectobj;
	rectobj.width = rectparam.width*2;
	rectobj.height = rectparam.height*2;
	return (rectobj);
}

void main () 
{
	CRectangle rect, rectb;
	rect.setvalues (2,3);
	rectb = duplicate (rect);
	cout << "The area is " << rectb.area() ;
}

*/

//****************************** Making a Class as friend of another class ***********************************//


#include "StdAfx.h"
#include "iostream.h"

class CSquare 
{
    int side;
public:
    void setside (int a) {side=a;}
  class CRectangle;
};

class CRectangle 
{
    int width, height;
public:
    int area () {return (width * height);}
    void convert (CSquare a)
	{
		width = a.side;
		height = a.side;	
	}	
};

void main () 
{
	CSquare sqr;
	CRectangle rect;
	sqr.setside(5);
	rect.convert(sqr);
	cout << "The area is " << rect.area() ;
}



//********************** Friend Function can't be used for Class Definition ********************////////////////


/*
#include "StdAfx.h"
#include "iostream.h"


class F;
class X 
{
	friend class F { } ;
};

void main()
{

}

*/