#include <stdio.h>
#include <stdlib.h>
#include <selfDefine/complex_struct.h>

//初始化
void complex_init (Ptrl ptrl){
    //for(int i=0;i<maxV;i++)
      //  ptrl->real[i]=ptrl->inscriber[i]=0;
      ptrl->real=ptrl->inscriber=0;
}

//创建值
void complex_creat(Ptrl ptrl){
    float rea,ins;
    scanf("%f%f",&rea,&ins);
    ptrl->real=rea;
    ptrl->inscriber=ins;

    return;
}

//加法运算
void complex_add(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    result->real=ptrl->real+ptrl2->real;//实部
    result->inscriber=ptrl->inscriber+ptrl2->inscriber;//虚部
    printf("加法计算结果：%.4f i + %.4f\n",result->real,result->inscriber);
}

//减法运算
void complex_sub(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    result->real=ptrl->real-ptrl2->real;//实部
    result->inscriber=ptrl->inscriber-ptrl2->inscriber;//虚部
    printf("减法计算结果：%.4f i + %.4f\n",result->real,result->inscriber);
}

//乘法运算
void complex_mul(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    result->real=ptrl->real * ptrl2->inscriber + ptrl2->real * ptrl->inscriber;//实部
    result->inscriber= -ptrl->real * ptrl2->real + ptrl->inscriber * ptrl2->inscriber;//虚部
    printf("乘法计算结果：%.4f i + %.4f\n",result->real,result->inscriber);
}

//除法运算
void complex_divi(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    float den;//分母
    den=-(ptrl2->real * ptrl2->real) + ptrl2->inscriber * (-ptrl2->inscriber);
    if(den!=0){
    result->real=((ptrl->real * -ptrl2->inscriber) + (ptrl->inscriber * ptrl2->real))/den;
    result->inscriber=(-(ptrl->real * ptrl2->real) + (ptrl->inscriber * -ptrl2->inscriber))/den;

    printf("除法计算结果：%.4f i + %.4f",result->real,result->inscriber);
    }else{
        printf("除法计算结果:error:分母为0！");
    }
}

int main()
{
   Ptrl ptrl1;
   ptrl1=(Ptrl)malloc(sizeof(struct complex));
   complex_init(ptrl1);

    printf("请输入Z1:");
   complex_creat(ptrl1);

   Ptrl ptrl2;
   ptrl2=(Ptrl)malloc(sizeof(struct complex));
   complex_init(ptrl2);

    printf("请输入Z2:");
   complex_creat(ptrl2);

   Ptrl result;
   result=(Ptrl)malloc(sizeof(struct complex));
   complex_init(result);

   //加法
   complex_add(ptrl1,ptrl2,result);
    //减法
   complex_sub(ptrl1,ptrl2,result);
   //乘法
   complex_mul(ptrl1,ptrl2,result);
   //除法
   complex_divi(ptrl1,ptrl2,result);

   free(ptrl1);
   free(ptrl2);
   free(result);
    return 0;
}
