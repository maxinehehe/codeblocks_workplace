#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__
#include<stdio.h>
#include<stdlib.h>

#define INIT_SIZE 100
#define TRUE 1
#define FALSE 0
#define max_value 10;


typedef char VaType[10];
typedef int boolean;

struct element
{
    int key;
    VaType value;
    int hash;
};

void hash_code(struct element *e);
struct hash_table_node
{
    struct element e;
    struct hash_table_node *next;

};

struct hash_table
{
    struct hash_table_node **slots;
    int count;
    int size;

};

struct hash_table *hash_table_init();

void hash_table_free(struct hash_table *table);

int hash_table_count(struct hash_table *table);
//void hash_table_clear(struct hash_table *table);
void hash_table_clear(struct hash_table *table,struct element *ele);

boolean hash_table_isempty(struct hash_table *table);

void hash_table_put(struct hash_table *table,struct element e);

struct element hash_table_get(struct hash_table *table,int key);

boolean hash_table_remove(struct hash_table *table,int key);

void Print_List(struct hash_table *table,struct element *ele);

void Query(struct hash_table *table,struct element *ele);

void AutoInit(struct hash_table *table,struct element *ele);

void add(struct hash_table *table,struct element *ele);

void menu(struct hash_table *table,struct element *ele);
#endif







void hash_code(struct element *e)
{
    e->hash = 3*e->key;
    return ;

}

//创建哈希表
struct hash_table *hash_table_init()
{
    struct hash_table *table=NULL;
    int i;
    table = (struct hash_table *)malloc(sizeof(struct hash_table));
    if(table == NULL) return NULL;
    table->slots=NULL;
    table->slots=(struct hash_table_node **)malloc(sizeof(struct hash_table_node *)*INIT_SIZE);
    if(table->slots==NULL)
    {
        free(table);    //分配内存失败
        return NULL;
    }
    for(i=0; i<INIT_SIZE; i++)
    {
        table->slots[i]=NULL;
    }
    table->count=0;
    table->size=INIT_SIZE;

    return table;
}

//销毁哈希表
void hash_table_free(struct hash_table *table)
{
    int i;
    struct hash_table_node *p=NULL;

    for(i=0; i<table->size; i++)
    {
        while(table->slots[i] != NULL)
        {
            p = table->slots[i];
            table->slots[i]=p->next;
            free(p);
        }
    }

    free(table->slots);
    free(table);
    return ;
}

int hash_table_count(struct hash_table *table)
{
    return table->count;

}
void hash_table_clear(struct hash_table *table,struct element *ele)
{
    int i;
    struct hash_table_node *p=NULL;

    for(i=0; i<table->size; i++)
    {
        while(table->slots[i] != NULL)
        {
            p = table->slots[i];
            table->slots[i]=p->next;
            free(p);
        }

        /**
        自行增加
        */

    }
    for(i=0;i<=table->count+3;i++){
        ele[i].key=-1;
    }

    table->count=0;
    return;


}

boolean hash_table_isempty(struct hash_table *table)
{

    return (table->count==0);


}

void hash_table_put(struct hash_table *table,struct element e)
{
    struct hash_table_node *node=NULL;

    hash_code(&e);
    //printf("X%o\n",&e);

    node = table->slots[e.hash % table->size];
    while(node!=NULL)
    {
        if(node->e.key==e.key)
        {
            //node->e.value = e.value;
            strcpy(node->e.value,e.value);
            node->e.hash = e.hash;
            return ;
        }
        node = node->next;
    }

    node = NULL;
    node = (struct hash_table_node *)malloc(sizeof(struct hash_table_node));
    node->e = e;
    node->next = NULL;

    node->next = table->slots[e.hash % table->size];
    table->slots[e.hash % table->size] = node;
    return ;

}

struct element hash_table_get(struct hash_table *table,int key)
{
    struct hash_table_node *node=NULL;
    struct element e;
    node = table->slots[(key*3)%table->size];
    while(node!=NULL)
    {
        if (node->e.key == key) return node->e;
        node = node->next;
    }
    e.key=e.hash=-1;
    strcpy(e.value,"NULL");
    return e;

}

boolean hash_table_remove(struct hash_table *table,int key)
{
    struct hash_table_node *p=NULL;
    struct hash_table_node *node=NULL;

    node = table->slots[(key*3)%table->size];

    if(node->e.key == key)
    {
        table->slots[(key*3)%table->size]=node->next;
        free(node);
        return TRUE;
    }

    p = node->next;
    while(p!=NULL)
    {
        if(p->e.key == key)
        {
            node->next = p->next;
            free(p);
            return TRUE;
        }
        node=node->next;
        p = p->next;
    }
    return FALSE;
}




