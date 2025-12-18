#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;

    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
    while(first != NULL)                    // Type 1
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }

    printf("NULL \n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)                    // Type 1
    {
        iCount++;

        first = first->next;
    }

    return iCount;
}

void InsertFirst(PPNODE first, int no)
{
    PNODE newn;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)                    // LL is empty
    {
        (*first) = newn;
    }
    else
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)                    // LL is empty
    {
        (*first) = newn;
    }
    else
    {
        temp = (*first);
            
        while(temp->next != NULL)       // type 2
        {
            temp = temp->next;
        }

        temp->next = newn; 
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return ;
    }
    else if((*first)->next == NULL)
    {
        free(first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;

        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return ;
    }
    else if((*first)->next == NULL)
    {
        free(first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)     // type 3
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;
    iSize = Count((*first));

    if((pos < 1) || (pos > (iSize+1)))          // filter
    {
        printf("Invalid Position\n");
        return ;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == (iSize+1))
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    iSize = Count((*first));

    if((pos < 1) || (pos > iSize))          // filter
    {
        printf("Invalid Position\n");
        return ;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
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
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes is : %d\n", iRet);

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes is : %d\n", iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes is : %d\n", iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes is : %d\n", iRet);

    InsertAtPos(&head, 105, 3);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes is : %d\n", iRet);

    return 0;
}