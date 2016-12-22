#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{
   map <string,int>colorBall;
   int maxV,n;
   string maxColor,color;
   printf("请输入气球数目(不区分中英文)：\n");
   while(cin>>n,n){//scanf("%d",&n)!=-1
        colorBall.clear();
        for(int i=0;i<n;i++){
        //scanf("%s",&color);
        cin>>color;

        colorBall[color]++;//统计气球数量
    }
    map<string,int>::iterator it;//定义迭代器
    maxV=0;
    for(it=colorBall.begin();it!=colorBall.end();it++)
        if(it->second>maxV){
            maxV=it->second;
            maxColor=it->first;
        }
    //cout<<maxColor;
     cout<<maxColor<<"颜色气球最多有"<<maxV<<"个"<<endl;
     cout<<"程序只考虑奇数或偶数同大优先考虑第一种出现的结果";
   }
    return 0;
}
