#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<limits.h>
#include<io.h>

#include<process.h>//exit()
//#define TRUE 1
#define ERROR 0
#define INFINITY INT_MAX
#define Max_value 100

typedef int bool;
#define true 1
#define false 0

//enum boolean{FALSE,TRUE};
typedef char VertexType[50];/*顶点类型 定义字符数组*/
typedef int VRType;

typedef struct ArcCell{
    VRType adj;
    VRType cost;
}ArcCell,Adjmatrix[Max_value][Max_value];

typedef struct{
    VertexType Vexs[Max_value];  //顶点
    Adjmatrix arcs; //邻接矩阵
    int vexnum;//顶点数
    int arcnum;//弧数
}MGraph;

//char pass_key[10];//初始密码




int p[Max_value][Max_value][Max_value], D[Max_value][Max_value],
    pcost[Max_value][Max_value][Max_value], Dcost[Max_value][Max_value];
int P[50][50];
int D2[Max_value],P2[Max_value];


//总模式
void menu(MGraph *G);
//管理员模式
void Manger_Menu(MGraph *G);
void User_Menu(MGraph *G);

int LocateVex(MGraph G,VertexType elem);//在图G中找elem位置
//创建图
void CreatMG(MGraph *G);
//自动创建图
void AutoCreatMG(MGraph *G);

//查询城市间里程信息 查询城市间是否可直达
void Query_City_Adj(MGraph *G);


//查询城市间最短路径
void Query(MGraph *G);

//void ShortestCost_FLOYD(MGraph *G);

//弗洛伊德求最短路径
void ShortestPath_FLOYD(MGraph *G);
//弗洛伊德求最少费用
void ShortestCost_FLOYD(MGraph *G);
void Query_Lowest_Cost(MGraph *G);
//修改城市名
void Modify_City(MGraph *G);

//设置密码
int Pass_word();
void City_List(MGraph *G);

//添加城市
void  Add_City(MGraph *G);

//删除城市
void Delete_City(MGraph *G);

//修改城市间里程信息
void Modify_City_Adj(MGraph *G);

//添加城市间里程信息
void Add_City_Adj(MGraph *G);

//删除城市间里程
void Delete_City_Adj(MGraph *G);


//单源问题
void Query_simpleToOther(MGraph *G);


//修改城市间费用花销
void Modify_City_Cost(MGraph *G);





//管理员登录界面
void menu(MGraph *G){
    int slec;
    while(1){
    system("cls");
    printf("-------------------------选择-------------------------->\n");
    printf("\t\t    1.开发者模式\n");
    printf("\t\t    2.用户模式\n");
    printf("\t\t    0.退出\n");
    printf("------------------------------------------------------->\n");
    printf("你的选择：");
    scanf("%d",&slec);

    switch(slec){
    case 1 : if(Pass_word()){
                    Manger_Menu(G);
            }
            else
                printf("密码输入有误！\n");
            break;//后续需要设计密码
    case 2 : User_Menu(G);break;
    case 0 : exit(0);
    default : printf("输入有误！\n");break;
        }
    getchar();
    getchar();
    }
}


int Pass_word(){
    //char sc[10];
    int pass_key=741;
    int sc=0;
    printf("请输入密码：");
    scanf("%d",&sc);

    if(sc==pass_key){//strcmp(sc,pass_key)
            printf("成功登录开发者模式\n");
  getchar();getchar();
        return 1;
    }else
        return 0;

}


void Manger_Menu(MGraph *G){
    int select=0;

    while(1){
    system("cls");
    printf("---------------------------开发者模式------------------------------->\n\n");
    printf("  1.还原城市交通网络图    \t\t2.查询城市间最短里程-路径\n");
    printf("  3.修改城市名称          \t\t4.添加城市\n");
    printf("  5.删除城市名            \t\t6.修改两城市间里程信息\n");
    printf("  7.添加两城市间里程信息  \t\t8.删除两城市间里程信息\n");
    printf("  9.查询城市间是否可直达  \t\t10.单源最短路径\n");
    printf("  11.查看城市列表         \t\t12.查询城市交通最少花销\n");
    printf("  13.修改城市间交通费用   \t\t14.返回上一级菜单\n");
    printf("  0.退出\n\n");
    printf("--------------------------------------------------------------------->\n");
    printf("你的选择：");
    scanf("%d",&select);
    switch(select){
        case 1 : AutoCreatMG(G);printf("还原城市信息...\n还原城市间里程信息......\n");
                  printf("还原城市间交通费用信息.........\n还原城市交通网络图成功。\n");  break;//printf("成功建立交通网络图\n");City_List(G);break;
        case 2 : Query(G);break;
        case 3 : Modify_City(G);break;
        case 4 : Add_City(G);break;
        case 5 : Delete_City(G);break;
        case 6 : Modify_City_Adj(G);break;
        case 7 : Add_City_Adj(G);break;
		case 8 : Delete_City_Adj(G);break;
		case 9 : Query_City_Adj(G);break;
        case 10: Query_simpleToOther(G);break;
        case 11: City_List(G);break;
        case 12: Query_Lowest_Cost(G);break;
        case 13: Modify_City_Cost(G);break;
        case 14: menu(G);break;
        case 0 : exit(0);
        default : printf("输入有误！\n");break;
    }
     getchar();
    getchar();
    }

}

