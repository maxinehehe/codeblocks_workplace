#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    //应用散列表
    map <string,int>color;
    char col[10];
    string maxColor;
    int n;
    while(scanf("%d",&n),n){
        color.clear();//清空散列表
        for(int i=0;i<n;i++){
            scanf("%s",&col);
            color[col]++;
        }
        int maxV=0;
        map <string,int>::iterator it;
        for(it=color.begin();it!=color.end();it++){
            if(it->second>maxV){
                    maxV=it->second;
                maxColor=it->first;
            }
        }
        //printf("%s\n",maxColor);
        cout<<maxColor<<endl;
    }
    return 0;
}
