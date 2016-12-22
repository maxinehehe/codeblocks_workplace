#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[1000],b[1000],i=0;
/*
    for(i=0;b[i]!=0;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
*/
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
     do{
        scanf("%d%d",&a[i],&b[i]);
        i++;
    }while(b[i]!=0);

    i=-1;
    do{
        i++;
        a[i]=a[i]*b[i];
        b[i]--;
    printf("%d %d ",a[i],b[i]);

    }while(b[i]!=0&&a[i]!=0);
    printf("\n");
   /*
    do{
        scanf("%d%d",&a[i],&b[i]);
    }while(b[i]!=0);
    */
    return 0;
}
