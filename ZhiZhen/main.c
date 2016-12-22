#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=5,*ipn=&n;
    //printf("n:%d\n&ipn:%d\n",n,&ipn);
    printf("ipn::%d\n&ipn::%d\n",ipn,&ipn);
    printf("*ipn:%d\n",*ipn);
    printf("n:%d\n&n:%d\n",n,&n);
    //printf("-----\n(*ipn):%d\n",*ipn);

    return 0;
}
