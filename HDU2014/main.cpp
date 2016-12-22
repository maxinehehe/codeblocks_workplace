/*
青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。


Input
输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。


Output
对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。


Sample Input

3 99 98 97
4 100 99 98 97



Sample Output

98.00
98.50



Author
lcy
*/
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,t;

    while(scanf("%d",&n)!=-1){
        int num[100];//OJ不允许用变量定义数组
        double sum = 0;
        for(int i = 0;i < n;i++){
            num[i]=0;
            scanf("%d",&t);
            num[i]=t;
        }
        //冒泡排序
        for(int i = 0;i<n-1;i++)
            for(int j = 0;j<n-i-1;j++){
                if(num[j]>num[j+1])
                    swap(num[j],num[j+1]);
            }
        //计算和
        for(int i = 1;i<n-1;i++){
            sum += num[i];
        }
        printf("%.2lf\n",sum/(n-2));
    }
    return 0;
}
