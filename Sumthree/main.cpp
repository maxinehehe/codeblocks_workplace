/*
A+B for Input-Output Practice (III)

*/
#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    int a,b,sum=0;
    while((scanf("%d%d",&a,&b)!=-1)&&(a!=0||b!=0)){// ||ÊÇ¹Ø¼ü
        sum = a+b;
        printf("%d\n",sum);
    }
    return 0;
}
