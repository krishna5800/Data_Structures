///////////////////////////////////////////////////////////////////////
//            Final Code of Queue Using Generic Approach
///////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        int iCount;
        Queuenode<T> * first;
        Queuenode<T> * last;

    public:
        Queue();

        void enqueue(T no);      
        T dequeue();              

        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout << "Queue gets created successfully...\n";

    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
}

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> * newn = NULL;
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;         
    }
    
    this->iCount++;
}

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)    
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

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = NULL;
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

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

int main()
{
    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();

    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    delete qobj;
    
    return 0;
}