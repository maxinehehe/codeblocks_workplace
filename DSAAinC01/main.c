#include <stdio.h>
#include <stdlib.h>
#include<hash_map>

int main()
{
   map<string,int>colorBall;
   int maxV,n;
   string maxColor,color;
   printf("请输入气球数目：\n");
   while(scanf("%d",&n)!=-1,n){
      colorBall.clear();
    for(int i=0;i<n;i++){
        scanf("%s",color);
        colorBall[color]++;//统计气球数量
    }
    map<string,int>::iterator it;//定义迭代器
    maxV=0;
    for(it=colorBall.begin();it!=colorBall.end();it++)
        if(it->second>maxV){
            maxV=it->second;
            maxColor=it->first;
        }

     printf("%s颜色气球最多有%d个\n",maxColor,maxV);
   }

    return 0;
}
