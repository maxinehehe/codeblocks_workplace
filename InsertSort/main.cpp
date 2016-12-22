//直接插入排序
#include <iostream>
#include <cstdio>
using namespace std;

int InsertSort(int a[],int len){
    int temp = 0;
    for(int i = 1;i<len;i++){
        temp = a[i];
        int j = i - 1;
        for(;j>=0&&temp<a[j];j--){
            a[j+1] = a[j];//后推一位
        }
        //然后把temp插入空出来的位置（后移一位留下的）
        a[j+1] = temp;
    }
    for(int i=0;i<len;i++){
        printf("%d%c",a[i],i<len-1?' ':'\n');
    }
}

int main()
{
    int arr[]={57,68,59,52};
    int len = sizeof(arr)/sizeof(int);
    InsertSort(arr,len);
    return 0;
}