void User_Menu(MGraph *G){
    int select=0;
    while(1){
    system("cls");
    printf("---------------------------欢迎使用交通咨询系统--------------------------->\n\n");
    printf("\t1.查询城市交通最短距离信息\t2.查询城市交通最少花销\n");
    printf("\t3.查看城市列表            \t4.查询城市间是否可直达\n");
    printf("\t5.单源最短路径            \t6.返回上一级菜单\n");
    printf("\t0.退出\n\n");
    printf("-------------------------------------------------------------------------->\n");
    printf("请输入你的选择：");
    scanf("%d",&select);
    switch(select){
        case 1 : Query(G);break;
        case 2 : Query_Lowest_Cost(G);break;
        case 3 : City_List(G);break;
        case 4 : Query_City_Adj(G);break;
        case 5 : Query_simpleToOther(G);break;
        case 6 : menu(G);break;
        case 0 : exit(0);
        default : printf("输入有误！\n");break;
    }
     getchar();
    getchar();
    }

}




void City_List(MGraph *G){
     int i=1;
     int j=1;
     int t=0;
    printf("-------------------------------城市列表------------------------------------->\n");
    /*
	printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t\n",j++,G->Vexs[i++]);
   */


  // printf("%s,%s,%s,%s\n",G->Vexs[26],G->Vexs[27],G->Vexs[28],G->Vexs[29]);
    while(strcmp(G->Vexs[i],"NULL")!=0&&i<50){//||strcmp(G->Vexs[i],"-已删除-")!=0
          if(j==26){printf("\n新增城市：\n");t=0;}
          printf("\t%d.%s            ",j++,G->Vexs[i++]); t++;
          if(t%3==0)printf("\n");
                                          }
    printf("\n");
    printf("----------------------------------------------------------------------------->\n");
    /*
    printf("\t1.%s\t2.西宁\t\t3.兰州\n",G->Vexs[1]);
    printf("\t4.呼和浩特\t5.北京\t\t6.天津\n");
    printf("\t7.沈阳\t\t8.长春\t\t9.哈尔滨\n");
    printf("\t10.大连\t\t11.徐州\t\t12.郑州\n");
    printf("\t13.西安\t\t14.成都\t\t15.武汉\n");
    printf("\t16.上海\t\t17.福州\t\t18.南昌\n");
    printf("\t19.株洲\t\t20.贵阳\t\t21.昆明\n");
    printf("\t22.南宁\t\t23.柳州\t\t24.广州\n");
    printf("\t25.深圳\t\t\n");
    */

    /*
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t7.%s    \t\t8.%s   \t\t9.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t10.%s   \t\t11.%s  \t\t12.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t13.%s   \t\t14.%s  \t\t15.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t16.%s   \t\t17.%s  \t\t18.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t19.%s   \t\t20.%s  \t\t21.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t22.%s   \t\t23.%s  \t\t24%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t25.%s   \t\t\n");
    */
}

//在图G中找到elem
int LocateVex(MGraph G,VertexType elem){
    int i;
    for(i=1;i<=G.vexnum;i++){
        if(strcmp(elem,G.Vexs[i]) == 0)
            return i;
    }
    return -1;//返回0
}

