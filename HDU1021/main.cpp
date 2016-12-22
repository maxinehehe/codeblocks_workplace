/*
#include <iostream>
#include <cstdio>
using namespace std;

__int64 Facci2(__int64 n){
    __int64 i,a,x=7,y=11;
   if(n==0)
        return x%3;
    else if(n==1)
        return y%3;
    else{
        for(i=2;i<=n;i++){
            a=(x%3+y%3);
            x=y;
            y=a;
        }
        return a;
    }
}

int main()
{
    __int64 n;
    while(scanf("%I64d",&n)!=EOF){
        if(Facci2(n)%3==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

*/
//2·¨
#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        if((n-2)%4==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
