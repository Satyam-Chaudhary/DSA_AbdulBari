#include <stdio.h>

int x = 0; //global variable same as static variable

int fun5(int n){
   // static int x = 0; // Static Variable --> not in the stack frame and is created only once rather than getting copied every single time
    if(n > 0){
        x++;
        return (fun5(n-1) + x);
    }
    return 0;
}

int main()
{
    int r;
    r = fun5(5);
    printf("%d\n" , r);

    r = fun5(5);
    printf("%d\n" , r); // give 50 as x starts at x = 5 because previous function made x from 0 to 5

    return 0;
}