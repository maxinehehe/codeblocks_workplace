#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846
int main()
{
    float alpha = 0.361222;
    float sd = (0.45959-0.04)/(alpha+tan(180/39.7)) - 0.04;
    float d = 39.7f,r = -0.14884f;
    char s[100];
    cout<<"d->r:"<<d*(PI/180)<<endl;
    cout<<"r->d:"<<r*(180/PI)<<endl;
    cout<<"tan45du="<<tan(45*(PI/180))<<endl;
    cout << "Hello world!" << endl;
    float H = 0.45959f,L = 0.0664316f,phi=0.0f;
    //ÄÃµ½phi headPitch
    phi =  -0.328571f;
    sprintf(s,"%.3f",3.1456);
    float ta = tan(phi+(39.7*(PI/180)));
   // float s = (H - L/2)/ta;
    cout<<"s:"<<s<<endl;


    return 0;
}
