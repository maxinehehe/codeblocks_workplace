#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

//二叉树结点声明

//typedef struct TreeNode *PtrToNode02;
//typedef struct PtrToNode02 Tree;

typedef struct TreeNode{
    ElementType element;
    struct TreeNode* left;
    struct TreeNode* right;
}*PtrToNode02;
typedef struct PtrToNode02 Tree;

//构建树
Tree InitTree(){
    Tree T;
    T = (Tree)malloc(sizeof(struct TreeNode));
    if(!T){
        printf("Out of Space!\n");
        exit(0);
    }
    T->left = NULL;
    T->right = NULL;
    return T;
}

//比较入树
void CreatTree(Tree T,ElementType e){
    Tree TNode;
    TNode = (Tree)malloc(sizeof(struct TreeNode));
    TNode->element = 0;

    if(TNode == NULL)
        exit(0);
    TNode->right = T;//根节点

    if(T->element > TNode->element)
        while()



}



//构造栈

typedef struct Node{
    ElementType data;
    struct Node *Next;
}*PtrToNode;



typedef PtrToNode Stack;//给ptrToNode起别名Stack

//函数
int IsEmpty(Stack S);//判断是否为空
Stack CreatStack();//创建链栈
void DisposeStack(Stack S);//销毁栈
void MakeEmpty(Stack S);//清空栈
void Push(Stack S,ElementType x);//入栈
ElementType Top(Stack S);//取栈顶元素
int Pop(Stack S,int e);//出栈
void convert10to8(Stack S,int n);
void convert10to2(Stack S,int n);


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

//函数实现
int IsEmpty(Stack S){
    return S->Next==NULL;
    if(S->Next == NULL)
        printf("---------------------\n\n");
}
//创建栈
Stack CreatStack(){
     Stack S;

    S = (Stack)malloc(sizeof(struct Node));
    if(!S){//如果为空
        printf("Out of space！");
        exit(0);
    }

    S->Next = NULL;//被坑的一步
    MakeEmpty(S);
    return S;
    }

   //销毁栈
void DisposeStack(Stack S){
    Stack p=NULL;

    while(!S){

        p = S->Next;
        S = S->Next;
        free(p);
    }
   }

//清空栈
void MakeEmpty(Stack S){
    int e=0;
    if(S == NULL){
        printf("Must use CreatStack first!");exit(0);
    }
    else
        while(!S)
            Pop(S,e);
}

//入栈
void Push(Stack S,ElementType x){
    PtrToNode Tmp;

    Tmp =(PtrToNode) malloc(sizeof(struct Node));
    if(Tmp == NULL){
        printf("Out of space!");
        exit(0);
    }else{
        Tmp->data = x;
        Tmp->Next = S->Next;//Tmp->Next =NULL;
        S->Next = Tmp;
    }
}

//出栈
int Pop(Stack S,int e){
    PtrToNode Fir;

    if(IsEmpty(S)){
        printf("Empty Stack!");
        exit(0);
    }
    else{
        Fir = S->Next;
        S->Next = S->Next->Next;
        e = Fir->data;
        //printf("出栈元素为：%d\n",Fir->data);
        free(Fir);
        return e;
    }
}

ElementType Top(Stack S){
    if(!IsEmpty(S))
        return S->Next->data;
    printf("Empty Stack!");
    return 0;
}

#include"time.h"
/*
srand((unsigned)time(NULL)); //随机种子
n=rand()%(Y-X+1)+X; //n为X~Y之间的随机数
int rand(void)
*/

int main()
{
    int i=0,e=0,g=0,n=0,number=0;
    Stack S;
    S = CreatStack();
    Tree T;
    T = InitTree();

    printf("输入一个数字：");
    scanf("%d",&n);
    srand(time(0));

    for( i=0;i<n;i++){
    number = rand()%100+1;
    //入栈
    Push(S,number);
     }
     while(!IsEmpty()){
        e=Pop(S,e);
        printf("出栈：%d\n",e);

     }





    DisposeStack(S);
    return 0;
}
