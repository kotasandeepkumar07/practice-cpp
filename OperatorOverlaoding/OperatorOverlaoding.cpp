// OperatorOverlaoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/* 
Intro

	  1. Operator overloading allows the programmer to define how operators (such as +, -, ==, =, and !) should interact with various data types. 
	  2. Compiler knows how to use the operator with built in data types (for example compiler knows to add two int values)
	  3. Operator overloading is useful to perform operations on userdefined datatypes 
			for example adding two strings can be done using operator '+' after overloading which is not possible normally.	  

Rules for overloading

	1. At least one of the operands in any overloaded operator must be a user-defined type
			(we cant add a int and double using overloading --as both are built in data types)

	2. We can only overload the operators that exist. You can not create new operators.
			For example, we cant create an operator ** to do exponents.

	3. nX + nY, is actually operator+(nX, nY) (where operator+ is the name of the function)

	4. C++ looks at the operands around the operator to see what type they are. 
			If all operands are built-in types, a built-in routine will be called

	5. If any of the operands are user data types (eg. one of our classes), 
			it looks to see whether the class has an overloaded operator function that it can call

	6.  If the compiler finds an overloaded operator whose parameters match the types of the operands, 
			it calls that function. Otherwise, it produces a compiler error.

	7. Use operator as friend when the operator has to be deal with other class objects, 
	       because only friend can access the private members of other classes.

			  
The following are the operators that cant be overloaded

.			(Member Access or Dot operator)
.*			(Pointer-to-member Operator )
?:			(Ternary or Conditional Operator )
::			(Scope Resolution Operator)
#			(preprocessor)
sizeof		(Object size Operator)
typeid		(Object type Operator)

*/




//*****************************************************  overloading a ++ operator **********************************************************//
//class base
//{
//private:
//	int m_nValue;
//
//public:
//	base(int i) { m_nValue = i; }
//	int getval() { return m_nValue; }
//	void operator++(int)
//	{
//		m_nValue++;
//	}
//};
//
//void main()
//{
//	base obj(5);
//	cout<<obj.getval()<<endl;
//	obj++;
//	cout<<obj.getval()<<endl;
//}


//******************************************* Addition objects of a class overloading '+' operator **************************************************//

/*

class Box
{
   public:

	   int m_length;
	   int m_breadth;
	   int m_height;

	   Box() {}
	   Box(int length, int breadth, int height) 
	   {
			m_length	= length;
			m_breadth	= breadth;
			m_height	= height;
	   }
      double getVolume(void)
      {
         return m_length * m_breadth * m_height;
      }
      
      // Overload + operator to add two Box objects.
      Box operator+(const Box& b)
      {
         Box box;
         box.m_length = this->m_length + b.m_length;
         box.m_breadth = this->m_breadth + b.m_breadth;
         box.m_height = this->m_height + b.m_height;
         return box;
      }
};


int main( )
{
   Box Box1(1,2,3);          // Declare Box1 of type Box
   Box Box2(2,3,4);          // Declare Box2 of type Box
   Box Box3(2,2,2);          // Declare Box3 of type Box
   Box Box4;                 // Declare Box3 of type Box

   double volume = 0.0;     // Store the volume of a box here
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;


   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   // Add two object as follows:
   Box4 = Box1 + Box2+ Box3;

   // volume of box 3
   volume = Box4.getVolume();
   cout << "Volume of Box4 : " << volume <<endl;

   return 0;
}
*/

//******************************************* Addition a constant value to an object overloading '+' operator **************************************************//


//class Test
//{
//private:
//	int m_nval;
//public:
//	Test(int val) {m_nval = val;}
//	int  get() { return m_nval;}
//	Test& operator+(int i)
//	{
//		m_nval = this->m_nval + i;
//		return *this;
//	}
//};
//
//void main()
//{
//	Test obj(5);
//	Test obj1(2);
//	Test obj2  = obj + 6;
//	cout<<obj2.get()<<endl;
//}




//************************************************* Addition of complex numbers overloading '+' operator **************************************************//

//class complex
//{
//private:
//	int real;
//	int imaginary;
//
//public:
//	complex(int i, int j) { real = i; imaginary = j; }
//
//	int getreal() { return real; }
//	int getimaginary() { return imaginary; }
//
//	complex& operator+(complex& obj1)
//	{
//		real = this->real + obj1.real;
//		imaginary = this->imaginary + obj1.imaginary;
//		return *this;
//	}
//
//};
//
//void main()
//{
//	complex ob1(2, 3);
//	complex ob2(4, 5);
//	complex obj3 = ob1 + ob2;
//
//	cout << obj3.getreal() << "+i" << obj3.getimaginary() << endl;
//}
//
//


