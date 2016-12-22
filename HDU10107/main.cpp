#include <iostream>
#include<cstdio>
using namespace std;
// count the number of
// pairs of integers (a,b)
//such that 0<a<b<n and (a^2+b^2 +m)/(ab)is an integer.
int main()
{
   int a,b,CT;
   int m,n,cnt;
   int ncase;
   scanf("%d",&CT);
   //getchar();
   while(CT--){
    ncase=0;
    while(scanf("%d%d",&n,&m),(n||m)){
     ncase++;
     cnt=0;
    for(a=1;a<n;a++){
    for(b=a+1;b<n;b++){
    if((a*a+b*b+m)%(a*b)==0)
        cnt++;
            }
        }
        printf("Case %d: %d\n",ncase,cnt);
    }
        if(CT)
            printf("\n");
   }


    return 0;
}













