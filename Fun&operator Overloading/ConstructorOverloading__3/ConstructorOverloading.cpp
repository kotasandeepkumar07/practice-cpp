
#include "stdafx.h"
#include "iostream.h"


class Box
{
public:
 double width, height, depth ;

Box(double w,double h,double d) //constructor with three parameters
{
	width  = w;
	height = h;
	depth  = d;
}

Box(double w) // constructor with one parameter
{
	width = height = depth = w;
}


double volume() 
{
 double volume = (width * height * depth);
 cout<<"The volume is " << volume<<endl;
 return volume;
}

};


void main()
{
//	Box ob(2,3,5); //calling constructor with three parameters
//	ob.volume();
	
	Box ob(2); ////constructor with one  parameter
	ob.volume();
}







