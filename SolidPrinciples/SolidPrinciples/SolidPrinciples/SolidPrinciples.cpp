// SolidPrinciples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


/*
SOLID Design Principles

The SOLID principle was introduced by Robert C. Martin, also known as Uncle Bob and it is a coding standard in programming
SOLID is an acronym for five design principles intended to make software designs more understandable, flexible, and maintainable

S - Single Responsiblity principle
O - Open/Closed Principle
L - Liskov’s Substitution Principle
I - Interface Segregation Principle
D - Dependency Inversion Principle

*/


/***************** S - Single Responsiblity principle *****************************/
/* 
	A class should have one and only one reason to change, meaning that a class should have only one job.
	A programmer should basically program and can break things in the development if he/she wants but should not have 
	some responisbility like making coffee or something

*/


/***************** O - Open/Closed Principle *****************************/
/*
It’s a principle for object oriented design first described by Bertrand Meyer that says that 
“software entities (classes, modules, functions, etc.)  should be open for extension, but closed for modification”

This principle states that “software entities (classes, modules, functions, etc.) should be open for extension, 
but closed for modification” which means you should be able to extend a class behavior,  without modifying it

Suppose developer A needs to release an update for a library or framework and developer B wants some modification or 
add some feature on that then developer B is allowed to extend the existing class created by developer A 
but developer B is not supposed to modify the class directly. Using this principle separates the existing 
code from the modified code so it provides better stability, maintainability and minimizes changes as in your code.
*/

//Example 
/*
	Lets say we have a class Rectangle

*/




/***************** L - Liskov’s Substitution Principle *****************************/
/*
The principle was introduced by Barbara Liskov in 1987 and according to this principle 
“Derived or child classes must be substitutable for their base or parent classes“.  
This principle ensures that any class that is the child of a parent class should be usable in place of its parent 
without any unexpected behavior.

Example: We should be able to pass our own string in to function that accepts a string as argument 
void test(string)	//here in place of string we can pass our own string that is we are able to replace parents class with child classes
*/





/*************************************** I - Interface Segregation Principle	********************************************/
/*
This principle is the first principle that applies to Interfaces instead of classes in SOLID and it is similar 
to the single responsibility principle

It states that “do not force any client to implement an interface which is irrelevant to them“. 
Here your main goal is to focus on avoiding fat interface and give preference to many small client-specific interfaces. 
You should prefer many client interfaces rather than one general interface and each interface should have a specific responsibility.
*/


/*************************************** L - Interface Segregation Principle	********************************************/
/*
This principle is the first principle that applies to Interfaces instead of classes in SOLID and it is similar
to the single responsibility principle

It states that “do not force any client to implement an interface which is irrelevant to them“.
Here your main goal is to focus on avoiding fat interface and give preference to many small client-specific interfaces.
You should prefer many client interfaces rather than one general interface and each interface should have a specific responsibility.
*/


/*************************************** D - Dependency Inversion Principle	********************************************/
/*
1. High-level modules/classes should not depend on low-level modules/classes. Both should depend upon abstractions.
2. Abstractions should not depend upon details. Details should depend upon abstractions.
*/



int main()
{
    std::cout << "Hello World!\n";
}

