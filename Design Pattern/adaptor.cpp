#include <iostream>
using namespace std;

class Indiancharger{
    public:
    virtual void indiacharge() = 0 ; 
}; 


class Usacharger{
    public:
    void usacharger(){
        cout<<"charging using usa socket\n"; 
    }
}; 


class adapter: public Indiancharger, public Usacharger{
    public: 
    void indiacharge(){
        usacharger() ; 
    }
}; 

int main(){
    


    return 0; 
}