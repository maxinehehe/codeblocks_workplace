#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BinTNode,*BinTree;
//typedef BinTNode *BinTree;

//struct node == BinTNode;
//struct node * == BinTree;

BinTree CreatBinTree(void);//返回根节点 针对先序遍历创建的二叉树

void Preorder(BinTree T);//先序遍历

void Inorder(BinTree T);//中序

void Postorder(BinTree T);//后序

//采用后序遍历求二叉树的深度，结点个数以及叶子数的递归算法。
int CountLeaf(BinTree T,int *count);//统计二叉树中叶子结点的个数
int LeafNodes(BinTree T);




#define OK 1;
#define ERROR 0;


//# 以示空指针的位置
BinTree CreatBinTree(void){//返回根节点 针对先序遍历创建的二叉树
	BinTree T;
	char ch;
	if((ch=getchar())=='#')
		return NULL;//读入# 返回空指针
	else{
		T = (BinTNode *)malloc(sizeof(BinTNode));//生成节点
		//T = (BinTNode *)malloc(sizeof(BinTNode)) == T = (BinTree)malloc(sizeof(BinTNode))
		T->data = ch;
		T->lchild = CreatBinTree();//构建左子树
		T->rchild = CreatBinTree();//构建右子树
		return T;
	}


}

void Preorder(BinTree T){//先序遍历
	if(T){
		printf("%c",T->data);
		Preorder(T->lchild);
		Preorder(T->rchild);
	}



}
void Inorder(BinTree T){//中序


	if(T){

		Inorder(T->lchild);
		printf("%c",T->data);
		Inorder(T->rchild);
	}




}

void Postorder(BinTree T){//后序

	if(T){
		Postorder(T->lchild);
		Postorder(T->rchild);
		printf("%c",T->data);
	}

}


int CountLeaf(BinTree T,int *count){

    if(T){
        if ((T->lchild ==NULL)&&(T->rchild ==NULL)){
             *count++;
             //printf("*count:%d\n",*count);
            return OK;
            }
         CountLeaf(T->lchild, &count);
                    // 统计左子树中叶子结点个数
         CountLeaf(T->rchild, &count);
                   // 统计右子树中叶子结点个数
        //printf("*count:%d\n",*count);
       }
   else
        return ERROR;

}


int LeafNodes(BinTree T)
{
    int num1,num2;
    if(T==NULL)
    return 0;
    else if(T->lchild==NULL && T->rchild==NULL)
    return 1;
    else
    {
        num1=LeafNodes(T->lchild);
        num2=LeafNodes(T->rchild);
        return (num1+num2);
    }
}






int main(){
	BinTree root;
	int i,depth;
	int getcount=0;
	int *count;
	count=&getcount;

	printf("\n");
	printf("Creat Bin_Tree; \nInput Preorder:");

	root = CreatBinTree();//创建二叉树，返回根结点

	do{

		printf("\t************select**************\n");
		printf("\t1:Preorder Traversal\n");
		printf("\t2:Inorder Traversal\n");
		printf("\t3:Postorder Traversal\n");
		printf("\t4:PostTreeDepth,Node number,Leaf number\n");
		//
		printf("\t0:Exit\n");
		printf("\t********************************\n");
		scanf("%d",&i);

		switch(i){
		case 1: printf("Printf BinTree Preorder: ");
				Preorder(root);
				printf("\n");
				break;

		case 2: printf("Printf BinTree Inorder: ");
				Inorder(root);
				printf("\n");
				break;

		case 3: printf("Printf BinTree Postorder: ");
				Postorder(root);
				printf("\n");
				break;


		case 4:printf("Printf BinTree Leafs: ");//实现树的叶子结点数
				//CountLeaf(root,&count);
				printf("count:%d\n",LeafNodes(root));
				//printf("getcount:%d\n",getcount);

				break;


		default:exit(1);
		}
		printf("\n");

	}while(i!=0);


	return 0;
}
