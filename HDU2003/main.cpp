#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    double d;
    while(scanf("%lf",&d)!=-1){
        printf("%.2lf\n",fabs(d));
    }
    //cout << "Hello world!" << endl;
    return 0;
}
