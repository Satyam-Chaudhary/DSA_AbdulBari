#include<iostream>
using namespace std;

int add(int a , int b){ //formal parameters
    return (a+b);
}

int main(){
    int a = 10;
    int b = 20;
    int c = add(a,b); // actual parameters
    cout << c << endl;

    return 0;
}