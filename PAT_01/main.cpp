#include <iostream>
#include <cstdio>
using namespace std;

int maxSumSe(const int arr[],int n){
    int thisSum,maxSum,j;
    thisSum=maxSum=0;
    for(int j=0;j<n;j++){
        thisSum +=arr[j];

        if(thisSum>maxSum)
            maxSum=thisSum;
        else if(thisSum<0)
            thisSum=0;
    }
    return maxSum;
}

int main()
{
    int k,t,coun;

    while(scanf("%d",&k)!=-1){
      int arr[k];
        //coun=k;
    for(int i=0;i<k;i++){
        scanf("%d",&t);
        arr[i]=t;
    }
    int len=sizeof(arr)/sizeof(int);
    printf("%d\n",maxSumSe(arr,len));
    }
    return 0;
}
