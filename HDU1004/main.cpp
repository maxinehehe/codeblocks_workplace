#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n),n!=0){
        int i=0;
        int reme[20];
        char c[20][15];
        do{
        scanf("%s",&c[i]);
        //puts(c[i]);
        }while(i++!=(n-1));
    //printf("i:%d\nn:%d\n",i,n);
    int count[20];
    for(int j=0;j<n-1;j++){
            count[j]=1;
        for(int i=0;i<n-1;i++){
            if(strcmp(c[j],c[i])==0){
                if(j>i){
                    count[j]++;
                }
            }
        }
    }

    }

    return 0;
}
