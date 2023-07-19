// FacadeDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
A customer in a restaurant orders food from the menu, which is probably described in half a line. 
The order goes to the kitchen and the food comes back after a while. Simple!
The customer does not need to know how things are behind the screens,  all that he does is order food and in reponse he needs the food he ordered

so we can achieve this using Facade pattern
	Facade pattern basically Wraps high level interface hiding all the complex things inside for the users to easily access and use the functions 
	instead of calling multiple functions to achieve what he wanted
	

*/


#include <iostream>
#include <string>


#include <iostream>
using namespace std;


class Waiter_Subsystem1
{
public:
	void writeOrder() { cout << " Waiter writes client's order\n"; }
	void sendToKitchen() { cout << " Send order to kitchen\n"; }
	void serveCustomer() { cout << " Yeeei customer is served!!!\n"; }
};


class Kitchen_Subsystem2
{
public:
	void prepareFood() { cout << " Cook food\n"; }
	void callWaiter() { cout << " Call Waiter\n"; }
	void washDishes() { cout << " Wash the dishes\n"; }
};


class Order_Facade
{
private:
	Waiter_Subsystem1 waiter;
	Kitchen_Subsystem2 kitchen;
public:
	void orderFood()
	{
		cout << "A series of interdependent calls on various subsystems:\n";
		waiter.writeOrder();
		waiter.sendToKitchen();
		kitchen.prepareFood();
		kitchen.callWaiter();
		waiter.serveCustomer();
		kitchen.washDishes();
	}
};



int main(int argc, char *argv[])
{
	// Simple for the client 
	// no need to know the order or the 
	// dependencies among various subsystems.
	Order_Facade facade;
	facade.orderFood();
	return 0;
}