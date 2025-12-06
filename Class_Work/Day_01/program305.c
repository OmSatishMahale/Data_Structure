#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
int main()
{

    //struct node obj;
    NODE obj;
    printf("%ld",sizeof(obj));

    return 0;
}