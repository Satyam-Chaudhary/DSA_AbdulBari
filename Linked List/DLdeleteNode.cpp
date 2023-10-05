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

void deleteNode(int index){
    if(index <= 0 || index > count(first)){
        cout << "INVALID INDEX" << endl;
        return;
    }
    int x;
    if(index == 1){
        if(first == NULL){
            cout << "NO NODE PRESENT" << endl;
        }else{
            Node *p = first;
            first = first->next;
            delete p;
            if(first) // next node is not null
                first->prev = NULL;
        }
    }else{
        Node *p = first;
        for(int i = 0 ; i < index - 1 ; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
}

int main(){
    
    int A[] = {2, 4, 5, 3, 6, 7};
    create(A, 6);
    dispaly();
    deleteNode(2);
    dispaly();
    deleteNode(1);
    dispaly();
    deleteNode(4);
    dispaly();
    deleteNode(10);
    dispaly();
    
    return 0;
}