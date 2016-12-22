
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int digit_root(int n){
    int t=0;
    while(n>0){
        t+=n%10;//取个位
        n/=10;//去个位
    }
    return t;
}

int main(){
    char s[10000];
    int sum;
  while(scanf("%s",s)!=EOF,s[0]!='0'){
    sum=0;
    for(int i=0;s[i]!='\0';i++){
        sum+=s[i]-'0';//'0'表示字符串的0
    }
        while(sum>9){
            sum=digit_root(sum);
        }
        printf("%d\n", sum);
  }
    return 0;
}







/*
#include <iostream>
#include <cstdio>
using namespace std;

int digit_root(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;//取个位
        n/=10;//去个位
    }
    return sum;
}

int main()
{
    int n;
    while(scanf("%d",&n),n){
        int ac=digit_root(n);
        while(ac>9){
            ac=digit_root(ac);
        }
        printf("%d\n", ac);
    }

    return 0;
}
*/


/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int del(int a)
{
    int b=0;
    while(a>0)
    {
       b+=a%10;
       a/=10;
    }
    return b;
}
int main()
{
    char s[1003];
    int i;
    int a;
    while(scanf("%s",s),s[0]!='0')
    {   a=0;
       for(i=0;s[i]!='\0';i++)
          a+=s[i]-'0';
        while(a>9)
        {
            a=del(a);
        }
        printf("%d\n",a);
    }
    return 0;
}
*/
