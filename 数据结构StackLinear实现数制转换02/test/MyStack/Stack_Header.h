#include <stdio.h>
#include <stdlib.h>

#define Stack_init_size 100
#define StackInCrement 10
typedef struct Node{
    int *base;
    int *top;
    int stackSize;
    int length;
}Node,*SqStack;

typedef SqStack Stack;//给sqStack起个名字：Stack
//初始化构造一个空栈
struct Node *InitStack();
void DestroyStack(Stack S);

int GetTop(Stack S,int e);
void convert10to8(Stack S,int n);

void convert10to2(Stack S,int n);
//入栈
void Push(Stack S,int e);

//出栈
int Pop(Stack S,int x);
//清空栈
void ClearStack(Stack S);

//栈是否为空
int IsEmpty(Stack S);
//栈长度
int StackLength(Stack S);

