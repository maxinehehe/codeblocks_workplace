#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    /*
    //<stdio.h>的sprintf测试(s,%d,n) n按照%d的格式转换成s
    int n = 100000;
    char s[10];
    sprintf(s,"%d",n);
    //容易发生错误例如sprintf(s,"%f",n);
    puts(s);
    */


    //<sstream>测试
    string result = "10000",result2="100 001";
    int n = 0,n2=0;
    stringstream stream(result);
    stringstream stream2(result2);//以空格缓出 若要缓出完毕 需用循环
    stream>>n;

    cout<<"n:"<<n<<endl;

    //stream2>>n2;
    //cout<<"n2:"<<n2<<endl;
    //结果：100
    cout<<"n2:";
    while(stream2>>n2)
        cout<<n2;



    return 0;
}
