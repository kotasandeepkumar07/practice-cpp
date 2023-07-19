// Queue.cpp : Defines the entry point for the console application.
//

/*
A Queue is a linear structure which follows a particular order in which the operations are performed. 
The order is First In First Out (FIFO). 
Example: Any queue of consumers for a resource where the consumer that came first is served first.

The difference between stacks and queues is in removing. 
In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.

Examples:

1. Serving requests on a single shared resource, like a printer, CPU task scheduling etc.
2. In real life scenario, Call Center phone systems uses Queues to hold people calling them in an order, until a service representative is free.
3. Handling of interrupts in real-time systems. The interrupts are handled in the same order as they arrive i.e First come first served.
4. Queue is used in BFS(Breadth First Search) algorithm. It helps in traversing a tree or graph.
*/


#include "stdafx.h"
#include <iostream>

using namespace std;

#define MAX 5

class Queue
{
private:
	int rear,front;
	int array[MAX];

public :
	Queue() { rear = front = -1 ;}

	void append(int num)
	{
		if( (rear == MAX-1) && front == 0 )
		{
			cout<<"Queue is full"<<endl;
		}
		else
		{
			rear++;
			array[rear] = num;
			cout<<array[rear]<<endl;
		}
		if(front == -1)
		{
			front = 0;
		}
	}

	int  Delete()
	{
		if(front == -1)
		{
			cout<<"Queue is Empty"<<endl;
			return NULL;
		}
		else
		{
			int data  = array[front];
			front++;
			if(front == MAX )	
			{
				front = -1;
			}
			return data;
		}
	}
};

void main(int argc, char* argv[])
{
	Queue obj;
	obj.append(10);
	obj.append(20);
	obj.append(30);
	obj.append(40);
	obj.append(50);

	int i = obj.Delete();
	cout<<i<<endl;

	int j = obj.Delete();
	cout<<j<<endl;
	
	int k = obj.Delete();
	cout<<k<<endl;
	
	int l = obj.Delete();
	cout<<l<<endl;	

	int m = obj.Delete();
	cout<<m<<endl;	


	int p = obj.Delete();
	cout << p << endl;
}
