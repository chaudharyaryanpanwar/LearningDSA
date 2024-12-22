//person class  , display_info method , instance of person 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
class Person {
    private : 
    string name ; 
    int age ; 
    string address ; 
    public:
    Person(string name, int age, string address) {
        this->name = name ; 
        this->age =age ; 
        this->address = address ;
    }
    void display_info() {
        cout << "Name : " << name << endl ;
        cout << "Age : " << age << endl ;
        cout << "Address : " << address << endl ;
    }
    string get_name(){
        cout << "Name : " << name << endl ;
        return name ; 
    }
    int get_age(){
        cout << "Age : " << age << endl ; 
        return age ; 
    }
    string get_address(){
        cout << "Address : " << address << endl ;
        return address ; 
    }
    void set_name(string name){
        this->name = name ;
    }
    void set_age(int age){
        this->age = age ;
    }
    void set_address(string address){
        this->address = address ; 
    }
};
int main() {
    Person person("Nagar", 21, "Meerut") ;

    cout << person.get_name() << endl ;
    cout << person.get_age() << endl ;
    cout << person.get_address() << endl ;
    person.set_name("Dubey") ;
    person.set_age(25) ;
    person.set_address("Kanpur , kidwai nagar") ;

    person.display_info() ; 

    //how to use copy constructor ?
    cout << "---------------------------------"<<endl ; 
    Person person2(person) ;
    person2.display_info() ;
    person2.set_age(21);
    person.get_age() ; 
    person2.get_age() ; 
    return 0;
}