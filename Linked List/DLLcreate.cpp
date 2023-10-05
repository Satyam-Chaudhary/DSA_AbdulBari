#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;
    for(int i = 1 ; i < n ; i++){
        t = new Node;
        t->data = A[i];
        last->next = t;
        t->prev = last;
        t->next = NULL;
        last = last->next;
    }
}

void dispaly(){
    Node *p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int count(Node *p){
    int c = 0;
    while(p){
        p = p->next;
        c++;
    }
    return c;
}
int main(){
    
    int A[] = {2, 4, 5, 3, 6, 7};
    create(A, 6);
    cout << "Length is --> " << count(first) << endl;
    dispaly();
    return 0;
}