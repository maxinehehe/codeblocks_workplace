#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=-1){
        long sum=0;
        for(int i=1;i<=n;i++){
            sum += i;
        }
        printf("%ld\n\n",sum);
    }
    return 0;
}
