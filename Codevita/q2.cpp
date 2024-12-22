// animal , three dderived classes Bird , Cat , Dog and one derived overriden method makeSound()
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
class Animal {
    protected:
    string name ; 
    int age ; 
    public:
    Animal(string name , int age) {
        this->name = name ;
        this->age = age ;
    }
    virtual void makeSound() = 0;
};
class Bird : public Animal {
    public:
    Bird(string name , int age) : Animal(name , age) {}
    void makeSound() {
        cout << "Bird makes sound" << endl ;
    }
};
class Cat : public Animal {
    public:
    Cat(string name , int age) : Animal(name , age) {}
    void makeSound() {
        cout << "Cat makes sound" << endl ;
    }
};
class Dog : public Animal {
    public:
    Dog(string name , int age) : Animal(name , age) {}
    void makeSound() {
        cout << "Dog makes sound" << endl ;
    }
};
int main() {
    vector<Animal*> animals ;
    animals.push_back(new Bird("Birdy" , 5)) ;
    animals.push_back(new Cat("Kitty" , 3)) ;
    animals.push_back(new Dog("Doggy" , 2)) ;
    for (auto animal : animals) {
        animal->makeSound() ;
    }
    return 0;
}