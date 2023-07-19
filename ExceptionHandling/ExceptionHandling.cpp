// ExceptionHandling.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include	<iostream>
#include "memory.h"  // for autp_ptr 
#include <vector>


/********************************** Exceptions *******************************************/
/*
Exception Handling for a C++ developer is designed to handle synchronous programing error such as
    resource allocation error
    value out of range 

Exception Handling is not designed to handle asynchronous events like 
    Hardware interrupts
    Instruction traps

C language is used to report errors using return values/arguments as there was no Exception Handling
Examples:
    malloc() - returns a null pointer if it can't allocate memory
    printf() - returns a negative value in case it can't print 

This might not work always. For example we have 

    Main() which calls void f() and void f() calls void g(), 
    If there is an exception in g() it should return something and the return value must be changed to int instead of void, 
    Inturn if f() can't handle the error, it should send info to main for which we need to have int for f() too and then main will handle the exception

Problems
    In each function we have to check if the called function returned a proper value or not. 
    The code is going to be huge if there are several functions called this way
    The return value just retuns only one value like -1 which is not sufficient for function that recieves this info to handle the exception

C++ Exception Handling
    It reports error as an exceptional event and transfers control to an exception handler

*/


/********************************** Need for Exceptions Handling *******************************************/
/*
* 
Causes of exceptions/errors
Most errors in a program don’t occur as the result of inadvertently misusing language features --
rather, most errors occur due to faulty assumptions made by the programmer and 
or a lack of proper error detection / handling.

Ways to Handle exceptions:

Return value
One of the fundamental ways to handle errors is via return codes but return codes does not give proper 
information of the error/exception that has occured.
We can return -1 or 0 or 1 for a failure case. It all depends on the developer and caller of the function
will know it only when they see the logic of the called function


Also some times we might need more than one value from the function, one for result of the operation and 
second to know if the operation is succeeded or not

int result(int a, int b){  //Here we want to know both the result of a/b and if the operation has succeeded or not 
    return a/b
}

we can use a boolean as reference argument to get back the result as below
int result(int a, int b, bool& bsuccess) //But this is considered a bad practise
{  
    if (b !=0 ) 
    {
        bsuccess = true;
        return a/b;
    }
    else
    {
         bsuccess = false;
         return 0.0;
    }

Problems with Exceptions
1.	Exceptions incur an extreme performance overhead in case of failure
2.	Exceptions rely on dynamic memory
3.	Exceptions make the binary size grows
*/


/*
	Exception handling provides a mechanism to decouple handling of errors or other exceptional
		circumstances from the typical control flow of your code

	Exceptions in C++ are implemented using three keywords that work in conjunction with each other: throw, try, and catch.

Throwing exceptions: (throw)

  1. In C++, a throw statement is used to signal that an exception or error case has occurred (think of throwing a penalty flag). 
  2. Signaling that an exception has occurred is also commonly called raising an exception.
  3. We don't usually throw exceptions of primitive types like int or double
  4. We throw exceptions of class types 

  Examples:

  throw -1; // throw a literal integer value
  throw "Can not take square root of negative number"; // throw a literal char* string
  throw MyException("Fatal Error"); // Throw an object of class MyException


Looking for exceptions(Try)
  1. In C++, we use the try keyword to define a block of statements (called a try block). 
  2. The try block acts as an observer, looking for any exceptions that are thrown by statements within the try block.
  3. try block does not define HOW we’re going to handle the exception
  4. Various standard C++ language and library components report errors by throwing an exception.
  5. They mostly throw exceptions of a class called exception or any class derived from it
  6. Standard headers <new> and <typeinfo> define other derived exception classes
  7. All standard exception classes are members of namespace std.
  8. As soon as the exception is thrown, the control directly goes to catch block and doesn't execute the next line after the throw statement
  9. Make sur to understand what a function can throw when it is implemented
  Example:

	try
	{	
		// Statements that may throw exceptions you want to handle now go here
		throw -1;
	}


Handling exceptions:
  1. Handling exceptions is the job of the catch block(s). 
  2. The catch keyword is used to define a block of code (called a catch block) that handles exceptions for a single data type.

	catch (int)
	{
		// Handle an exception of type int here
		cerr << "We caught an exception of type int" << endl;
	}
	
It is recomded that exceptions are thrown by value and caught by const ref

 */

