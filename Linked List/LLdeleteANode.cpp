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

int deleteANode(int pos){
    struct Node *p = first , *q = NULL;
    int x = -1;
    if(pos < 1 || pos > count())
        return -1;
    if(pos == 1){
        p = first;
        first = first->next;
        x = p->data;
        free(p);
    }else{
        for(int i = 0 ; i < pos -1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        }
    return x;
}

void display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

int main(){
    int A[6] = {3, 5, 1 ,5 ,10, 2};
    create(A , 6);
    int pos;
    cout << "Enter position to delete at: ";
    cin >> pos; 
    cout << deleteANode(pos) << endl;
    display(first);
    cout << endl;
    return 0;
}