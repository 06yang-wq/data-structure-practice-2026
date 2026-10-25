#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node*next;
}Node;

Node*initList(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
int displayNode(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
Node* get_tail(Node*L){
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

//寻找倒数第K个位置上结点(快慢指针)：
int findNodeFS(Node *L,int k){
    Node*fast=L->next;
    Node*slow=L->next;
    for(int i=0;i<k;i++){
        fast=fast->next;
    }
    while (fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    printf("倒数第%d个元素是：%d\n",k,slow->data);
}

//翻转链表（3指针）：
Node*reverseList(Node*L){
    Node* first=NULL;
    Node* second=L->next;
    Node* third;
    while(second!=NULL){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    Node*head=initList();
    head->next=first;
}

//快慢指针寻找中间结点：
Node *findMid(Node*L){
    Node *slow=L->next;
    Node *fast=L->next;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node*list=initList();
    Node*tail=get_tail(list);
    tail=insertTail(tail,10);
    tail=insertTail(tail,20);
    tail=insertTail(tail,30);
    tail=insertTail(tail,40);
    tail=insertTail(tail,50);
    displayNode(list);
    findNodeFS(list,2);
    
    Node*MidNode=findMid(list);
    printf("%d\n",MidNode->data);
    
    Node*rList=reverseList(list);
    displayNode(rList);
}
