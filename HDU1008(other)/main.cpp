
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    while(cin>>n,n){
        int time=0,t;
        int currFoor=0;
        while(n--){
            cin>>t;
            if(t>currFoor)
                time+=(t-currFoor)*6;
            else
                time+=(currFoor-t)*4;
    // time+=(t>floor?(t-currFoor)*6:(currFoor-t)*4;
            time+=5;
            currFoor=t;
        }
        //time +=n*5;
        cout<<time<<endl;
    }

    return 0;
}


/*
#include<stdio.h>
int main ()
{
 int t,sum,floor,a;
 while(scanf("%d", &t)&&t){
     floor = 0 ;
     sum = 0;
     while(t--){
         scanf("%d",&a);
   sum+=(a>floor?6*(a-floor):4*(floor-a));
         sum+=5;
         floor= a ;
     }
     printf("%d\n", sum );
 }
 return 0 ;
}
*/
