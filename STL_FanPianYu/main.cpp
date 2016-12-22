#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;


string repr(const string& s){
    string ans = s;//不操作原文件
    for(int i=0;i<ans.length();i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s;
    while(cin>>s){
        if(s[0]=='#')
            break;
        //先保存一个备份
    words.push_back(s);
    string r = repr(s);//拆分排序

    if(!cnt.count(r))//如果不存在该钥匙
        cnt[r]=0;
    cnt[r]++;//存在则++
    }
    vector<string> save;
    set<string> words02;
    for(int i=0;i<words.size();i++){
       // cout<<words[i]<<endl;//ords[i]中存储每个输入的单词
       if(cnt[repr(words[i])]==1) //save.push_back(words[i]);//如果不能重排 (打乱后不存在) 就存进vector
            words02.insert(words[i]);
    }
   // sort(save.begin(),save.end());
    //for(int i=0;i<save.size();i++)
     //   cout<<save[i]<<endl;
     for(set<string>::iterator it=words02.begin();it!=words02.end();it++)
        cout<<*it<<endl;

    return 0;
}
