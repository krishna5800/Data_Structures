///////////////////////////////////////////////////////////////////////
// Final Code For Singly Linear Linked List Using Generic Approach
///////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLL
{
    private:             
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int Count();

};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    cout << "Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T no)     
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;   
    this->first = newn;

    this->iCount++;
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;
    
    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)          
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)             
    {
        return ;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)            
    {
        return ;
    }
    else if(this->first->next == NULL)   
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

template<class T>
void SinglyLL<T> :: Display()            
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template<class T>
int SinglyLL<T> :: Count()
{
    return this->iCount;
}

template<class T>
void SinglyLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;

    if(pos < 1 || pos > (this->iCount+1))
    {
        cout << "Invalid Input\n";
        return ;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount+1))
    {
        this->InsertLast(no);
    }
    else
    {
        SinglyLLLnode<T> * newn = NULL;

        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template<class T>
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    if(pos < 1 || pos > (this->iCount))
    {
        cout << "Invalid Input\n";
        return ;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == (this->iCount))
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

int main()
{
    SinglyLL<int> *obj = new SinglyLL<int> ();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    obj->InsertAtPos(105, 4);

    obj->Display();
    iRet = obj->Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet = obj->Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    delete obj;

    return 0;
}