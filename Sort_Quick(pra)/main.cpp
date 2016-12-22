#include <bits/stdc++.h>

using namespace std;
clock_t start,stop,start2,stop2;
double duration;

void select_sort(int arr[],int len){
    int miniPosi;
    for(int i=0;i<len-1;i++){
        miniPosi=i;
        for(int j=i;j<len;j++){
            if(arr[miniPosi]>arr[j])
                miniPosi=j;
        }
        if(miniPosi!=i)
            swap(arr[miniPosi],arr[i]);
    }
    return ;
}

void quick_sort(int arr[],int low,int high){
    int l=low;
    int h=high;
    int key=arr[low];//需要找一个元素做标记

    while(l<h){
        while(l<h&&arr[h]>=key)
            h--;
        if(l<h){
            swap(arr[l],arr[h]);
            l++;
        }
        while(l<h&&arr[l]<=key)
            l++;
        if(l<h){
            swap(arr[l],arr[h]);
            h--;
        }

    }
    if(l>low)quick_sort(arr,low,l-1);
    if(h<high)quick_sort(arr,h+1,high);
    return ;
}

int main()
{

    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    int len=sizeof(a)/sizeof(int);
    start=clock();
    quick_sort(a,0,len-1);
    for(int i=0;i<len;i++){
        printf("%d%c",a[i],i<len-1?' ':'\n');
    }
    stop=clock();
    double result=((double)(stop-start))/CLK_TCK;
    printf("快排耗时耗时：%f\n",result);

    start2=clock();
    select_sort(a,len);
    for(int i=0;i<len;i++){
        printf("%d%c",a[i],i<len-1?' ':'\n');
    }
     stop2=clock();
    double result2=((double)(stop2-start2))/CLK_TCK;
    printf("选择排序耗时：%f\n",result2);
    return 0;
}
