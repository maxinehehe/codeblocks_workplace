/*
A. Kefa and First Steps
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kefa decided to make some money doing business on the Internet for exactly n days. He knows that on the i-th day (1 ≤ i ≤ n) he makes ai money. Kefa loves progress, that's why he wants to know the length of the maximum non-decreasing subsegment in sequence ai. Let us remind you that the subsegment of the sequence is its continuous fragment. A subsegment of numbers is called non-decreasing if all numbers in it follow in the non-decreasing order.

Help Kefa cope with this task!

Input
The first line contains integer n (1 ≤ n ≤ 105).

The second line contains n integers a1,  a2,  ...,  an (1 ≤ ai ≤ 109).

Output
Print a single integer — the length of the maximum non-decreasing subsegment of sequence a.

Sample test(s)
input
6
2 2 1 3 4 1
output
3
input
3
2 2 9
output
3
Note
In the first test the maximum non-decreasing subsegment is the numbers from the third to the fifth one.

In the second test the maximum non-decreasing subsegment is the numbers from the first to the third one.


*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,t,lastNum,curCount,maxCount;
    bool f;
    while(cin>>n){
    	f=true;
        lastNum=maxCount=curCount=0;
        for(int i=0;i<n;i++){
            cin>>t;

            if(t>=lastNum){
                lastNum = t;
                curCount++;
            }
            else{
            	lastNum = t;
            	curCount = 1;
            }
            if(curCount>maxCount)
            	maxCount = curCount;
        }
        cout<<maxCount<<endl;
    }
    return 0;
}
