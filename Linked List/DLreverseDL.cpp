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
void insert(int index, int x){
    if(index < 0 || index > count(first)){
        cout << "INVALID COMMAND" << endl;
        return;
    }

    if(index == 0){
        Node *t = new Node;
        t->data = x;
        t->next = t->prev = NULL;
        if(first == NULL){
            first = t;
            }else{
                t->next = first;
                first->prev = t;
                first = t;
            }
        }else{
            Node *p = first;
            Node *t = new Node;
            t->data = x;
            for(int i = 0 ; i < index - 1 ; i++){
                p = p->next;
            }
            t->next = p->next;
            t->prev = p;
            if(p->next) p->next->prev = t;
            p->next = t;
        } 
    }

void reverse(){
    Node *p = first;
    Node *temp;
    while(p){
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev; // as the links are now modified
        if(p->next == NULL){ // last node
            p->next = p->prev;
            p->prev = NULL;
            first = p;
            return;
        }
    }
}

int main(){
    
    int A[] = {2, 4, 5, 3, 6, 7};
    create(A, 6);
    dispaly();
    reverse();
    dispaly();
    
    return 0;
}