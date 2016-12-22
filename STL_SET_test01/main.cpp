#include <iostream>
#include <set>
using namespace std;

set<string> str;
set<int> in;
int main()
{
    in.insert(4);
    in.insert(88);
    in.insert(26);
    in.insert(10);
    //set内部会自动排序
    set<int>::iterator it;
    for(it=in.begin();it!=in.end();it++)
        cout<<*it<<"\n";
    return 0;
}