void menu(struct hash_table *table,struct element *ele)
{
    int n;

while(1){
        system("cls");
    printf("利用哈希表进行制作\n");
    printf("------------------------计科一班----------------------------\n");
    printf("\t1.添加学生信息     \t2.修改学生信息\n");
    printf("\t3.查询学生信息     \t4.删除学生信息\n");
    printf("\t5.打印所有学生信息 \t6.查询学生人数\n");
    printf("\t7.清空表单         \t8.表单是否为空\n");
    printf("\t0.退出\n");
    printf("------------------------------------------------------------\n");

    printf("请输入选项：");


scanf("%d",&n);
    switch(n)
    {
    case 1:add(table,ele);

        break;
    case 2:MOdify(table,ele);
        break;
    case 3:Query(table,ele);
        break;
    case 4:Delete(table,ele);
        break;
    case 5:Print_List(table,ele);
            break;
    case 6:printf("现有学生人数：%d\n",table->count);break;
    case 7:hash_table_clear(table,ele);printf("表单清空成功！\n");break;
    case 8:if(!hash_table_isempty(table))printf("表单不空\n");
           else printf("表单为空！\n");
           break;
    case 0:exit(0);
    default :
        printf("输入有误\n");
        }
        getchar();
        getchar();
    }
    return ;

}

void Delete(struct hash_table *table,struct element *ele){
    int key;
    VaType name;
    struct element etest;
    printf("请输入学号 后 两位：");
    scanf("%d",&key);
    strcpy(name,ele[key].value);
    etest = hash_table_get(table,key);
    if(etest.key!=-1){
    hash_table_remove(table,ele[key].key);
    printf("删除学生%s信息成功。\n",name);
    ele[key].key=-1;

    table->count--;
    }else
        printf("警告：该学生信息不存在\n");
}



void add(struct hash_table *table,struct element *ele)
{
    int i,j,k,n;
    int num,value;
    struct element etest;
    //ele={1,"刘和合",10};
    /*
    printf("请输入该学生的学号后两位:\n");
    scanf("%d",&num);
    if(num>50){
        printf("警告：一个班级最多允许50个人！\n");
    }else{
    ele[num].key = num;
    etest = hash_table_get(table,ele[num].key);
    if(etest.key!=-1){
    printf("该学生已经存在！\n");
    }else{
    hash_code(&ele[num]);//[num]
    */
    printf("请输入该学生的姓名\n");
    num = table->count+3;

    scanf("%s",&ele[++num].value);//[num]
    ele[num].key=num;
    hash_table_put(table,ele[num]);//[num]
            if(table->count>=10)
                printf("信息如下：\t\n学号：B2010403021%d\t姓名：%s\t\n",ele[num].key,ele[num].value);
            else
                printf("信息如下：\t\n学号：B20104030210%d\t姓名：%s\t\n",ele[num].key,ele[num].value);
    printf("录入信息成功。");
    table->count++;

    //}
    return ;






/*
    ele[0].key=1;
    strcpy(ele[0].value,"刘和合");

    ele[1].key=10;
    strcpy(ele[1].value,"半位面");

    struct element ele2;


    //printf("请输入关键字");
    // for(i=0;i<)

    hash_code(&ele[0]);
    hash_code(&ele[1]);


    hash_table_put(table,ele[0]);
    hash_table_put(table,ele[1]);
    ele2=hash_table_get(table,10);
    //table->slots[ele->key]
    printf("key:%d\nvalue:%s\nhash:%d\n",ele2.key,ele2.value,ele2.hash);

    hash_table_free(table);

*/

}


