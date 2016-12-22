#include <iostream>
#include <cstdio>
#include <vector>
#define m 100
using namespace std;

int main()
{
    vector<int>v;
    int n;
    cout<<"n:";
    while(cin>>n,n){
        //cout<<n<<endl;;
        v.clear();
       // v.resize(50);

        for(int i=0;i<n;i++)
            v.push_back(i);//追加元素

            v.pop_back();//删除元素
            cout<<"v.at(0):"<<v.at(0)<<endl;//at(x);返回第x个元素。
            cout<<"v.back:"<<v.back()<<endl;//返回最后一个元素。
            cout<<"v.empty:"<<v.empty()<<endl;//集合是否为空。
            //v.erase(4);

        cout<<"v.max_size():"<<v.max_size()<<endl;//所能开辟的最大空间。

        //
        vector<int>::iterator it;//调用迭代器

            //insert(),erase()等需要和迭代器联合使用。如下：
            it=v.begin();
            v.insert(it+28,482);//在28个位置插入482.

        for(;it!=v.end();it++)
            cout<<*it <<" ";
        cout<<"\n"<<endl;
            it=v.begin();

            v.erase(it+10);//删除第10个元素。

            v.erase(it+11,v.end());//从11开始删除到截止。
        for(;it!=v.end();it++)
            cout<<*it <<" ";

        cout<<"\nv[2]: 1"<<v[2]<<endl;
        cout << "\n容器 大小为: " << v.size() << endl;//元素个数
        cout << "容器 容量为: " << v.capacity() << endl;//总容量大小（含未使用空间）
        //cout<<v.resize(50)<<endl;
        //cout<<v.size()<<endl;

        /* 测试effective stl中的特殊的交换 swap() */

        //关闭掉多余的空间
        vector<int>(v).swap(v);

        cout << "临时的vector<int>对象 的大小为: " << (vector<int>(v)).size() << endl;
        cout << "临时的vector<int>对象 的容量为: " << (vector<int>(v)).capacity() << endl;
        cout << "交换后，当前vector 的大小为: " << v.size() << endl;
        cout << "交换后，当前vector 的容量为: " << v.capacity() << endl;
    }

    return 0;
}
