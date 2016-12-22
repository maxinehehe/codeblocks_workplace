#include <iostream>

using namespace std;


struct Point{
    int x,y;
    string b;
    Point(int x=0,int y=0):x(x),y(y){}

    void Init(){

        cout<<"我已初始化！--->x+y:"<<x+y<<endl;
    }


};

template <typename T>

T sum(T*begin,T*end){
    T* p = begin;
    T ands = 0;
    for(T *p = begin;p!=end;p++){
        ands = ands + *p;
    }
    return ands;
}

Point operator + (const Point& A,const Point& B){
    return Point(A.x+B.x,A.y+B.y);
}
Point operator += (const Point& A,const Point& B){
    return 0;
}

ostream& operator <<(ostream &out,const Point& p){
    out<<"("<<p.x<<","<<p.y<<")"<<endl;
    return out;
}


int main()
{
    double a[]={1.1,2.2,3.3,4.4,5.5,6.6,7.7};
    cout<<sum(a,a+7)<<endl;
    //char c[]={'L','i','u',' ','H','e','h','e'};
    //cout<<sum(c,c+8);
    string s="Liu Hehe";
    cout<<s<<endl;

    Point b[]={Point(1,2),Point(3,4)};
    cout<<sum(b,b+2)<<endl;

    return 0;
}
