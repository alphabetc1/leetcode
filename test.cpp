#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory>
#include <algorithm>
using namespace std;

class A{
public:
    // A() {
    //     f();
    // }
    virtual void f()    {
        cout<<"A"<<endl;
    }
};

class B: public A{
public:
    B() {
        f();
    }
    virtual void f()    {
        cout<<"B"<<endl;
    }
};


int main()
{
    

    return 0;
}