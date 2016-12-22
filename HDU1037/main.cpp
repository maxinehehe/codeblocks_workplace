#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int h[3],wh=168;
   while(scanf("%d%d%d",&h[0],&h[1],&h[2])!=-1){
        if(h[0]>wh&&h[1]>wh&&h[2]>wh)
            printf("NO CRASH");
        else{
                printf("CRASH");
        for(int i=0;i<3;i++){
            if(h[i]<=wh){
                printf(" %d",h[i]);
            }
            //printf("%c",i<2?' ':'\n');
          }
        }
        printf("\n");
   }
    return 0;
}
