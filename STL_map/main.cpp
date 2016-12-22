#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;
//标准化单词
string repr(const string& s){//引用
    string ans = s;
    for(int i=0;i<ans.length();i++){//逐个遍历单词
        ans[i]=tolower(ans[i]);
        sort(ans.begin(),ans.end());
        return ans;
    }
}

int main()
{
    int n=0;
    string s;
    while(cin>>s){
        if(s[0]=='#')
            break;
          /*s="ladder came tape soon leader acme RIDE lone Dreis peat\
 ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed\
noel dire Disk mace Rob dries";*/
        words.push_back(s);
        string r = repr(s);
        cout<<"R:::r:"<<r<<endl;
        if(!cnt.count(r)) cnt[r]=0;
            cnt[r]++;
            cout<<"cnt[r]:"<<cnt[r]<<endl;
            cout<<"r:"<<r<<endl;
     }
    vector<string> ans;
    for(int i=0;i<words.size();i++)
        if(cnt[repr(words[i])]==1)ans.push_back(words[i]),
            cout<<"repr(words[i]):"<<repr(words[i])<<endl,
            cout<<"word[i]:"<<words[i]<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"\n";


    return 0;
}
