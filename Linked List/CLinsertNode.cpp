#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
}*Head = NULL;

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

int  count(Node *p){
    int count  = 0;
    do{
        p = p->next;
        count++;
    }while(p!= Head);
    return count;
}
void insert(int x, int pos){
    Node *p;
    Node *t;
    if(pos < 0 || pos > count(Head)){
        cout << "INDEX OUT OF BOUND" << endl;
        return;
    }
    t = new Node;
    t->data = x;
    if(pos == 0){
        if(Head == NULL){ // no node present and t is the first node in this case the first node need to be circular
            Head = t;
            Head->next = Head;
        }else{ // when atleast one node is present and the list is already circular
            p = Head;
            while(p->next !=Head){
                p = p->next;
            }
            p->next =t;
            t->next = Head;
            Head = t; // optional as the list is circular
        }
    }else{ // not before first node
        p = Head;
        for(int i = 0 ; i < pos - 1 ; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int deleteNode(int pos){
    int x = -1;
    if(pos <= 0 || pos > count(Head)){
        cout << "INVALID COMMAND" << endl;
        return x;
    }
    if(pos == 1){
        Node *p = Head;
        while(p->next != Head){
            p = p->next;
        }
        if(Head == p){ // scenario when there is only one node in the circular linked list
            delete Head;
            Head = NULL;
        }else{
        p->next = Head->next;
        x = Head->data;
        delete Head; // this doesn't delete the pointer but thr node at that pointer 
        Head = p->next;
        }
    }else{ 
        // using tail pointer
        // Node *p = Head, *q = NULL;
        // for(int i = 0 ; i < pos - 1; i++){
        //     q = p;
        //     p = p->next;
        // }
        // q->next = p->next;
        // x = p->data;
        // delete p; 

        // without tail pointer
        
        Node *p = Head , *q = NULL;
        for(int i = 0 ; i < pos - 2; i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main(){
    int A[] = {2, 3, 5, 6, 7, 8};
    create(A , 6);
    display();
    displayRec(Head);
    cout << endl;
    cout << count(Head) << endl;
    insert(20 , 2);
    display();
    insert(10, 0);
    display();
    insert(69, 8);
    display();
    insert(27, 200);
    display();
    cout << "Deleted data == " << deleteNode(7) << endl;
    display();
    return 0;
}