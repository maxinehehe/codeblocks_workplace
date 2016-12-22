#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 100
#define LISTCEREMENT 10

typedef struct SqList{
    int *ele;//[LIST_INIT_SIZE];
    int length;
    int listSize;
}*SqL;

//初始化表 又
void initList(SqL list){
    list->ele = (int*)malloc(LIST_INIT_SIZE*sizeof(int));//分配空间。
    //memset(list->ele,0,sizeof());
    if(!list->ele){
        printf("分配内存失败\n");
        return ;
    }

    list->length=0;
    list->listSize=LIST_INIT_SIZE;
    return ;
}

//清空表
void clearList(SqL list){
    //memset(list->ele,0,sizeof(LIST_INIT_SIZE));//置空
    int i;
    for(i=0;i<list->listSize;i++)
        list->ele[i]=0;
    return;
}


//判断空表
int IsEmptyList(SqL list){
   return list->length==0?0:1;
}

//表长度
int listLength(SqL list){
    return list->length;
}

//创建表
void creatList(SqL list){
    int i,sur;
    int *newBase;
    printf("请输入一个数做顶范围\n");
    scanf("%d",&sur);

    while(sur>=list->listSize){
        //当前空间已满 增加分配
        newBase=(int*)realloc(list->ele,(list->listSize + LISTCEREMENT)*sizeof(int));
        if(!newBase) {printf("内存分配失败！\n");return;}
        list->ele=newBase;//新基址
        list->listSize += LISTCEREMENT;//新增加的容量。
    }


    for(i=0;i<sur;i++){//注意越界问题
        list->ele[i]=i;
        list->length++;
    }

}

//插入操作
int listInsert(SqL list,int q,int e){//在顺序性表list中第i个位置之前插入新元素i.
    //i的位置是否合法
    int *newBase;

    if(q<1||q>list->listSize){
        printf("插入位置不合法！\n");

        return 0;
    }

    if(list->length>=list->listSize){
        //当前空间已满 增加分配
        newBase=(int*)realloc(list->ele,(list->listSize + LISTCEREMENT)*sizeof(int));
        if(!newBase) {printf("内存分配失败！\n");return 0;}
        list->ele=newBase;//新基址
        list->listSize += LISTCEREMENT;//新增加的容量。
    }

    if(q>list->length&&q<=list->listSize){
        list->ele[list->length]=e;
        list->length++;
        return 1;
    }

    int p;//=list->ele[i-1];//q为要插入的元素。

    for(p=list->ele[list->length-1];p >= q-1; --p)
           list->ele[p+1]=list->ele[p];
    list->ele[q-1]=e;
    ++list->length;
    return 1;

}

//打印表
void printList(SqL list){
    int i;
    printf("打印结果如下：\n");
    for(i=0;i<list->length;i++){
            //arr[%d]:(i),
        printf("%d%c",list->ele[i],i<list->length-1?' ':'\n');
    }
}

//删除
int listDelete(SqL list,int q,int de){//删除第i个元素并用e返回。
    int i;
    if(q<1||q>list->length){
        printf("指定位置不合法\n");
        return -1;
    }

/*
    int p;
    p=list->ele[i-1];
    de=p;
    q=list->ele+list->length - 1;
    for(++p;p <= q;++p)
        list->ele[p-1]=list->ele[p];
    --list->length;
    */


    de=list->ele[q-1];
    for(i=q;i<list->length;i++)
        list->ele[i-1]=list->ele[i];

    list->length--;

    return de;
}

//查找元素匹配元素位置
int listFindKth(SqL list,int e){
    int i;
    for(i=0;i<list->length;i++)
        if(list->ele[i] == e)
            return i+1;
    printf("未查找到该元素\n");
    return 0;
}

//查找按位置get元素
int listFindEle(SqL list,int k){
    int i;
    if(k<1||k>list->length){
        printf("查找位置不合法\n");
        return -1;
    }
    for(i=0;i<list->length;i++){
        if(i==(k-1))
            return list->ele[k-1];
    }
}

int main()
{
    while(1){
    SqL list1;
    list1=(SqL)malloc(sizeof(struct SqList));
    //初始化表
    initList(list1);
    //清空表
    clearList(list1);
    //创建表
    creatList(list1);
    //打印表

    printList(list1);


    int len=listLength(list1);
    printf("顺序表元素个数：%d\n",len);
    //插入
    int i,e;
    printf("插入位置:");
    scanf("%d",&i);
    printf("插入元素:");
    scanf("%d",&e);

    //打印表
    if(listInsert(list1,i,e))
        printList(list1);

     printf("顺序表元素个数：%d\n",listLength(list1));


     int q,de=0;
    printf("删除位置:");
    scanf("%d",&q);
    de=listDelete(list1,q,de);
     //if(de||list1->ele[0]==0){
     if(de>=0)
        printf("删除元素：%d\n",de);

        printList(list1);
        printf("顺序表元素个数：%d\n",listLength(list1));
     //}
     //查找返回位置
     int kth,elememt;
     printf("请输入要查找的元素\n");
     scanf("%d",&kth);
     elememt=listFindKth(list1,kth);
     if(elememt)
            printf("该元素位置是：%d\n",elememt);

    //查找返回元素
    int kth2,th;
     printf("请输入要查找的位置\n");
     scanf("%d",&kth2);
     th=listFindEle(list1,kth2);
     if(th>=0)
        printf("该元素是：%d\n",th);

    free(list1);

    }
    return 0;
}
