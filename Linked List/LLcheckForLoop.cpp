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

bool isLoop(){
    struct Node *p , *q;
    p = q = first;
    do{
        p = p->next;
        q = q->next;
        //q = q!= NULL ? q->next:NULL;
        // if(q!= NULL){
        //     q = q->next;
        // }else{
        //     q = NULL;
        // }
        q = q!= NULL ? q->next:NULL; // short of above
    }while(p && q && p!=q);
    
    return (p == q) ? 1 : 0;
}

int main(){
    

    int A[6] = {3, 5, 1 ,5 ,10, 2};
    create(A , 6);
    struct Node *t1, *t2;
    t1 = first->next->next; // pointing at third node --> 1
    t2 = first->next->next->next->next->next; //pointing at last node --> 2
    t2->next = t1; //loop done
    cout << isLoop() << endl;
    return 0;
}