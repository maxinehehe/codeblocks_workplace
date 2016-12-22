#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <iterator>

using namespace std;

typedef set<int> Set;
map<Set,int> IDcache;//集合==ID
vector<Set>Setcache;//根据ID取集合

int ID(Set x){
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);//添加新集合
    return IDcache[x] = Setcache.size()-1;//元素个数
}

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())


int main()
{
    stack<int>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    string op;
    cin>>op;
    if(op[0]=='p') s.push(ID(Set()));
    else if(op[0] == 'D') s.push(s.top());
    else{
        Set x1 = Setcache[s.top()];s.pop();//相当于取走s.top
        Set x2 = Setcache[s.top()];s.pop();
        Set x;
        if(op[0]=='U') set_union (ALL(x1),ALL(x2),INS(x));//求并集
        if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
        if(op[0]=='A'){x = x2;x.insert(ID(x1));}
        s.push(ID(x));
    }
    cout<<Setcache[s.top()].size()<<endl;
    }
    return 0;
}
