#include <stdio.h>
#include <stdlib.h>


typedef struct LNode{
    int data;
    struct LNode *next;
    int length;
}LNode,*LinkList;

void CreatList_head(LinkList L,int n);
void CreatList_tail(LinkList L,int n);

struct LNode *LNodeList_init(){
    LinkList L = NULL;
    L=(LinkList)malloc(sizeof(LNode));//开辟头结点
    L->length = 0;
    return L;
}

void CreatList_head(LinkList L,int n){//头插法建表
    LinkList p;
    int i;
   // L=(LinkList)malloc(sizeof(LNode));//开辟空间
    L->next=NULL; //先创建一个带头结点的单链表
    for(i=n;i>0;--i){
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&(p->data)); //输入元素值
        L->length++;
        p->next=L->next;//将头结点指向开端
        L->next = p;
    }
}

//尾插法建表
void CreatList_tail(LinkList L,int n){//尾插法建立链表
    LinkList p,r;
    int i;

   //L=(LinkList)malloc(sizeof(LNode));//开辟空间
   r=L;
    L->next=NULL; //先创建一个带头结点的单链表
    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&(p->data));

        r->next=p;
        r=p;

         L->length++;
    }
    r->next=NULL;
    //printf("LIST LENGTH:%d\n",L->length);

}

void printList(LinkList L,int n){
   int i;

   //for(i=0;i<n;i++){
   while(L->next!=NULL){
    L=L->next;
    printf("%d ",L->data);
   }
    printf("\n");
}


int LocateElem(LinkList L,int x){
    int i,count=0;

        while(L->data!=x){
            if(L->next!=NULL){
                L=L->next;
                count++;
            }else
                return 0;
        }

        //i=L->data;
    return count;
}

int LENGTH(LinkList L){
    int length=0;
    while(L->next!=NULL){
        length++;
        L=L->next;
    }
    return length;

}

int list_Length(LinkList L){
    return L->length;
}

int Getelem(LinkList L,int i){
    //L为带头结点的单链表的头指针
    //当第i个元素存在时，其赋值给e并返回ok，否则返回error
    LinkList p;
    int j,e;
    p=L->next;j=1;//p指向第一个结点
    while(p&&j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i) return 0;
    e=p->data;
    return e;
}


int main()
{
    LinkList L;
    int n,x;
    //L=(LinkList)malloc(sizeof(LNode));
    L = LNodeList_init();//开辟空间

    printf("请输入表顶范围：");
    scanf("%d",&n);

    CreatList_tail(L,n);
    printList(L,n);


    printf("查找：\n");
    scanf("%d",&x);

    if(LocateElem(L,x))
        printf("地址：%d\n",LocateElem(L,x));
    else
        printf("查找不到该元素\n");

    printf("表长度01:%d\n",LENGTH(L));
    printf("表长度02:%d\n",list_Length(L));

    //获取元素
    int i,e,t;
    printf("i:");
    scanf("%d",&i);
   t = Getelem(L,i);
   if(t) printf("该位置元素是：%d\n",t);
    else printf("输入位置不对\n");

/*
    printf("请输入表顶范围：");
    scanf("%d",&n);

    CreatList_head(L,n);
    printList(L,n);
*/
    free(L);
    return 0;
}
