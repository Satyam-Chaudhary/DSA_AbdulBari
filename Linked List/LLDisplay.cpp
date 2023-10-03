#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL; // struct Node *first = NULL --> like global

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

void display(struct Node* p){
    while(p != NULL){
    cout << p->data << " ";
    p = p->next;
    }
}

void Rdisplay(struct Node *p){ //displaying using recursion
    if(p != NULL){
        cout<< p->data << " ";
        Rdisplay(p->next);
    }
}

void RdisplayRev(struct Node *p){ //displaying using recursion -- in reverse
    if(p != NULL){
        RdisplayRev(p->next);
        cout<< p->data << " ";
    }
}

int main(){
    
    int A[5] = {3, 5, 7 , 8 ,10};
    create(A , 5);
    display(first);
    cout << endl;
    Rdisplay(first);
    cout << endl;
    RdisplayRev(first);
    cout << endl;
    return 0;
}