#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define MIN_INT  0;
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[] , int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
    }
}

int max(Node * p){
    int x = MIN_INT;
    while(p){
        if(p->data > x){
            x = p->data;
        }
            p = p->next;
    }
    return x;
}

int min(Node *p){
    int x = p->data;
    while(p){
        if(p->data < x){
            x = p->data;
        }
            p = p->next;
    }
    return x;
}

int maxRec(Node * p){
    int x = 0;
    if(!p){
        return x;
    }
    x = maxRec(p->next);
    return (x > p->data ? x : p->data);
}

int minRec(Node * p ){
    int x = INFINITY;
    if(!p){
        return x;
    }
    x = minRec(p->next);
    if(x < p->data)
        return x;
    else
        return p->data;
}

int main(){
    int A[6] = {3, 5, 1 ,5 ,10, 2};
    create(A , 6);

    cout << "Max--> " << max(first) << endl;
    cout << "Min--> " << min(first) << endl;
    cout << "Max--> " << maxRec(first) << endl;
    cout << "Min--> " << minRec(first) << endl;
    

    return 0;
}