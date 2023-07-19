// AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
// Abstract product 
class HWProduct
{
public:
    virtual void readData()=0;
    virtual void writeData()=0;
};


//Concrete USB Product
class USBProduct:public HWProduct
{
public:
    USBProduct() {}
    void readData()
    {
        cout << "USB Read"<<endl;
    }
    void writeData()
    {
        cout << "USB Write"<<endl;
    }
};



//Concrete PCI Product
class PCIProduct:public HWProduct
{
public:
    PCIProduct() {}
    void readData()
    {
        cout << "PCI Read"<<endl;
    }
    void writeData()
    {
        cout << "PCI Write"<<endl;
    }
};




// Abstract Factory
class HardwareFactory
{
public:
    virtual HWProduct* getProduct()=0;
};



// Concrete USB Factory
class USBFactory:public HardwareFactory
{
public:
    HWProduct* getProduct()
    {
        return new USBProduct();
    }
    ~USBFactory(){}
};




// Concrete PCI Factory
class PCIFactory:public HardwareFactory
{
public:
    HWProduct* getProduct()
    {
        return new PCIProduct();
    }
    ~PCIFactory(){}
};



class Application
{
public:
    Application(HardwareFactory* factory) 
    { 
        HWProduct* product = factory->getProduct(); 
        product->readData();
        product->writeData();
        delete product;
        delete factory;
    }
};




HardwareFactory* getHWFActory(short int FactoryID)
{
    if(FactoryID == 1)
        return new USBFactory();
    else
        return new PCIFactory();
} 




int main()
{
    Application  app(getHWFActory(1));
    return 0;
}



