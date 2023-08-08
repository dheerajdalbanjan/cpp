#include <iostream>
using namespace std;

class Singleton{
    string name ;
    string loves ;
    static Singleton* instancePtr ; 

    Singleton(){

    }

    public: 
    Singleton(const Singleton& other) = delete ; 

    static Singleton * getInstance(){
        if(instancePtr==NULL){
            instancePtr = new Singleton(); 
            return instancePtr;
        }
        else {
            return instancePtr;
        }
    }

    void setValue(string name, string loves){
        this->name = name ; 
        this->loves = loves ;
    }

    void print(){
        cout<<this->name<<" loves "<<this->loves<<endl ; 
    }
}; 

Singleton * Singleton::instancePtr = NULL ; 

int main(){
    Singleton *ptr , *g ; 
    ptr = Singleton::getInstance() ; 
    ptr->setValue("Dheeraj", "Eleven"); 
    ptr->print() ; 
    cout<<ptr<<endl ; 
    g = Singleton::getInstance() ;
    g->setValue("Dheeraj", "Max") ; 
    g->print() ; 
    cout<<g <<endl  ; 
    return 0; 
}