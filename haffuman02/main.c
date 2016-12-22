/*
根据Huffman树的构造原理进行构造  ...
哈夫曼树在编码压缩的领域有很好的应用,利用Huffman进行编码可以保证数据传输
的无二义性 。
但是要注意的是 对于出现频率大的数据我们应该尽量放在离根节点近的地方进行编码 ,
出现频率小的数据我们可以放在距离根节点小的地方。
这样可以提高数据的传输效率 。
*/
#include "stdio.h"
#include "malloc.h"

///节点声明
typedef struct  node{
    struct node *lChild ;
    struct node *rChild ;
    int data ;//权值
}TreeNode ;
TreeNode * CreateHuffmanTree(int a[],int n)  ; //数组a表示权的数组  n是个数
void  FindLittle(int *x1,int *x2 ,TreeNode**pArr,int n)  ; //查找出2个权值最小的节点的下标


TreeNode * CreateHuffmanTree(int a[],int n)   //数组a表示权的数组  n是个数
{
    int i;
    TreeNode**pArr=(TreeNode**)malloc(sizeof(TreeNode*)*n);  //动态产生指针数组
    TreeNode*p =NULL;//用于返回哈夫曼树的根节点的指针
    int k1,k2 ;  //k1代表最小权  k2代表次小权    用于做为 FindLittle的参数查找最小权下标
    for( i=0;i<n;i++)
    {
        pArr[i]=new TreeNode ;    //为节点指针数组动态分配指向的对象
        pArr[i]->data=a[i]  ;
        pArr[i]->lChild=pArr[i]->rChild=NULL ;//初始化每个节点的左右节点都是空
    }

    ///因为哈夫曼树是循环的从节点数组中找出权值最小的两个节点进行组合 并从数组中删除这两个节点,并把合并后的节点添加到数组中。
    for(i=0;i<n-1;i++) //因为最后还剩下一个节点所以就会挑选n-1次
    {
        FindLittle(&k1,&k2,pArr,n) ; //查找2个最小权节点下标
        p=new TreeNode;   //循环组合最后的p指向的节点便是最终的pRoot
        p->data=pArr[k1]->data+pArr[k2]->data  ;
        p->lChild=pArr[k1] ;
        p->rChild=pArr[k2] ;

        pArr[k1]=p    ;   //将合并后的新节点赋值给pArr最小的那个下标
        pArr[k2]=NULL ;   // 次下标设置NULL, k1和k2也可以反过来这个具体我们自己定

    }
    free(pArr) ;//释放指针数组
    return p;
}


void  FindLittle(int *x1,int *x2 ,TreeNode**pArr,int n)  //查找出2个权值最小的节点的下标
{
    int  k1,k2;  //保存权最小的两个节点下标
    k1=-1 ; //表示没有找到数据
    for(int i=0;i<n;i++)    //找出其中的前两个元素不为NULL的下标
    {
        if(pArr[i]!=NULL&&k1==-1)
        {
            k1=i ;     //第一个下标
            continue ;
        }
        if(pArr[i]!=NULL)
        {
            k2=i ;
            break;//找到第二个下标退出循环
        }
    }

    ////// 最小权的2个下标的搜索实现//////////
    for(i=k2;i<n;i++) //我们是先获取k1  后获取k2所以一开始 一定是从k2开始循环的
    {
    if(pArr[i]!=NULL)
    {
        if(pArr[i]->data<pArr[k1]->data )  //如果下标k1的权 小于当前下标的元素的权
        {
            k2=k1;  //此时还是k1<k2满足我们返回的结果
            k1=i ;
        }
        else if(pArr[i]->data<pArr[k2]->data)
        {
            k2=i ;
        }

    }
    }
    *x1=k1  ;
    *x2=k2  ;
}

///哈夫曼树的先序遍历
void PreHufOrder(TreeNode*p)   //先序遍历
{
    if(p!=NULL)
    {
        printf("%d ",p->data) ;
        PreHufOrder(p->lChild) ;
        PreHufOrder(p->rChild) ;
    }
}

//中序遍历
void InHufOrder(TreeNode*p)
{
       if(p!=NULL)
       {
           InHufOrder(p->lChild) ;
           printf("%d ",p->data) ;
           InHufOrder(p->rChild) ;
       }
}
//后续遍历
void PostHufOrder(TreeNode*p)
{
    if(p!=NULL)
    {
        InHufOrder(p->lChild) ;
        InHufOrder(p->rChild) ;
        printf("%d ",p->data) ;
    }
}
//清空树
void ClearHufTree(TreeNode*p)
{
    if(p!=NULL)
    {
        ClearHufTree(p->lChild) ;
        ClearHufTree(p->rChild) ;
        delete p ;
    }
}

int main()
{
    int a[]={3,5,3,8,7,9,4,2,4,5,6,3,2,3} ;  //权值
    TreeNode*p=::CreateHuffmanTree(a,sizeof(a)/sizeof(int)) ; //创建huffman树
    printf("Huffman前序遍历:\n") ;
    PreHufOrder(p) ;  //前序遍历huffmanTree
    printf("\n");
    printf("Huffman后序遍历:\n") ;
    PostHufOrder(p) ;//后序遍历
    printf("\n");
    printf("Huffman中序遍历:\n") ;
    InHufOrder(p) ;//中序遍历
    printf("\n");
    ClearHufTree(p) ;//清空树
    return  0 ;
}
