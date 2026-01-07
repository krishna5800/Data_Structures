/////////////////////////////////////////////
//    Generalised Data Structure Library   //
/////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------------------+
    Type                    Name of class for node            Name of class for functionality      |
---------------------------------------------------------------------------------------------------
    Singly Linear           SinglyLLLnode                     SinglyLLL         Done               |
    Singly Circular         SinglyCLLnode                     SinglyCLL                            |
    Doubly Linear           DoublyLLLnode                     DoublyLLL         Done               |
    Doubly Circular         DoublyCLLnode                     DoublyCLL                            |
    Stack                   Stacknode                         Stack             Done               |
    Queue                   Queuenode                         Queue             Done               |
---------------------------------------------------------------------------------------------------+
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear Linked List Using Generic Approach
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////
//          Doubly Linear Linked List Using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode * next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }

};

template<class T>
class DoublyLLL
{
    private:
        int iCount;
        DoublyLLLnode<T> * first;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout << "Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
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
        newn->prev = temp;
    }

    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > (this->iCount+1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                         
    {   
        return;
    }
    else if(this->first->next == NULL)             
    {
        delete this->first;
        first = NULL;
    }       
    else                                            
    {
        this->first  = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                         
    {   
        return;
    }
    else if(this->first->next == NULL)             
    {
        delete this->first;
        first = NULL;
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
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout << "\nNULL <=>";
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | <=>";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Stack Using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        int iCount;
        Stacknode<T> * first;

    public:
        Stack();

        void push(T no);      
        T pop();             
        T peep();

        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout << "Stack gets created successfully...\n";

    this->iCount = 0;
    this->first = NULL;
}

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> * newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;
    
    this->iCount++;
}

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout << "Stack is empty...\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}   

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout << "Stack is empty...\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout << "Stack is empty...\n";
        return ;
    }

    while(temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n"; 
        temp = temp->next;
    }
}

template<class T>
int Stack<T> :: Count()
{
    return iCount;
}

//////////////////////////////////// End of Library ////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout << "Number of DoublyLLLnodes are : " << dobj->Count() << "\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout << "Number of DoublyLLLnodes are : " << dobj->Count() << "\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout << "Number of DoublyLLLnodes are : " << dobj->Count() << "\n";

    dobj->DeleteLast();

    dobj->Display();

    cout << "Number of DoublyLLLnodes are : " << dobj->Count() << "\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();

    cout << "Number of DoublyLLLnodes are : " << dobj->Count() << "\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout << "Number of DoublyLLLnodes are : " << dobj->Count() << "\n";

    /////////////////////////////////////////////////////////////////////////////////////
    cout << "\n";

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();

    cout << "Number of elements in Stack : " << sobj->Count() << "\n";

    cout << "Return value of peep() is : " << sobj->peep() << "\n";

    sobj->Display();

    cout << "Number of elements in Stack : " << sobj->Count() << "\n";

    cout << "Popped element is : " << sobj->pop() << "\n";

    sobj->Display();

    cout << "Number of elements in Stack : " << sobj->Count() << "\n";

    cout << "Popped element is : " << sobj->pop() << "\n";

    sobj->Display();

    cout << "Number of elements in Stack : " << sobj->Count() << "\n";

    sobj->push('e');

    sobj->Display();

    cout << "Number of elements in Stack : " << sobj->Count() << "\n";

    delete sobj;
    delete dobj;
    delete obj;

    return 0;
}