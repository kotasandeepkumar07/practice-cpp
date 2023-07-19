// ProxyDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

using namespace std;


/*
Proxy in general means, in place of, or substitution

Proxy are of 3 types :
	1. Property Proxy
	2. Virtual proxy
	3. Communication proxy
*/


/******************************************    Virtual proxy  ***********************************************************/
/*
In the follwing class, there are two things happening 
	1. Loading the file 
	2. Drawing

In the following case, even if someone doesn't call draw method, the file is loaded which is un necessary(assuming that 
Bitmpap class is an external library and we cant change it)

	what we can do is create a dummy class/proxy class and make sure to call load file only when Draw is called
*/

class Image
{
public:
	virtual void Draw() = 0;
	int i;
};

//original Bitmap class
class Bitmap : public Image
{
public:
	Bitmap(){}
	Bitmap(const string& filename) { cout << "Loading from bitmap" << endl; }
	void Draw() override
	{
		cout << "Drawing bitmap" << endl;
	}
};


class ProxyBitmap : public Bitmap
{
public:
	string strfilename;
	Bitmap *pBitMap{ nullptr };
	ProxyBitmap(const string& filename) : strfilename(filename) {}

	void Draw() override // When the Draw class is called then only we load the Bitmap i.e. Bitmap constructor is called only when we call Draw function
	{
		if (!pBitMap)
		{
			pBitMap = new Bitmap(strfilename);
			pBitMap->Draw();
		}
	}
};



int main()
{
	ProxyBitmap* pBitMap = new ProxyBitmap("test"); // here instead of calling original Bitmap class, we have to call Proxyclass and it takes care of calling original Bitmap class
	pBitMap->Draw();			// if no Draw function is called then file is not loaded									
	

	return 0;
}




/*******************************  Property proxy ***************************************/
/*
Languages like C# has got properties in built 
We can create a proxy instead of setter/getter 
*/

template <class T> 
class PropertyProxy
{
public:
	T value;
	PropertyProxy(T nval)
	{
		*this = nval;
	}

	operator T()
	{
		return value;
	}

	T operator=(T obj)
	{
		this->value = obj;
		return this->value;
	}

};


class Creature //using this class we can avoid the setters and getters and use the templpated class as below
{
public:
	//int Agility;
	//int Strength;
//
//public:
//	int getAgility() { return Agility; }
//	int getStrength() { return Strength; }
//
//	void SetAgility(int agility) { Agility = agility;}
//	void SetStrength(int strngth) { Strength = strngth; }

	PropertyProxy<int> Strength{ 10 };
	PropertyProxy<int> Agility{ 5 };

};
//
//void main() //for main its the same as before (it as good as using Creature class)
//{
//	Creature cr;
//	cr.Agility = 12;
//}