#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;      //Another way to write typedef


int main()
{

    PNODE ptr= NULL;

    ptr = (PNODE)malloc(sizeof(NODE));

    //USE the NODE

    free(ptr);

    return 0;
}