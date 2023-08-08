#include <iostream>
#include <math.h>
using namespace std;

class Loan{
    protected:
    string loan_id ;
    float loan_amount ;
    float loan_interest ; 
    int rperiod ; 

    public : 
    Loan(string loan_id, float loan_amount, float loan_interest, int rperiod){
        this->loan_id = loan_id ;
        this->loan_amount = loan_amount ;
        this->loan_interest = loan_interest ;
        this->rperiod = rperiod ;
    }

    virtual void calculateEMI(){
        double r = loan_interest/1200 ; 
        double emi = (loan_amount*r*(pow(1 + r , rperiod)/pow(1 + r, rperiod - 1))) ;
        cout<<"EMI: "<<emi<<endl ;
    }

    virtual void displayDetails(){
        cout<<"\nLoan Details"<<endl ; 
        cout<<"----------------"<<endl ;
        cout<<"Loan Id: "<<loan_id<<endl ;
        cout<<"Loan Amount: "<<loan_amount<<endl ;
        cout<<"Loan Interest: "<<loan_interest<<endl ;
        cout<<"R period: "<<rperiod<<endl ;
    }

}; 


class FourWheeler : public Loan{
    float new_interest; 
    public : 
    FourWheeler(string loan_id, float loan_amount, float loan_interest, int rperiod): Loan(loan_id, loan_amount, loan_interest, rperiod) {
        cout<<"Enter the new interest for four wheeler?\nElse enter 0 if no change"<<endl ;
        cin>>new_interest ;
        if (!new_interest)
            new_interest = loan_interest ; 
    }

    void calculateEMI(){
        double r = new_interest/1200 ; 
        double emi = (loan_amount*r*(pow(1 + r , rperiod)/pow(1 + r, rperiod - 1))) ;
        cout<<"The EMI is: "<<emi<<endl;
    }

    void displayDetails(){
        cout<<"\nFour wheeler Loan Details"<<endl ; 
        cout<<"----------------"<<endl ;
        cout<<"Loan Id: "<<loan_id<<endl ;
        cout<<"Loan Amount: "<<loan_amount<<endl ;
        cout<<"Loan Interest: "<<loan_interest<<endl ;
        cout<<"R period: "<<rperiod<<endl ;
    }
} ;


class TwoWheeler : public Loan{
    float new_interest; 
    public : 
    TwoWheeler(string loan_id, float loan_amount, float loan_interest, int rperiod): Loan(loan_id, loan_amount, loan_interest, rperiod) {
        cout<<"Enter the new interest for two wheeler?\nElse enter 0 if no change"<<endl ;
        cin>>new_interest ;
        if (!new_interest)
            cout<<"a;lkdsf"<<endl ;
            new_interest = loan_interest ; 
    }

    void calculateEMI(){
        double r = new_interest/1200 ; 
        double emi = (loan_amount*r*(pow(1 + r , rperiod)/pow(1 + r, rperiod - 1))) ;
        cout<<"The EMI is: "<<emi<<endl;
    }

    void displayDetails(){
        cout<<"\nFour wheeler Loan Details"<<endl ; 
        cout<<"----------------"<<endl ;
        cout<<"Loan Id: "<<loan_id<<endl ;
        cout<<"Loan Amount: "<<loan_amount<<endl ;
        cout<<"Loan Interest: "<<loan_interest<<endl ;
        cout<<"R period: "<<rperiod<<endl ;
    }
} ;

class Customer {
    string name ;
    string address ; 
    string phone ; 
    Loan *loan ; 

    public :
    Customer(string name, string address, string phone, Loan *loan){
        this->name = name ;
        this->address = address ;
        this->phone = phone ;
        this->loan = loan ;
    }

    void display(){
        cout<<"Customer Details"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"Name: "<<this->name<<endl;
        cout<<"Address: "<<this->address<<endl;
        cout<<"phone: "<<this->phone<<endl ;
        loan->displayDetails() ;
    }

    void repayment(){
        cout<<"\nRepayment Status:"<<endl ;
        loan->calculateEMI() ; 
    }
}; 

int main(){
    int choice ;
    Loan *loan ;
    cout<<"Enter the type of loan your want to avail: \n1.Four Wheeler\n2. Two Wheeler"<<endl ; 
    cin>>choice ; 
    if(choice==1){
        FourWheeler f("k34j3k", 100, 6, 1) ;
        loan = &f ; 
    }
    else {
        TwoWheeler t("k34j3k", 100,6, 1) ;
        loan = &t ; 
    }
    
    Customer customer("Prajwal", "Dharwad", "918233434", loan) ;
    while(1){
        cout<<"1. Display Details(loan/customer)"<<endl ;
        cout<<"2. Repayment status/EMI"<<endl ;
        cin>>choice ; 
        switch (choice)
        {
        case 1:
            customer.display() ;
            break;
        
        default:
            loan->calculateEMI() ;
            customer.repayment() ; 
            break;
        }
    }
    return 0 ;
}