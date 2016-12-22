#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    int t;
   while(scanf("%d",&n)!=-1){
        int sum=0;
    for(int i = 0;i < n;i ++){
        scanf("%d",&t);
        sum += t;
    }
    printf("%d\n",sum);
   }
    return 0;
}
