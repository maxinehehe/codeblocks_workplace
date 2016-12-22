#include <iostream>

using namespace std;

//引用 在参数前面加一个& 即改变形参，实参也会发生改变
void swap2(int &a,int &b){
    int t = a;
        a = b;
        b = t;
}

int main()
{
    int a = 3,b = 4;
    swap2(a,b);
    cout << a <<" "<<b<< endl;
    return 0;
}
