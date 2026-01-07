///////////////////////////////////////////////////////////////////////
//            Final Code of Stack Using Generic Approach
///////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

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

int main()
{
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
    
    return 0;
}