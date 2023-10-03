#include<iostream>
using namespace std;

int main(){
    int A[5] = {0}; //initialized to 0
    A[0] = 12;
    A[1] = 13;
    int B[5] = {1, 2, 3, 4, 5};
    int C[10] = {2, 3, 3, 4, 5, 2};

    cout << sizeof(B) << endl;

    for(int i = 0 ; i < 5 ; i++){
        cout << A[i] << endl;
    }

    // for each loop --> iterate over elements

    for(int x : C){
        cout << x << endl;
    }

    int n;
    cout << "Enter size of array D: ";
    cin >> n;
    //int D[n] = {2, 3, 4, 5, 5, 2}; // cannot be initialized can be declared though
    int D[n];
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    for(int i = 0 ; i < n ; i++){
        cout << A[i];
    }
    cout << endl;

    return 0;
}