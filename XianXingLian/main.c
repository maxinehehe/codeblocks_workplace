#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int Date;
    struct Node*Next;//指向下一个节点的指针
}List;
List L,*PtrL;

//1.求表长
int length(List *PtrL){//参数传递的是结构体
    List *p=PtrL;//对p进行赋值初始化 p指向表的第一个结点
    int j=0;    //j是用来计时
    while(p){
        p=p->Next;
        j++;        /*当前p指向的是第j个结点*/
    }
    return j;
}

//2.查找
//（1）按序号查找
List *FindKth(int k,List *PtrL){
    List *p=PtrL;//头指针
    int i=1;//记下初始序号
    while(p!=NULL&&i<k){
        p=p->Next;
        i++;
    }
    if(i==k)
        return p;/*找到第k个，并返回指针*/
    else
        return NULL;
}

//按值查找
List *Find(int x,List*PtrL){
    List*p=PtrL;
    while(p!=NULL&&p->Date!=x){
        p=p->Next;
    }
    return p;
}

//插入
List *insert(int x,int i,List*PtrL){
    List*p,*s;
    if(i==1){                               /*新结点插入到表头*/
        s=(List*)malloc(sizeof(List));  /*申请 填装结点*/
        s->Date=x;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);//查找第i-1个结点
    if(p==NULL){
        printf("参数i出错");
        return NULL;
    }
    else{
        s=(List*)malloc(sizeof(List));//申请一个新结点。
        s->Date=x;
        s->Next=p->Next; /*新结点插入在第i-1个结点的后面*/
        p->Next=s;
        return PtrL; /*返回插入后的链表*/
    }
}

//删除结点
List *Delete(int i,List* PtrL){
    List *p,*s;
    if(i==1){
        s=PtrL;
        if(PtrL!=NULL)
            PtrL=PtrL->Next;
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);/*查找i-1个结点*/
    if(p==NULL){
        printf("第%d个结点不存在\n",i-1);
        return NULL;
    }else if(p->Next==NULL){
        printf("第%d个结点不存在\n",i);
    }else{
        s=p->Next;
        p->Next=s->Next;
        s=p->Next;
        free(s);
    }
}

List *creatList(){
    List*pjiewei,*PtrL,*pDangQian;
    int i;
    if((PtrL=(List*)malloc(sizeof(List)))==NULL){
        printf("不能分配内存空间");
        exit(0);
    }
    PtrL->Date=0;
    PtrL->Next=NULL;
    i=0;
    do{

    }while(1);
    return PtrL;
}

int main()
{
    List*PtrL=NULL;
    PtrL=creatList();
    return 0;
}
