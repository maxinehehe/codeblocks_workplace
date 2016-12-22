#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main()
{
   /*
   int a=4,b=50;
   int t=max(a,b);//=min(a,b);
   int t2=min(a,b);
   cout<<"最大值："<<t<<endl;
   cout<<"最小值："<<t2<<endl;
   */


  /*
   string line;
   while(getline(cin,line)){
    int sum=0,x;
    stringstream ss(line);
    while(ss >> x) sum += x;
    cout<<sum<<endl;
   }
   */

   int arr[]={5,4,6,8,3,89,46};
    int s=sizeof(arr)/sizeof(int);
   sort(arr,arr+s);

   for(int i=0;i<s;i++)
    printf("%d%c",arr[i],i<s-1?' ':'\n');

    int t=(int)lower_bound(arr,arr+s,3);
    printf("%d\n",&t);
    return 0;
}
