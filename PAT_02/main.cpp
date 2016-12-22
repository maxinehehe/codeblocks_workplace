#include <iostream>
#include <cstdio>
using namespace std;



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

   int thisSum,maxSum,j;
    int f=0,l=0,last=0,sum=0;
    thisSum=maxSum=0;
    for(int j=0;j<len;j++){
        thisSum +=arr[j];

        if(thisSum>maxSum){
            maxSum=thisSum;
            last=j;
        }
       // if(thisSum>=maxSum&&arr[j==0])
        //    last=j;

        else if(thisSum<0)
            thisSum=0;
    }
    if(arr[last]>0)
        l=arr[last];

    else if(last==0&&maxSum==0){
            f=arr[0],l=arr[len-1];
            for(int i=0;i<len;i++)
                if(arr[i]>=0)
                    f=l=0;
    }
    else
        l=0;

    while(sum!=maxSum){
        f=arr[last];
        sum+=arr[last--];
    }
    if(last>0&&arr[last]==0)
        f=0;
    printf("%d %d %d\n",maxSum,f,l);
    }
    return 0;
}
