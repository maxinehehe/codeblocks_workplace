#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int m,n,maxValue,t,th,tl;
    while(scanf("%d%d",&m,&n)!=-1){
            maxValue=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                scanf("%d",&t);
                if(abs(t)>abs(maxValue)){
                    maxValue=t;
                    th=i;
                    tl=j;
                }
            }
            printf("%d %d %d\n",th,tl,maxValue);
    }
    return 0;
}
