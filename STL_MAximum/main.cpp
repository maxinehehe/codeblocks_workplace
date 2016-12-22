#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m=0;
    long long maxn;
    long long t,mul;
    while(scanf("%d",&n)!=EOF){
        t=0;mul=1;maxn=0;
        long long k=1;
        for(int i=0;i<n;i++){
            scanf("%lld",&t);
            mul *= t;
            k *=t;
            if(mul>maxn)maxn = mul;
            k = mul;
            if(k>0)mul=k;
            if(mul<0)mul=1;


        }
        long long va = maxn>mul?maxn:mul;

        printf("Case #%d: The maximum product is %ld.\n",++m,va);
    }
    return 0;
}
