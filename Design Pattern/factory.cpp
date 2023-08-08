#include <iostream>
using namespace std;

class Toy{
    int name ; 
    public : 
    Toy(int name) : name(name) {} 
    virtual void display() {
        cout<<"Main toy display"<<endl;
    }
} ;


class Car: public Toy{
    public: 
    Car(int name): Toy(name) {} 
    void display(){
        cout<<"Collecting parts..."<<endl;
        cout<<"Assembling parts..."<<endl;
        cout<<"Designing..."<<endl;
        cout<<"Your car is ready"<<endl ; 
    }
}; 

class Bike: public Toy{
    public: 
    Bike(int name): Toy(name) {} 
    void display(){
        cout<<"Collecting parts..."<<endl;
        cout<<"Assembling parts..."<<endl;
        cout<<"Designing..."<<endl;
        cout<<"Your Bike is ready"<<endl ; 
    }
}; 

class Cycle: public Toy{
    public: 
    Cycle(int name): Toy(name) {} 
    void display(){
        cout<<"Collecting parts..."<<endl;
        cout<<"Assembling parts..."<<endl;
        cout<<"Designing..."<<endl;
        cout<<"Your cycle is ready"<<endl ; 
    }
}; 


class Factory {
    public: 
    static Toy * chooseFactory(int type ){
        Toy * tv ; 
        switch(type){
            case 1: 
            tv = new Car(1); 
            break;
            case 2:
            tv = new Bike(2); 
            break;
            case 3:
            tv = new Cycle(3); 
            break ; 
            default: 
            cout<<"Invalid case"<<endl ;
        } 
        return tv ;
    }
};






int main() {
    int ch ; 
    while(true){
        cout<<"1. Car\n2.Bike\n3.Cycle\n" ; 
        cin>>ch ; 
        Toy * t ; 
        t = Factory::chooseFactory(ch); 
        t->display() ; 
    }
    return 0 ; 
}