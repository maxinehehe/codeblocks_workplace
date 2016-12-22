/*
此为排序法插入元素！
首先初始化一个足够大的数组,
然后输入n个元素，将要插入的元素插入到元素n的位置（因为数组从零开始）。
More easy！
*/
#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
   int n,inser;
   while(scanf("%d%d",&n,&inser),n!=0||inser!=0){
    int arr[101];
    int t=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arr[n]=inser;
    int len=101;
    for(int i = 0;i<n;i++)
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    for(int i=0;i<n+1;i++){

            printf("%d%c",arr[i],i<n?' ':'\n');
           /*
            if(t++!=0){
                printf(" ");
            }
            printf("%d",arr[i]);
            */
    }
    //printf("\n");
   }
    return 0;
}