//手动创建图 邻接矩阵
void CreatMG(MGraph *G){
    int i,j,k,l,w;
    VertexType a,b;
    printf("请输入图的顶点数、弧数：");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    printf("请输入每个顶点的值\n");
    for(i=1;i<=G->vexnum;i++){
        //G->Vexs[i]=(Vertextype)malloc(sizeof(char)*10);
        scanf("%s",&(G->Vexs[i]));
    }
    //初始化邻接矩阵
    //memset(G->arcs,0,sizeof(G->arcs));
    for(i=1;i<=G->vexnum;++i)/*初始化邻接矩阵*/
		for(j=1;j<=G->vexnum;++j){
			G->arcs[i][j].adj=INFINITY;/*网*/
			G->arcs[i][j].cost=INFINITY;
			//(*G).arcs[i][j].info=NULL;/*没有相关信息*/
		}

    printf("请输入弧的弧尾、弧头(以空格为间隔):\n");
    for(k=1;k<=G->arcnum;k++){
        printf("请输入第%d条弧的起点、终点:\n",k);
        scanf("%s%s*c",a,b);
        printf("请输入该弧对应的权值：");
        scanf("%d",&w);
        i = LocateVex(*G,a);
        j = LocateVex(*G,b);
        G->arcs[i][j].adj = G->arcs[j][i].adj = w;//定位权值

    }
    printf("\n");

    // return TRUE;
}

