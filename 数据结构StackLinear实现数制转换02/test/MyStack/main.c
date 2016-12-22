#include <stdio.h>
#include <stdlib.h>
#include "Stack_Header.h"


int main()
{
    Stack S;
    int n,i;
    int e=0;
    S=InitStack();//初始化

    printf("输入一个10进制数：");
    scanf("%d",&n);
    printf("该数八进制形式：");
    convert10to8(S,n);
     printf("该数二进制形式：");
    convert10to2(S,n);
    /*

    printf("请输入一个数字：");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        Push(S,i);
    }

    //栈是否为空
    if(IsEmpty(S))printf("栈不为空.\n");
    else printf("栈为空！\n");

    //栈长
    printf("栈长：%d\n\n",StackLength(S));
    //for(i=0;i<n;i++)
        printf("取顶元素：%d\n\n",GetTop(S,e));

        for(i=0;i<n;i++)
            printf("出栈元素：%d\n",Pop(S,e));


        //清空栈
        ClearStack(S);
        //栈长
    printf("栈长：%d\n\n",StackLength(S));
        Pop(S,e);

         //栈是否为空
    if(IsEmpty(S))printf("栈不为空.\n");
    else printf("栈为空！\n");


    */


            //销毁栈
        //DestroyStack(S);

    return 0;
}
