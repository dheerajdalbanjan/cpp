#include <iostream>
using namespace std;

class Teacher {
    int teacherId ; 
    string teacherName ; 
    public: 
    Teacher(){
        cout<<"Teacher: Default constructor"<<endl ;
        cin>>teacherId>>teacherName ;
    }
    Teacher(int id , string name ){
        teacherId = id;
        teacherName = name;
    }

    void printTeacher(){
        cout<<"Teacher: "<<teacherId<<endl<<"Name:"<<teacherName<<endl ;
    }

}; 

class Course :public Teacher {
    int courseCode ;
    string courseTitle ;
    char grade ;
    int isa1 ;
    int isa2 ;
    int activity ; 
    public:
}; 

int main(){

    return 0 ;
}