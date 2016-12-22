#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int N,M;
    int sc;
  scanf("%d",&N);
  while((N--)!=0){
    scanf("%d",&M);
    int sum=0;
    for(int i = 0;i<M;i++){
        scanf("%d",&sc);
        sum += sc;
    }
    if(N>=1)
    printf("%d\n\n",sum);
    else
        printf("%d\n",sum);
  }
    return 0;
}
