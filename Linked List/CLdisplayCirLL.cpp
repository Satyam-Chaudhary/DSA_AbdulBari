#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
}*Head;

void create(int A[] , int n){
    int i;
    Node *t, *last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->next = Head; // now circular
    Head ->data = A[i];
    last = Head;
    for(int i = 1 ; i < n ; i++){
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = last->next; // for circular
    last->next = t;
    last = t;
    }
}

void display(){
    Node *p = Head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p != Head);
    cout << endl;
}

void displayRec(Node *p){
    static int flag = 0;
    if(p!=Head || flag == 0){
        flag = 1;
        cout << p->data << " ";
        displayRec(p->next);
    }
}

int main(){
    int A[] = {2, 3, 5, 6, 7, 8};
    create(A , 6);
    display();
    displayRec(Head);
    cout << endl;
    return 0;
}