//**************************************** simple example ** ********************************* //

// Try block detects any exceptions thrown by statements inside it and routes it to corrosponding catch block
/*
int main()
{
    try
    {
        // Statements that may throw exceptions you want to handle now go here
        throw -1;
    }
    catch (int)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        cerr << "We caught an exception of type int" << endl;
    }
    catch (double)
    {
        // Any exceptions of type double thrown within the above try block get sent here
        cerr << "We caught an exception of type double" << endl;
    }
 
    return 0;
}
*/


//**************************************** Exceptions are Handled Immediatley ******************************************///

/*
  int main()
	{
		try
		{
			throw 4.5; // throw exception of type double
			cout << "This never prints" << endl;
		}
		catch(double dX) // handle exception of type double
		{
			cerr << "We caught a double of value: " << dX << endl;
		}
	}
*/



 //**************************************** Exceptions within functions ******************************************/ //

// throw statements do NOT have to be placed directly inside a try block

/*
double MySqrt(double dX)
{
    // If the user entered a negative number, this is an error condition
    if (dX < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type char*
 
    return (dX * dX);
}
 
void main()
{
    cout << "Enter a number: ";
    double dX;
    cin >> dX;
 
    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        cout << "The sqrt of " << dX << " is " << MySqrt(dX) << endl;
    }
    catch (char* strException) // catch exceptions of type char*
    {
        cerr << "Error: " << strException << endl;
    }
}
*/


 //**************************************** Stack Unwinding *******************************************************//

// Exception need not be caught in the function where it is been throw , 
//sometimes it may happen that the error gets caught in some other function (which is called by present function)


#include <iostream>
using namespace std;

void Last() // called by Third()
{
    cout << "Start Last" << endl;
    cout << "Last throwing int exception" << endl;
    throw -1;
    cout << "End Last" << endl;
 
}
 
void Third() // called by Second()
{
    cout << "Start Third" << endl;
    Last();
    cout << "End Third" << endl;
}
 
void Second() // called by First()
{
    cout << "Start Second" << endl;
    try
    {
        Third();
    }
    catch(double)
    {
         cerr << "Second caught double exception" << endl;
    }
    cout << "End Second" << endl;
}
 
void First() // called by main()
{
    cout << "Start First" << endl;
    try
    {
        Second();
    }
    catch (int)
    {
         cerr << "First caught int exception" << endl;
    }
    catch (double)
    {
         cerr << "First caught double exception" << endl;
    }
    cout << "End First" << endl;
}
 
int main()
{
    cout << "Start main" << endl;
    try
    {
        First();
    }
    catch (int)
    {
         cerr << "main caught int exception" << endl;
    }
    cout << "End main" << endl;
 
    return 0;
}


 //**************************************** Catching all Exceptions *******************************************************//

/* 
The Exceptions thrown can be of any data type and if there is no proper catch type for
  that particular data type then application terminates with OS throwing an exception calling std::terminate
 To resolve this we can use catch(...) to catch all types of exceptions ellipses operator " (...) "
 Some times people use the follwing syntax

 catch(...)
 {
    delete p  //if p is a pointer allocated on the heap 
    throw ; //Here we can use throw statement inside the catch block without an operand. This type of throw is possible only in catch block.
            //here we are telling that if there is some one who can catch this exception, please do as we do not know how to handle it as this is a common catch block
 }

*/



/*
try
{
    throw 5; // throw an int exception
}
catch (double dX)
{
    cout << "We caught an exception of type double: " << dX << endl;
}
catch (...) // catch-all handler
{
    cout << "We caught an exception of an undetermined type" << endl;
}
 */

 //**************************************** Exceptions and inheritance *******************************************************//

// it’s possible to throw classes as exceptions, and classes can be derived from other classes, 
// output is caught Base  (expected output is caught Derived)
// Reason: when an exception is caught the exception immediatley looks for a catch and it found Base and as
//			 Derived 'is a' Base (Inheritance is called "IS-a" relationship). 

// Remedy: Write the Derived catch First and then Base
// when we throw Base Exception Base Catch is used even though we have Derived first becuase Base cant be achieved using Derived

