#include <iostream>

class Beverage {
public:
    // This is the template method that defines the algorithm structure
    void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }
};

class Coffee : public Beverage {
public:
    void brew() override {
        std::cout << "Dripping coffee through filter" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk" << std::endl;
    }
};

class Tea : public Beverage {
public:
    void brew() override {
        std::cout << "Steeping the tea" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding lemon" << std::endl;
    }
};

int main() {
    Beverage *coffee = new Coffee();
    coffee->prepareBeverage();
    delete coffee;

    std::cout << std::endl;

    Beverage *tea = new Tea();
    tea->prepareBeverage();
    delete tea;

    return 0;
}