void AutoCreatMG(MGraph *G){
    int i=1,j,k,w;
    int t=0;
    G->arcnum = 30;

    while(t<50){
            strcpy(G->Vexs[t++],"NULL");
             }

    strcpy(G->Vexs[0],"该城市不存在");
    strcpy(G->Vexs[i++],"乌鲁木齐");
    strcpy(G->Vexs[i++],"西宁");
    strcpy(G->Vexs[i++],"兰州");
    strcpy(G->Vexs[i++],"呼和浩特");
    strcpy(G->Vexs[i++],"北京");
    strcpy(G->Vexs[i++],"天津");
    strcpy(G->Vexs[i++],"沈阳");
    strcpy(G->Vexs[i++],"长春");
    strcpy(G->Vexs[i++],"哈尔滨");
    strcpy(G->Vexs[i++],"大连");
    strcpy(G->Vexs[i++],"徐州");
    strcpy(G->Vexs[i++],"郑州");
    strcpy(G->Vexs[i++],"西安");
    strcpy(G->Vexs[i++],"成都");
    strcpy(G->Vexs[i++],"武汉");
    strcpy(G->Vexs[i++],"上海");
    strcpy(G->Vexs[i++],"福州");
    strcpy(G->Vexs[i++],"南昌");
    strcpy(G->Vexs[i++],"株洲");
    strcpy(G->Vexs[i++],"贵阳");
    strcpy(G->Vexs[i++],"昆明");
    strcpy(G->Vexs[i++],"南宁");
    strcpy(G->Vexs[i++],"柳州");
    strcpy(G->Vexs[i++],"广州");
    strcpy(G->Vexs[i++],"深圳");

    /*
    G->Vexs[i++] = "乌鲁木齐";
    G->Vexs[i++] = "西宁";
    G->Vexs[i++] = "兰州";
    G->Vexs[i++] = "呼和浩特";
    G->Vexs[i++] = "北京";
    G->Vexs[i++] = "天津";
    G->Vexs[i++] = "沈阳";
    G->Vexs[i++] = "长春";
    G->Vexs[i++] = "哈尔滨";
    G->Vexs[i++] = "大连";
    G->Vexs[i++] = "徐州";
    G->Vexs[i++] = "郑州";
    G->Vexs[i++] = "西安";
*/
    G->vexnum = i - 1;
    t = i-1;
    if(t<50){


             }

   // memset(G->arcs,0,sizeof(G->arcs));
   for(i=1;i<=G->vexnum;i++)/*初始化邻接矩阵*/
		for(j=1;j<=G->vexnum;j++){
			G->arcs[i][j].adj=INFINITY;/*网*/  //里程
			G->arcs[i][j].cost=INFINITY;//花费
			//(*G).arcs[i][j].info=NULL;/*没有相关信息*/
		}
    //里程和费用花销
    G->arcs[1][3].adj = G->arcs[3][1].adj = 1892;G->arcs[1][3].cost = G->arcs[3][1].cost = 328;
    G->arcs[2][3].adj = G->arcs[3][2].adj = 216;G->arcs[2][3].cost = G->arcs[3][2].cost = 189;
    G->arcs[3][4].adj = G->arcs[4][3].adj = 1145;G->arcs[3][4].cost = G->arcs[4][3].cost = 201;
    G->arcs[4][5].adj = G->arcs[5][4].adj = 668;G->arcs[4][5].cost = G->arcs[5][4].cost = 176;
    G->arcs[5][6].adj = G->arcs[6][5].adj = 137;G->arcs[5][6].cost = G->arcs[6][5].cost = 80;
    G->arcs[6][7].adj = G->arcs[7][6].adj = 704;G->arcs[6][7].cost = G->arcs[7][6].cost = 305;
    G->arcs[7][8].adj = G->arcs[8][7].adj = 305;G->arcs[7][8].cost = G->arcs[8][7].cost = 232;
    G->arcs[8][9].adj = G->arcs[9][8].adj = 242;G->arcs[8][9].cost = G->arcs[9][8].cost = 211;
    G->arcs[7][10].adj = G->arcs[10][7].adj = 397;G->arcs[7][10].cost = G->arcs[10][7].cost = 277;
    G->arcs[6][11].adj = G->arcs[11][6].adj = 674;G->arcs[6][11].cost = G->arcs[11][6].cost = 222;
    G->arcs[5][12].adj = G->arcs[12][5].adj = 695;G->arcs[5][12].cost = G->arcs[12][5].cost = 120;
    G->arcs[11][12].adj = G->arcs[12][11].adj = 349;G->arcs[11][12].cost = G->arcs[12][11].cost = 109;
    G->arcs[12][13].adj = G->arcs[13][12].adj = 511;G->arcs[12][13].cost = G->arcs[13][12].cost = 243;
    G->arcs[3][13].adj = G->arcs[13][3].adj = 676;G->arcs[3][13].cost = G->arcs[13][3].cost = 321;
    G->arcs[13][14].adj = G->arcs[14][13].adj = 842;G->arcs[13][14].cost = G->arcs[14][13].cost = 301;
    G->arcs[12][15].adj = G->arcs[15][12].adj = 534;G->arcs[12][15].cost = G->arcs[15][12].cost = 411;
    G->arcs[11][16].adj = G->arcs[16][11].adj = 651;G->arcs[11][16].cost = G->arcs[16][11].cost = 316;
    G->arcs[14][21].adj = G->arcs[21][14].adj = 1100;G->arcs[14][21].cost = G->arcs[21][14].cost = 623;
    G->arcs[14][20].adj = G->arcs[20][14].adj = 967;G->arcs[14][20].cost = G->arcs[20][14].cost = 588;
    G->arcs[15][19].adj = G->arcs[19][15].adj = 409;G->arcs[15][19].cost = G->arcs[19][15].cost = 200;
    G->arcs[16][18].adj = G->arcs[18][16].adj = 825;G->arcs[16][18].cost = G->arcs[18][16].cost = 349;
    G->arcs[17][18].adj = G->arcs[18][17].adj = 622;G->arcs[17][18].cost = G->arcs[18][17].cost = 211;
    G->arcs[18][19].adj = G->arcs[19][18].adj = 367;G->arcs[18][19].cost = G->arcs[19][18].cost = 270;
    G->arcs[19][20].adj = G->arcs[20][19].adj = 902;G->arcs[19][20].cost = G->arcs[20][19].cost = 462;
    G->arcs[19][23].adj = G->arcs[23][19].adj = 672;G->arcs[19][23].cost = G->arcs[23][19].cost = 323;
    G->arcs[19][24].adj = G->arcs[24][19].adj = 675;G->arcs[19][24].cost = G->arcs[24][19].cost = 320;
    G->arcs[20][23].adj = G->arcs[23][20].adj = 607;G->arcs[20][23].cost = G->arcs[23][20].cost = 450;
    G->arcs[20][21].adj = G->arcs[21][20].adj = 639;G->arcs[20][21].cost = G->arcs[21][20].cost = 471;
    G->arcs[22][23].adj = G->arcs[23][22].adj = 255;G->arcs[22][23].cost = G->arcs[23][22].cost = 177;
    G->arcs[24][25].adj = G->arcs[25][24].adj = 140;G->arcs[24][25].cost = G->arcs[25][24].cost = 56;
    return ;
}

//弗洛伊德求最少花销

