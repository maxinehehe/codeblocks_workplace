
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
//用散列表改进
typedef struct Polynomial{
    int date[Max+1];
    int highPower;
}*Poly;

//初始化
void initList(Poly poly){

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

//求导再开辟一个结点存储
void derivPoly(Poly poly,Poly retPoly){//定义两个结构体指针 类似retPoly是新开的一个结点 这个结点的元素有
        int i;
        if(poly->highPower)
            retPoly->highPower=poly->highPower-1;//记录下求到后的最好指数
        for(i=1;i<=poly->highPower;i++){
            if(poly->date[i])
                retPoly->date[i-1]=i * poly->date[i];
        }
}

void print(Poly poly){
    int i;
    if(poly->highPower==0&&poly->date[0]==0)
        printf("0 0");
    for(i=poly->highPower;i>=0;i--){
        if(poly->date[i]){
        if(i!=poly->highPower)
            printf(" ");
        printf("%d %d",poly->date[i],i);
    }
    }
}

int main()
{
    while(1){
    Poly poly;

    poly=(Poly)malloc(sizeof(struct Polynomial));
     memset(poly->date,0,Max);//初始化为0开辟空间后才能初始化
    poly->highPower=0;

    initList(poly);
    Poly retPoly=(Poly)malloc(sizeof(struct Polynomial));
    memset(retPoly->date,0,Max);//初始化为0
    retPoly->highPower=0;

    derivPoly(poly,retPoly);
    print(retPoly);
    printf("\n");
    free(poly);
    free(retPoly);
  }
    return 0;
}



/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct Polynomial{
	int data[MAX + 1];
	int highPower;
}*Poly;

void ZeroPoly(Poly poly) {	//将所有系数置0
    int i;
	for( i = 0; i < MAX; i++)
		poly->data[i] = 0;
	poly->highPower = 0;
}
void InitPoly(Poly poly) {		//根据输入格式设计的初始化多项式函数
	int coef, exp;
	scanf("%d%d", &coef, &exp);
	poly->data[exp] = coef;
	poly->highPower = exp;
	while(scanf("%d%d", &coef, &exp) != EOF){
		poly->data[exp] = coef;
	}
}
void DerivPoly(Poly poly, Poly retPoly) {	//求导
    int i;
	if(poly->highPower)
		retPoly->highPower = poly->highPower - 1;
	for(i = 1; i <= poly->highPower; i++)
		if(poly->data[i]) {
			retPoly->data[i - 1] = i * poly->data[i];
		}
}
void Print(Poly poly) {
    int i;
	if(poly->highPower == 0 && poly->data[0] == 0)
		printf("0 0");
	for(i = poly->highPower; i >= 0; i--) {
		if(poly->data[i]) {
			if(i != poly->highPower)
				printf(" ");
			printf("%d %d", poly->data[i], i);
		}
	}
}
int main() {
	Poly poly = (Poly)malloc(sizeof(struct Polynomial));
	ZeroPoly(poly);
	InitPoly(poly);		//读入数据
	Poly retPoly = (Poly)malloc(sizeof(struct Polynomial));
	ZeroPoly(retPoly);
	DerivPoly(poly, retPoly);	//求导
	Print(retPoly);		//输出结果
	free(poly);
	free(retPoly);

	return 0;
}
*/
