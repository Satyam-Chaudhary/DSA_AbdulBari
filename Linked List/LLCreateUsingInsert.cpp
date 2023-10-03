#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void display(struct Node* p){
    if(p){
        cout << p->data << " ";
        display(p->next);
    }
}


int count(struct Node *p){
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

void insert(int pos , int x){
    Node *p = first;
    if(pos < 0 || pos > count(p)){
        cout << "INVALID COMMAND" << endl;
        return;
    }
    Node * t = new Node;
    t->data = x;
    t->next = NULL; // can be initialized just for caution if not written no problem

    if(pos == 0){
        t->next = first;
        first = t;
    }
    else{
    for(int i = 0 ; i < pos - 1 && p != NULL ; i++){
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
    }
}



void insertAtlast(int x){ // when need to always need to insert at last ... // LIKE PUSH
    Node * last = NULL;
    Node * t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first == NULL){ // case when no node present
        first = t;
        last = t;
    }else{ // case when atleast one node is present
        last = first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = t;
        last = t;
    }
}
int main(){

    insert(0 , 10);
    insert(1 , 2);
    insert(2 , 69);
    insert(0 , 7);
    insert(3, 9);
    insert(4 , 34);
    insert(6 , 24);
    insertAtlast(5);
    insertAtlast(6);

    display(first);
    cout << endl;
    return 0;
}