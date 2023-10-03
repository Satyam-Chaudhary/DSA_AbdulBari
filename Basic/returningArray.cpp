// can only be passed by address not by value
#include<iostream>
using namespace std;
int* fun(int n){
    int* p;
    //p = (int*)malloc(n * sizeof(int));
    p = new int[5];
    return p;
}

int main(){
    
    int* A;
    int n = 5;
    A = fun(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> A[i];
    }
    for(int i = 0 ; i < n ; i++){
        cout << A[i] << " "; // A[] == *(A + i)
    }
    cout << endl;

    return 0;
}