void ShortestCost_FLOYD(MGraph *G)//, int p[Max_value][Max_value][Max_value], int D[Max_value][Max_value])
{
    int u, v, w, i, j;

    for(v=1; v<=G->vexnum; v++)
        for(w=1; w<=G->vexnum; w++)
        {
            Dcost[v][w] = G->arcs[v][w].cost;//费用
            for(u=1; u<=G->vexnum; u++){
                pcost[v][w][u] = -1;//费用
            }

            if(Dcost[v][w] < INFINITY)
            {
                pcost[v][w][0]=v;
                pcost[v][w][1]=w;
            }
        }
        for(u=1; u<=G->vexnum; u++)
            for(v=1; v<=G->vexnum; v++)
                for(w=1; w<=G->vexnum; w++)
                    if(Dcost[v][u] < INFINITY && Dcost[u][w] < INFINITY && Dcost[v][u]+Dcost[u][w] < Dcost[v][w])
                    {
                        //更新Dcost
                        Dcost[v][w]=Dcost[v][u]+Dcost[u][w];
                        for(i=1; i<=G->vexnum; i++)
                        {
                            if(pcost[v][u][i]!=-1)
                                pcost[v][w][i]=pcost[v][u][i];
                            else
                                break;
                        }
                        for(j=1; j<=G->vexnum; j++)//注意：这里j从1开始而不是从0开始，因为从v到u的路径最后一个顶点是u,
                            //而从u到w的路径第一个顶点是u，只需打印u一次即可。
                        {
                            if(pcost[u][w][j]!=-1)
                                pcost[v][w][i++]=pcost[u][w][j];
                            else
                                break;
                       }
            }
}



//计算最少花销
//查询城市间最少花销
void Query_Lowest_Cost(MGraph *G){
    int i,j,k;
    VertexType cha;
    City_List(G);

    ShortestCost_FLOYD(G);//,&p,&D);

    printf("请输入城市起点序号：");
    scanf("%d",&i);
    printf("请输入城市终点序号：");
    scanf("%d",&j);
    printf("--->");
    printf("查询信息结果如下：\n");
    printf("---------------------------------------------------------------------------\n");
    if(i<=G->vexnum&&j<=G->vexnum&&i>0&&j>0) {//更改
     if(i!=j)
        if(Dcost[i][j]!=INFINITY){
        //if(G->arcs[i][j].adj!=INFINITY){
            printf("%s   到   %s 最少花销：%d\n",G->Vexs[i],G->Vexs[j],Dcost[i][j]);
            printf("\n");
            printf("最少花销径为：%s",G->Vexs[i]);
            for(k=1;k<G->vexnum;k++){
                if(pcost[i][j][k]!=-1)//&&strcmp(G->Vexs[p[i][j][k]],cha)!=0)
                {
                    if(strcmp(G->Vexs[pcost[i][j][k]],cha) == 0)
                        continue;
                     printf("->%s",G->Vexs[pcost[i][j][k]]);
                     strcpy(cha,G->Vexs[pcost[i][j][k]]);
                     if(strcmp(cha,G->Vexs[j])== 0)
                        break;
                }
                else
                    break;
            }
            printf("\n");

        }else
        printf("%s到%s不可达\n",G->Vexs[i],G->Vexs[j]);
        else
            printf("警告：起点城市不能与终点城市一样！\n");
        printf("---------------------------------------------------------------------------\n");
    }else{
        printf("警告：输入城市序号有误！");
    }
}


/**
修改城市间的费用花销，如果城市间存在直接通路，则允许进行添加（修改），
不再单独实现，添加花销，因为在里程信息添加后只需判断是否存在直接通路，
-------修改花销费用函数的实现
*/
void Modify_City_Cost(MGraph *G){
    int i,j,a,b,New_Cost;
     VertexType cha,chb;
     City_List(G);
     printf("请输入要修改里程的第一个城市序号：");
     scanf("%d",&a);
     printf("请输入要修改里程的第二个城市序号：");
     scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {

     if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
              printf("警告：%d.%s 与 %d.%s 之间不存在直接通路\n",a,G->Vexs[a],b,G->Vexs[b]);
     else{
          printf("%s 到 %s 之间存在直接通路，里程为：%d\n",G->Vexs[a],G->Vexs[b],G->arcs[b][a].adj);
          printf("请输入费用：");
          scanf("%d",&New_Cost);
          G->arcs[a][b].cost = G->arcs[b][a].adj = New_Cost;
          printf("费用信息录入成功\n");
          }
        } else{
		 printf("警告：输入城市序号有误！\n");
		 }
}





//弗洛伊德求最短路径算法

