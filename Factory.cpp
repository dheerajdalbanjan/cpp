// A design without factory pattern
#include <iostream>
using namespace std;

// Library classes
class Vehicle {
public:
	virtual void printVehicle() = 0;
};
class TwoWheeler : public Vehicle {
public:
	void printVehicle()
	{
		cout << "I am two wheeler" << endl;
	}
};
class ThreeWheeler : public Vehicle {
public:
	void printVehicle()
	{
		cout << "I am three wheeler" << endl;
	}
};
class FourWheeler : public Vehicle {
public:
	void printVehicle()
	{
		cout << "I am four wheeler" << endl;
	}
};

// Client (or user) class
class Client {
public:
	Client(int type)
	{
		//Client explicitly creates classes according to
		// type
		if (type == 1)
			pVehicle = new TwoWheeler();
		else if (type == 2)
			pVehicle = new FourWheeler();
        else if (type == 3)
			pVehicle = new ThreeWheeler();
		else
			pVehicle = NULL;
	}

	~Client()
	{
		if (pVehicle) {
			delete pVehicle;
			pVehicle = NULL;
		}
	}

	Vehicle* getVehicle() { return pVehicle; }

private:
	Vehicle* pVehicle;
};

// Driver program
int main()
{
	Client* pClient = new Client(1);
	Vehicle* pVehicle = pClient->getVehicle();
	pVehicle->printVehicle();
	cout<<pVehicle<<endl;

	Client* pClient1 = new Client(2);
	Vehicle* pVehicle1 = pClient1->getVehicle();
	pVehicle1->printVehicle();
	cout<<pVehicle1<<endl;

	Client* pClient2 = new Client(3);
	Vehicle* pVehicle2 = pClient2->getVehicle();
	pVehicle2->printVehicle();
	cout<<pVehicle2<<endl;
	return 0;
}
