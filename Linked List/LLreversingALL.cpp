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

void reverseElements(Node * p){
    int *arr;
    arr = (int*)malloc(sizeof(int)*count()); // new int[count()]
    int i = 0;
    while(p){
        arr[i] = p->data;
        p = p->next;
        i++;
    }
    i--;
    p = first;
    while(p){
        p->data = arr[i];
        p = p->next;
        i--;
    }
}

void reverseLinks(Node * p){ //sliding pointers
    Node *q = NULL, *r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseRec(struct Node *p, struct Node *q){
    if(p!= NULL){
        reverseRec(p->next, p);
        p->next = q; // at returning time
    }else{
        first = q;
    }
}

int main(){
    

    int A[6] = {3, 5, 1 ,5 ,10, 2};
    create(A , 6);
    reverseElements(first);
    display(first);
    cout << endl;
    reverseLinks(first);
    display(first);
    cout << endl;
    reverseRec(first, NULL);
    display(first);
    cout << endl;
    return 0;
}