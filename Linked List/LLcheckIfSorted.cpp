#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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

bool checkIfSorted(struct Node *p){
    int x = INT8_MIN;
    while(p){
        if(p->data < x){
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int count(){
    Node *p = first;
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

void display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}



int main(){
    

    int A[6] = {2, 4, 5, 7, 8, 9};
    create(A , 6);
    cout << checkIfSorted(first) << endl;
    
    return 0;
}