/*
class complex
{
private:
	int m_real;
	int m_imaginary;
public:
	complex(int real, int imaginary) { m_real = real; m_imaginary = imaginary;}
	void sum() 
	{ 
		cout<<"sum is"<<"\t"<<m_real<<"+i"<<m_imaginary<<endl;
	//	return (m_real + m_imaginary) ;
	}

	complex& operator+(const complex& ob)
	{
		m_real = this->m_real + ob.m_real;
		m_imaginary = this->m_imaginary + ob.m_imaginary;
		return *this;
	}

};

void main()
{
	complex obj(2,5);
	complex obj1(3,5);
	complex obj3 = obj+obj1;
	obj3.sum();
}
*/


//*******************************************************  overloading a + operator using friend function ************************************************************//
/*

class Cents
{
private:
    int m_nCents;
 
public:
    Cents(int nCents) 
	{ 
		m_nCents = nCents; 
	}
 
    // Add Cents + Cents
    friend Cents operator+(const Cents &c1, const Cents &c2);
 
    int GetCents() { return m_nCents; }
};
 
// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
    // use the Cents constructor and operator+(int, int)
    return Cents(c1.m_nCents + c2.m_nCents);
}
 
int main()
{
    Cents cCents1(6);
    Cents cCents2(8);
    Cents cCentsSum = cCents1 + cCents2;
    cout << "I have " << cCentsSum .GetCents() << " cents" << endl;
 
    return 0;
}

  */


/*
class Cents
{
private:
    int m_nCents;
 
public:
    Cents(int nCents) 
	{ 
		m_nCents = nCents; 
	}
 
    // Add Cents + Cents
    friend Cents operator+(const Cents &c1, const Cents &c2);
	friend Cents operator+(const Cents &c1, int nCents);

    int GetCents() { return m_nCents; }
};
 
// note: this function is not a member function!
Cents operator+(const Cents &c1, int nCents )
{
    // use the Cents constructor and operator+(int, int)
    return Cents(c1.m_nCents + nCents);
}
 
Cents operator+(const Cents &c1, const Cents &c2 )
{
    // use the Cents constructor and operator+(int, int)
    return Cents(c1.m_nCents + c2.m_nCents);
}


int main()
{

	Cents c1 = Cents(4) + 6;
	cout<<c1.GetCents()<<endl;

    Cents cCents1(6);
    Cents cCents2(8);
    Cents cCentsSum = cCents1 + cCents2;
    cout << "I have " << cCentsSum .GetCents() << " cents" << endl;

    return 0;
}
*/


//********************* overloading new operator in private section of class to restrict object creation on heap (allowing only on stack) ***********//


//class Test
//{
//private:
//	Test() {}
//public:
//	/*void* operator new(size_t)
//	{
//		void *p;
//		return p;
//	}*/
//
//	void operator delete(void*)
//	{
//			
//	}
//};
//
//
//void main()
//{
//	Test *p = new Test(); //error   'new' : cannot access private member declared in class 'Test'
//	Test obj; //fine 
//}
//




//***************************************************** overloading prefix operator **************************************************///

/*

class Test
{
private:
int	m_nval;
public:
	Test(int nval) {m_nval =  nval;}
	int getval() {return m_nval;}
	int operator++()
	{
		return ++m_nval;
	}
};

void main()
{
	Test obj(5);
	int i = ++obj;
	cout<<obj.getval()<<endl;
	cout<<i<<endl;
}
*/


//***************************************************** overloading prefix increment operator **************************************************///

/*
class Test
{
private:
int	m_nval;
public:
	Test(int nval) {m_nval =  nval;}
	int getval() {return m_nval;}
	int operator++()
	{
		return ++m_nval;
	}
};

void main()
{
	Test obj(5);
	int i = ++obj;
	cout<<obj.getval()<<endl;
	cout<<i<<endl;
}
*/

//***************************************************** overloading postfix increment operator **************************************************///

/*
class Test
{
private:
int	m_nval;
public:
	Test(int nval) {m_nval =  nval;}
	int getval() {return m_nval;}
	int operator++(int)
	{
		return ++m_nval;
	}
};

void main()
{
	Test obj(5);
	int i = obj++;
	cout<<obj.getval()<<endl;
	cout<<i<<endl;
}
*/


//***************************************************** overloading prefix decrement operator **************************************************///