void ShortestPath_FLOYD(MGraph *G)//, int p[Max_value][Max_value][Max_value], int D[Max_value][Max_value])
{
    int u, v, w, i, j;

    for(v=1; v<=G->vexnum; v++)
        for(w=1; w<=G->vexnum; w++)
        {
            D[v][w]=G->arcs[v][w].adj;
            //Dcost[v][w] = G->arcs[v][w].cost;//费用
            for(u=1; u<=G->vexnum; u++){
                p[v][w][u] = -1;
                //pcost[v][w][u] = -1;//费用
            }

            if(D[v][w] < INFINITY)
            {
                p[v][w][0]=v;//pcost[v][w][0]=v;
                p[v][w][1]=w;//pcost[v][w][1]=w;
            }
        }
        for(u=1; u<=G->vexnum; u++)
            for(v=1; v<=G->vexnum; v++)
                for(w=1; w<=G->vexnum; w++)
                    if(D[v][u] < INFINITY && D[u][w] < INFINITY && D[v][u]+D[u][w] < D[v][w])
                    //if(D[v][u]+D[u][w] < D[v][w])
                    {
                        //更新D
                        D[v][w]=D[v][u]+D[u][w];
                        //更新p，从v到w的路径是从v到u，再从u到w的所有路径


                        for(i=1; i<=G->vexnum; i++)
                        {
                            if(p[v][u][i]!=-1)
                                p[v][w][i]=p[v][u][i];
                            else
                                break;
                        }
                        for(j=1; j<=G->vexnum; j++)//注意：这里j从1开始而不是从0开始，因为从v到u的路径最后一个顶点是u,
                            //而从u到w的路径第一个顶点是u，只需打印u一次即可。
                        {
                            if(p[u][w][j]!=-1)
                                p[v][w][i++]=p[u][w][j];
                            else
                                break;
                       }
            }
}


//迪杰斯特拉解决单源路径问题

void ShortestPath_Dijkstra(MGraph *G){
    int v1;//定义起点
    int v,i,j,k,min_element;


}




//查询城市间是否可直达
void Query_City_Adj(MGraph *G){
     int a,b;
      City_List(G);
      printf("请输入起点城市序号：");
      scanf("%d",&a);
       printf("请输入终点城市序号：");
      scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {

	      if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
	           printf("%s到%s无法直达\n",G->Vexs[a],G->Vexs[b]);
	      else
	          printf("%s到%s可以直达，里程为：%d\n",G->Vexs[a],G->Vexs[b],G->arcs[a][b].adj);
	     }else{

		 printf("警告：输入城市序号有误！\n");

		 }


     }





//修改城市信息
void Modify_City(MGraph *G){
    int i,j;
    VertexType oldCity;//字符数组类型
    printf("请输入你要修改的城市的名称：");
    scanf("%s",&oldCity);
    for(i=1;i<=G->vexnum;i++){
        if(strcmp(oldCity,G->Vexs[i]) == 0){
            printf("查找到%d.%s\n",i,oldCity);
            printf("请输入城市新名称：");
            scanf("%s",&(G->Vexs[i]));
            printf("修改成功\n");
            return ;
        }
    }
    printf("未查找到该城市相关信息！\n");

}


//添加城市
void  Add_City(MGraph *G){
      VertexType ch;
      int i,j,t=1;
      printf("请输入你要添加的城市名：");
      scanf("%s",&ch);
      for(i=1;i<=G->vexnum;i++)
           if(strcmp(G->Vexs[i],ch)==0)
              t=0;

      if(t==1){
      strcpy(G->Vexs[++G->vexnum],ch);
      if(strcmp(G->Vexs[G->vexnum],"NULL")!=0){
	  //重新初始化里程
             /*初始化邻接矩阵*/
				for(j=1;j<=G->vexnum;j++){
					G->arcs[G->vexnum][j].adj=G->arcs[j][G->vexnum].adj=INFINITY;/*网*/
			//(*G).arcs[i][j].info=NULL;/*没有相关信息*/
		}
			  printf("添加城市：%s成功。\n",G->Vexs[G->vexnum]);
              }
      else
          printf("！添加失败，请重新添加！\n");

          }else
          printf("警告：该城市已存在！请重新添加！\n");

      }


//删除城市
void Delete_City(MGraph *G){
     int i,j,t,k,f=0;
     VertexType ch;

    printf("请输入你要删除的城市名：");
     scanf("%s",&ch);
        for(k=1;k<=G->vexnum;k++)
            if(strcmp(G->Vexs[k],ch)==0){
               printf("查找到该城市。\n");
               f=1;
                strcpy(G->Vexs[k],"-已删除-");

                t=k;
                break;
                }
            if(f==1){
                 printf("删除%s成功。\n",ch);

                for(i=1;i<=G->vexnum;i++)
                   for(j=1;j<=G->vexnum;j++)
                     if(i==t||j==t)
                         G->arcs[i][j].adj = G->arcs[j][i].adj= INFINITY;
                     else
                       continue;
                 printf("清除相关路线成功。\n");
                }else{

                      printf("警告：未查找到该城市，请确认该城市是否存在！\n");
                      }




                   }



