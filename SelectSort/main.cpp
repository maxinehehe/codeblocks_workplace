#include <iostream>
#include <cstdio>
using namespace std;
int slect_sort(int arr[],int len){


    for(int j=0;j<len-1;j++){
        int minValue=arr[j];
        int t=j;
    for(int i = j;i<len;i++){
        if(arr[i]<minValue){
            minValue=arr[i];
            t=i;
        }
    }
    swap(arr[j],arr[t]);
}
   for(int i = 0;i<len;i++){
    printf("%d%c",arr[i],i<len-1?' ':'\n');
   }
}

int main()
{
    int arr[]={57,68,59,52,5,8,7,6,13,123};
    int len=sizeof(arr)/sizeof(int);
    slect_sort(arr,len);
    return 0;
}