/*
class Base
{
public:
    Base() {}
};
 
class Derived: public Base
{
public:
    Derived() {}
};
 
int main()
{
    try
    {
        throw Derived();
    }
    catch (Base &cBase)
    {
        cerr << "caught Base";
    }
    catch (Derived &cDerived)
    {
        cerr << "caught Derived";
    }
 
    return 0;
}
*/

//**************************************** DownSides or Disadvantages *******************************************************//
//Example 
// if the process fails in ProcessPerson fucnctions the exception is caught and the pointer never gets deleted 
/*
try
{
    Person *pJohn = new Person("John", 18, E_MALE);
    ProcessPerson(pJohn);
    delete pJohn;
}
catch (PersonException &cException)
{
    cerr << "Failed to process person: " << cException.what() << endl;
}

*/

//1st Remedy
// declare pJohn before try and delete it inside the catch

/*
Person *pJohn = NULL;
try
{
    pJohn = new Person("John", 18, E_MALE);
    ProcessPerson(pJohn );
    delete pJohn;
}
catch (PersonException &cException)
{
    delete pJohn;
    cerr << "Failed to process person: " << cException.what() << endl;
}
*/

//2nd remedy
// std::auto_ptr is a template class that holds a pointer, and deallocates it when it goes out of scope.
/*
try
{
    pJohn = new Person("John", 18, E_MALE);
    auto_ptr<Person> pxJohn(pJohn); // pxJohn now owns pJohn
 
    ProcessPerson(pJohn);
 
    // when pxJohn goes out of scope, it will delete pJohn
}
catch (PersonException &cException)
{
    cerr << "Failed to process person: " << cException.what() << endl;
}
*/

//*******************************************  Exceptions Base and Derived class ****************************************//

// when a derived class exception is thrown and if we write base class catch first and derived class next, then base class catch is executed
/// In order to avoid this, the derived class catch is to be written first.

/*
class Base {};
class Derived: public Base {};
int main()
{
   Derived d;
   // some other stuff
   try 
   {
       // Some monitored code
       throw d;
   }
   catch(Base b) 
   { 
        cout<<"Caught Base Exception";
   }
    catch(Derived d) 
	{ 
		This catch block is NEVER executed
        cout<<"Caught Derived Exception";
	}
   return 0;
}

*/


//*********************************  placement of catch block **************************************//
// The following program throws an error as catch(...) as it will include to catch an int exception also.
// The catch(...) should be placed at last i.e after all the other specific catch.


/*
void main()
{
	try
	{
		throw 4;
	}
	catch(...)
	{
		cout<<"caught int in general"<<endl;
	}
	catch(int)
	{
		cout<<"caught int integer"<<endl;
	}
}
*/




/*
// this works fine 

void main()
{
	try
	{
		throw 4;
	}
	catch(int)
	{
		cout<<"caught int integer"<<endl;
	}
	catch(...)
	{
		cout<<"caught int in general"<<endl;
	}
}
*/



//****************************  C++ Standard Exceptions: ***************************************//

/* C++ provides a list of standard exceptions defined in <exception> which we can use in our programs.

bad_alloc:			Exception thrown on any failure allocating memory
bad_cast:			Exception thrown on failure to dynamic cast
bad_exception:		Exception thrown by unexpected handlers
bad_function_call:	Exception thrown on bad call
bad_typeid:			Exception thrown on typeid of null pointer
bad_weak_ptr:		Bad weak pointer (class )
logic_error:	Logic error exception
runtime_error:	Runtime error exception


Indirectly (through logic_error):

domain_error:		Domain error exception (class )
future_error:		Future error exception (class )
invalid_argument:	Invalid argument exception (class )
length_error:		Length error exception (class )
out_of_range:		Out-of-range exception (class )
	
Indirectly (through runtime_error):

overflow_error:		Overflow error exception (class )
range_error:		Range error exception (class )
system_error :		System error exception (class )
underflow_error:	Underflow error exception (class )

Indirectly (through bad_alloc):

bad_array_new_length:	Exception on bad array length (class )

*/

//****************************  User defined Exceptions: ***************************************//

// we can define your own exceptions by inheriting and overriding exception class functionality

