#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct PolyNode{
    int coef;//系数
    int expon;//指数
    struct node*link;//指向其他结构体
}*Polynomial;

Polynomial p1,p2;//定义两个结构体数据

//多项式加法实现过程
Polynomial PolyAdd(Polynomial p1,Polynomial p2){
    Polynomial front,rear,temp;
    int sum;
    Polynomial PolyNode;
    rear=(Polynomial)malloc(sizeof(PolyNode));
    front=rear;
    while(p1&&p2)
        switch(strcmp(p1->expon,p2->expon)){
    case 1:
        Attach(p1->coef,p1->expon,&rear);
        p1=p1->link;//指向下一个结点
        break;

    case -1:
        Attach(p2->coef,p2->expon,&rear);
        p2=p2->link;
        break;
    case 0:
        sum=p1->coef+p2->coef;
        if(sum)Attach(sum,p1->expon,&rear);
        p1=p1->link;
        p2=p2->link;
        break;

/*将未处理完的多项式结点依次复制到结果多项式中*/
for(;p1;p1=p1->link) Attach(p1->coef,p1->expon,&rear);
for(;p2;p2=p2->link) Attach(p2->coef,p2->expon,&rear);
rear->link=NULL;
temp=front;
front=front->link;
free(temp);
return front;
    }
}

void Attach(int coef,int expon,Polynomial*PtrRear){
    Polynomial p,PolyNode;

    p=(Polynomial)malloc(sizeof(PolyNode));
    p->coef=coef;
    p->expon=expon;
    (*PtrRear)->link=p;

    *PtrRear=p;
}

int main()
{
    Polynomial p1,p2,front;
    p1->coef=2;
    p1->expon=4;
    p2->coef=8;
    p2->expon=4;
    front=PolyAdd(p1,p2);
    //printf("Hello world!\n");
    return 0;
}
