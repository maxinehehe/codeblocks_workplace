#include <stdio.h>
#include <stdlib.h>
#include "Stack_Header.h"

//初始化构造一个空栈
struct Node *InitStack(){
    Stack S=NULL;
	
	/************************************************************************/
	//要先开辟结构体
	S = (Stack)malloc(sizeof(Node));
/************************************************************************/


    S->base = (int*)malloc(Stack_init_size*sizeof(int));//分配首地址
    if(!S->base){printf("分配内存失败\n");exit(0);}

    S->top = S->base;
    //再分配初始内存
    S->stackSize = Stack_init_size;
    S->length = 0;
    return S;
}

//栈是否为空
int IsEmpty(Stack S){
    return S->base == S->top;
}



void DestroyStack(Stack S){
    free(S->base);
	free(S);
    //printf("已销毁栈!\n");
    return ;
}

//取栈顶元素
int GetTop(Stack S,int e){
        if(S->top == S->base){
            printf("栈为空！\n");
            return 0;
        }

	e = *(S->top - 1);//指针取地址
	//S->top--;
	return e;
}

void convert10to8(Stack S,int n){
    int e=0;
    while(n){
        Push(S,n%8);
        n = n/8;
    }

    while(!IsEmpty(S)){
        printf("%d",Pop(S,e));
    }
    printf("\n");
}

void convert10to2(Stack S,int n){
    int e=0;
    while(n){
        Push(S,n%2);
        n = n/2;
    }

    while(!IsEmpty(S)){
        printf("%d",Pop(S,e));
    }
    printf("\n");
}

//入栈
void Push(Stack S,int e){
	//首先判断是否为满
	if(S->top - S->base >= S->stackSize){//栈满
	//S = (Stack)malloc(sizeof(Node));
	S->base = (int*)realloc(S->base,(S->stackSize + StackInCrement)*sizeof(int));//将新分配的地址收地址给base

	if(!S->base){printf("再分配内存失败！\n");exit(0);}
	S->top = S->base + S->stackSize;//stackSize是指栈的实际尺寸。top = S[stackSize]
	S->stackSize += StackInCrement;//接上一步再‘将改变后的大小赋值给新的尺寸。
	//printf("分配\n");
	}
	*S->top++ = e;
//	++S->length;
	//printf("入栈元素：%d\n",e);
	//S->top++;
	//printf("入栈成功\n");
}

//出栈
int Pop(Stack S,int x){
    //判断栈为空不
    if(S->top == S->base) {printf("栈空！\n");return 0;}//printf("栈已满!\n");
     //--S->top;
    x =*--S->top;
   // --S->length;
    return x;

}

//清空栈
void ClearStack(Stack S){
    S->top = S->base;
    //再分配初始内存
    S->stackSize = Stack_init_size;
    //S->length=0;
    return ;
}


//栈长度
int StackLength(Stack S){
    //printf("Top - Base得长度：%d\n",S->top - S->base);
    return S->top - S->base;//S->length;
}
