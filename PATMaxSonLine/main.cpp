/*
01-复杂度2. Maximum Subsequence Sum (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4

*/
#include <stdio.h>
#include <stdlib.h>
#define __int64 long long
//using namespace std;
void MaxSubseqSum4( __int64 A[], int N ) {
    __int64 ThisSum, MaxSum;
    __int64 i,t1=A[N-1],t2=0,t3=0,sum2=0;
    ThisSum= MaxSum= 0;
    for( i = 0; i < N; i++ ) {
            ThisSum+= A[i]; /* 向右累加*/
    if( ThisSum> MaxSum){
        MaxSum= ThisSum; /* 发现更大和则更新当前结果*/
        t1=A[i];/*标记t1作为最大子列中最后一个元素。*/
        t3=i;/*标记此序列下标，用于下面辅助找到该最大子列的首位。*/
    }
    else if( ThisSum < 0 ) /* 如果当前子列和为负*/
        ThisSum= 0; /* 则不可能使后面的部分和增大，抛弃之*/
    }
    while(sum2!=MaxSum){
        sum2+=A[t3];
        t2=t3;
        t3--;
    }
    //判断第5 1种情况
    if(MaxSum==0){
        for(int i=0;i<N;i++){
            if(A[i]==0){
                t2=i;
                t1=0;
                break;
            }
        }
    }
    printf("%lld %lld %lld\n",MaxSum,A[t2],t1);
    return ;
    }

int main()
{
    __int64 a[100000];
    int k;
    while(scanf("%d",&k)!=-1){
        for(__int64 i=0;i<k;i++){
            scanf("%lld",&a[i]);
        }
        MaxSubseqSum4(a,k);
    }
    return 0;
}


/*
01-复杂度1. 最大子列和问题(20)

时间限制
10000 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
给定K个整数组成的序列{ N1, N2, ..., NK }，“连续子列”被定义为{ Ni, Ni+1, ..., Nj }，其中 1 <= i <= j <= K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。

输入格式：

输入第1行给出正整数 K (<= 100000)；第2行给出K个整数，其间以空格分隔。

输出格式：

在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例：
6
-2 11 -4 13 -5 -2
输出样例：
20

*/


/*


#include <iostream>
#include <cstdio>

using namespace std;
int MaxSubseqSum4( int A[], int N ) {
    int ThisSum, MaxSum;
    int i;
    ThisSum= MaxSum= 0;
    for( i = 0; i < N; i++ ) {
            ThisSum+= A[i]; // 向右累加
    if( ThisSum> MaxSum)
        MaxSum= ThisSum; // 发现更大和则更新当前结果
    else if( ThisSum< 0 ) //如果当前子列和为负
        ThisSum= 0; // 则不可能使后面的部分和增大，抛弃之
    }
    return MaxSum;
    }

int main()
{
    int a[100000],k;
    while(scanf("%d",&k)!=-1){
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",MaxSubseqSum4(a,k));
    }
    return 0;
}

*/
