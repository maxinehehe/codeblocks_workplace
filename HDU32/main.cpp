/*
Consider the following algorithm:


    1.      input n

    2.      print n

    3.      if n = 1 then STOP

    4.           if n is odd then n <- 3n + 1

    5.           else n <- n / 2

    6.      GOTO 2


Given the input 22, the following sequence of numbers will be printed 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    __int64 n,i,j,x,y,count1,maxValue;
     while(scanf("%I64d%I64d",&i,&j)!=-1){
            x=i,y=j;
            maxValue=0;
            if(i>j)
                swap(i,j);
     for(__int64 t=i;t<=j;t++){
            count1=0;
            n=t;
         do{
            //printf("%I64d ",n);
            count1++;
            if(n==1)
                break;
            else if(n%2!=0)
                n=n*3+1;
            else
                n=n/2;
         }while(1);
        if(count1>maxValue)
                maxValue=count1;
     }
     printf("%I64d %I64d %I64d\n",x,y,maxValue);
    }
    return 0;
}
