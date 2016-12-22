#include <iostream>

#define ADD(x,y,z) (x+y+z)/3
//感觉和python的lambda挺像的
using namespace std;

int main()
{
    cout<<"宏:"<<ADD(3,3,27)<<endl;
    return 0;
}
