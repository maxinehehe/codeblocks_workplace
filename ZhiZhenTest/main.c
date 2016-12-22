#include <stdio.h>
#include <stdlib.h>

int main()
{
   char cShuJu1='A',cShuJu2='V',*cpZiFu;
   int it1=90,it2=100,*ipt1=&it1,*ipt2=&it2;
   int t=*ipt2-*ipt1;
   printf("(*ipt2-*ipt1):%d\n",t);


   cpZiFu=&cShuJu1;
   printf("\ncpZiFu=%X,*cpZiFu=%c",cpZiFu,*cpZiFu);
   cpZiFu=&cShuJu2;
   printf("\ncpZiFu=%X,*cpZiFu=%c",cpZiFu,*cpZiFu);

    return 0;
}
