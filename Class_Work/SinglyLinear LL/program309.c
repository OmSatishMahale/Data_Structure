#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{

    PNODE ptr= NULL;

    ptr = (PNODE)malloc(sizeof(NODE));

    //USE the NODE

    free(ptr);

    return 0;
}