/*
#include "iostream.h"
#include <exception>


class MyException : public exception
{
public:

  const char* what() const throw ()  //what is a method of exception class
  {
    return "C++ Exception";
  }
};
 
void main()
{
  try
  {
    throw MyException();
  }
  catch(MyException& e)
  {
    cout << "MyException caught" << endl;
    cout << e.what() << endl;
  }
  catch(std::exception& e)
  {
    //Other errors
  }
}
*/


/*********************************************   Fatal errors ****************************************************/
/*
If the error is so bad that the program can not continue to operate properly, 
this is called a non-recoverable error (also called a fatal error). In such cases, the best thing to do is terminate the program. 

If your code is in main() or a function called directly from main(), 
the best thing to do is let main() return a non-zero status code.

However, if you’re deep in some nested subfunction, a halt statement (such as std::exit()) can be used

*/

/*********************************************   noexcept keyword  ****************************************************/
/*
In C++, all functions are classified as either non-throwing (do not throw exceptions) or 
potentially throwing (may throw an exception).

It is not enforced at compile time
If a noexcept function throws an exception it calls std::terminate

The noexcept specifier defines a function as non-throwing.
noexcept can be declared as noexcept(true) and noexcept(false). A simple noexcept is same noexcept(true)

Examples:
void doSomething() noexcept; // this function is non-throwing
void f() noexcept; // the function f() does not throw
void (*fp)() noexcept(false); // fp points to a function that may throw

noexcept doesn’t actually prevent the function from throwing exceptions or calling other functions that are potentially throwing.
Rather, when an exception is thrown, if an exception exits a noexcept function, std::terminate will be called. 
And note that if std::terminate is called from inside a noexcept function, stack unwinding may or may not occur
which means your objects may or may not be destructed properly prior to termination.

Example

void doSomething() noexcept
void main()
{
    doSomething() // It does not mean doSomething will not throw exceptions
                 //If there is an exception inside this function, the compiler would call std::terminate and immediatley stops.

    int i = 10;
    Cout << test <<endl;



The Functions that are non-throwing by default but they become throwing functions if they call any other functions 
which can throw so if we want them strictly to be non throwing then we should use noexcept keyword

default constructors
copy constructors
move constructors
destructors
copy assignment operators
move assignment operators
}
*/


/*********************************************   The noexcept operator  ****************************************************/
/*
The noexcept operator can be used inside functions. 
It takes an expression as an argument, and returns true or false if the compiler thinks it will throw an exception or not. 
The noexcept operator is checked statically at compile-time, and doesn’t actually evaluate the input expression.


void foo() {throw -1;}
void boo() {};
void goo() noexcept {};
struct S{};

constexpr bool b1{ noexcept(5 + 3) }; // true; ints are non-throwing
constexpr bool b2{ noexcept(foo()) }; // false; foo() throws an exception
constexpr bool b3{ noexcept(boo()) }; // false; boo() is implicitly noexcept(false)
constexpr bool b4{ noexcept(goo()) }; // true; goo() is explicitly noexcept(true)
constexpr bool b5{ noexcept(S{}) };   // true; a struct's default constructor is noexcept by default

*/



//********************************** Good thing about Stack Unwinding *******************************************************//

/*
In stack unwinding, execution proceeds as follows :
    Control reaches the try statement by normal sequential execution
    If no exception occurs 
        If no exception occurs then none of the catch blocks will be called and code after that gets executed
    When an exception occurs 
        An exception object is created by throw operand
        Compiler looks for the catch block that can handle the exception occured. 
        If no catch block is found to handle exception terminate is called
        If another exception has occured before stack undwinding has begun after there is an exception then terminate is called
        If catch block is found has argument as value then 
            exception object created by throw is copied to argument of catch block
        If catch block is found has argument as reference then 
            exception is directly referred here

        After the object is intialized either by value or reference as above the stack unwinding process begins
        This involves the destruction of all automatic objects that were fully constructed—but not yet destructed—between the
            beginning of the try block that is associated with the catch handler and the throw site of the exception
        Destruction occurs in reverse order of construction.
*/

