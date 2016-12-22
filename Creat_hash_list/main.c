#include <stdio.h>
#include <stdlib.h>

#define maxn 100
typedef int ElementType;

typedef struct Hash_table{
    ElementType data;
    struct Hash_table* next;
    int length;
}*Hash;

/*
typedef struct arr_hash{
  ElementType *base;
  int length;
  int size;
};
*/


int main()
{
    printf("Hello world!\n");
    return 0;
}
