// FactoryDesignPattern.cpp : Defines the entry point for the console application.
//

/*
Factory Method is a creational design pattern that provides an interface for creating objects in a superclass,
but allows subclasses to alter the type of objects that will be created.


Example:
	If we are creating an application for a road transport and in future
	we want to extend the application to sea transport, we might have to change a lot of things.

	Instead if we separate out the basic things that any transport has then we can implement
	functions needed for that particular class inside the subclasses


	The Factory Method separates product construction code from the code 
	that actually uses the product. Therefore it’s easier to extend the product construction code 
	independently from the rest of the code.

	For example, to add a new product type to the app, you’ll only need to create a 
	new creator subclass and override the factory method in it.

*/

#include "stdafx.h"
#include <iostream>
using namespace std;  


/*
 
enum genre_e{ROCK,POP, REGGAE, INVALID};
 
//Base Class//
class Music {
public:
 virtual void song() = 0;
};
 
//Derived class Rock from Music//
class Rock: public Music
{
public:
 void song()
 {
  cout<<"Nirvana: Smells like a teen spirit\n";
 }
};
 
//Derived class Pop from Music//
class Pop: public Music
{
public:
 void song()
 {
  cout<<"Michael Jackson: Billie Jean\n";
 }
};
 
//Derived class Reggae from Music//
class Reggae: public Music
{
public:
 void song()
 {
  cout<<"Bob Marley: No woman, No cry\n";
 }
};
 
//Factory Class//
class MusicFactory
{
public:
 //Factory Method//
 Music *getMusic(genre_e genre)
 {
  Music *music = NULL;
 
  //Logic based on Genre//
  switch(genre)
  {
  case ROCK:
   music = new Rock();
   break;
  case POP:
   music = new Pop();
   break;
  case REGGAE:
   music = new Reggae();
   break;
  default:
   music = NULL;
   break;
  }
  return music;
 }
};
 
void main()
{
 //Create factory//
 MusicFactory *musicFactory = new MusicFactory();
 
 //Factory instantiating an object of type ROCK//
 Music *music = musicFactory->getMusic(ROCK);
 
 cout<<"Song: ";
 if(music)
  music->song();
 else
  cout<<"Wrong selection dude/dudette !!";


}

*/


//enum musictype
//{
//	ROCK = 1,
//	POP	 = 2
//};
//
//
//
//class music
//{
//public:
//	virtual void song() = 0;
//};
//
//class Rock : public music
//{
//public:
//
//	void song()
//	{
//		cout<<"Rock song"<<endl;
//	}
//};
//
//class Pop : public music
//{
//public:
//
//	void song()
//	{
//		cout<<"Pop song"<<endl;
//	}
//};
//
//
//class musicfactory
//{
//
//public:
//	music* selectmusictype(int musictype)
//	{
//
//		music *music = NULL;
//
//		if(musictype == ROCK)
//		{
//			music = new Rock();
//			return music;
//		}
//
//		else if(musictype == POP)
//		{
//			music = new Pop();
//			return music;
//		}
//
//		return NULL;
//	}
//
//};
//
//void main()
//
//{
//	musicfactory *p =  new musicfactory;
//	music *musictype = p->selectmusictype(POP);
//	musictype->song();
//};
//
//


//enum musciType
//{
//	musciType_POP,
//	musciType_ROCK,
//};
//
//class Music
//{
//public:
//	virtual void song() = 0;
//
//};
//
//class POP : public Music
//{
//public:
//	virtual void song() { cout << "pop music" << endl; }
//};
//
//class Rock : public Music
//{
//public:
//	virtual void song() { cout << "Rock music" << endl; }
//};
//
//
//class MusicFactory
//{
//public:
//	Music* CreateMusicObject(int nMusicType)
//	{
//		if (nMusicType == musciType_POP)
//		{
//			return new POP();
//		}
//		else
//		{
//			return new Rock();
//		}
//
//		return nullptr;
//	}
//
//};
//
//
//void main( )
//{
//
//	MusicFactory* pMusicfactory = new MusicFactory();
//	pMusicfactory->CreateMusicObject(musciType_POP)->song();
//}


enum class MusicType
{
	Music_Pop,
	Music_Rock,
};

class Music
{
public:
	virtual void Song() = 0;
};

class POP : public Music
{
	virtual void Song() { 
		cout << "Pop music Type" << endl;
	};
};


class Rock : public Music
{
	virtual void Song() { 
		cout << "Rock music Type" << endl;
	};
};

class Musicfactory
{
public:
	Music* GetObject(MusicType nType)
	{
		if (nType == MusicType::Music_Pop)
		{
			return  new POP();
		}
		else
		{
			return  new Rock();
		}
	}
};


void main()
{
	Music* pMusicType = nullptr;
	Musicfactory* pFcatory = new Musicfactory;
	pMusicType = pFcatory->GetObject(MusicType::Music_Rock);
	pMusicType->Song();
}
