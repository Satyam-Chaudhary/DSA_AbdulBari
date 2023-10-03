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
void display(struct Node* p){
    if(p){
        cout << p->data << " ";
        display(p->next);
    }
}

Node *search(Node* p, int key){
    while(p){
        if(key == p->data){
            return p;
        }
        p = p->next;        
    }
    return NULL;
}

Node *searchRec(Node *p , int key){
    if(p == NULL)
        return NULL;
    if(key == p->data){
        return p;
    }
    return searchRec(p->next , key);
}

struct Node *improvedSearch(Node *p, int key){ // MOVE TO HEAD
    Node * q = new Node;
    q->next = NULL;
    q->data = 0;
    while(p){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main(){
    int A[6] = {3, 5, 1 ,7 ,10, 2};
    create(A , 6);
    int k;
    cout << "Enter key to search: "; 
    cin >> k;
    Node* temp;
    temp = search(first , k);
    if(temp)
        cout << "Key Found: " << temp->data << endl;
    else   
        cout << "Key Not Found" << endl;

    Node * temp2;
    temp2 = searchRec(first, k);
    if(temp2)
        cout << "Key Found: " << temp2->data << endl;
    else   
        cout << "Key Not Found" << endl;
    Node * temp3;
    temp3 = improvedSearch(first , 5);
    if(temp3){
        cout << "Key Found: " << temp3->data << endl;
        display(first);
    }
    else {  
        cout << "Key Not Found" << endl;
        display(first);
    }
    cout << endl;
    return 0;
}