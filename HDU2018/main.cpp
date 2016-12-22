/*
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？


Input
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。


Output
对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。


Sample Input

2
4
5
0



Sample Output

2
4
6



Author
lcy
分析
　　根据题意，先列出前几年的牛头数，试着找找规律：

第n年：


         n=1   n=2   n=3   n=4   n=5   n=6   n=7    n=8    n=9

fn头牛？f1=1   f2=2  f3=3  f4=4  f5=6  f6=9  f7=13  f8=19  f9=28

    在列出这个序列的过程中，应当能找出规律。
　　以n=6为例，fn=9头牛可以分解为6+3，其中6是上一年（第5年）的牛，3是新生的牛（因为第3年有3头牛，这3头在第6年各生一头牛）。
　　我们可以得出这样一个公式：fn=fn-1+fn-3
*/
#include <iostream>
#include<cstdio>

using namespace std;

int cow(int n){
    if(n<5)
        return n;
    else
        return cow(n-1)+cow(n-3);
}

int main()
{
    int n;
    while(scanf("%d",&n),n!=0){
        printf("%d\n",cow(n));
    }
    return 0;
}
