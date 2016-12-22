#include <iostream>
#include <cstdio>
using namespace std;
/*
int f(int a,int b,int n){
    if(n==1||n==2)
        return 1;
    else
        return (a*f(a,b,n-1)+b*f(a,b,n-2))%7;
}
*/
static int a,b;
int f(int n){
    if(n==1||n==2){
        return 1;
    }
    if(n>2){
        return (a*f(n-1)+b*f(n-2))%7;
    }
}

int main()
{
    int n;
    while(scanf("%d%d%d",&a,&b,&n),a||b||n!=0){
          int value=0;
          //int t = 1;
          if(n==1||n==2)
                printf("%d\n",1);
          else{
          for(int i = 3;i<=n;i++){
            //t = i;
            value=f(i);
          }
          printf("%d\n",value);
          }
        //printf("%d\n",f(a,b,n));
    }
    //cout << "Hello world!" << endl;
    return 0;
}
