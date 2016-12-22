#include <iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
using namespace std;
clock_t start,stop;
double duration;

void insert_sort(int arr[],int len){
    int temp;
    for(int i=1;i<len;i++){
        int j=i-1;
        temp=arr[i];
        for(;j>=0&&temp<arr[j];j--){
            arr[j+1]=arr[j];
        }

        arr[j+1]=temp;
    }
    return;
}

int main()
{
    int arr[]={6,4,18,56,75,12,10,44};
    int len=sizeof(arr)/sizeof(int);
    start=clock();
    insert_sort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
    }
    stop=clock();
    double re=((double)(stop-start))/CLK_TCK;
    printf("ºÄÊ±£º%f\n",re);
    return 0;
}
