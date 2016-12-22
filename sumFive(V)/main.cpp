/*
1093 HDU
*/
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int limit;
   int n;
   int t;
   scanf("%d",&limit);
   while((limit--)!=0){
        scanf("%d",&n);
       int sum=0;
      for(int i=0;i<n;i++){
        scanf("%d",&t);
        sum+=t;
      }
      printf("%d\n",sum);
   }
    return 0;
}
