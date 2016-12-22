#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
   int n;
   int t;
   while((scanf("%d",&n),n!=0)){
      // int num[n];
       //memset(num,0,n);
       int sum=0;
      for(int i=0;i<n;i++){
        scanf("%d",&t);
        sum+=t;
      }
      printf("%d\n",sum);
   }
    return 0;
}
