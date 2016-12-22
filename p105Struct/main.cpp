#include <iostream>
#include <stdio.h>

using namespace std;

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}// == {this->x=x;this->y=y;}
    void test(int t){//this->t=t;
    printf("我们拿到了%d\n",t);
    }
};


Point operator - (const Point &A,const Point &B){//operator 操作符 表示要重定义操作符
    return Point(A.x+B.x,A.y+B.y);
}//可以把“-”变成“+”的功能

//定义操作符后好要匹配 流
ostream& operator << (ostream &out,const Point &p){
out<<"【"<<p.x <<","<<p.y<<"】";
return out;
}


int main()
{
    Point a,b(1,2);//a=1,b=2;
    //==分别调用了Piont()和point(1,2);
    a.x = 3;
    cout<<a-b<<"\n";
    a.test(20);
    return 0;
}






