#include <stdio.h>
#include <stdlib.h>

#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<limits.h>
#include<io.h>
#include<math.h>//abs()...add()...
#include<process.h>//exit()

#define TRUE    1
#define FALSE   0
#define  OK     1
#define  ERROR  0
#define INFEASIBLE  -1

#define INFINITY INT_MAX //用来表示无穷大
#define max_Vertex_num 20  //最大只允许有20个顶点

typedef int VRType;//权值类型
typedef char InfoType;/*相关信息类型*/
typedef char VertexType;
typedef int status;

/*------顶点的信息-----------------*/
typedef struct ArcCell{
    VRType adj;//顶点

   // InfoType *info;

}ArcCell,AdjMatrix[max_Vertex_num][max_Vertex_num];//matrix矩阵

/*------边和弧的关系信息-----------------*/
typedef struct {
    VertexType vexs[max_Vertex_num]; //顶点向量
    AdjMatrix arcs; //邻接矩阵
    int vexnum,arcnum; //图的当前顶点数和弧数
}MGraph;
status CreatUDN(MGraph *G);
status LocateVex(MGraph *G,VertexType v);
//void InputInfo(char ifo);

status CreatUDN(MGraph *G){
//采用数组(邻接矩阵)构建无向网
int i,j,k;

G = (MGraph *)malloc(sizeof(MGraph));
//G->vexs=(VertexType )malloc(sizeof(int));
//G->arcs = (AdjMatrix **)malloc(sizeof(struct ArcCell));

printf("无向网\n");
printf("请输入顶点数、弧数:");  //弧相关信息:"
scanf("%d %d",&G->vexnum,&G->arcnum);//,&IncInfo);
printf("输入%d个顶点：\n",G->vexnum);
printf("提示:不间隔输入 #表示结束\n");
i=0;

do{
    G->vexs[i] = getchar();
    if(G->vexs[i]=='#'){//输入换行表示输入结束。
            G->vexs[i]='\0';//对该输入进行封装。
            break;
                }
                i++;
}while(1);
printf("----------------------");
for(i=0;G->vexs[i]!='\0';i++)
    printf("%c",G->vexs[i]);
/*
for(i=0;i<G->vexnum;i++) //G->vexs[i]=getchar();
    scanf("%s",&G->vexs[i]);

G->vexs[i]='\0';
*/





//for(i=0;i<G->vexnum;i++)printf("%c ",G->vexs[i]);

for(i=0;i<G->vexnum;i++)
    for(j=0;j<G->vexnum;j++){
        G->arcs[i][j].adj=0;

        //G->arcs[i][j].info=NULL;
        }//初始化{adj,info}

char v1,v2,v[10];
int w;

for(k=0;k<G->arcnum;k++){

printf("输入顶点1，顶点2，权值（不间隔输入，#表示结束）:\n");
i=0;
do{//循环输入样例
                v[i]=getchar();//………………………………………… 1.

                if(v[i]=='#'){//输入换行表示输入结束。
                        v[i]='\0';//对该输入进行封装。
                        break;
                            }
                       i++;
                    }while(1);

v1 = v[0];
v2 = v[1];
w = (int)v[2];
printf(":%d\n",w);


printf("v1:%c\nv2:%c\n",v1,v2);

//i = LocateVex(G,v1);  j = LocateVex(G,v2);


  //      G->arcs[i][j].adj = w;

    if(i!=-1&&j!=-1)
        if(i==-1)printf("%c顶点不存在！",v1);
        else if(j==-1)printf("%c顶点不存在！",v2);
        else printf("%c和%c顶点不存在！",v1,v2);




    //if(IncInfo)
        //InputInfo((*G).arcs[i][j].info);
      //  printf("输入相关信息省略。");

}

return 1;
}

void PrintGraph(MGraph *G){
    int i,j;
    int ilength=G->vexnum,jlength=G->arcnum;
    for(i=0;i<ilength;i++)
        printf("%c%c",G->vexs[i],i<ilength?'\t':'\n');
    for(i=0;i<ilength;i++){
        printf("%c\t",G->vexs[i]);
    for(j=0;j<ilength;j++){
        printf("%d\t",G->arcs[i][j].adj);
        }
    }
}


status LocateVex(MGraph *G,VertexType v){
    int i;
    for(i=0;i<G->vexnum;i++)
        if(strcmp(G->vexs[i],v)==0)
            return i;
    return -1;
}



int main()
{

    MGraph *G=NULL;
    CreatUDN(G);
    PrintGraph(G);
    printf("Hello world!\n");
    return 0;
}
