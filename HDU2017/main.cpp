/*
对于给定的一个字符串，统计其中数字字符出现的次数。


Input
输入数据有多行，第一行是一个整数n，表示测试实例的个数，后面跟着n行，每行包括一个由字母和数字组成的字符串。


Output
对于每个测试实例，输出该串中数值的个数，每个输出占一行。


Sample Input

2
asdfasdf123123asdfasdf
asdf111111111asdfasdfasdf



Sample Output

6
9



Author
lcy
*/
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    char word[1000];
    scanf("%d",&n);
    while(n--!=0){
        scanf("%s",word);
        int count=0;
        int len=strlen(word);
       for(int i=0;i<len;i++){
            int integ=word[i];
            integ -= 48;
            if(integ>=0&&integ<=9){
                count +=1;
            }
       }
       printf("%d\n",count);
    }
    return 0;
}
