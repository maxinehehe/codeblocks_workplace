/*
Problem Description
Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.

This year, they decide to leave this lovely job to you.


Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.

A test case with N = 0 terminates the input and this test case is not to be processed.


Output
For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.


Sample Input

5
green
red
blue
red
red
3
pink
orange
pink
0



Sample Output

red
pink
*/

//高能警醒
//不要用C++/C混输 很容易出现CE
#include <iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    int n,maxValue;
    map<string,int>airBall;
    string color,maxColor;
    while(cin>>n,n!=0){
        airBall.clear();//map清空
        while(n--){
            cin>>color;
            airBall[color]++;//表示键对应的值++
        }
        map<string,int>::iterator it;
        maxValue=0;
        for(it=airBall.begin();it!=airBall.end();it++){
            if(it->second>maxValue){
                maxValue=it->second;
                maxColor=it->first;
            }
        }
       // printf("%s\n",maxColor);
       cout<<maxColor<<endl;
    }

    return 0;
}
