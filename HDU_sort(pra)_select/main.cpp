#include<bits/stdc++.h>
//**********************************
//时间复杂度O(n**2)
using namespace std;

void select_sort(int arr[],int len){
    int t=0;
    for(int i=0;i<len-1;i++){
        t=i;//重要的一步，如果本身就是最小值的情况！
        int miniValue=arr[i];
        for(int j=i+1;j<len;j++){
            if(miniValue>arr[j]){
                miniValue=arr[j];
                t=j;
            }
        }
        swap(arr[i],arr[t]);
    }

}

int main()
{
    int arr[]={56,52,64,89,12,35,44,65,10,1,6,3,4,560,79,12,25};
    int len=sizeof(arr)/sizeof(int);
    select_sort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
     }
    return 0;
}
