#include <iostream>
using namespace std;


class Complex{
    int a ; 
    int b ;
    public: 
    friend Complex suma(Complex a, Complex b) ; 
    void setNum(int n1, int n2){
        a = n1; 
        b = n2 ;
    }

    void printNum(){
        cout<<a<<" + "<<b<<"i "<<endl ;
    }
};

Complex suma(Complex a, Complex b){
    Complex c ; 
    c.setNum(a.a + b.a, a.b+ b.b) ;
    return c  ;
}

int main(){
    Complex a, b, sum ;
    a.setNum(1, 2); 
    b.setNum(2, 3); 

    sum = suma(a, b); 
    sum.printNum() ;
    return 0; 
}