#include<bits/stdc++.h>

using namespace std;

int bubble_sort(int arr[],int len){
    for(int i=0;i<len-1;i++)
    for(int j=0;j<len-1-i;j++){//==for(int j=0;j<len-1;j++)²»ÍÆ¼ö
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    return 0;
}

int main()
{
    int arr[]={56,52,64,89,12,35,44,65,10,1,6,3,4,560,11};
    int len=sizeof(arr)/sizeof(int);
    bubble_sort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
    }
    return 0;
}
