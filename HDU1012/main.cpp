#include <iostream>
#include<cstdio>
using namespace std;

double mult(int n){
    double t=1.0;
   for(int i=1;i<=n;i++){
        t*=i;
   }
    return t;
}

int main()
{
   int n,t;
   double sum;
   printf("n e\n");
   printf("- -----------\n");
   printf("0 1\n");
   for(int n=1;n<10;n++){
    sum=0.0;
    t=n+1;
    while(t-->0){
        sum+=1.0/mult(t);
    }
    if(n<2)
        printf("%d %.0f\n",n,sum);
    if(n==2)
        printf("%d %.1f\n",n,sum);
    if(n>2)
        printf("%d %.9f\n",n,sum);
   }
    return 0;
}
