#include <bits/stdc++.h>

using namespace std;

int binary_search(int arr[],int len,int value){
    int left=0;
    int mid,right=len-1;
    while(left<=right){
        mid=(left+right)/2;
        if(value==arr[mid])
            return mid;
        if(value<=arr[mid])
            right=mid-1;
         else
            left=mid+1;
    }
    return -1;
}
int main()
{
   int arr[]={11,22,33,44,55,66,77,88};
   int len=sizeof(arr)/sizeof(int);
   int value;
   cin>>value;
   int index=binary_search(arr,len,value)+1;
   cout<<"Ë÷ÒýÎªindex£º"<<index<<endl;
   //for(int i=0;i<len;i++)
    //cout<<arr[i]<<(i<len-1?' ':'\n');
    return 0;
}
