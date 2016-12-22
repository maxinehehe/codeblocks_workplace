#include <stdio.h>
#include <stdlib.h>

/**
特点：先进先出
*/
typedef int ElementType;
typedef int Status;

//单链队列
typedef struct QNode{
  ElementType data;//数据
  struct QNode *next;
}QNode,*QueuePtr;

typedef struct LinkeQueue{
    QueuePtr front;
    QueuePtr rear;
    int length;
}LinkeQueue;

/*
Status InitQueue(LinkeQueue *Q);//构造一个空队列

Status DestroyQueue(LinkeQueue *Q);//销毁队列，前提队列存在

Status ClearQueue(LinkeQueue *Q);//清空队列

Status QueueEmpty(LinkeQueue Q);//若队列为空则返回TRUE,否则返回FALSE

int QueueLength(LinkeQueue Q);//返回元素个数

Status GetHead(LinkeQueue Q);//,ElementType *e);//取队顶元素

void EnQueue(LinkeQueue *Q,ElementType e);

Status DeQueue(LinkeQueue *Q);//,ElementType *e);

//void visit();
Status QueueTraverse(LinkeQueue *Q);//,visit());
*/

//遍历

Status QueueTraverse(LinkeQueue *Q){
   QueuePtr p;
   // QueuePtr r;
   /**
   类型应该匹配对
   */
    p = Q->front;
    //r = (QueuePtr)malloc(sizeof(QNode));
    while((p->next)){//当p不为空的时候

            printf(":%d\n",p->next->data);
            p = p->next;
    }
    return 1;//ok
}

//函数实现
struct LinkeQueue *InitQueue(){
    //应该先开辟Q
    LinkeQueue *Q;
    Q = (LinkeQueue *)malloc(sizeof(LinkeQueue));//重要的一步
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!(Q->front)) exit(0);
    Q->front->next = NULL;
    Q->length = 0;
    return Q;//OK
}

//销毁
void DestroyQueue(LinkeQueue *Q){
    /**
    从头开始销毁：
    头跟着尾走。
    */
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
        Q->length--;
    }
    return ;//OK
}

//入队列
void EnQueue(LinkeQueue *Q,ElementType e)
{
    QueuePtr p;

    p = (QueuePtr)malloc(sizeof(QNode));

    if(!p)exit(0);

    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    Q->length++;
   // return 1;//OK
}

Status DeQueue(LinkeQueue *Q)//,ElementType *e)
{
    QueuePtr p;
    ElementType e;
    if(Q->front == Q->rear)
        return 0;
    p = (QueuePtr)malloc(sizeof(QNode));
    p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;

    if(Q->rear == p)
        Q->rear = Q->front;

    free(p);
    Q->length--;
    return e;//OK
}

//取头元素
Status GetHead(LinkeQueue Q)//,ElementType *e)
{

    if(Q.front==Q.rear)return 0;
    return Q.rear->data;
}

//队列长度

int QueueLength(LinkeQueue Q){
    return Q.length;
}


//队列是否为空
Status QueueEmpty(LinkeQueue Q){
    return Q.front == Q.rear;
}

//清空队列
Status ClearQueue(LinkeQueue *Q){
    Q->front = Q->rear;
    Q->length = 0;
    return 1;//OK
}


//主函数
int main()
{
    LinkeQueue *Q;
    int i;
    ElementType e;
    Q = InitQueue();//初始化
   //入队
    EnQueue(Q,100);

    for(i = 1;i <= 10;i++)
        EnQueue(Q,i);

    QueueTraverse(Q);//遍历
    printf("队头元素:%d\n",GetHead(*Q));
    printf("队列长度:%d\n",QueueLength(*Q));
    /**
    判断条件：Q->front == Q->rear
        如果为空，则满足条件，返回 1
                否则，返回 0。
    */
   // printf("队列空否状态：%d\n",QueueEmpty(*Q));

    //ClearQueue(Q);

    printf("队列空否状态：%d\n",QueueEmpty(*Q));
    printf("出队列：%d\n",DeQueue(Q));
    for(i = 1;i <= 10;i++){
    e = DeQueue(Q);
    printf(":%d\n",e);
    }
    //QueueTraverse(Q);
    DestroyQueue(Q);
    return 0;
}
