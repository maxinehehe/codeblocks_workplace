#include <iostream>
#include <cstdio>
#include <cstring>
#include <time.h>
using namespace std;
clock_t s1,e1,s2,e2,s3,e3,s4,e4,s5,e5;
double duration;

//冒泡排序
void bubble_sort(int arr[],int len){
    for(int i=0;i<len-1;i++)
    for(int j=0;j<len-i-1;j++){
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
    }
}

//插入排序
void insert_sort(int arr[],int len){
    for(int i=1;i<len;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0&&temp<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}

//选择排序
void select_sort(int arr[],int len){
    for(int i=0;i<len-1;i++){
        int minindex=i;//标记下标
        for(int j=i;j<len;j++)
            if(arr[minindex]>arr[j])
                minindex=j;//记下下标即可

        if(minindex!=i)//下标如果被更改了，就交换。
            swap(arr[minindex],arr[i]);
    }

   return;
}

//快速排序
void quick_sort(int arr[],int low,int high){
    int l=low;
    int h=high;
    int key=arr[low];//定位key

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
    if(l>low) quick_sort(arr,low,l-1);
    if(h<high) quick_sort(arr,h+1,high);

}


//桶排序 注意初始化为0 下为改进版可排负数
void bucket_sort(int arr[],int len){
    int a[100000],t;
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++){
        //scanf("%d",&t);
        t=(arr[i]+9999);
        a[t]++;
    }
    for(int i=0;i<=(100000-1);i++)//仅仅用来遍历一下所有桶
    for(int j=1;j<=a[i];j++){//j=1是为了让j和空桶（数为0）比较的时候，排除掉空桶。
        printf("%d ",i-9999);//a[i]表示该桶放的数量，也即是循环打印的次数（同数的情况）
    }
    return ;
}

void print(int arr[],int len){
    for(int i=0;i<len;i++)
        printf("%d%c",arr[i],i<len-1?' ':'\n');

    //retrun;
}

int main()
{
    int arr[]={53,12,3,10,89,-46,51,-79,6,3,49,120,789,-987,789};
    //int arr[]={2,1,4,3,9,8};
    int len=sizeof(arr)/sizeof(int);
    print(arr,len);


    s1=clock();
    printf("桶排序：\n");//100以内桶排序效率优胜
       /* for(int i=0;i<100;i++){
        bucket_sort(arr,len);
         }*/
    bucket_sort(arr,len);
    e1=clock();
    double re=((double)(e1-s1))/CLK_TCK;
    printf("\n运行时间：%f\n",re);



    s2=clock();
    printf("\n快速排序：\n");
       /* for(int i=0;i<100;i++){//100意外快排效率优胜
        quick_sort(arr,0,len-1);
        }*/

    quick_sort(arr,0,len-1);
    print(arr,len);
    e2=clock();
    double re2=((double)(e2-s2))/CLK_TCK;
    printf("运行时间：%f\n",re2);


    s3=clock();
    printf("\n选择排序:\n");
    select_sort(arr,len);
    print(arr,len);
    e3=clock();
    double re3=((double)(e3-s3))/CLK_TCK;
    printf("运行时间：%f\n",re3);

    s4=clock();
    printf("\n插入排序:\n");
    insert_sort(arr,len);
    print(arr,len);
    e4=clock();
    double re4=((double)(e4-s4))/CLK_TCK;
    printf("运行时间：%f\n",re4);


    s5=clock();
    printf("\n冒泡排序:\n");
    bubble_sort(arr,len);
    print(arr,len);
    e5=clock();
    double re5=((double)(e5-s5))/CLK_TCK;
    printf("运行时间：%f\n",re5);

    return 0;
}
