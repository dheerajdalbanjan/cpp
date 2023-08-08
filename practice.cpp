#include <iostream>
#include <string.h>
using namespace std;

class Laptop{
    protected:
    string brandName ;
    int memorySize ; 
    int numberOfCores ;
    float basicPrice ; // 4gb, 4cores
    public:
    Laptop(){
        cout<<"Default constructor"<<endl ;
        cin>>brandName>>memorySize>>numberOfCores>>basicPrice;
    }
    Laptop(string bn, int ms, int nc, float bp){
        cout<<"Parent Parameterized constructor"<<endl ;
        brandName = bn ;
        memorySize = ms ; 
        numberOfCores = nc ;
        basicPrice = bp ;
    }
    float getPrice(){
        float price = basicPrice*(memorySize/4 + numberOfCores/4) ;
        return price ;
    }
}; 

class Tablet: public Laptop{
    float touchScreenSize ; // 8inch
    bool mouse ;
    bool keyboard; //   true if keyboard is enabled                
    public: 
    Tablet(float t, bool m = false, bool k = false){
        cout<<"Parameterized constructor: child "<<endl;
        touchScreenSize = t ;
        mouse = m ; 
        keyboard = k ;
    }
    float getPrice(){
        float price = basicPrice*((float)memorySize/4 ) ; 
        price += (float)numberOfCores/6 ; 
        price += (float)touchScreenSize/8 ;
        if(mouse){
            price += 500 ;
        }
        if(keyboard){
            price += 1000; 
        }
        return price ;
    }
};


int main(){
    Laptop hp("HP", 8, 16, 1000) ;
    float p = hp.getPrice() ;
    cout<<"The Laptop price is $"<<p<<endl; 
    Tablet t(16.7, true, true) ;
    p = t.getPrice() ;
    cout<<"The tablet price is $"<<p<<endl;
    return 0; 
}