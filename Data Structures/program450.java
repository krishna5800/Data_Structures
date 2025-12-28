// Doubly Linear

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    private node first;
    
    private int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created.");
        
        this.first = null;
        
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null)
        {
            first = newn;
        }
        else 
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);
        node temp = null;

        if(first == null)
        {
            first = newn;
        }
        else 
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            newn.prev = temp;
            temp.next = newn;
        }

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }

        System.gc();

        iCount--;
    }
    
    public void DeleteLast()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        System.gc();

        iCount--;
    }
    
    public void Display()
    {
        node temp = null;

        temp = first;

        System.out.print("\nNULL <=>");
        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=>");
            temp = temp.next;
        }

        System.out.println("NULL");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > (iCount+1))
        {
            System.out.println("Invalid Position");
            return;
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
            node newn = new node(no);
            node temp = null;
            int iCnt = 0;

            temp = first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            newn.prev = temp;
            temp.next = newn;

            iCount++;
        }
    }
    
    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > (iCount))
        {
            System.out.println("Invalid Position");
            return;
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
            node temp = null;
            int iCnt = 0;

            temp = first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp.next;
            }

            temp.next.next.prev = temp;
            temp.next = temp.next.next;

            System.gc();
            
            iCount--;
        }
    }
}

class program450
{
    public static void main(String A[])
    {
        DoublyLL obj = null;
        int iRet = 0;

        obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.DeleteAtPos(4);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}