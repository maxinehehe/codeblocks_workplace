#include <iostream>

using namespace std;

bool test(int i,int j){  //用数组t存放i，j的各位数字

   int t[10]={0};  //初始化数组t，使得各位数字为0，好处是使得fghij<10000时f位置为0

   int ia = 0;

 while(i) {  //取i中各位数字存放在数组t中

      t[ia++] = i % 10;

      i = i / 10;

   }

while(j) {  //取j中各位数字存放在数组t中

      t[ia++] = j % 10;

       j = j / 10;

   }

//判断a～j是否恰好为数字的0～9的一个排列

   for(int m = 0; m < 10; ++m)

      for(int n = m+1; n < 10; ++n)

         if(t[n] == t[m])   return false;

  return true;

}

int main(){

   int n;

   int k;

   while(cin >> n && n >=2 && n <= 79) {

      k = 1234;

      while(k <= 98765) {

        int j = k * n;

        if(j < 100000) { //若fghij<10000，满足题目的条件，f位置输出0

           if(test(j,k)) {

              cout << j << "/" ;

              if(k < 10000)  cout <<"0";

              cout << k << "=" << n <<endl;

           }

        }

        ++k;

      }

   }

   return 0;

}
