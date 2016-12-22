#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int element;
	struct Node *next;

}*PtrToNode;

typedef PtrToNode Position,List;
List MakeEmpty(List L);//将表置空
int IsEmpty(List L);//表是否为空
int IsLast(Position P);//是否为最后一个元素

//表是否空
int IsEmpty(List L){
    return  L->next == NULL;
}

//是否为最后一个元素
int IsLast(Position p){
    return p->next == NULL;
}

//创建链表
List CreatList(){

}

