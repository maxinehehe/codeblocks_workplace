#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s[10000];
    int sum;
  while(scanf("%s",s)!=EOF,s[0]!='0'){
    sum=0;
    for(int i=0;s[i]!='\0';i++)
        sum=sum*10+s[i]-'0',sum=sum%9;//'0'表示字符0 /48
    if(sum==0) sum=9;
    printf("%d\n",sum);
  }
    return 0;
}

