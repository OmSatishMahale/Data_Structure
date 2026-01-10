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


void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)               //LL is empty
    {
        (*first) = newn;
    }

    else                            //LL contains atleast 1 node
    {
        newn -> next = (*first);
        (*first) = newn;
    }
}

void InsertLast(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)               //LL is empty
    {
        *first = newn;
    }
    
    else                            //LL contains atleast 1 node
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)                  //Case 1
    {
        return;
    }
    else if((*first) -> next == NULL)     //Case 2
    {
        free(*first);
        (*first) = NULL;
    }
    else                                    //Case 3
    {
        temp = (*first);
        (*first) = (*first) -> next;
        free(temp); 
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)                  //Case 1
    {
        return;
    }
    else if((*first) -> next == NULL)     //Case 2
    {
        free(*first);
        (*first) = NULL;
    }
    else                                    //Case 3
    {
        temp = (*first);
        
        while(temp->next->next!=NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first -> data);
        first = first -> next;
    }

    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount =0;
    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertAtPos(PPNODE first,int no,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iSize =0;
    int iCnt=0;
    iSize = Count(*first);
    
    if((pos < 1) || (pos > iSize +1))       //Filter
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos==iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;

        temp = *first;

        for(iCnt =1;iCnt<pos-1;iCnt++)
        {
            temp = temp ->next;
        }
        newn -> next = temp -> next;
        temp ->next = newn;
    }
}

void DeletetAtPos(PPNODE first,int no,int pos)
{
    int iSize =0;
    int iCnt = 0;
    int temp =0;

    iSize = Count(*first);
    
    if((pos < 1) || (pos > iSize))       //Filter
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos==iSize)
    {
        DeleteLast(first);
    }
    else
    {
        
    }
}

int main()
{
    PNODE head = NULL;
    int iRet=0;

    InsertFirst(&head,75);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet=Count(head);

    printf("Number of Nodes are : %d",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,151);


    Display(head);
    iRet=Count(head);

    printf("Number of Nodes are : %d",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet=Count(head);

    printf("Number of Nodes are : %d",iRet);

    DeleteLast(&head);

    Display(head);
    iRet=Count(head);

    printf("Number of Nodes are : %d",iRet);

    InsertAtPos(&head,105,5);
    Display(head);
    iRet=Count(head);

    printf("Number of Nodes are : %d",iRet);

    return 0;
}