#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    
    Rectangle r = {10, 5}; // in cpp you can leave writing struct but in c it's mandatory
    cout << r.length << " " << r.breadth << endl;

    Rectangle* p = &r; // pointer to structure
    cout << (*p).length << " " << p->breadth << endl; // (*p)length == p -> length // ARROW OPERATOR --> to not use dot operator as it has higher precendence thatn * and pointer to be put under ()

    Rectangle* p2;
    p2 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    //p2 = new Rectangle; //--> that's it in cpp

    p2->length = 20;
    p2->breadth = 30;
    cout << p2->length << " " << p2->breadth << endl;

    free(p2);


    return 0;
}