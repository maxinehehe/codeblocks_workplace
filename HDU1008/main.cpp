/*
Problem Description
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input
There are multiple test cases. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100. A test case with N = 0 denotes the end of input. This test case is not to be processed.


Output
Print the total time on a single line for each test case.

Sample Input

1 2
3 2 3 1
0

Sample Output

17
41
*/
#include <iostream>
#include<cstdio>
using namespace std;


int main()
{
    int n;
    int arr[101];
    int up=6,down=4,stay=5;
    int time;
    while(cin>>n,n){
       time=0;
       for(int i=0;i<101;i++)
            arr[i]=-1;
       for(int i=0;i<n;i++){
        cin>>arr[i];
       }
      for(int i=1;i<=n;i++){
        if(arr[i-1]>0&&(i-1)==0){
            time=up*arr[i-1]+stay;
        }
        if(arr[i]>arr[i-1]){
            time+=(arr[i]-arr[i-1])*up+stay;
        }
        else{
            if(arr[i]!=-1){
                time+=(arr[i-1]-arr[i])*down+stay;
            }
        }
      }

        cout<<time<<endl;
    }
    return 0;
}
