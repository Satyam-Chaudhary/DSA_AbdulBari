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

// void insertAtStart(struct Node * p , int x){
//     struct Node * t = (struct Node*)malloc(sizeof(struct Node));
//     t->data = x;
//     t->next = p->next;
//     first = t;
// }
void display(struct Node* p){
    // while(p){
    //     cout << p->data << " ";
    //     p = p->next;
    // }
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

void insert(Node *p , int pos , int x){
    if(pos < 0 || pos > count(p)){
        cout << "INVALID COMMAND" << endl;
        return;
    }
    Node * t = new Node;
    t->data = x;
    t->next = NULL; // can be initialized just for caution if not written no problem

    if(pos == 0){
        t->next = first; // IMPORTANT
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
int main(){
    
    int A[6] = {3, 5, 1 ,5 ,10, 2};
    create(A , 6);
    display(first);
    int data;
    cout << endl;

    // cout << "Enter data to be inserted: ";
    // cin >> data;

    // insertAtStart(first , data);
    // display(first);
    // cout << endl;
    
    cout << "Enter data to be inserted: ";
    cin >> data;
    int pos;
    cout << "Enter position to insert at: ";
    cin >> pos;
    insert(first , pos , data);
    display(first);
    cout << endl;



    return 0;
}