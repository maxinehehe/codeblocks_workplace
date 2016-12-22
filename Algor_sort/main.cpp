#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
   int arr[]={5,6,4,9,80,356,45,89};
   int len=sizeof(arr)/sizeof(int);
   for(int i=0;i<len;i++)
    printf("%d%c",arr[i],i<len-1?' ':'\n');

   sort(arr,arr+len);
   for(int i=0;i<len;i++)
    printf("%d%c",arr[i],i<len-1?' ':'\n');
    printf("请输入要查找的数(sort)：");
    int x;
    scanf("%d",&x);
   int p=lower_bound(arr,arr+len,x)-arr;
   printf("%d  found at %d\n",x,p+1);
    return 0;
}
