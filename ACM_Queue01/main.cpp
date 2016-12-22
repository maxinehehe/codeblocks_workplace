#include <iostream>
#include <cstdio>
#include <queue>
#include <list>

using namespace std;

int main()
{
    queue<int>q1;

    for(int i=0;i<10;i++)
        q1.push(i);
    cout<<"q1.size:"<<q1.size()<<endl;
    while(!q1.empty()){
    cout<<"front:"<<q1.front()<<endl;
    //cout<<"back:"<<q1.back()<<endl;
    q1.pop();
    }
    return 0;
}
