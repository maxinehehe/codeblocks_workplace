/*
有n(n<=100)个整数，已经按照从小到大顺序排列好，现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。


Input
输入数据包含多个测试实例，每组数据由两行组成，第一行是n和m，第二行是已经有序的n个数的数列。n和m同时为0标示输入数据的结束，本行不做处理。


Output
对于每个测试实例，输出插入新的元素后的数列。


Sample Input

3 3
1 2 4
0 0



Sample Output

1 2 3 4



Author
lcy

此为二分法插入元素(1法)
*/
#include <iostream>
#include<cstdio>
using namespace std;

int binary_insert(int arr[],int len,int key){//二分法通过查询找到该元素要插入的位置 返回给主函数
    int left=0,mid,right =len-1;
    while(left<right){
        mid = (left+right)/2;
        if(key<=arr[mid])
            right=mid;
        else
            left=mid+1;
    }
    if(key>=arr[len-1])
        left++;

    return left;

}

int main()
{
   int n,inser;
   while(scanf("%d%d",&n,&inser),n!=0||inser!=0){
        int arr[100];
        for(int i = 0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        int len = n;
        int arr02[100];
        int rep=binary_insert(arr,len,inser);//接收元素要插入的位置

   for(int i=0;i<len+1;i++){
        if(i<rep){
            arr02[i]=arr[i];
        }
        if(i==rep)
            arr02[i]=inser;//将元素插入指定位置

        if(i>rep){
            arr02[i]=arr[i-1];
        }
   }
    for(int i=0;i<len+1;i++){
       printf("%d%c",arr02[i],i<len?' ':'\n');
       /* if(i!=0)
              printf(" ");
        printf("%d",arr02[i]);*/
    }
    //printf("\n");
   }
    return 0;

}
