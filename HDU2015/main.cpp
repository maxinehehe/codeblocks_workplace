/*
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。


Input
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。


Output
对于每组输入数据，输出一个平均值序列，每组输出占一行。


Sample Input

3 2
4 2



Sample Output

3 6
3 7
注意：1.最后输出不能有空格
      2.最后以实际即是有多少数就输出这些数的平均数！
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)!=-1){
        int num[100];
        int all=0,t=0,i2=0,test=0;
    for(int i=0;i<n;i++){
            t += 2;
            num[i]=t;
            all += num[i];
    }
    for(int i = 0;i<n/m;i++){
            int sum=0,count=0;
        for(int j=i2;count<m;j++,i2++){
            sum +=num[j];
            count += 1;
        }
            if(test!=0){
                printf(" ");
            }
            printf("%d",sum/m);
            test++;
    }
    if(n%m==0)
        printf("\n");
    else{
        int sum2=0;
        for(int i=i2;i<n;i++) sum2 += num[i];
        printf(" %d\n",sum2/(n-i2));
        }
   }
    return 0;
}
