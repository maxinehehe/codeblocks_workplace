/*
Rightmost Digit
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 40224    Accepted Submission(s): 15191


Problem Description
Given a positive integer N, you should output the most right digit of N^N.


Input
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case contains a single positive integer N(1<=N<=1,000,000,000).


Output
For each test case, you should output the rightmost digit of N^N.


Sample Input

2
3
4



Sample Output

7
6

Hint

In the first case, 3 * 3 * 3 = 27, so the rightmost digit is 7.
In the second case, 4 * 4 * 4 * 4 = 256, so the rightmost digit is 6.

*/
/* 需要寻找规律
(0)1~9 是一个与十位(为偶数)相关的循环 10~19是与十位(为奇数)有关的循环。
还要额外判断十位为0的情况。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



int main()
{
    __int64 T,n,t;
    while(scanf("%I64d",&T)!=-1){

            for(__int64 i=0;i<T;i++){
                __int64 mul=1;

            scanf("%I64d",&n);
            t=n;
            t = t/10%10;
            //printf("t:%d\n",t);
        if(n>20&&t!=0){

                    if(t%2==0)
                        n = n%10;
                    else{
                        n = n%10;
                        n += 10;
                    }
            	}
            	else
                    n=n%10;

		if(n==0) mul=0;
            for(__int64 j=1;j<=n;j++){
                mul *= n;
                if(mul>10)
				mul = mul%10;
            }
            printf("%lld\n",mul);
        }



    }
    return 0;
}
/*
int main()
{
    __int64 T,n;
    while(scanf("%I64d",&T)!=-1){
            __int64 mul[1000];
            memset(mul,1,sizeof(mul));
        for(__int64 i=0;i<T;i++){


            scanf("%I64d",&n);
            for(__int64 j=1;j<=n;j++){
                mul[i] *=n;
                if(mul[i]>10)
				mul[i] = mul[i]%10;
            }

        }
        for(__int64 i=0;i<T;i++)
                printf("%lld\n",mul[i]);

    }
    return 0;
}

*/
