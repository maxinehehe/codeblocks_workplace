#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string,int> cnt;
vector<string> vec;

string repr(const string& s){//引用
    string ans = s;
    for(int i=0;i<ans.length();i++){//逐个遍历单词
        ans[i]=tolower(ans[i]);
        sort(ans.begin(),ans.end());
        cout<<"ans:"<<ans<<endl;
        return ans;
    }
}


int main()
{
    string s="ladder came tape soon leader acme RIDE lone Dreis peat\
 ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed\
noel dire Disk mace Rob dries";

    vec.push_back(s);
    string r = repr(s);
    cout<<"R:::r:"<<r<<endl;
    if(!cnt.count(r)) cnt[r]=0;
            cnt[r]++;


    cout << r << endl;

    vector <string>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
        cout<<*it<<endl;
    //cout<<"vec:"<<vec<<endl;
    return 0;
}
