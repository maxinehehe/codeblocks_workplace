#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    char c[1000],sta[10],ex[10];
    int i=0;

       while(gets(ex),strcmp("ENDOFINPUT",ex)!=0){
        do{
            i=0;
           do{

            c[i]=getchar();
            if(c[i]=='\n'){
                c[i]='\0';
                break;
            }
            if(c[i]>='A'&&c[i]<='Z'){
                  c[i]=c[i]-5;
                 if(c[i]<65)
                    c[i]='Z'-(65-c[i])+1;
                    /*
                c[i]=c[i]+5;
                if(c[i]>90)
                    c[i]='A'+(c[i]-91);*/
            }
            i++;
           }while(1);
                printf("%s\n",c);
            }while(gets(sta),strcmp("END",sta)!=0);

    }

    return 0;
}
