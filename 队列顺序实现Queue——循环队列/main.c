#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100

/**
循环队列
*/
typedef struct Node{
    int *base;//数组的首地址
    int front;
    int rear;
    /**
    另外也可以在此处定义一个 count用于计算长度。
    */
}SqQueue;

//创建顺序队列
struct Node *InitQueue(){
    SqQueue *Q;
    /**
    首先要为Q开辟空间。

    */
    Q = (SqQueue *)malloc(sizeof(SqQueue));
    if(!Q)exit(0);

    Q->base = (SqQueue*)malloc(MAXQSIZE*sizeof(int));//对数组首地址开辟空间（注意数组类型）如所示
    if(!Q->base) exit(0);
    Q->front = Q->rear = 0;//初始化
    return Q;
};

void MakeEmpty(SqQueue *Q){
    Q->front = Q->front = 0;
}

//取队头元素
int GetHead(SqQueue *Q){
    return Q->base[Q->front];
}

//队列长度
int QueueLength(SqQueue *Q){
    return (Q->rear - Q->front + MAXQSIZE)%MAXQSIZE;//rear会和front差1
    /**
    Q->rear - Q->front + MAXQSIZE :+MAXSIZE是为了Q->rear超过最大长度时，
    使得两个数相减后还能够得到正数进行计算。
    例如：
        Q->rear = 2 , Q->front = 5 MAXSIZE = 7
        此时的长度：(Q->rear - Q->front + MAXQSIZE)%MAXQSIZE
                     (    2   -   5      +  7     ) % 7 = 4【即是 6,0,1,2】
    */
}

//队列是否为空
int IsEmpty(SqQueue *Q){
    return (Q->front) % MAXQSIZE == Q->rear;
}

//入队列
void EnQueue(SqQueue *Q,int e){
    if((Q->rear + 1) % MAXQSIZE == Q->front) exit(0);

    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    /**注解：
    循环队列：
    例如：MAXQSIZE = 6 数据[0,1,2,3,4,5]
    一。
        Q->front = 0 , Q->rear = 3
        入队时首先要判断队列是否满了，该算法是：【(尾+1)%元素个数 == 头】
        -》：(Q->rear + 1)%Q->MAXQSIZE == Q->front
    二。
        如果满足条件：
        则入队 ：Q->base[Q->rear] = e;//e为入队元素

        然后更改Q->rear的相对位置，不能简单地+1
        处理Q->rear方式：Q->rear = (Q->rear + 1)%MAXSIZE;
    */

}

//出队
void DeQueue(SqQueue *Q,int e){
    if(Q->front == Q->rear) return 0;
    /**
    如果队列为空，返回0
    */

    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    /**注意此是判断空与否的重要一点
    front得到元素后 才会移到下一位
    移到相对位置。
    */
    printf("出队元素：%d\n",e);
}
void DestroyQueue(SqQueue *Q){
    free(Q);
    free(Q->base);
}

int main()
{
    SqQueue *Q;
    Q = InitQueue();
    printf("空与否状态：%d\n",IsEmpty(Q));
    int i,t,e;
    printf("输入顶范围：");
    scanf("%d",&t);
    for(i=0;i<t;i++)
        EnQueue(Q,i);
    printf("已入队%d个元素！\n",t);
    printf("空与否状态：%d\n",IsEmpty(Q));
    printf("队头元素：%d\n",GetHead(Q));
    printf("队列长度：%d\n",QueueLength(Q));
    for(i=0;i<t;i++)
        DeQueue(Q,e);

    DestroyQueue(Q);
    return 0;
}