/*
Unhandles exceptions are dangerous. In the follwing code if you have throw statement and if you do not have try and catch blocks then
exception reaches main and it goes out of main and 
    1. It results in calling std::terminate and default action of terminate is to call abort 
    2. No stack unwinding happens
    3. No destructor are called
    4. Resources are leaked

    If you want terminate to call some other function in your program before exiting the application, 
            call the set_terminate function with the name of the function to be called as its single argument.
*/

//Objects in the stack are destroyed before the control goes out of that function. In the example below i is destroyed before it goes to function g()
// Destruction happens in the reverse order of construction
// vector v is formed 1st and then int i but destruction happens in reverse order during exception

//void f()
//{
//    int i = 10;
//    throw; //Here before it goes catch block in the main function. It makes sure that varibale i is destroyed
//}
//
//void g()
//{
//    std::vector<int> v = { 1,2,3 }; //This vector is also destroyed in case of throw before going to catch block in main function
//    f();
//}
//
//void main()
//{
//    try
//    {
//        g();
//    }
//    catch (...)
//    {
//
//    }
//}




//**************************************** When to use Exceptions *******************************************************//
/*
use exceptions
    1. for errors that occur rarely because exceptions are heavy
    2. for exceptional cases which can't be dealt locally
        File not found
        Can't find key in map
    3. for operator and constructors - because these are few functions that can't really return anything from them

Dont use exceptions
    1. for errors that occur often
    2. for functions that are expected to fail
    3. when response time for functions is less even if failure occurs as exceptions might take a lot of time
    4. for issues that usally shouldn't happen (These are bugs, don't try to handle them with exceptions)
         Dereferencing nullptrs
         out of range access

*/


//**************************************** How to use Exceptions *******************************************************//
/*
1. Build exceptions on std::exception (This is base class for lot of types of exception classes like std::bad_alloc, std::runtime, std::logic_error etc)
2. Throw r-values -Don't throw by pointer or reference
3. Catch by reference -
    Catch by values is bad because
        1. It makes a copy
        2. The exception might be sliced off (If you throw by std::bad_alloc and catch using std::exception, though it works but there may be object slice)

*/



//**************************************** Exceptions safety Gurantees *******************************************************//
/*
Code is said to be exception safe by not just using try and catch but program staying consistent even there is an exception thrown

    It has 3 levels

    1. Basic Exception safety gurantee
        Function might throw exception but program will remain self-consistent
        Invariants are preserved
        No resources are leaked 
        won't leave an object in an invalid state

        This is the weakest gurantee of the three gurantees available
        The basic guarantee states that if an exception occurs, 
                    no memory is leaked and the object is still in a usable state even though the data might have been modified.

    2. Strong Exception safety gurantee
        The program's state remains unchanged evne after exception
        Invariants are preserved
        No resources are leaked
        No state changed (committ or rollback), It means the program state is like same as before calling the function which throws
        Not always possible (sockets treams etc)

        A function that provides a strong guarantee is essentially a transaction that has commit or rollback semantics: 
            either it completely succeeds or it has no effect.

    3. No-Throw Gurantee or n-fail gurantee
        The operation can't fail
        Even there is an exception, this function guarantees that the exception will be handled inside it and doen't propogate to caller
        Expressed in code with "noexcept" key word

        This is the strongest gurantee 
        It states that the function will not throw an exception or allow one to propagate
        However, we cannot reliably provide such a guarantee unless 
            (a) we know that all the functions that this function calls are also no-fail or no-Throw gurantee
            (b) we know that any exceptions that are thrown are caught before they reach this function
            (c) we know how to catch and correctly handle all exceptions that might reach this function.


        Both the strong guarantee and the basic guarantee rely on the assumption that the destructors are no-fail. 
        All containers and types in the Standard Library guarantee that their destructors do not throw.


     Functions that  should never fail 

        1. Destructors
            These are for sure called during stack unwinding
            If an exception occurs while another exception is already there, then terminate() is called
            Destructor are marked as noexcept since c++11
            clean up must be safe

        2. Move constructor 
        3. Swap operation
        4. opeartor delete


        -------Use the RAII idiom to manage resources----------[
        To be exception-safe, a function must ensure that objects that it has allocated by using malloc or new are destroyed, 
            and all resources such as file handles are closed or released even if an exception is thrown
        In exception-safe code, it is critically important to pass ownership of each resource immediately to some kind of RAII object. 
        Note that the vector, string, make_shared, fstream, and similar classes handle acquisition of the resource
            
*/


