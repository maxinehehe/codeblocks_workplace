/*
此为给定数组元素的情况下插入元素！
*/
#include <iostream>
#include<cstdio>
using namespace std;
int binary_insert(int arr[],int len,int key){
    int left=0,mid,right =len-1;
    while(left<right){
        mid = (left+right)/2;
        //if(key==arr[mid])
           // return mid;
        if(key<=arr[mid])
            right=mid;
        else
            left=mid+1;
    }
     //printf("arr[len-1]:%d\n",arr[len-1]);
    // printf("key:%d\n",key);
    if(key>=arr[len-1])
        left++;

    return left;

}

int main()
{
   int arr[]={1,2,4};//{1,3,5,9,12,16,21,23,39};
   int len=sizeof(arr)/sizeof(int);
   int arr02[len+1];
   int insert=3;
   int rep=binary_insert(arr,len,insert);
   printf("%d\n",rep);
   for(int i=0;i<len+1;i++){
        if(i<rep){
            arr02[i]=arr[i];
        }
        if(i==rep)
            arr02[i]=insert;

        if(i>rep){
            arr02[i]=arr[i-1];
        }
   }
    for(int i=0;i<len+1;i++)
        printf("%d ",arr02[i]);

   printf("arr[2]:%d\n",sizeof(arr)/sizeof(int));
    return 0;
}
