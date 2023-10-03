#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

void callByValue(Rectangle r1){ //CALL BY VALUE // we can leave writing struct in cpp
    r1.length = 200;
    cout << "Length -> " << r1.length << endl << "Breadth -> " << r1.breadth << endl;
}

void callByRefrence(struct Rectangle &r1){ //CALL BY REFRENCE
    r1.length = 12;
    cout << "Length -> " << r1.length << endl << "Breadth -> " << r1.breadth << endl;
}

void callByAddress(struct Rectangle* r1){ //CALL BY ADDRESS
    r1->breadth = 22; // (*r1).breadth
    cout << "Length -> " << r1->length << endl << "Breadth -> " << r1->breadth << endl;
}

int main(){
    struct Rectangle r = {10 , 5};

    callByValue(r);
    callByRefrence(r); // only in cpp
    callByAddress(&r);
    
    cout << "legth " << r.length << endl << "breadth " << r.breadth << endl; // call by value and call by address changes the code in main function as well


    return 0;
}