#include<bits/stdc++.h>
using namespace std;

void quick_sort(int arr[],int low,int high){

    int l=low;
    int h=high;
    int key=arr[low];
    while(l<h){
        while(l<h&&arr[h]>=key)
            h--;
        if(l<h){
            int temp =arr[l];
            arr[l]=arr[h];
            arr[h]=temp;
            l++;
        }
        while(l<h&&arr[l]<=key)
            l++;
        if(l<h){
            int temp =arr[l];
            arr[l]=arr[h];
            arr[h]=temp;
            h--;
        }
    }
    if(l>low)quick_sort(arr,low,l-1);
    if(h<high)quick_sort(arr,h+1,high);

        /*
        int low = left;
		int high=right;
		int key = arr[low];
		while(low<high){
			while(low<high&&arr[high]>=key)
				high--;
			if(low<high){
				int temp=arr[high];
				arr[high]=arr[low];
				arr[low]=temp;
				low++;
			}
			while(low<high&&arr[low]<=key)
				low++;
			if(low<high){
				int temp=arr[high];
				arr[high]=arr[low];
				arr[low]=temp;
				high--;
			}
		}
		//ตÝน้
		if(low>left)quick_sort(arr,left,low-1);
		if(high<right)quick_sort(arr,high+1,right);
		*/
}

int main()
{
    int arr[]={57,68,59,52,66,45,25,29,49,53,45,10};
    int high=sizeof(arr)/sizeof(int);
    quick_sort(arr,0,high-1);
    for(int i=0;i<high;i++){
        printf("%d%c",arr[i],i<high-1?' ':'\n');
    }
    return 0;
}
