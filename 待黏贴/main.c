#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}


void Dijkstra(MGraph *G, int v1,int n)  
{  //用Dijkstra算法求有向网G的v1顶点到其他顶点v的最短路径P[v]及其权D[v]    //设G是有向图的邻接矩阵，若边<i,j>不存在则G[i][j]=Maxint     //S[v]为真当且仅当v属于S,即已经求得从v1到v的最短路径   int  D[MVNum], P2[MVNum];   int  v,i,w,min;   enum  boolean S[MVNum];   for(v=1;v<=n;v++)   {   // 初始化S和D    S[v]=FALSE;        //置空最短路径终点集    D[v]=G->arcs[v1][v];   //置初始的最短路径值    if(D[v]< Maxint)     P2[v]=v1;     //v1是前趋双亲   else  
  
 
P2[v]=0;     //v 无前趋   }   // End_for  
 D[v1]=0;S[v1]=TRUE;    //S集初始时只有源点 源点到源点的距离为0   //开始循环每次求的V1到某个V顶点的最短路径并加V到S集中   for(i=2;i<=n;i++)//其余n-1个顶点  {   min=Maxint;    // 当前所知离v1顶点的最近距离设初值为∞    for(w=1;w<=n;w++)    //对所有顶点检查     if(!S[w] && D[w]<min) 
   {  //找离v1最近的顶点w并将其赋给v距离赋给min      v=w;        //在S集之外的离v1最近的顶点序号      
min=D[w];     //最近的距离  
 
 
 
}                //W顶点距离V1顶点更近  









 
 
7    S[v]=TRUE;       //将v并入S集  
   for(w=1;w<=n;w++)   //更新当前最短路径及距离      if(!S[w]&&(D[v]+G->arcs[v][w]<D[w]))      {  //修改D2[w]和p2[w] w 属于 V-S     
 
 
 
D[w]=D[v]+G->arcs[v][w];    //更新D2[w]  
     P2[w]=v;      }   //End_if   }    //End_for  
 
printf ("路径长度（单位：km） 最短路径\n");  
 for(i=1;i<=n;i++)   {      printf ("%10d", D[i]);    printf ("%13d", i);v=P2[i];    while(v!=0) {     printf ("<-%d", v);     v=P2[v];    }    printf("\n");   }  
    printf("\n\n"); } 
