#include <stdio.h>
#include <stdlib.h>
#define maxSize 40
typedef struct{
    int Data[maxSize];
    int last;
}List;
//={2,4,6,9,3,40,12}
List L,*PtrL;
//访问下标为i的元素：L.Data[i]或PtrL->Data[i]
//线性表的长度:L.last=1或PtrL->last+1;

//1.初始化线性表（建立空的顺序表）
List *makeEmpty(){
    List *PtrL;
    PtrL =(List*)malloc(sizeof(List));//申请动态内存分配空间
    PtrL->last=0;
    return PtrL;
}

//增加
void add(List*PtrL){
    int i;
    if(PtrL->last+1>=maxSize){
        printf("表已满！");
    }
    else{
            //if(PtrL->last<)
          for(i=0;i<maxSize;i++)
        PtrL->Data[PtrL->last]=i+1;
        PtrL->last++;
    }
    return;
}

void show(List*PtrL){
    int i;
    if(PtrL->last==-1)
    {
        printf("表为空！");
        return ;
    }
    else
        for(i=0;i<PtrL->last;i++){
            printf("%d ",PtrL->Data[i]);
        }
    return ;
}

//查找
int find(int x,List *PtrL){
    int i=0;//数组从0开始
    while(i<=PtrL->last&&PtrL->Data[i]!=x)
        i++;
    if(i>PtrL->last)
        return -1;//如果没找到返回-1.
    else
        return i;
}

//插入操作
void insert(int x,int i,List* PtrL){//x:插入元素,i:插入位置，PtrL:要操作的线性表
    int j;
    if(PtrL->last==maxSize-1){
        printf("线性表已满！");
        return;
    }
    if(i<1||i>PtrL->last+2){//如果是0则会插入到0-1的位置
       printf("位置不合法！");
       return;
    }
    for(j=PtrL->last;j>=i-1;j--)
        PtrL->Data[j+1]=PtrL->Data[j];/*将 ai～ an倒序向后移动*/
    PtrL->Data[i-1]=x;/*新元素插入*/
    PtrL->last++;/*last也要增加一位指向最后一位*/
    return;
}

void Delete(int i,List*PtrL){//按指定位置删除指定元素
    int j;
    if(i<1||i>PtrL->last+1){
        printf("不存在第%d个元素",i);
        return ;
    }
    for(j=i;j<=PtrL->last;j++)
        PtrL->Data[j-1]=PtrL->Data[j];//把i-1的值挤掉了
    PtrL->last--;
    return;
}

int main()
{
    while(1){
printf("1.初始化   2.查找    3.插入    4.删除    5.增加元素 6.显示表\n");
int n;
int l,x;
scanf("%d",&n);
switch(n){
case 1: makeEmpty();break;
case 2: printf("请输入要查找的元素\n");int x;
        scanf("%d",&x);find(x,PtrL);break;
case 3:printf("请输入要插入的元素和位置\n");
        scanf("%d%d",&l,&x);insert(l,x,PtrL);break;
case 4:printf("请输入要删除元素的位置\n");int l;
        scanf("%d",&l);Delete(l,PtrL);break;
case 5://printf("请输入要增加的元素！\n");scanf("%d",&x);
        add(PtrL);break;
case 6:show(PtrL);break;
default :printf("输入有误！\n");break;
}
    }
    return 0;
}
