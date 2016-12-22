/*
Problem Description
输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。


Input
输入数据有多组，每组占一行，每行的开始是一个整数n，表示这个测试实例的数值的个数，跟着就是n个整数。
n=0表示输入的结束，不做处理(结束输入)。
 注意！！！：如果有重复的且是最小的元素，一定要是最后一个最小的元素与第一个数交换！代码 应 >=(<=)

Output
对于每组输入数据，输出交换后的数列，每组输出占一行。


Sample Input

4 2 1 3 4
5 5 4 3 2 1
0



Sample Output

1 2 3 4
1 4 3 2 5



Author
lcy

*/
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    int t;//用于记录mini索引
    while(scanf("%d",&n),n!=0){
        int num[100],sta=0;
        t=0;
        for(int i = 0;i<n;i++){
            scanf("%d",&num[i]);
        }
        int mini=num[0];
        for(int i =0;i<n;i++){
            if(mini>=num[i]){
                mini = num[i];
                t = i;
            }
        }
        swap(num[t],num[0]);//最小数和第一个数交换
        //下面循环遍历一下即可
        for(int i = 0;i<n;i++){
                if(i!=0)
                    printf(" ");
                printf("%d",num[i]);
        }
        printf("\n");
    }
    return 0;
}
