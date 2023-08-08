#include <iostream>
using namespace std;


class Base{
    public: 

    Base(){
        cout<<"fuck"<<endl; 
    }
    virtual void show(){
        cout<<"Base"<<endl;
    }
};


class Derv1: public Base{
    public: 
    void show(){
        cout<<"Derv1"<<endl;
    }
}; 

class Derv2: public Base{
    public: 
    void show(){
        cout<<"Derv2"<<endl;
    }
};

int main(){

    Derv1 dv1 ; 
    Derv2 dv2 ; 
    Base *ptr ; // object is not created 

    ptr = &dv1 ; 
    ptr->show() ;
    ptr = &dv2 ; 
    ptr->show() ;
    return 0; 
}

// virtual function is used to achieve run time polymorphism