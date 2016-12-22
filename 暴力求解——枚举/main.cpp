#include <iostream>
#include <cstdio>
using namespace std;
/*
const int maxn = 10000;
void print_permutation(int n,int *A,int cur){
    if(cur==n){
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }
    else
        for(int i = 1;i<=n;i++){
        //从1开始
        int ok=1;
        for(int j = 0;j < cur;j++)
            if(A[j]==i)//检查A[]中是否有i
                ok=0;
        if(ok){
            A[cur]=i;
            print_permutation(n,A,cur+1);//递归调用
        }
        }
}

int main()
{

    int A[maxn];
    print_permutation(3,A,0);
    return 0;
}
*/


const int maxn = 10000;
void print_permutation(int n,int *A,int *p,int cur){
    if(cur==n){
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }
    else
        for(int i = 0;i<n;i++)
        if(!i||p[i]!=p[i-1]){//去重复
        //从1开始
        int c1=0,c2=0;
        for(int j = 0;j < cur;j++)
            if(A[j]==p[i])//检查A[]中是否有i
                c1++;
        for(int j=0;j<n;j++)if(p[i]==p[j]) c2++;
        if(c1<c2){
            A[cur]=p[i];
            print_permutation(n,A,p,cur+1);//递归调用
            }
        }
}

int main()
{

    int A[maxn];
    int p[]={1,2,3};
    //int p[]={1,1,1};
    print_permutation(3,A,p,0);
    return 0;
}
