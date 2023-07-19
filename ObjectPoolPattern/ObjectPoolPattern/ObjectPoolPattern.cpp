// ObjectPoolPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <list>



class Resource
{
	int m_nVal;
public:
	Resource() { m_nVal = 0; }
	void SetVal(int nval) { m_nVal = nval; }
	int GetVal() { return m_nVal; }
	void Reset() { m_nVal = 0; }
};

class Singleton
{
private:
	Singleton() { }
	std::list< Resource*> ResourceList;

public:
	static Singleton* GetInstance();
	static Singleton* Instance;
	Resource* GetResource();
	void ReturnResource(Resource* resobj);
};

Singleton* Singleton::Instance = nullptr;

Singleton* Singleton::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new Singleton();
	}
	else
	{
		return Instance;
	}

	return Instance;
}


Resource* Singleton::GetResource()
{
	if (ResourceList.empty())
	{
		return new Resource;
	}
	else
	{
		Resource *newRes = ResourceList.front();
		ResourceList.pop_front();
		return newRes;
	}
}

void Singleton::ReturnResource(Resource* resobj)
{
	resobj->Reset();
	ResourceList.push_back(resobj);
}

int main()
{
	
	Singleton* ptr = Singleton::GetInstance();

	Resource *res1 = ptr->GetResource();
	res1->SetVal(10);

	Resource *res2 = ptr->GetResource();
	res2->SetVal(20);

	ptr->ReturnResource(res1);
	ptr->ReturnResource(res2);

	res1 = ptr->GetResource();

	return 0;
}
