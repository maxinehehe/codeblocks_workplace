#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct BitNode{
    ElementType data;
    struct BitNode* lchild;
    struct BitNode* rchild;
};

struct BitNode *BitCreat();
void PreOrder(struct BitNode* bt);

struct BitNode *BitCreat(){
    struct BitNode * bt = NULL;
    char ch;
    if((ch=getchar())=='#'){
        return NULL;
    }
    else{
            //此处忘了最重要的一步：生成结点
        bt=(struct BitNode*)malloc(sizeof(struct BitNode));//递归时也要生成结点
        bt->data=ch;
        bt->lchild = BitCreat();
        bt->rchild = BitCreat();
        return bt;
    }

}

//前序遍历
void PreOrder(struct BitNode* bt){
    if(bt){
        printf("%c",bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}






int main()
{
    struct BitNode *bt=NULL;
    bt = BitCreat();
    PreOrder(bt);
    return 0;
}
