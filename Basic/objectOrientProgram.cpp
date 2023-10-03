#include<iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
        Rectangle(){ // default constructor --> no parameters and initializes to 1 if you want
            length = 1; 
            breadth = 1;
        }
        Rectangle(int l , int b){ //constructor // --> CONSTRUCTOR OVERLOADING
            length = l;
            breadth = b;
        }
        int area(){
            return length * breadth;
        }
        ~Rectangle(){//DESTRUCTOR
            cout << "Destructor" << endl;
        } 
};
int main(){
    Rectangle r1(10, 50);
    int area = r1.area();
    cout << area << endl;
    return 0;
}