//修改城市间里程信息
void Modify_City_Adj(MGraph *G){
     int i,j,a,b,distance;
     VertexType cha,chb;
     City_List(G);
     printf("请输入要修改里程的第一个城市序号：");
     scanf("%d",&a);
     printf("请输入要修改里程的第二个城市序号：");
     scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {

     if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
              printf("警告：%d.%s 与 %d.%s 之间不存在直接通路\n",a,G->Vexs[a],b,G->Vexs[b]);
     else{
          printf("%s 到 %s 之间里程为：%d\n",G->Vexs[a],G->Vexs[b],G->arcs[b][a].adj);
          printf("请输入要新的里程：");
          scanf("%d",&distance);
          G->arcs[a][b].adj = G->arcs[b][a].adj = distance;
          printf("修改里程成功\n");
          }
        } else{

		 printf("警告：输入城市序号有误！\n");
		 }
     }



//添加城市间里程信息
void Add_City_Adj(MGraph *G){
     int i,j,a,b,distance;
     VertexType cha,chb;
     City_List(G);
     printf("请输入要添加里程的第一个城市序号：");
     scanf("%d",&a);
     printf("请输入要添加里程的第二个城市序号：");
     scanf("%d",&b);
     if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {
	     if(G->arcs[a][b].adj!=INFINITY&&G->arcs[b][a].adj!=INFINITY)
	              printf("警告：%d.%s 与 %d.%s 之间已存在直接通路,里程为：%d\n",a,G->Vexs[a],b,G->Vexs[b],G->arcs[b][a].adj);
	     else{
	          printf("请输入里程：");
	          scanf("%d",&distance);
	           G->arcs[a][b].adj = G->arcs[b][a].adj = distance;
	           printf("添加城市间里程成功\n");
	          }
	        }else{
	        		 printf("警告：输入城市序号有误！\n");
	        }

     }

//删除城市间里程
void Delete_City_Adj(MGraph *G){
      int i,j,a,b,distance;
     VertexType cha,chb;
     City_List(G);
     printf("--->提醒：费用信息会跟随擦除！输入无效序号 0 可取消操作！\n");

     printf("请输入要删除里程的第一个城市序号：");
     scanf("%d",&a);
     if(a!=0){
     printf("请输入要删除里程的第二个城市序号：");
     scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {
	     if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
	              printf("警告：%d.%s 与 %d.%s 之间不存在直接通路\n",a,G->Vexs[a],b,G->Vexs[b]);
	      else{
	           G->arcs[a][b].adj = G->arcs[b][a].adj = INFINITY;
	           G->arcs[a][b].cost = G->arcs[b][a].cost = INFINITY;
	           printf("删除里程信息成功\n");

	           }
 		}else{
 			 printf("警告：输入城市序号有误！\n");
                }
            }
            else
                printf("已取消！\n");
     }




//打印
/**
屏幕大小限制问题 该矩阵无法完整展现
*/
void Print_MGraph(MGraph *G){
    int i,j;
    for(i=1;i<=G->vexnum;i++)
        printf("\t%s",G->Vexs[i]);
    printf("\n");
    for(i=1;i<=G->vexnum;i++){
         printf("%s\t",G->Vexs[i]);
    for(j=1;j<=G->vexnum;j++)
        if (G->arcs[i][j].adj == INFINITY)
            printf("0\t");
        else
            printf("%d\t",G->arcs[i][j].adj);
    printf("\n");
    }
}


//查询城市间最短路径
void Query(MGraph *G){
    int i,j,k;
    VertexType cha;
     City_List(G);

    ShortestPath_FLOYD(G);//,&p,&D);



    printf("请输入城市起点序号：");
    scanf("%d",&i);
    printf("请输入城市终点序号：");
    scanf("%d",&j);
    printf("--->");
    printf("查询信息结果如下：\n");
    printf("---------------------------------------------------------------------------\n");
   if(i<=G->vexnum&&j<=G->vexnum&&i>0&&j>0) {
    if(i!=j)
        if(D[i][j]!=INFINITY){
        //if(G->arcs[i][j].adj!=INFINITY){
            printf("%d.%s\t到\t%d.%s 最短里程：%d\n",i,G->Vexs[i],j,G->Vexs[j],D[i][j]);
            printf("^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n");
            printf("最短路径为：%s",G->Vexs[i]);
            for(k=1;k<G->vexnum;k++){
                if(p[i][j][k]!=-1)//&&strcmp(G->Vexs[p[i][j][k]],cha)!=0)
                {
                    if(strcmp(G->Vexs[p[i][j][k]],cha) == 0)//该信息如果与上次打印一样，则跳过该信息
                        continue;
                     printf("->%s",G->Vexs[p[i][j][k]]);
                     strcpy(cha,G->Vexs[p[i][j][k]]);
                     if(strcmp(cha,G->Vexs[j])== 0)//如果已到达终点则终止
                        break;
                }
                else
                    break;
            }
            printf("\n");

        }else
        printf("%s到%s不可达\n",G->Vexs[i],G->Vexs[j]);
        else
            printf("警告：起点城市不能与终点城市一样！\n");

        printf("---------------------------------------------------------------------------\n");
        }else{
           printf("警告：输入城市序号有误！\n");
        }
}


