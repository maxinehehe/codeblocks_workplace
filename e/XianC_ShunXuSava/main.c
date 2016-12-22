#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define LISTINCREMENT 10//分配增量
typedef struct{
    int *elem;//存储空间基址
    int length;
    int listSize;
}sqList;

int initList sq(sqList &L){
    //g构造一个空线性表
    L.elem=(int*)malloc(SIZE*sizeof(int));
    if(!L.elem)exit(-2);//存储分配失败
    L.length= 0;//空表长度为0
    L.listSize=SIZE;
    return 1;//ok
}

int listInsert_sq(sqList &L,int i,int e){
    sqList *newBase;
    //i的合法性
    if(i<1||i>=L.length+1)
        return 0;
    if(L.length>=L.listSize){//当前存储空间已满
        newBase=(int*)realloc(L.elem,(L.listSize+LISTINCREMENT))*sizeof(int));
        if(!newBase)exit(-2);
        L.elem=newBase;
        L.listSize += LISTINCREMENT;
    }
    q=&(L.elem[i-1]);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
