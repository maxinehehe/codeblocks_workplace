/*
数列的定义如下：
数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。


Input
输入数据有多组，每组占一行，由两个整数n（n<10000）和m(m<1000)组成，n和m的含义如前所述。


Output
对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。


Sample Input

81 4
2 2



Sample Output

94.73
3.41



Author
lcy

*/
#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=-1){
            double ans = n ;
            double d = n;
        for(int i = 1;i < m; i++){//注意：是前m项 不包括m项
            d = sqrt(d);
            ans += d;
        }
        printf("%.2lf\n",ans);
    }
   // cout << "Hello world!" << endl;
    return 0;
}
