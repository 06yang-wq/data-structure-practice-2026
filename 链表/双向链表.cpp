#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node*prev,*next;
}Node;

Node*initList(Node*L){
    Node*p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->prev=NULL;
    p->data=0;
}
int display(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//头插法：
int insertHead(Node*L,ElemType e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->prev=L;
    p->next=L->next;
    if(L->next!=NULL){
        L->next->prev=p;
    }
    L->next=p;
}
//尾插法：
Node* get_tail(Node*L){
    Node*p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node* insertTail(Node*tail,ElemType e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->prev=tail;
    tail->next=p;
    p->next=NULL;
    return p;
}
//插入指定位置：
Node* get_prior(Node*L,int pos){
    if(pos<1){return 0;}
    Node*p=L;
    int i=0;
    while(i<pos-1&&p!=NULL){
        p=p->next;
        i++;
    }
    return p;
}
int insertNode(Node*p,int pos,ElemType e){
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->prev=p;
    q->next=p->next;
    p->next->prev=q;
    p->next=q;
    return 1;
}
//删除结点：
int deleteNode(Node*L,int pos){
    Node*p=get_prior(L,pos);
    Node*q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
}


int main(){
    Node*list=initList(list);
    insertHead(list,10);
    insertHead(list,20);
    insertHead(list,30);
    insertHead(list,40);
    insertHead(list,50);
    display(list);
    
    Node*list2=initList(list2);
    Node*tail=get_tail(list2);
    tail=insertTail(tail,10);
    tail=insertTail(tail,20);
    tail=insertTail(tail,30);
    tail=insertTail(tail,40);
    tail=insertTail(tail,50);
    display(list2);
    Node*pr=get_prior(list2,2);
    insertNode(pr,2,66);
    display(list2);
    deleteNode(list2,2);
    display(list2);

}
