#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100

typedef int ElementType;
typedef struct hash_table{
  ElementType *base;
  int length;
  int size;
}*Hash;

struct hash_table* Creat_Hash(){
    Hash ha=NULL;
    ha = (Hash)malloc(sizeof(struct hash_table));
    ha->base = (ElementType *)malloc(maxn*sizeof(ElementType));
    ha->size=maxn;
    ha->length = 0;
    memset(ha->base,0,maxn);//初始化
    return ha;
};
void Hashing(Hash ha,int key,int arr[],int arr_len){
    int va,n=0,i,t=0;
    ha->length=arr_len;
    for(i=0;i<arr_len;i++){

        if(ha->base[arr[i]%key]==0)
            ha->base[arr[i]%key] = arr[i];
        else{
            t=arr[i]%key;
            while((ha->base[t])!=0)t++;
            ha->base[t] = arr[i];
        }
    }

}

void Print_hash_table(Hash ha){
    int i,cou=0;
    for(i=0;i<ha->size;i++){
        if(ha->base[i]){
            printf("hash[%d]->%d\n",i,ha->base[i]);
            cou++;
            if(cou==ha->length)break;
        }
    }
}

void Print2_hash_table(Hash ha){
    int i,cou=0;
    for(i=0;i<ha->size;i++){
        if(ha->base[i]){
            printf("%d\t",i);
            cou++;
            if(cou==ha->length)break;
        }
    }
    printf("\n");
    for(i=0;i<ha->size;i++){
        if(ha->base[i]){
            printf("%d\t",ha->base[i]);
            cou++;
            if(cou==ha->length)break;
        }
    }
}



int main()
{
    Hash ha=NULL;
    int key;
    ha=Creat_Hash();

    int arr[]={47,7,29,11,16,92,22,8,3};
    int len=sizeof(arr)/sizeof(int);
    printf("请输入关键码：");
    scanf("%d",&key);

    Hashing(ha,key,arr,len);
    Print_hash_table(ha);
    Print2_hash_table(ha);
    //printf("Hello world!\n");
    return 0;
}
