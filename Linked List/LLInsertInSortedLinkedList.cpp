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

void insertSortPosition(int x){
    Node * p = first;
    Node *q = NULL; // Tail Pointer follows p at one node back
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL){ // no node is present
        first = t;
    }else{
        while(p && x > p->data){
            q = p;
            p = p->next;
        }
        if(p == first){ // when x is smaller than all the nodes data
            t->next = first;
            first = t;
        }else{
            t->next = q->next;
            q->next = t;
        }
    }
}

void display(){
    Node *p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

int main(){
    
    int A[6] = {3, 4, 7, 9, 10, 15};
    create(A , 6);
    insertSortPosition(12);
    insertSortPosition(20);
    insertSortPosition(6);
    insertSortPosition(2);
    display();
    cout << endl;
    return 0;
}