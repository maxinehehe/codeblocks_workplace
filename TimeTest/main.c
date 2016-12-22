#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start,stop;
/*clock_t是clock()函数返回的类型*/
double duration;

void myFunction(){
    int n=10000;
    while(n--){
        printf("%d ",n);
    }
    return ;
}

int main()
{
    start=clock();
    myFunction();
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK;
    printf("duration耗费时间%lf:\n",duration);
    return 0;
}
