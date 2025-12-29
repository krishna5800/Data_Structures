// Doubly Lieanr

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout<<"Object of DoublyLL gets created.\n";
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first->prev = newn;
                first = newn;
            }

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                PNODE temp = NULL;

                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                newn->prev = temp;
                temp->next = newn;
            }

            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return ;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                temp = first;

                first = first->next;
                first->prev = NULL;

                delete temp;
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            PNODE target = NULL;

            if(first == NULL)
            {
                return ;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                target = temp->next;

                temp->next = NULL;

                delete target;
            }

            iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = first;

            cout << "\nNULL <=>";

            while (temp != NULL)
            {
                cout << "| " << temp->data << " | <=>";
                temp = temp->next;
            }

            cout << "NULL\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            if(pos < 1 || pos > (iCount+1))
            {
                cout << "Invalid Position\n";
                return ;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == (iCount+1))
            {
                InsertLast(no);
            }
            else
            {
                PNODE newn = NULL;
                PNODE temp = NULL;
                int iCnt = 0;

                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;
                
                temp = first;

                for(iCnt = 1; iCnt < (pos-1); iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next->prev = newn;
                newn->prev = temp;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > (iCount))
            {
                cout << "Invalid Position\n";
                return ;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == (iCount))
            {
                DeleteLast();
            }
            else
            {
                PNODE temp = NULL;
                PNODE target = NULL;
                int iCnt = 0;
                
                temp = first;

                for(iCnt = 1; iCnt < (pos-1); iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;

                temp->next = target->next;
                target->next->prev = temp;

                delete target;

                iCount--;
            }
        }
};

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    return 0;
}