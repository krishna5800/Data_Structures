#include<iostream>
using namespace std;

#pragma pack(1)
class Stacknode
{
    public:
        int data;
        Stacknode * next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Stack
{
    private:
        int iCount;
        Stacknode * first;

    public:
        Stack();

        void push(int no);      // InsertFirst()
        int pop();              // DeleteFirst()
        int peep();

        void Display();
        int Count();
};

Stack :: Stack()
{
    cout << "Stack gets created successfully...\n";

    this->iCount = 0;
    this->first = NULL;
}

void Stack :: push(int no)
{
    Stacknode * newn = NULL;
    newn = new Stacknode(no);

    newn->next = this->first;
    this->first = newn;
    
    this->iCount++;
}

int Stack :: pop()
{
    int Value = 0;
    Stacknode * temp = NULL;
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

int Stack :: peep()
{
    int Value = 0;

    if(this->first == NULL)
    {
        cout << "Stack is empty...\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

void Stack :: Display()
{
    Stacknode * temp = NULL;
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

int Stack :: Count()
{
    return iCount;
}

int main()
{
    Stack *sobj = new Stack();

    sobj->push(11);
    sobj->push(21);
    sobj->push(51);
    sobj->push(101);

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

    sobj->push(121);

    sobj->Display();

    cout << "Number of elements in Stack : " << sobj->Count() << "\n";

    delete sobj;
    
    return 0;
}