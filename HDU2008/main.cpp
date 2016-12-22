#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    double t;
    while(scanf("%d",&n),n){
        int a=0;//负数
        int b=0;//零
        int c=0;//正数
        for(int i = 0;i<n;i++){
            scanf("%lf",&t);
            if(t<0) a += 1;
            if(t==0) b += 1;
            if(t>0) c += 1;
        }
        printf("%d %d %d\n",a,b,c);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
