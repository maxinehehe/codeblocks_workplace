#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
   string line;
   while(getline(cin,line)!=0){
    double sum = 0,x;
    stringstream ss(line);
    while(ss >> x)//рт©у╦Я╩╨ЁЖ
        sum += x;
    cout<<sum<<endl;
   }
    return 0;
}
