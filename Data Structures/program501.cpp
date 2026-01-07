///////////////////////////////////////////////////////////////////////
//                        Menue driven code                          //
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
    Queue<int> *qobj = new Queue<int>();

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while(1)
    {
        cout << "-----------------------------------------------\n";
        cout << "-----------Please select the option------------\n";
        cout << "-----------------------------------------------\n";
        cout << "1 : Insert new element into the queue\n";
        cout << "2 : Remove new element into the queue\n";
        cout << "3 : Display the elements of the queue\n";
        cout << "4 : Count the number of elements from the queue\n";
        cout << "0 : Exit the application\n";

        cin >> iChoice;
        cout << "-----------------------------------------------\n";

        switch(iChoice)
        {
            
            case 1:
                cout << "Enter the element you want to insert : \n";
                cin >>Value;
                qobj->enqueue(Value);
                cout << "Element gets inserted successfully\n";
                break;

            case 2:
                iRet = qobj->dequeue();
                if(iRet != -1)
                {
                    cout << "Element removed from queue is : " << iRet << "\n";
                }
                break;

            case 3:
                cout << "Elements of the queue are : \n";
                qobj->Display();
                break;

            case 4:
                iRet = qobj->Count();
                cout << "Number of elements in queue are : " << iRet << "\n";
                break;

            case 0:
                cout << "Thank You for using our application\n";
                delete qobj;
                return 0;

            default:
                cout << "Please enter the valid option\n";
        }   // End of switch
    }       // End of while

    delete qobj;
    
    return 0;
}           // End of main()