void MOdify(struct hash_table *table,struct element *ele){
    int i,j,num,n,newNum;
    VaType newName;//新名字
    struct element eget;
    printf("请输入你要修改的学生的学号后两位：");
    scanf("%d",&num);
    if(num<=50){
    eget = hash_table_get(table,ele[num].key);
    if(eget.key==-1){
        printf("该学生信息还不存在\n");
    }
    else{
            //printf("修改该生的学号请输入 ”1“、姓名请输入”2“,一并修改请输入”3“:");
            //scanf("%d",&n);
            /*if(n==1){
                printf("请输入新的后两位学号：");
                scanf("%d",&newNum);
                ele[newNum].key=newNum;
                strcpy(ele[newNum].value,eget.value);
                if(num!=newNum)
                    hash_table_remove(table,table->slots[eget.key]);
                printf("修改学号成功.\n");
            }*/
           // else if(n==2){

                printf("请输入新的姓名：");
                scanf("%s",&newName);
                strcpy(ele[num].value,newName);
                hash_table_put(table,ele[num]);
                printf("修改姓名成功.\n");
            //}
            /*
            else if(n==3){
                printf("请输入新的后两位学号：");
                scanf("%d",&newNum);
                ele[newNum].key=newNum;
                //strcpy(ele[newNum].value,eget.value);

                printf("修改学号成功.\n");

                 printf("请输入新的姓名：");
                scanf("%s",&newName);
                strcpy(ele[newNum].value,newName);

                printf("修改姓名成功.\n");
                if(num!=newNum)
                    hash_table_remove(table,eget.key);

            }*/
            //else printf("警告：输入出错\n");
        }
    }else
        printf("警告：请注意输入的学号不要大于50！\n");
}



void Query(struct hash_table *table,struct element *ele){
    int i,j,k,num,value;
    struct element eget;
    printf("请输入学号后两位：");
    scanf("%d",&num);
    eget = hash_table_get(table,ele[num].key);//[num]
    if(ele[num].key==-1||eget.key>50){
        printf("该学生不存在\n");
    }
    else{
            if(eget.key>=10)
                printf("信息如下：\t\n学号：B2010403021%d\t姓名：%s\t\n",eget.key,eget.value);
            else
                printf("信息如下：\t\n学号：B20104030210%d\t姓名：%s\t\n",eget.key,eget.value);
    }

}


void AutoInit(struct hash_table *table,struct element *ele){
    int i;
    for(i=1;i<=35;i++){
    if(i==2||i==18||i==24)
        continue;
        ele[i].key=i;
        table->count++;
    }
    strcpy(ele[1].value,"毛宇");strcpy(ele[3].value,"易振宇");
    strcpy(ele[4].value,"周春黎");strcpy(ele[5].value,"张建勋");
    strcpy(ele[6].value,"石高峰");strcpy(ele[7].value,"唐大鹏");
    strcpy(ele[8].value,"曹仲");strcpy(ele[9].value,"欧阳亦文");
    strcpy(ele[10].value,"唐旭");strcpy(ele[11].value,"何雨秋");
    strcpy(ele[12].value,"梁钜义");strcpy(ele[13].value,"史习欢");
    strcpy(ele[14].value,"欧阳意文");strcpy(ele[15].value,"佘阳");
    strcpy(ele[16].value,"陈先平");strcpy(ele[17].value,"胡豪坤");
    strcpy(ele[19].value,"杨所为");strcpy(ele[20].value,"周珊");
    strcpy(ele[21].value,"周湘贤");strcpy(ele[22].value,"何丽芳");
    strcpy(ele[23].value,"殷征文");strcpy(ele[25].value,"何中冠");
    strcpy(ele[26].value,"吴黛芸");strcpy(ele[27].value,"贾宝");
    strcpy(ele[28].value,"叶晓华");strcpy(ele[29].value,"刘贺贺");
    strcpy(ele[30].value,"班伟铭");strcpy(ele[31].value,"张义江");
    strcpy(ele[32].value,"雷亚辉");strcpy(ele[33].value,"孙正茂");
    strcpy(ele[34].value,"吴淼");strcpy(ele[35].value,"王智龙");
 for(i=1;i<=35;i++){
    if(i==2||i==18||i==24)
        continue;
    hash_code(&ele[i]);
    hash_table_put(table,ele[i]);
 }

}
void Print_List(struct hash_table *table,struct element *ele){
    int i,j;
   if(!hash_table_isempty(table)){
    printf("学号\t\t\t姓名\n\n");
    for(i=1;i<=table->count+3;i++){
            if(i==2||i==18||i==24)
                continue;
        if(ele[i].key!=-1&&ele[i].key<=50){
            if(ele[i].key>=10)
                printf("B2010403021%d\t\t%s\n",ele[i].key,ele[i].value);
            else
                printf("B20104030210%d\t\t%s\n",ele[i].key,ele[i].value);
        } else
            continue;
    }
   }else
    printf("表单为空！\n");
}

int main()
{
     struct hash_table *table = NULL;
     struct element ele[51];
     table = hash_table_init();
    AutoInit(table,ele);
    menu(table,ele);
    return 0;
}
