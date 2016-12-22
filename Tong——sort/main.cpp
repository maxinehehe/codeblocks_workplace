//桶排序 注意初始化为0
#include <iostream>
#include <cstdio>
#include <cstring>
//#define Max 9999
using namespace std;
//暂时处理正数
int main()
{
    int a[11],t;//数组一定要大几位
    memset(a,0,sizeof(a));//初始化a
    for(int i=0;i<5;i++){
        scanf("%d",&t);
        //t+=Max;
        a[t]++;
    }

    for(int i=0;i<=10;i++)
        for(int j=1;j<=a[i];j++)
                printf("%d ",i);
        //getchar();getchar();

    return 0;
}