/**
现在要计算从源到其他所有各顶点的最短路径长度。
这里的长度就是指路上各边权之和。
这个问题通常称为单源最短路径问题
                --百度百科
*/
//单源问题
//查询单城市最短路径
void Query_simpleToOther(MGraph *G){
    int i,j,k;
    VertexType cha;
     City_List(G);

    ShortestPath_FLOYD(G);//,&p,&D);



    printf("请输入城市起点序号：");
    scanf("%d",&i);
    //printf("请输入城市终点序号：");
    //scanf("%d",&j);
    if(i>0&&i<=G->vexnum){
    printf("--->");
    printf("查询信息结果如下：\n");
    printf("---------------------------------------------------------------------------\n");
    printf("最短里程\t最短路径\n");
    for(j=1;j<=G->vexnum;j++){
    if(i!=j)
        if(D[i][j]!=INFINITY){
        //if(G->arcs[i][j].adj!=INFINITY){
            //printf("%d.%s\t到\t%d.%s 最短里程：%d\t",i,G->Vexs[i],j,G->Vexs[j],D[i][j]);
            printf("%d\t",D[i][j]);
           // printf("^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n");
            printf("\t%s",G->Vexs[i]);
            for(k=1;k<G->vexnum;k++){
                if(p[i][j][k]!=-1)//&&strcmp(G->Vexs[p[i][j][k]],cha)!=0)
                {
                    if(strcmp(G->Vexs[p[i][j][k]],cha) == 0)
                        continue;
                     printf("->%s",G->Vexs[p[i][j][k]]);
                     strcpy(cha,G->Vexs[p[i][j][k]]);
                     if(strcmp(cha,G->Vexs[j])== 0)
                        break;
                }
                else
                    break;
            }
            printf("\n");

        }else
        printf("%s到%s不可达\n",G->Vexs[i],G->Vexs[j]);
        else
            continue;//printf("警告：起点城市不能与终点城市一样！\n");
        }
    printf("---------------------------------------------------------------------------\n");
    }else
    printf("警告：输入城市序号有误！\n");
}




void Dijkstra(int n, int v, int *dist, int *prev, int c[Max_value][Max_value])
{
    int i,j;
    bool s[Max_value];    // 判断是否已存入该点到S集合中
    for(i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     // 初始都未用过该点
        if(dist[i] == INFINITY)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
    for(i=2; i<=n; ++i)
    {
        int tmp = INFINITY;
        int u = v;
        // 找出当前未使用的点j的dist[j]最小值
        for(j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u保存当前邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1;    // 表示u点已存入S集合中

        // 更新dist
        for(j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<INFINITY)
            {
                int newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}




void searchPath(int *prev,int v, int u)
{
    int i,j;
    int que[Max_value];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(i=tot; i>=1; --i)
        if(i != 1)
            printf("%d->",que[i]);// << " -> ";
        else
            printf("%d",que[i]);
}






//主函数
int main()
{
    MGraph *G=NULL;
    int i,j,v,w,k;
    G = (MGraph *)malloc(sizeof(MGraph));
    //手动创建
    //CreatMG(G);
     //自动创建城市交通图
    AutoCreatMG(G);
    // 最短路径长度

     int dist[Max_value];     // 表示当前点到源点的最短路径长度
    int prev[Max_value];     // 记录当前点的前一个结点
    int c[Max_value][Max_value];   // 记录图的两点间路径长度
    int n, line;             // 图的结点数和路径数
    Dijkstra(G->vexnum, 0, dist, prev, c);
    printf("源点到最后一个顶点的最短路径长度:%d ",dist[n]);

    // 路径
    printf("源点到最后一个顶点的路径为: \n");
    searchPath(prev, 1, G->vexnum);

     //菜单
     menu(G);

    return 0;
}


