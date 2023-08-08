#include <iostream>
using namespace std ; 

class A{
    protected:int a ; 
    public:
    A(){
        cout<<"A"<<endl; 
    }
    void prinfA(){
        cout<<"This is print() of A"<<endl ; 
    }
}; 

class B : private A{
    int b ;
    public:
    B(){
        cout<<"B"<<endl; 
    }
    void print(){
        cout<<"print() of B"<<endl;
        prinfA() ; 
        cout<<a<<endl ; 
    }
}; 

/*
Public Mode: If we derive a subclass from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in the derived class.
Protected Mode: If we derive a subclass from a Protected base class. Then both public members and protected members of the base class will become protected in the derived class.
Private Mode: If we derive a subclass from a Private base class. Then both public members and protected members of the base class will become Private in the derived class.

Here only the public and protected members of the base class are inherited
*/


//protected - it is private but is accessible within the inhereted class

int main(){
    B b ;
    b.print() ; 
    return 0; 
}