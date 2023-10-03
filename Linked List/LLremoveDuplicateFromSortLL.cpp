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

void removeDuplicate(Node *p){
    Node *q = p->next; // p is tail pointer for q
    while(q!= NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }else{
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}


int main(){
    

    int A[6] = {2, 3, 3, 5, 6, 6};
    create(A , 6);
    removeDuplicate(first);
    display(first);
    cout << endl;

    return 0;
}