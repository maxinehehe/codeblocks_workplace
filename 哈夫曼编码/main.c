#include <stdio.h>
#include <stdlib.h>
//此为独立重现哈夫曼
typedef int ElementType;

struct BitTree{
    ElementType data;
    struct BitTree *lchild;
    struct BitTree *rchild;
};


struct BitTree* HuffumanCreatAndCoding(ElementType arr[],int n){
    struct BitTree *bt,**b;
    int i,j;

    b = (struct BitTree**)malloc(n*sizeof(struct BitTree));//动态分配数组
    for(i=0;i<n;i++){
        b[i]=(struct BitTree *)malloc(sizeof(struct BitTree));//为b[i]开辟结点空间
        b[i]->data=arr[i];
        b[i]->lchild = b[i]->rchild = NULL;
    }



    for(i=0;i<n-1;i++){
        int k1=-1,k2;
        //找到森林中最小和此最小的树
        //首先让k1指向森林中第一棵树,k2
        for(j=0;j<n;j++){
            if(b[j]!=NULL && k1 == -1){
                k1 = j;
               //然后就不能继续往下走了 要跳出循环找第二棵树
               continue;//打破for循环
            }
            if(b[j]!=NULL){
                k2 = j;
                break;
            }
        }

        //首先做一个循环 找到最小值给k1，次最小值给k2
        for(j=k2;j<n;j++){
            //通过比较找最小值
            if(b[j]!=NULL){
                if(b[j]->data<b[k1]->data){
                    k2 = k1;
                    k1 = j;

                }
                else if(b[j]->data<b[k2]->data){
                    k2 = j;
                }
            }
        }

        bt = (struct BitTree *)malloc(sizeof(struct BitTree));
        bt->data = b[k1]->data + b[k2]->data;
        bt->lchild = b[k1];
        bt->rchild = b[k2];

        b[k1] = bt;
        b[k2] = NULL;

    }
    free(b);
    return bt;


}

void PrintHuffmancoding(struct BitTree *bt,int len){
    static int arr[10];
    if(bt!=NULL){
        if(bt->lchild == NULL && bt->rchild==NULL){
            int i;
            printf("%d结点编码为：",bt->data);
            for(i=0;i<len;i++){
                printf("%d",arr[i]);
            }
            printf("\n");
        }else{
            //向深度为len 向下增加
            arr[len]=0;
            PrintHuffmancoding(bt->lchild,len+1);
            arr[len]=1;
            PrintHuffmancoding(bt->rchild,len+1);
        }

    }

}



int main()
{
    struct BitTree *bt=NULL;
    int n,i;
    ElementType *arr;

    printf("请输入结点数：");
    scanf("%d",&n);
    while(1){
        if(n>1)
            break;
        else{
            printf("请重新输入：");
            scanf("%d",&n);
        }
    }

    arr=(ElementType *)malloc(n*sizeof(ElementType));
    printf("请输入%d个权值:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    //创建哈夫曼树
    bt = HuffumanCreatAndCoding(arr,n);

    //打印哈夫曼编码
    PrintHuffmancoding(bt,0);


    return 0;
}
