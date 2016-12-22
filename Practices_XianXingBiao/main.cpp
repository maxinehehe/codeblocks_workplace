#include <iostream>
#include <cstdio>
#include <stdlib.h>
#define Max 1000//空间开辟太小也会通不过
using namespace std;

typedef struct polyminal{
    int date[Max+1];
    int high_exp;
}*Poly;
//初始化
void initList(Poly poly){
    for(int i=0;i<Max+1;i++)
        poly->date[i]=0;

    poly->high_exp=0;
        //此处是对传过来的结点进行操作 POly->date[i]则是对上面已给的进行操作。

    return;
}

//输入数据
void initGetValue(Poly poly){
    int coef,exp;
    while(scanf("%d%d",&coef,&exp)!=-1){
        poly->date[exp]=coef;
        if(exp>poly->high_exp)
            poly->high_exp=exp;
    }
   // return;
}

//求导
void devi(Poly poly,Poly retPoly){
    if(poly->high_exp)//如果其不为零
        retPoly->high_exp=poly->high_exp-1;
    for(int i=1;i<=poly->high_exp;i++){
        //如果 不是连续的 几发生断层 4 2 1
        if(poly->date[i])
            retPoly->date[i-1]=i*poly->date[i];
    }
    return;
}

//打印
void print(Poly poly){
    if(poly->high_exp==0&&poly->date[0]==0)
        printf("0 0");

    for(int i=poly->high_exp;i>=0;i--){
        if(poly->date[i]){
        if(i!=poly->high_exp)
        printf(" ");
            printf("%d %d",poly->date[i],i);
        }
    }
    return;
}

int main()
{
    //while(1){
    Poly poly;
    poly=(Poly)malloc(sizeof(struct polyminal));
    initList(poly);
    initGetValue(poly);
    Poly retPoly=(Poly)malloc(sizeof(struct polyminal));

    initList(retPoly);//勿忘初始化
    devi(poly,retPoly);
    print(retPoly);
    free(poly);
    free(retPoly);
    //printf("\n");
   // }
    return 0;
}
