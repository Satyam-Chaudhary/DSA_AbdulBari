// Calling Phase Recursion --> printf executes at calling time
#include<stdio.h>
void fun1(int n){
    if(n > 0){
        printf("%d\n" , n);
        fun1(n-1);
    }
}
int main(){
    int x = 3;
    fun1(x);
    return 0;
}