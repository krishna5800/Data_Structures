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
            data = no;
            next = NULL;
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

}

void Stack :: push(int no)
{

}

int Stack :: pop()
{
    return 0;
}   

int Stack :: peep()
{

}

void Stack :: Display()
{

}

int Stack :: Count()
{
    return iCount;
}

int main()
{
    Stack *sobj = new Stack();

    delete sobj;
    
    return 0;
}