#include <iostream>
#include <cstdio>
using namespace std;

int prime(){
    int n,p;
    while(scanf("%d",&n)!=-1){
        p=2;
        for(int i=2;i<n;i++,p++){
            if(p%2==0)

        }
    }
}
/*
__int64 getCount_Prime(int n){
    int cou=1;
    __int64 x;
    if(n==1)
        return 1;
    else{
        x=1;
        while(x){
            if(cou==n)
                return x;
            x++;
            if(x%2==0||x%3==0||x%5==0||x%7==0)
                cou++;
            //printf("X:%I64d\n",x);
        }

    }
}

int main()
{
    __int64 a;
    int n;
    while(scanf("%d",&n),n){
        //printf("%I64d\n",a);
        a=getCount_Prime(n);
        printf("%I64d\n",a);
    }

    return 0;
}
*/
