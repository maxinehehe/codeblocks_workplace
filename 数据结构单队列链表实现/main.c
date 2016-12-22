#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

//方便建立头结点
typedef struct {
    QueuePtr front;//队头指针
    QueuePtr rear;//队尾指针
}LinkQueue;

//构造一个空队列
struct LinkQueue *InitQueue(){
    LinkQueue *LQ;
    LQ->front = LQ->rear =(QueuePtr)malloc(sizeof(QNode));
    if(!LQ) exit(0);
    LQ->front->next = NULL;
    return LQ;
};

//入队
void EnQueue(LinkQueue *LQ,QElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(0);
    p->data = e;
    p->next = NULL;
    LQ->rear->next = p;
    LQ->rear = p;
}

QElemType DeQueue(LinkQueue *LQ,QElemType e){
    QueuePtr p;
    if(LQ->front ==  LQ->rear){
        printf("队列为空！\n");
        return ;
    }
    p = LQ->front->next;
    e = p->data;
    LQ->front->next = p->next;
    if(LQ->rear == p) LQ->rear = LQ->front;
    free(p);
    return e;
}

//销毁队列
void DestroyQueue(LinkQueue *LQ){
    while(LQ->front){
        LQ->rear = LQ->front->next;
        free(LQ->front);
        LQ->front = LQ->rear;
    }
    printf("队列已销毁！");
}

//判断是否为空
int IsEmpty(LinkQueue *LQ){
    return LQ->front == LQ->rear;
}

//清空队列
void ClaerQueue(LinkQueue *LQ){
    QueuePtr p;

    while(LQ->front != LQ->rear){
        p = LQ->front->next;
        //e = p->data;
        LQ->front->next = p->next;
        if(LQ->rear == p) LQ->rear = LQ->front;
        free(p);
    }
     //printf("队列为空！\n");
    return ;
}

//得到对头元素
int GetHead(LinkQueue *LQ){
    return LQ->front->next->data;
}

int main()
{
    LinkQueue *LQ;
    int i,n,e;
    LQ = InitQueue();//创建队列
    printf("输入一个数做顶范围：");
    scanf("%d",&n);
    for(i = 0;i<n;i++)
        EnQueue(LQ,i);
    if(IsEmpty(LQ)) printf("队列为空！\n");
    else printf("队列不空。\n");
    printf("队列空否状态：%d\n",IsEmpty(LQ));
    for(i=0;i<n;i++){

        printf("出队元素：%d\n",DeQueue(LQ,e));
    }

    if(IsEmpty(LQ)) printf("队列为空！\n");
    else printf("队列不空。\n");

DestroyQueue(LQ);
    return 0;
}
