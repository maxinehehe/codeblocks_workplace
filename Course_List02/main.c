#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MaxDegree 1000

typedef struct PolyList{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
}*Polynomial;

int max(int a,int b){

    return a>b?a:b;
}
//多项式初始化为0过程
void ZeroPolynomial(Polynomial poly){
    int i;

    for(i=0;i<=MaxDegree;i++)
        poly->CoeffArray[i]=0;
    poly->HighPower=0;

    return;
}

//两个多项式相加过程
void AddPolynomial(const Polynomial poly1,const Polynomial poly2,Polynomial polySum){
    int i;
    printf("加法：");
    ZeroPolynomial(polySum);

    polySum->HighPower = max(poly1->HighPower,poly2->HighPower);

    for(i=polySum->HighPower;i>=0;i--)
        polySum->CoeffArray[i] = poly1->CoeffArray[i]+poly2->CoeffArray[i];
}

//两个多项式相乘
void MulPolynomial(const Polynomial poly1,const Polynomial poly2,Polynomial polyProd){
    int i,j;
    printf("乘法:");
    ZeroPolynomial(polyProd);
    polyProd->HighPower=poly1->HighPower + poly2->HighPower;

    if(polyProd->HighPower > MaxDegree)
        printf("Exceeded array size");
    else
        for(i=0;i<=poly1->HighPower;i++)
            for(j=0;j<=poly2->HighPower;j++)
                polyProd->CoeffArray[i+j] +=
                    poly1->CoeffArray[i]*poly2->CoeffArray[j];
}
void creatList(Polynomial poly){
     //poly->highPower=0;//最高阶初始化为0
    int coef,exp;//coef系数 exp指数
    //scanf("%d%d",&coef,&exp);
   // poly->date[exp]=coef;
   // poly->highPower=exp;//标记最高指数

    while(scanf("%d%d",&coef,&exp)!=-1){

          if(exp>poly->HighPower)
                poly->HighPower=exp;//记录最大的指数幂
          poly->CoeffArray[exp]=coef;//指数记录系数
        if(exp==0)
            break;
    }
    return ;
}

void printPolynomial(Polynomial poly){

    int i,j;
    if(poly->HighPower==0)
        printf("0 0\n");

    for(i=poly->HighPower;i>=0;i--){
        if(poly->CoeffArray[i]){
        if(i!=poly->HighPower)
            printf(" ");
        printf("%d %d",poly->CoeffArray[i],i);
    }
    }
    /*
    else
        for(i=poly->HighPower;i>=0;i--){
            if(poly->CoeffArray[i]){
                printf("%d  %d",poly->CoeffArray[i],i);
            }
    }
    */
    printf("\n");
    return;
}

int main()
{
    printf("以0幂为结束输入！\n");
    Polynomial poly1,poly2,polySum,polyProd;

    poly1=(Polynomial)malloc(sizeof(struct PolyList));
    poly2=(Polynomial)malloc(sizeof(struct PolyList));
    polySum=(Polynomial)malloc(sizeof(struct PolyList));
    polyProd=(Polynomial)malloc(sizeof(struct PolyList));

    ZeroPolynomial(poly1);
    ZeroPolynomial(poly2);
    printf("poly1:");
    creatList(poly1);
    printf("poly2:");
    creatList(poly2);

    //加法
    AddPolynomial(poly1,poly2,polySum);
    printPolynomial(polySum);
    MulPolynomial(poly1,poly2,polyProd);
    printPolynomial(polyProd);

    free(poly1);
    free(poly2);
    free(polyProd);
    free(polySum);

    return 0;
}
