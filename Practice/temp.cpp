#include <iostream>
using namespace std;
  
// base class
class Parent {
    // protected data members
protected:
    int id_protected;

public:
    Parent() {
        id_protected = 10;
    }
    void show() {
        cout << "protected: " << id_protected << endl;
    }
};
  
// sub class or derived class
class Child : public Parent {
  
public:
    void setId(int id)
    {
  
        // Child class is able to access the inherited
        // protected data members of base class
  
        id_protected = id;
    }
  
    void displayId()
    {
        cout << "id_protected is: " << id_protected << endl;
    }
};
  
// main function
int main()
{
    Parent Obj;
    Child obj1;
  
    // member function of the derived class can
    // access the protected data members of the base class
  
    Obj.show();
    obj1.setId(81);
    obj1.displayId();
    Obj.show();
    return 0;
}