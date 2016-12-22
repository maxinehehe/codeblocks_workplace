/*
蒜头的数学实在是太差了，于是老师把他关到小黑屋让他闭门修炼。
老师跟他一张纸，上面一排写着1, 2, 3...N这N个数，中间用空白分隔。
老师让他在空白处填上加号或者减号。他让蒜头君求出一共有多少种加运算符的方法使得整个表达式的值为0，
并输出所有的方案。比如N=7时，1 2 3 4 5 6 7排成一排，一种插入符号的方案为1+2-3+4-5-6+7=0。
是不是很有趣，快来帮蒜头君解出这题吧(*´▽｀)

输入为一行，包含一个整数N（3≤N≤9）。

输出为所有在每对数字间插入“+”或“-”后能得到和为零的数列，并按照字典（ASCII码）序排列。
如果无解就输出一行None。不知道字典序和ASCII也不要紧，我们看样例输出就清楚啦，
1到N排成一排，先每个位置优先放"+"，再放"-"，这么放的原因是因为"+"的ASCII码要比"-"小。
*/

#include <bits/stdc++.h>
using namespace std;
int n; // 保存读入的整数N
bool opr[10]; // 可以用一个bool数组保存所有n-1个符号，我们用true表示加号"+"，用false表示减号"-"。
bool found = false; // 表示是否找到一组解，如果没找到的话需要在最后输出"None"
// dfs函数，保存两个状态：deep表示递归深度，就是枚举到第几个数字左边的符号；sum表示之前部分表达式的值。
// 如果枚举完成后sum的值刚好为0，则输出这组方案。我们需要在搜索的过程中用opr数组保存状态。
void dfs(int deep, int sum) {
    // 请在下面的条件表达式中填上对应的值。
    if (deep == (n-1)) {
        if (sum == 0) {
            found = true;
            // 请在下面将最终方案输出，方案格式参照题目描述。
            // 最后记得换行哦。



        }
        else{
            printf("None");
        }

        return ;
    }
    // 请在下面的语句中填出正确的逻辑。
    opr[deep] = true;//1.
    dfs( deep+1  , sum - n );
    opr[deep] = true;
    dfs(  deep+1 ,sum-n-1   );
}

// main函数请自己完成哦，加油~
int main() {
    scanf("%d",&n);
    return 0;
}