#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

set<string> dict;

int main()
{
    string s,buf;
    while(cin>>s){
            if(s=="EOF")
                break;
    //s=
    /*"Adventures in Disneyland \
Two blondes were going to Disneyland when they came to a fork in the road.\
The sign read: Disneyland Left.So they went home.";*/
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i])) s[i] = tolower(s[i]);//将其变为小写
            else s[i]=' ';
            //cout<<"s[i]:"<<s[i]<<endl;

        stringstream ss(s);
        while(ss>>buf)
            dict.insert(buf);
    }
    set<string>::iterator it;
    for(it=dict.begin();it!=dict.end();it++)
        cout<<*it<<endl;
    return 0;
}
