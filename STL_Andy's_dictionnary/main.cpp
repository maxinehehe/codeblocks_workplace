#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

set<string> dict;

int main()
{
    string s,buf;//buf为临时变量
    while(cin>>s){
        if (s=="EOF"||s=="eof")
            break;

        for(int i=0;i<s.length();i++){
            //cout<<"s[i]:"<<s[i]<<endl;
            if(isalpha(s[i]))//如果s[i]是字母
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        //此时再把s扫入流
        //cout<<s<<endl;
         stringstream ss(s);
         while(ss>>buf)
            dict.insert(buf);//set的insert会自动排序
    }
    //用迭代器遍历
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<*it<<endl;

    return 0;
}
