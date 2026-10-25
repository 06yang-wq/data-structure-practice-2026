#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node *next;
}Node;
//单链表初始化：
Node *initList(){
    Node *head =(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
//遍历显示链表元素：
void displayList(Node *L){
    Node *p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//headinsert
int insertHead(Node*L,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
}
//tailinsert
Node*get_tail(Node*L){
    Node*p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node*insertTail(Node*tail,ElemType e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}
//寻找前驱节点（指定插入/删除）：
Node* get_prior(Node*L,int pos){
     if(pos<1){
        return 0;
    }
    int i=0;
    Node *p=L;
    while(i<pos-1 && p!=NULL){
        p=p->next;
        i++;
    }
    return p;
}
//指定位置插入
int insertNode(Node*L,int pos,ElemType e){
    Node*p=get_prior(L,pos);
    if(p==NULL){return 0;}
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}
//删除元素：
int deleteNode(Node*L,int pos){
    Node*p=get_prior(L,pos);
    Node*q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}
//释放链表：
void freeList(Node*L){
    Node*p=L->next;
    Node*q;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}

int main(){
    Node *list=initList();
    insertHead(list,10);
    insertHead(list,20);
    insertHead(list,25);
    Node *tail=get_tail(list);
    tail=insertTail(tail,30);
    tail=insertTail(tail,40);
    displayList(list);
    //指定插入：
    insertNode(list,3,66);
    displayList(list);
    //删除：
    deleteNode(list,3);
    displayList(list);

    freeList(list);
    displayList(list);

    return 0;
}

