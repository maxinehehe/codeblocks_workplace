/*
给定一个日期，输出这个日期是该年的第几天。


Input
输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，
具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。


Output
对于每组输入数据，输出一行，表示该日期是该年的第几天。

Sample Input

1985/1/20
2006/3/12



Sample Output

20
71

if(year%400 == 0 || year%100 != 0 && year % 4 == 0)是瑞年
*/
#include <iostream>
#include<cstdio>
#include<cstring>
//#include<string.h>
using namespace std;

int is_runYear(int year){
    if(year%400 == 0|| year %100 !=0 && year % 4 == 0)//闰年366
        return true;
    else
        return false;
}
int main()
{
int year,mon,day;
int monA[]={1,3,5,7,8,10,12};
int monB[]={4,6,9,11};
while(scanf("%d/%d/%d/",&year,&mon,&day)!=-1){
        int count=0;

               count += day;

                for(int i = 1;i<mon;i++){
                        if(i==2) {
                            if(is_runYear(year))
                                count += 29;
                            else
                                count +=28;
                        }
                        for(int j=0;j<7;j++){
                            if(i==monA[j])
                                count += 31;
                        }
                        for(int j = 0;j<4;j++){
                            if(i==monB[j])
                                count += 30;
                        }

                    }

     printf("%d\n",count);
}

    return 0;
}