//**************************************** Benifits of noexcept keyword *******************************************************//
/*
noexcpet keyword makes the promise to never "throw visible" in the code 
noexcpet can lead to faster code 
If an exception is thrown from a function which is marked as noexcept then compiler calls terminate 
    In this case compiler doesn't keep its promise of not throwing 
*/


#include <string>

//**************************************** RAII pattern *******************************************************//
/*
RAII - Resource acquisition is intialization is an idiom which states that 
acuquire the resource in constructor
release the resource in destructor 


Follwing is an example class which implements RAII for a default "FILE" class 
*/
//class MyFile
//{
//public:
//
//    //constructor - option 1
//    //Here we warapped the fopen function which returns a file pointer fp in the construtor of our class 
//    // In this case we utilize the help of is_open function if fopen fails and returns nullptr (as construcor can't return value to the caller)
//    MyFile(const char* strfilename, char const* Mode) : fp{ fopen(strfilename, Mode) }  { }; 
//
//    //constructor - option 2
//    //Here we warapped the fopen function which returns a file pointer fp in the construtor of our class 
//    //In this case, we check fp is nulllptr and throw exception
//
//
//    //When a ctor throws an exception, the construction is interrupted before it finishes
//        //The destructor won't be called as object was never created fully
//       // Ctor might need to clean up all the resources that have been allocated before it throwing an exception
//    MyFile(const char* strfilename, char const* Mode) : fp{ fopen(strfilename, Mode) }  
//    {
//        if (fp == nullptr)
//            throw catastrophic_failure();
//    }; 
//
//    //Here we wrapped up the fclose function in our destructor
//    ~MyFile() noexcept 
//    { 
//        if (fp != nullptr) //if pointer is nullptr for any reason , just close the file 
//            { fclose(fp); }
//    };
//
//
//    //when we try to open a file using our MyFile class. It internally calls "fopen" and if "fopen" fails , it returns a nullptr
//    // and our fp becomes nullptr but since this is all hapenning in MyFile constructor we can't 
//    // use fp (at the caller of MyFile) to check if file opening is failed or not so we need this function
//    bool is_open() noexcept { return fp != nullptr; };
//
//    void put(int i) {};
//    void put(std::string strFilecontent) {};
//
//private:
//    FILE* fp;
//};


/*************    basic safety guarantee for above file example *****************/

//For above implementation, we can have the basic safety guarantee as follows
//Here even an exception occurs then myfile object goes out of scope and makes sure that destructor of MyFile class is called
// and the file is closed.

//problems
// This is still not stongly safe because if g() throws exception then the exception will flow out of function f, even though the files
// gets closed and some content is already written to file by that time (  myfile.put("The value is"); )

//void f(char const * filename)
//{
//    MyFile myfile(filename, "W");
//    if (myfile.is_open())
//    {
//        myfile.put("The value is");
//        myfile.put(g()); //writing content by callin some external function g()
//    }
//}


/*************    strong safety guarantee for above file example *****************/

//Follwing are techniques to have strong guarantee 
//Here we called g() before write so that even if there is exception in g(), it will throw before it writes to file
//so there will be nothing written to file in case of exception and file will also get closed in case of exception
//void f(char const * filename)
//{
//    MyFile myfile(filename, "W");
//    int temp = g();
//    if (myfile.is_open())
//    {
//        myfile.put("The value is");
//        myfile.put(temp); 
//    }
//}

/****** Avoid throwing in Destructors ***********/
//If an exception occurs then destructor is the one that gets called and if the dstrcutor again throws an exception
//then compiler may not handle it and std::terminate is called which can lead to anything
//So destructors and opeartor delete should never throw


/************************  Guidelines ***********************************/
/*
1. RAII is the single most idiom of c++ programming language. Use it 

2. All functions should atleast provide the basic exception guarantee, if possible and reasonable the strong guarantee

3. Consider the no-throw gurantee, but only provide it if you can gurantee it even for possible future changes

*/












