#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

struct Rectangle* createStructure(){ // object created by a function --> returning a pointer to structure
    struct Rectangle *p;
    p = new struct Rectangle;
    //p = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    return p;
}
int main(){
    
    struct Rectangle * ptr;
    ptr = createStructure();
    ptr->length = 20;
    ptr->breadth = 30;
    cout<< "Length -> " << ptr->length << endl << "Breadth -> " << ptr->breadth << endl;

    return 0;
}