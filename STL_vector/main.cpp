#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*
测试sort和lower_bound()
int main()
{
    int a[100],x,y,q;
    printf("数组长度：");
    scanf("%d",&x);
    printf("输入一个数组：\n");
    for(int i=0;i<x;i++)
        scanf("%d",&a[i]);
    sort(a,a+x);
    for(int i=0;i<x;i++)
        printf("%d%c",a[i],i<x-1?' ':'\n');
    int index01 = lower_bound(a,a+x,20)-a;
    int index02 = lower_bound(a,a+x,18)-a;
    //for(int i=0;i<x;i++)
     //   printf("%d%c",a[i],i<x-1?' ':'\n');
    printf("20:%d\n18:%d\n",index01,index02);
    return 0;
}

*/

//vector就是一个不定长数组
//template <typename T>
int main(){
    vector<int> vec,vec2;
    vec2.push_back(48);
    vector<int>vec3(4,50);//创建一个含有4个50的vector.
    vector<int> vec01(50);//创建一个500个元素的vector
    vector<int> vec02(50,int(7));//创建500个元素的vector并都初始化为123


    for(int i=0;i<10;i++)
        vec.push_back(i);

    printf("vec.capacity:%d\n",vec.capacity());
    printf("(5)at索引为5的数:%d\n",vec.at(5));
    printf("front第一个元素:%d\n",vec.front());
    printf("front最后一个元素:%d\n",vec.back());
    //vec.insert(1,100);
    vec.push_back(123456);//在尾部增加一个元素
    printf("vec元素个数：%d\n",vec.size());
    printf("vec容纳最大尺寸：%d\n",vec.max_size());
   vec.swap(vec2);//1.互换vec1和vec2元素
   swap(vec,vec2);//2.等价于上面 1
    vector<int>(vec).swap(vec);//此步骤可以有效利用空间 去除多余空间
    printf("vec.capacity:%d\n",vec.capacity());
    printf("vec2.capacity:%d\n",vec2.capacity());


    vector<int>::iterator it,it2;
    printf("vec:");
    for(it=vec.begin();it!=vec.end();it++)
        printf("%d ",*it);
    printf("\nvec3_size:%d\n",vec3.size());
    printf("vec3:");
   // vector<int>::iterator it2;
    for(it2=vec3.begin();it2!=vec3.end();it2++)
        printf("%d ",*it2);
    printf("\nvector<int> vec01(50)：");
    for(it2=vec01.begin();it2!=vec01.end();it2++)
        printf("%d ",*it2);

    printf("\nvector<int> vec02(50,int(123))：");
    for(it2=vec02.begin();it2!=vec02.end();it2++)
        printf("%d ",*it2);


    //测试erase 其是迭代类型
    for(it=vec.begin();it!=vec.end();it++){
        if((*it)==10){//次序会改变 删除10
            it2=it;
            vec.erase(it2);
            }
    }

    printf("\nvec:");
    for(it=vec.begin();it!=vec.end();it++)
        printf("%d ",*it);


    return 0;
}
