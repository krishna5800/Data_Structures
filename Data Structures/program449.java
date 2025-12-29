// Doubly Circular

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

class DoublyCL
{
    private node first;
    private node last;
    
    private int iCount;

    public DoublyCL()
    {
        System.out.println("Object of DoublyCL gets created.");
        
        this.first = null;
        this.last = null;
        
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;
        first.prev = last;

        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.prev = last;
            last.next = newn;
            last = newn;
        }

        last.next = first;
        first.prev = last;

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
            iCount--;
            return;
        }
        else
        {
            first = first.next;
        }

        last.next = first;
        first.prev = last;

        System.gc();

        iCount--;
    }
    
    public void DeleteLast()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
            iCount--;
            return;
        }
        else
        {
            last = last.prev;
        }

        last.next = first;
        first.prev = last;

        System.gc();

        iCount--;
    }
    
    public void Display()
    {
        node temp = null;

        temp = first;

        System.out.print("\n(start) <=>");
        do
        {
            System.out.print("| " + temp.data + " | <=>");
            temp = temp.next;
        }while(temp != first);

        System.out.print("(back to first)\n");
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

class program449
{
    public static void main(String A[])
    {
        DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

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