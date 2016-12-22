#include <iostream>
#include<cstdio>
#include<map>
using namespace std;

int main(){
int n,maxValue;
string color,maxColor;
map<string ,int>airBall;
while(cin>>n,n!=0){
        airBall.clear();
        maxValue=0;
    while(n--&&cin>>color){
        airBall[color]++;
    }
    map<string,int>::iterator it;
    for(it=airBall.begin();it!=airBall.end();it++){
        if(it->second>maxValue){
            maxValue = it->second;
            maxColor = it->first;
        }
    }
  cout<<maxColor<<endl;
}
return 0;
}
/*
int rabit(int n){
    if(n==0||n==1)
        return 1;
    else
        return rabit(n-1) + rabit(n-2);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=-1){
        printf("%d\n",rabit(n));
    }
    return 0;
}
*/
