#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int T,n,a[1001];//a[0]=0;
   scanf("%d",&T);
   while(T){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<n;i++){
            int temp=a[i];
            int j=i-1;
            for(;j>=0&&temp<a[j];j--)
                a[j+1]=a[j];
            if(a[i]!=temp)
                swap(a[j+1],temp);
        }

        for(int i=0;i<n;i++){
            printf("%d%c",a[i],i<n-1?' ':'\n');
        }
        T--;
   }
    return 0;
}
