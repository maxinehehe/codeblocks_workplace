#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MaxDegree 1000

typedef struct {
    int CoeffArray[MaxDegree + 1];
    int HighPower;
}*Polynomial;

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

    ZeroPolynomial(polySum);

    polySum->HighPower = max(poly1->HighPower,poly2->HighPower);

    for(i=polySum->HighPower;i>=0;i--)
        polySum->CoeffArray[i] = poly1->CoeffArray[i]+poly2->CoeffArray[i];
}

//两个多项式相乘
void MulPolynomial(const Polynomial poly1,const Polynomial poly2,Polynomial polyProd){
    int i,j;
    ZeroPolynomial(polyProd);
    polyProd->HighPower=poly1->HighPower + poly2->HighPower;

    if(polyProd->HighPower > MaxDegree)
        printf("Exceeded array size");
    else
        for(i=0;i<=poly1->HighPower;i++)
        for(j=0;j<=poly2->HighPower;j++)
        polyProd->CoeffArray[i+j]=
            poly1->CoeffArray[i]*poly2->CoeffArray[j];
}
void creatList(Polynomial poly){
     //poly->highPower=0;//最高阶初始化为0
    int coef,exp;//coef系数 exp指数
    //scanf("%d%d",&coef,&exp);
   // poly->date[exp]=coef;
   // poly->highPower=exp;//标记最高指数

    while(scanf("%d%d",&coef,&exp),exp){
          if(exp>poly->highPower)
                poly->highPower=exp;
          poly->date[exp]=coef;//指数记录系数
    }
    return ;
}

int main()
{
    Polynomial poly1,poly2,polySum,polyProd;

    poly1=(Polynomial)malloc(sizeof(struct Polynomial));
    poly2=(Polynomial)malloc(sizeof(struct Polynomial));
    polySum=(Polynomial)malloc(sizeof(struct Polynomial));
    polyProd=(Polynomial)malloc(sizeof(struct Polynomial));

    ZeroPolynomial(poly1);
    ZeroPolynomial(poly2);

    return 0;
}
