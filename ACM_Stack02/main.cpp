//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <list>
//#include <stdafx.h>

using namespace std;

//vector封装数组，list封装了链表，map和set封装了二叉树等

typedef set<int> Set;
map<Set,int> IDcache;//把集合映射成ID
vector<Set> Setcache;//根据ID取集合

//查找指定集合x的ID.如果找不到，分配一个新的ID


int ID (Set x){
    //对于set而言 count可用于判断是否存在某个元素。因为set内元素不重复，count结果只会是1和0.
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x); //添加新集合。
    return IDcache[x] = Setcache.size() - 1;
}

#define ALL(X) x.begin(),x.end()
#define INS(X) inserter(x,x.begin())
int main()
{
    stack<int>s;
    int n;
    cout<<"n:";
    cin>>n;
    for(int i = 0;i < n;i++){
        string op;
        cout<<"op字符串:";
        cin>>op;
        if(op[0] == 'p') s.push(ID(Set()));//
        else if(op[0] == 'D') s.push(s.top());
        else{
            Set x1 = Setcache[s.top()];s.pop();
            Set x2 = Setcache[s.top()];s.pop();

            Set x;
           // if(op[0]=='U') set_union (ALL(x1),ALL(x2),INS(x));
            //if(op[0]=='I') set_intersection (ALL(x1),ALL(x2),INS(x));
            //if(op[0]=='A') {x = x2;x.insert(ID(x1));}
            s.push(ID(x));
        }
        cout<<Setcache[s.top()].size() <<endl;
    }
    return 0;
}
