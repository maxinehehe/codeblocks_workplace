#include <iostream>
#include <set>

using namespace std;

int main()
{
    int a[] = {1,2,3,56};
    set<int> s(a,a+4);//还可以这样赋值。
    for(int i=2;i<50;i++)
        s.insert(i);

    set<int>::iterator iter;
    set<int>::iterator it1;
    set<int>::iterator it2;

    if((iter = s.find(2)) != s.end())
    {
        cout<<"find(2):"<<*iter<<endl;
    }
    //set的最大尺寸
    cout<<"size:"<<s.size()<<endl;

    cout<<"max_size:"<<s.max_size()<<endl;

    cout<<"count(3):"<<s.count(3)<<endl;//set不重复的特性 相当于判断是否出现。
    cout<<"count(20):"<<s.count(200)<<endl;

     pair<set<int>::const_iterator,set<int>::const_iterator> pr;
    pr = s.equal_range(3);
    cout<<"第一个大于等于 3 的数是 ："<<*pr.first<<endl;
    cout<<"第一个大于 3的数是 ： "<<*pr.second<<endl;

    for(it1=s.begin();it1!=s.end();it1++)
        cout<<*it1<<" ";

    cout<<endl;

//lower_bound(key_value) ，返回第一个大于等于key_value的定位器
//upper_bound(key_value)，返回最后一个大于key_value的定位器
//定位器 需要指针
    cout<<"low_bound(10):"<<*s.lower_bound(10)<<endl;//返回元素地址
    cout<<"upper_bound(10):"<<*s.upper_bound(10)<<endl;


    return 0;
}
