#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int T,n,a1,maxDays,minRMB;
double m;
char c[101];
int main()
{
    map<string,int>s;
    map<string,double>s2;


    string cheapestMilk;
    cin>>T;
    while(T--){//scanf("%d",&T)

        cin>>n;//scanf("%d",&n)
        maxDays = 0;
        minRMB = 10000;
        for(int i=0;i<n;i++){
            cin>>c>>a1>>m;
            s2[c] = a1;//p
            s[c] = m;//y
        }

       map<string,int >::iterator it;
       map<string,double>::iterator it2;


       for(it=s.begin(),it2=s2.begin();it!=s.end(),it2!=s2.end();it++,it2++){
            if(it->second/200>0){
                if((it->second)/200>=maxDays&&(it2->second)<minRMB){
                    cheapestMilk = it->first;//×î±ãÒËÅ£ÄÌÃû×Ö
                    maxDays = it->second/200;
                    minRMB = it2->second;//Ç®
                }
                if(it->second/200>5){

                }
            }
       }
        cout<<cheapestMilk<<endl;

    }
    return 0;
}
