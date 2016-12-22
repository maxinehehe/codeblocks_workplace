/*
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。


Input
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。


Output
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。


Sample Input

0 1
0 0



Sample Output

OK



Author
lcy

*/
#include <iostream>
#include<cstdio>
using namespace std;
//该数除了1和它本身以外不再有其他的因数；否则称为合数。
bool is_or(int num){

    for(int i = 2;i < num; i++){
        if(num%i==0)
            return false;
    }

    return true;

}


int main()
{
    int x,y;
/*
    while(scanf("%d",&x)!=-1){
        if(is_or(x))
            printf("是素数！\n");
        else
            printf("不是素数！\n");
    }
    */

    while(scanf("%d%d",&x,&y),x!=0||y!=0){
        int sum = 0;
        int count = 0;
        for(int n = x;n <= y;n++){
            sum = n*n + n + 41;
            if(is_or(sum))
                count += 1;
            else
                break;
        }
        if(count ==(y-x+1))
            printf("OK\n");
        else
            printf("Sorry\n");
    }

    return 0;
}
