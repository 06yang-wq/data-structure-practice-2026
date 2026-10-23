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
//显示链表元素：
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

int main(){
    Node *list=initList();
    insertHead(list,10);
    insertHead(list,20);
    displayList(list);
    return 0;
}
