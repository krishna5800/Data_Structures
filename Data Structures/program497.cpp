// Class with first and last pointer

#include<iostream>
using namespace std;

#pragma pack(1)
class Queuenode
{
    public:
        int data;
        Queuenode * next;

        Queuenode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Queue
{
    private:
        int iCount;
        Queuenode * first;
        Queuenode * last;

    public:
        Queue();

        void enqueue(int no);       // InsertLast()
        int dequeue();              // DeleteFirst()

        void Display();
        int Count();
};

Queue :: Queue()
{
    cout << "Queue gets created successfully...\n";

    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
}

void Queue :: enqueue(int no)
{
    Queuenode * newn = NULL;
    newn = new Queuenode(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;          // OR last = newn;
    }
    
    this->iCount++;
}

int Queue :: dequeue()
{
    int Value = 0;
    Queuenode * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)       // Imp
    {
        cout << "Queue is empty...\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

void Queue :: Display()
{
    Queuenode * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)   
    {
        cout << "Queue is empty...\n";
        return ;
    }

    while(temp != NULL)
    {
        cout << "| " << temp->data << " | - "; 
        temp = temp->next;
    }

    cout << "\n";
}

int Queue :: Count()
{
    return iCount;
}

int main()
{
    Queue *qobj = new Queue();

    qobj->enqueue(11);
    qobj->enqueue(21);
    qobj->enqueue(51);
    qobj->enqueue(101);

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();

    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    qobj->enqueue(121);

    qobj->Display();

    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    delete qobj;
    
    return 0;
}