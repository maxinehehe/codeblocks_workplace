#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/**
线性队列
*/
typedef int status;

typedef struct Queue_node{
    int *pData;
    int length;
    int tail;
    int count;
}Queue_node;


//申请内存
Queue_node* alloca_queue(int number){
    Queue_node* pQueueNode;
    if( 0 == number)
        return NULL;
    pQueueNode = (Queue_node*)malloc(sizeof(Queue_node));
    assert(NULL!=pQueueNode);
    memset(pQueueNode,0,sizeof(Queue_node));

    pQueueNode->pData = (int*)malloc(sizeof(int)*number);
    if(NULL!=pQueueNode){
        free(pQueueNode);
        return NULL;
    }
    pQueueNode->length = number;
    return pQueueNode;
}

/**
主函数
*/
int main()
{
    printf("Hello world!\n");
    return 0;
}
