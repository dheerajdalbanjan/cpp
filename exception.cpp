#include <iostream>
#include <exception>
#include <string.h>
#include <cstring>
using namespace std;


class Custom : public exception{
    int no ; 
    string msg ; 
    public : 
    Custom(int no, char * msg):no(no), msg(msg){}

    const char * what() const throw(){
        static char buffer[100]; // Assuming a reasonable size for the buffer
        std::string errorStr = "Error code: " + std::to_string(no) + ", " + msg;
        strncpy(buffer, errorStr.c_str(), sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
        return buffer;
    }
};

class a{
    int x ; 
    int y ; 
    public:
    a(int x, int y) : x(x), y(y){}

    friend class b ;
} ; 

class b{
    public:
    void display(a &k){
        cout<<"x: "<<k.x<<" y: "<<k.y<<endl ; 
    }
}; 


int main(){
    int x = 1; 
    char msg[] = "I love you" ;
    a k(6, 9); 
    b l ; 

    try {
        if (x == 1){
            l.display(k) ; 
            throw Custom(143,"I love you" ); 
        }
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }

    return 0 ; 
}