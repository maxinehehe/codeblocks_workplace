//#include<iostream>
//#include<cstdio>
#include<bits\stdc++.h>
#include<cstring>
using namespace std;

int main(){
	char str[3];

	while(gets(str)){

		for(int i=0;i<2;i++)
			for(int j=0;j<2-i;j++){
				if(str[j]>str[j+1])
				swap(str[j],str[j+1]);
			}

	printf("%c %c %c\n",str[0],str[1],str[2]);
	}


	return 0;
}
