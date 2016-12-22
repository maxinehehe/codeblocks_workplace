#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n),n!=0){
        int num[100];
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }

        for(int i = 0;i<n-1;i++)
        for(int j= 0;j<n-i-1;j++){
            int t1 = abs(num[j]);
            int t2 = abs(num[j+1]);
            if(t1<t2)
                swap(num[j],num[j+1]);

        }
        for(int i=0;i<n;i++){
            printf("%d%c",num[i],i<n-1?' ':'\n');
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
