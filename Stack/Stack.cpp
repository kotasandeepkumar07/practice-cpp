// Stack.cpp : Defines the entry point for the console application.
//
/*
Stack is a linear data structure which follows a particular order in which the operations are performed. 
The order may be LIFO(Last In First Out) or FILO(First In Last Out).

Example: Plates in a Cafeteria
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

#define MAX 3

//class Stack
//{
//private:
//
//	int top;
//	int array[MAX];
//
//public:
//
//	Stack() { top = -1  ;}
//
//	void push( int data)
//	{
//		if(top == MAX-1)
//		{
//			cout<<"Stack is full"<< endl;
//		}
//
//		else
//		{
//			top++;
//			array[top] = data;
//			cout<<"pushed item is "<<array[top]<<endl;
//		}
//	}
//
//
//
//	int pop()
//	{
//		if(top == -1)
//		{
//			cout<<"Stack is Empty"<<endl;
//			return NULL;
//		}
//
//		int data =  array[top];
//		top--;
//		return data;
//	}
//
//};


//class Stack
//{
//private:
//	int nIndex;
//	int arr[MAX];
//
//public:
//	Stack() { nIndex = -1; }
//	void push(int nData);
//	int pop();
//};
//
//
//void Stack::push(int nData)
//{
//	if (nIndex == MAX - 1)
//	{
//		cout << "stack is full" << endl;
//		
//	}
//	else
//	{
//		cout << "Pushed Element " << nData << endl;
//		nIndex++; //first increament the count because the nIndex is -1 initially.
//		arr[nIndex] = nData;
//	}
//}
//
//int Stack::pop()
//{
//	int nRetData;
//
//	if (nIndex == - 1)
//	{
//		cout << "No elements in Stack" << endl;
//		nRetData = -1;
//	}
//	else
//	{
//		nRetData = arr[nIndex]; //since we have pushed elements we have to first pop the element and then reduce the count/index
//		nIndex--;
//	}
//	return nRetData;
//}

class Stack
{
private:
	int nIndex;
	int arr[MAX];

public:
	Stack() { nIndex == -1; }
	void push(int nData);
	int pop();
};


void Stack::push(int nData)
{
	if (nIndex == MAX -1)
	{
		cout << " stack is full" << endl;
	}
	else
	{
		nIndex++;
		arr[nIndex] = nData;
	}
}

int Stack::pop()
{
	if (nIndex == -1)
	{
		cout << "stack is empty" << endl;
		return -1;
	}
	else
	{
		int data = arr[nIndex];
		nIndex--;
		return data;
	}
}

void main(int argc, char* argv[])
{
	Stack obj;
	obj.push(11);
	obj.push(22);
	obj.push(33);
	obj.push(44);

	int i = obj.pop();
	cout << "Popped item is    " << i << endl;

	int j = obj.pop();
	cout << "Popped item is    " << j << endl;

	int k = obj.pop();
	cout << "Popped item is    " << k << endl;

	int p = obj.pop();
	cout << "Popped item is    " << p << endl;
}
