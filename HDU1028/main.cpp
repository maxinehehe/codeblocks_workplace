   /*
    #include"stdio.h"
    #include"string.h"
    int main()
    {
        int n;
        int dp[130][130];
        int i,l;

        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        for(i=1;i<=130;i++)
        {
            dp[i][1]=1;
            dp[1][i]=1;
        }
        for(i=2;i<=120;i++)
        {
            for(l=2;l<=120;l++)
            {
                if(l>i)
                    dp[i][l]=dp[i][i];
                else if(l==i)
                    dp[i][l]=dp[i][l-1]+1;
                else
                    dp[i][l]=dp[i][l-1]+dp[i-l][l];
            }
        }


        while(scanf("%d",&n)!=EOF)
            printf("%d\n",dp[n][n]);


        return 0;
    }
    */
/*
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 121
int dp[maxn][maxn]={0};
int main()
{
    int i,j;
    for(i=1;i<=121;i++)dp[1][i]=dp[i][1]=1;
    for(i=2;i<121;i++)
    {
        for(j=2;j<=121;j++)
        {
            if(i<j) dp[i][j]=dp[i][i];
            else if(i==j)dp[i][j]=1+dp[i][j-1];
            else if(i>j) dp[i][j]=dp[i-j][j]+dp[i][j-1];
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF)printf("%d\n",dp[n][n]);
    return 0;
}
*/

    #include <stdio.h>

    int A[121][70];

    int main()
    {
        int n, i, j, k;
        for (k=1; k<=120; k++)
        {
            A[k][0] = 1;
            for (i=1; i<=k/2; i++)
            {
                for (j=i; j<=(k-i)/2; j++)
                    A[k][i] += A[k-i][j];
                A[k][i] += 1;
                A[k][0] += A[k][i];
            }
        }
        while (scanf("%d", &n) != EOF)
            printf("%d\n", A[n][0]);
        return 0;
    }
