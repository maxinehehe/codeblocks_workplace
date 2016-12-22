#include <iostream>
#include<cstdio>
using namespace std;

void insert_sort(int arr[],int len){
    for(int i=1;i<len;i++){
        int j=i-1;
        int temp=arr[i];
        for(;j>=0&&temp<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;//如果本身即是最小值与自身交换。（类似选择排序）
    }
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
    }
}

int main()
{
    int arr[]={57,68,59,52,4,3,89,56,23,12,45,10,35};
    int len=sizeof(arr)/sizeof(int);
    insert_sort(arr,len);
    return 0;
}
