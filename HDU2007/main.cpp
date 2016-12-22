/*
Problem Description
给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。


Input
输入数据包含多组测试实例，每组测试实例包含一行，由两个整数m和n组成。
 //注解 两个数不一定会按大小顺序输入 首先要判断 m大于n吗！

Output
对于每组输入数据，输出一行，应包括两个整数x和y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
你可以认为32位整数足以保存结果。


Sample Input

1 3
2 5



Sample Output

4 28
20 152



Author
lcy

*/
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    long  m,n;

    while(scanf("%ld%ld",&m,&n)!=-1){
        long p=0;
        long v=0;
        if(m > n) swap(m,n);//务必要仔细审题
        for(long i=m;i<=n;i++){
            if(i%2==0)
               p += i*i;
            else
                v += i*i*i;
        }
        printf("%ld %ld\n",p,v);
    }
   // cout << "Hello world!" << endl;
    return 0;
}
