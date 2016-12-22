/*
根据输入的半径值，计算球的体积。


Input
输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。


Output
输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。
*/

/*头文件math.h中宏定义的是M_PI
#define M_PI 3.14159265358979323846*/
#include <iostream>
#include<cstdio>
//#include<math.h>
//要求定义为3.1415927
#define PI 3.1415927
using namespace std;

int main()
{

   double r;
   double v;
   while(scanf("%lf",&r)!=-1){
        v = 4.0/3*PI*r*r*r;
        printf("%.3lf\n",v);
   }
    return 0;
}
