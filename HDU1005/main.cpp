#include <iostream>
#include<cstdio>
using namespace std;
int arr[10000];
int main()
{
    int A,B,n;
    arr[1]=arr[2]=1;
    while(cin>>A>>B>>n,A!=0||B!=0||n!=0){
        int i;
        for(i=3;i<=1000;i++){
            arr[i]=(A*arr[i-1]+B*arr[i-2])%7;

            if(arr[i]==1&&arr[i-1]==1)
                break;
        }
        n=n%(i-2);
        //arr[0]=arr[i-2];
        cout<<arr[n]<<endl;
        //printf("%d\n",arr[n]);
    }
    return 0;
}
