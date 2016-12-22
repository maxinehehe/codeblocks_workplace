/*
Problem Description
A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers.

Write a program to find and print the nth element in this sequence


Input
The input consists of one or more test cases. Each test case consists of one integer n with 1 <= n <= 5842. Input is terminated by a value of zero (0) for n.


Output
For each test case, print one line saying "The nth humble number is number.". Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" for the ordinal number nth has to be used like it is shown in the sample output.


Sample Input

1
2
3
4
11
12
13
21
22
23
100
1000
5842
0



Sample Output

The 1st humble number is 1.
The 2nd humble number is 2.
The 3rd humble number is 3.
The 4th humble number is 4.
The 11th humble number is 12.
The 12th humble number is 14.
The 13th humble number is 15.
The 21st humble number is 28.
The 22nd humble number is 30.
The 23rd humble number is 32.
The 100th humble number is 450.
The 1000th humble number is 385875.
The 5842nd humble number is 2000000000.

*/

//我学到的 应该先对程序进行分析。

//时间复杂度过高 200以外会超出开销
//应考虑 用数组。

#include <iostream>
#include <cstdio>

using namespace std;

bool IsPrime(__int64 n){

	for(__int64 i=2;i<n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}


int main()
{
    __int64 n,t,count1,k;
    bool flag;
    while(scanf("%d",&k),k){
            count1=0;
            n=2000000002;
          // n=k;
        for(__int64 i=1;i<=n;i++){
                t=i;
                flag=true;

                  for(__int64 j=8;j<=n&&t>j;j++){
                            if(IsPrime(j)&&t%j==0){
                                    //printf("J:%d t:%d\n",j,t);
                                flag=false;
                                break;
                            }
                        }

            if(flag&&(i%2==0||i%3==0||i%5==0||i%7==0||i==1)){
                  count1++;
                if(k==count1)
                    {
                    printf("The %I64dnd humble number is %I64d.\n",count1,i);
                    //The 5842nd humble number is 2000000000
                        break;
                }
            }
        }
    }

    return 0;
}







/*
#include<stdio.h>

long long num[5843];

int main(){
    num[1]=1;
    int i,j,k;
    int prime[4]={2,3,5,7};
    for(i=2;i<=5842;i++){
        num[i]=2000000001;
        for(j=0;j<4;j++)
            for(k=i-1;k>=1;k--){
                if(num[k]*prime[j]<=num[i-1])
                    break;
                if(num[k]*prime[j]<num[i])
                    num[i]=num[k]*prime[j];
            }
    }


    int n;
    while(scanf("%d",&n) && n){
        printf("The %d",n);
        if(n%10==1 && n%100!=11)
            printf("st ");
        else if(n%10==2 && n%100!=12)
            printf("nd ");
        else if(n%10==3 && n%100!=13)
            printf("rd ");
        else
            printf("th ");
        printf("humble number is %I64d.\n",num[n]);
    }
    return 0;
}


*/
