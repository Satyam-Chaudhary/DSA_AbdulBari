//Returning phase Recursion --> printf executes at returning time
#include<stdio.h>
void fun2(int n){
    if(n > 0){
        fun2(n-1);
        printf("%d\n" , n);
    }
}
int main(){
    int x = 3;
    fun2(x);
    return 0;
}