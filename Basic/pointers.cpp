#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    int a = 10;
    int* p;
    p = &a;
    cout << "Pointer --> "<< *p << endl;
    printf("Pointer address --> %lu \n" , (unsigned long)p);

    int A[5] = {0};
    int* z;
    z = A;

    for(int i = 0 ; i < 5 ; i++){
        cout << z[0] << " "; // same as *z
    }
    cout << endl;

    int* x;
    x = (int*)malloc(5 * sizeof(int)); // x = new int[5]; --> for cpp
    x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4; x[4] = 5; // in heap same as *(x+i)
    for(int i = 0 ; i < 5 ; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    free(x); // freed up the heap memory // delete []p
    for(int i = 0 ; i < 5 ; i++){
        cout << x[i] << " ";
    }
    cout << endl;


    int *p1;
    float *p2;
    double *p3;
    char *p4;
    struct Rectangle *p5;

    cout << sizeof(p1) << " " << sizeof(p2) << " " << sizeof(p3) << " " << sizeof(p4) << " " << sizeof(p5) << endl;
    //pointers take same amount of memory
    return 0;
}