//no gurantee
//
//
// 
//basic gurantee 
// 
// 
// 
//strong gurantee   
// 
// 
// 
//nothrow gurantee















//no gurantee

//const char* getvalue()
//{
//    throw 6;
//    return "get value";
//}
//
//void write(char const* filename)
//{
//    FILE* fp = fopen(filename, "w");
//    
//    if (fp  != nullptr)
//    {
//        printf("file is opened successfully \n");
//        fprintf(fp, "line 1 \n");
//        fprintf(fp, getvalue());
//        fclose(fp);
//        printf("file is closed successfully \n");
//    }
//}
//
//int main()
//{
//    write("D:\\input.txt");
//    return 0;
//}






//Basic gurantee 

//RAII - Resource acquisition is initialization  -  

//
//const char* getvalue()
//{
//    throw 6;
//    return "get value";
//}
//
//class MyFileClass
//{
//public:
//    FILE* fp;
//
//    MyFileClass(char const* filename)
//    {
//        fp = fopen(filename, "w");
//    }
//
//    ~MyFileClass()
//    {
//        fclose(fp);
//        printf("file is closed successfully \n");
//    }
//
//    void PutData(const char* data)
//    {
//        fprintf(fp, data);
//    }
//
//    bool is_open()
//    {
//        return (fp != nullptr ? true : false);
//    }
//
//};
//
//
//void write(char const* filename)
//{
//    MyFileClass fileobj(filename);
//    if (fileobj.is_open())
//    {
//        printf("file is opened successfully \n");
//
//        fileobj.PutData("line 1"); //line 1
//
//
//        try
//        {
//            getvalue();
//        }
//        catch (...)
//        {
//            return;
//        }
//
//        fileobj.PutData(getvalue()); //line 2
//    }
//
//}
//
//int main()
//{
//    write("D:\\input.txt");
//    return 0;
//}
//





//strong gurantee
//const char* getvalue()
//{
//    throw 6;
//    return "get value";
//}
//
//class MyFileClass
//{
//public:
//    FILE* fp;
//
//    MyFileClass(char const* filename)
//    {
//        fp = fopen(filename, "w");
//    }
//
//    ~MyFileClass()
//    {
//        if(fp != nullptr )
//            fclose(fp);
//        printf("file is closed successfully \n");
//    }
//
//    void PutData(const char* data)
//    {
//        fprintf(fp, data);
//    }
//
//    bool is_open()
//    {
//        return (fp != nullptr ? true : false);
//    }
//
//};
//
//
//void write(char const* filename)
//{
//   
//
//    const char* val = nullptr;
//    try
//    {
//        val = getvalue();
//    }
//    catch (...)
//    {
//        return;
//    }
// 
// 
// 
//   MyFileClass fileobj(filename);
//    if (fileobj.is_open())
//    {
//        printf("file is opened successfully \n");
//
//        fileobj.PutData("line 1"); //line 1
//        fileobj.PutData(val); //line 2
//    }
//
//}
//
//int main()
//{
//    write("D:\\input.txt");
//    return 0;
//}







//class Test
//{
//private:
//    int* m_p;
//
//public:
//   
//    Test(int i)
//    {
//        m_p = new int(10);
//    };
//
//    ~Test() //std::terminate
//    {
//        throw;
//        delete m_p;
//    }
//
//    void func() noexcept(false)
//    {
//        try
//        {
//            throw 1;
//        }
//        catch (double d)
//        {
//
//        }
//    }
//
//};
//
//int main()
//{
//    Test obj(10);
//    try
//    {
//        obj.func();
//    }
//    catch (...)
//    {
//        throw;
//    }
//}





//#include <iostream>
//#include <filesystem>
//#include <fstream>
//
////using namespace std;
//
//int main()
//{
//    //std::experimental::filesystem
//
//     std::experimental::filesystem::path path{ "D:\\TestingFolder" }; //creates TestingFolder object on C:
//    path /= "my new file.txt"; //put something into there
//    std::filesystem::create_directories(path.parent_path()); //add directories based on the object path (without this line it will not work)
//
//    std::ofstream ofs(path);
//    ofs << "this is some text in the new file\n";
//    ofs.close();
//
//    return 0;
//}

