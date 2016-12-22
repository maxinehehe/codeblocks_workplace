#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
clock_t start,stop;
double duration;
#define MAXN 10/*多项式最大项数，即多项式阶数+1*/
#define MAXK 1e7
double f1(int n,double a[],double x);//函数声明
double f2(int n,double a[],double x);//函数声明

int main()
{
    int i;
    double a[MAXN];
    for(i=0;i<MAXN;i++){
            //printf("%f\n",a[i]);
        a[i]=(double)i;
    }
    start =clock();
    for(i=0;i<MAXK;i++)
        f1(MAXN-1,a,1.1);
    stop=clock();
    duration =((double)(stop-start))/CLK_TCK/MAXK;
    printf("ticks1= %f\n",(double)(stop-start));
    printf("duration1= %6.2e\n",duration);

    start =clock();
    for(i=0;i<MAXK;i++)
        f2(MAXN-1,a,1.1);
    stop=clock();
    duration =((double)(stop-start))/CLK_TCK/MAXK;
    printf("ticks2= %f\n",(double)(stop-start));
    printf("duration2= %6.2e\n",duration);

    return 0;
}
//f(x)=a0+a1*x…………an-1*x**(n-1)+a2*x**(n)
double f1(int n,double a[],double x){
    double p=a[0];
    int i;
    for(i=1;i<=n;i++){
        p+=(a[i]*pow(i,x));
    }
    return p;
}

double f2(int n,double a[],double x){
    double p=a[n];
    int i;
    for(i=n;i>0;i--){
        p=a[i-1]+x*a[i];
    }
    return p;
}
