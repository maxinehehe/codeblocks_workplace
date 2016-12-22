#include<bits/stdc++.h>

using namespace std;

void insert_sort(int arr[],int len){
    int temp=0;
    for(int i=1;i<len;i++){
        temp=arr[i];
        int j=i-1;
        for(;j>=0&&temp<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}
int main()
{
     int arr[]={56,52,64,89,12,35,44,65,10,1,6,3,4,560,11};
    int len=sizeof(arr)/sizeof(int);
    insert_sort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
    }
    return 0;
}
