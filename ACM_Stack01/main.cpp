#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <list>
using namespace std;




int main()
{
    stack<int,list<int> >a;//默认是deque现在是用list实现的栈 元素类型是int
    stack<int,vector<int> > b;//默认是deque现在是用vector实现的栈 元素类型是int

    int i;
    //雅茹数据
    for(int i=0;i<10;i++){
        a.push(i);
        b.push(i*i);
    }
    //栈的大小
    printf("出栈前：\na.size:%d\nb.size:%d\n",a.size(),b.size());
    printf("a[0]:%d",a.top());
    //打印栈内元素
    while(!a.empty()){
        printf("a栈顶元素：%d\n",a.top());
        a.pop();//出栈
    }
    putchar('\n');

    while(!b.empty()){
        printf("b栈顶元素：%d\n",b.top());
        b.pop();
    }
    putchar('\n');
    printf("出栈后：\na.size:%d\nb.size:%d\n",a.size(),b.size());

    return 0;
}
