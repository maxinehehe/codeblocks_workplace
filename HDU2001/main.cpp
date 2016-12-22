#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
   double a,b,c,d;
   double cha;
   while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=-1){
        cha=(a-c)*(a-c)+(b-d)*(b-d);
       // cha = pow(a-c,2)+pow(b-d,2);
        cha=sqrt(cha);
        printf("%.2lf\n",cha);
   }
    return 0;
}

/*
楼主要注意阅读题目要求，题目的输入格式中明确说明了每组测例的输入是4个实数，
而不是4个整数，而楼主程序里是按照整型读入的。
scanf("%d", &n);这样的写法，在输入中有非数字和空格的字符出现时，
读入会失败，但不报错，也不会跳过失败处的字符。
所以楼主的程序在遇到第一个小数点的时候就一直重复输入最后一次正确读入的测例的结果了，最终造成输入超限。
影响程序效率的因素非常多，比如算法的效率，使用的数据结构等等，
这些要靠殷实的基础和不断的积累才能渐渐掌握，楼主想要学习的话可以先看看数据结构和算法类的书箱。
*/

