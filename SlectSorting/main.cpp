#include <iostream>

using namespace std;
int slect_sorting(int arr[],int len){

    while(len--){
        int mini = arr[0];
        for(int i = 1;i<len;i++){
            if(arr[i]<mini){
                mini = arr[i];
            }
            swap(arr[len],mini);
        }
    }
    for(int i=0;i<len;i++){
       printf("%d",arr[i]);

    }
}

int main()
{
    int arr[]={3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int length = sizeof(arr)/sizeof(int);
   //µ÷ÓÃº¯Êý
    slect_sorting(arr,length);
    return 0;
}
