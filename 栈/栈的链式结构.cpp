#include<stdio.h>
#include<stdlib.h>
typedef  int Elemtype;
typedef struct stack{
    Elemtype data;
    struct stack*next;
}Stack;
//动态内存初始化：
Stack* initStack(){
    Stack*s=(Stack*)malloc(sizeof(Stack));
    s->data=0;
    s->next=NULL;
    return s;
}
//进栈（头插）：
int push(Stack*s,Elemtype e){
    Stack*p=(Stack*)malloc(sizeof(Stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}
//出栈：
int pop(Stack*s,Elemtype*e){
    if(s->next==NULL){
        return 0;
    }
    *e=s->next->data;
    Stack*q=s->next;
    s->next=q->next;
    free(q);
    return 1;
}

int main(){
    Stack*s=initStack();
    Elemtype e;

    push(s,10);
    push(s,20);
    push(s,30);

    if(pop(s,&e)){
        printf("%d\n",e);
    }

    free(s);
    return 0;
}
