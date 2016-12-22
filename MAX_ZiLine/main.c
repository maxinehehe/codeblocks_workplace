#include <stdio.h>
#include <stdlib.h>

int MaxSubseqSum1(int A[],int n){
    int thisSum,maxSum=0;
    int i,j,k;
    for( i=0;i<n;i++){
        for(j=i;j<n;j++){
            thisSum=0;
            for( k=i;k<=j;k++)
                thisSum+=A[k];

            if(thisSum>maxSum)
                maxSum=thisSum;

        }
    }
    return maxSum;
}
//时间复杂度O(n3次方)

int MaxSubseqSum2(int A[],int n){
    int thisSum,maxSum=0;
    int i,j;
    for(i=0;i<n;i++){
            thisSum=0;
        for(j=i;j<n;j++){
            thisSum+=A[j];
        if(thisSum>maxSum)
            maxSum=thisSum;
        }
    }

    return maxSum;
}
//时间复杂度O(n2次方)

int MaxSubseqSum3(int A[],int n){
    int thisSum=0,maxSum=0;
    int i;
    for(i=0;i<n;i++){
        thisSum+=A[i];
        if(maxSum<thisSum)
            maxSum=thisSum;
        else if(thisSum<0)
            thisSum=0;
    }
    return maxSum;
}

int main()
{
    int a[]={4,-3,5,-2,-1,2,6,-2};
    int a2[]={4,5,6,7,8};
    int t=MaxSubseqSum1(a,8);
    int t2=MaxSubseqSum2(a,8);
    int t3=MaxSubseqSum3(a,8);
    printf("%d\n",t);
    printf("%d\n",t2);
    printf("%d\n",t3);
    return 0;
}
//         3         5    Good Choice
