#include<iostream>
using namespace std;

// void swap(int a, int b){ // call by value
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void swap(int* a, int* b){ // call by address
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swap(int &x, int &y){ // call by reference // refernce is just different name for variable and any change to them reflects the change in original vaiable
    int temp = x;
    x = y;
    y = temp;
}


int main(){
    int a = 10, b = 20;
    //swap(a,b)l //call by value
    // swap(&a, &b); // call by address
    swap(a, b); // call by reference
    cout << a << " " << b << endl;

    return 0;
}