/*
class Test
{
private:
int	m_nval;
public:
	Test(int nval) {m_nval =  nval;}
	int getval() {return m_nval;}
	int operator--()
	{
		return --m_nval;
	}
};

void main()
{
	Test obj(5);
	int i = --obj;
	cout<<obj.getval()<<endl;
	cout<<i<<endl;
}
*/


//***************************************************** overloading postfix decrement operator **************************************************///

/*
class Test
{
private:
int	m_nval;
public:
	Test(int nval) {m_nval =  nval;}
	int getval() {return m_nval;}
	int operator--(int)
	{
		return m_nval--;
	}
};

void main()
{
	Test obj(5);
	int i = obj--;
	cout<<obj.getval()<<endl;
	cout<<i<<endl;
}
*/


/*
class Test
{
private:
	int m_real, m_imag;
public:
	Test(int i, int j) { m_real = i; m_imag = j;}

	void sum()
	{
		cout<<"sum is"<<m_real<<"+ i"<<	m_imag<<endl;
	}

	Test& operator+(Test obj)
	{
		m_real = this->m_real+obj.m_real;
		m_imag = this->m_imag+obj.m_imag;

		return *this;
	}
};

void main()
{
	Test obj1(10, 20);
	Test obj2(3, 4);
	Test obj4(56, 56);
	Test obj3 = obj1 + obj2 + obj4;
	obj3.sum();
}
*/


/*

class Test
{
private:
	int m_i;
	
public:
	Test() {}
	int getfunc() {  return m_i ;}
	Test(int i) { m_i = i; }
	
	Test operator=(Test& obj)
	{
		if(this == &obj) //checking for self assignment 
		{
			cout<<"same object"<<endl;
			return *this;
		}
		else
		{
			Test obj3;            //returning by reference, it is not preferred because the variable dies once the function ends
			obj3.m_i = obj.m_i;
			return obj3; 	
		}
	}
};

void main()
{
	Test obj1(10);
	Test obj2(20);
	obj2 = obj1;
	cout<<obj2.getfunc()<<endl;
}
*/


//
//class Test2
//{
//public:
//	int m_nval2;
//	Test2()
//	{
//		m_nval2 = 0;
//	}
//
//};
//
//
//class Test1
//{
//public:
//	int m_nval2;
//	Test1()
//	{
//		m_nval2 = 0;
//	}
//
//	Test1 operator+(Test1& obj)
//	{
//		Test1 newobj;
//		newobj.m_nval2 = this->m_nval2 + obj.m_nval2;
//		return newobj;
//	}
//};
//
//
//
//void main()
//{
//	Test1 obj2;
//	obj2.m_nval2 = 10;
//
//	Test1 obj1;
//	obj1.m_nval2 = 20;
//
//	Test1 obj3;
//	obj3 = obj2 + obj1;
//
//	cout << obj3.m_nval2 << endl;
//}

//
//class B
//{
//public:
//	int b;
//	B()
//	{
//		b = 0;
//	}
//
//};
//
//class A
//{
//public:
//	int a;
//	A()
//	{
//		a = 0;
//	}
//	friend A operator+(A& obja, B& objb);
//
//	//friend A operator+(A& obja, B& objb);
//};
//
//A operator+(A& obja, B& objb)
//{
//	A newobj;
//	newobj.a = obja.a + objb.b;
//	return newobj;
//}
//
//void main()
//{
//	A obj1, obj3;
//	obj1.a = 10;
//
//	B obj2;
//	obj2.b = 20;
//
//	obj3 = obj1 + obj2;
//	cout << obj3.a << endl;
//}



/************** overloading subscription[] operator *************************************/

/*** without using subscription[] operator ****/
/*
class List
{
private:
	int m_nList[10];
public:
	void setval(int nindex, int ndata)
	{
		m_nList[nindex] = ndata;
	}

	int getval(int nindex)
	{
		return m_nList[nindex];
	}
};


void main()
{
	List obj;
	obj.setval(2, 7);

	int val = obj.getval(2);
	cout << val << endl;
}
*/


/*** Advantage of using subscription[] operator ****/
/*
class List
{
public:
	int m_nList[10];
public:
	int& operator[](const int nIndex)
	{
		return m_nList[nIndex];
	}
};

void main()
{
	List obj;
	obj[2] = 7;
	cout << obj.m_nList[2] << endl;
}
*/


//class Test
//{
//public:
//	friend ostream& operator<<(std::ostream& os);
//
//
//};
//
//void main()
//{
//	Test obj;
//	cout << obj;
//}