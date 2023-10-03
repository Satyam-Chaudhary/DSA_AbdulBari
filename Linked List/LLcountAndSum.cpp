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

int count(struct Node *p){
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

int countRec(struct Node * p){
    if(p){
        return countRec(p->next) + 1;
    }
    return 0;
}

int sum(struct Node *p){
    int sum = 0;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sumRec(struct Node *p){
    int sum = 0;
    if(p){
        return sumRec(p->next) + (p->data);
    }
    return 0;
}
int main(){
    int A[6] = {3, 5, 7 , 8 ,10, 20};
    create(A , 6);

    cout << "Number of Nodes in Linked List --> " << count(first) << endl;

    cout << "Number of Nodes in Linked List --> " << countRec(first) << endl;


    cout << "Sum of data in linked list --> " << sum(first) << endl;
    cout << "Sum of data in linked list --> " << sumRec(first) << endl;
    return 0;
}