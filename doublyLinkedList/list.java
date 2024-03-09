class list
{
    node start;
    list()
    {
        start=null;
    }

    list(node s)
    {
        start=s;
    }

    void append(int value)
    {
        node nptr=new node(null,value,null);
        if(start==null)
            start=nptr;
        else
        {
            node ptr=start;
            while(ptr.getNext()!=null)
                ptr=ptr.getNext();
            nptr.setPrev(ptr);
            ptr.setNext(nptr);
        }
    }

    void addAtBegin(int value)
    {
        node nptr=new node(null,value,start);
        if(start!=null)
            start.setPrev(nptr);
        start=nptr;
    }

    void addAtPosition(int value,int position)
    {
        node nptr;
        if(position==1)
        {
            nptr=new node(null,value,start);
            if(start!=null)
                start.setPrev(nptr);
            start=nptr;
        }
        else if(start==null)
            System.out.println("Empty list");
        else
        {
            node ptr=start;
            int i=1;
            while(i!=position-1)
            {
                if(ptr.getNext()==null)
                {
                    System.out.println("Invalid position");
                    return;
                }
                ptr=ptr.getNext();
                i++;
            }
            nptr=new node(ptr,value,ptr.getNext());
            ptr.getNext().setPrev(nptr);
            ptr.setNext(nptr);
        }
    }

    void reverse()
    {
        node ptr1=null,ptr2=start;
        while(ptr2!=null)
        {
            ptr1=ptr2;
            ptr2=ptr2.getNext();
            node temp=ptr1.getPrev();
            ptr1.setPrev(ptr1.getNext());
            ptr1.setNext(temp);
        }
        start=ptr1;
    }

    void sort()
    {
        int c=0;
        node ptr=start;
        while(ptr!=null)
        {
            c++;
            ptr=ptr.getNext();
        }
        for(int i=0;i<c;i++)
        {
            node ptr1=start;
            node ptr2=start.getNext();
            for(int j=0;j<c-i-1;j++)
            {
                if(ptr1.getData()>ptr2.getData())
                {
                    int temp=ptr1.getData();
                    ptr1.setData(ptr2.getData());
                    ptr2.setData(temp);
                }
                ptr1=ptr2;
                ptr2=ptr2.getNext();
            }
        }
    }

    void addSorted(int value)
    {
        node nptr=new node(null,value,null);
        if(start==null||value<start.getData())
        {
            nptr.setNext(start);
            if(start!=null)
                start.setPrev(nptr);
            start=nptr;
        }
        else
        {
            node ptr=start;
            while(ptr!=null)
            {
                if(value>=ptr.getData()&&(ptr.getNext()==null||value<ptr.getNext().getData()))
                {
                    nptr.setNext(ptr.getNext());
                    nptr.setPrev(ptr);
                    ptr.setNext(nptr);
                    if(nptr.getNext()!=null)
                        nptr.getNext().setPrev(nptr);
                    return;
                }
                ptr=ptr.getNext();
            }
        }
    }

    void deletePosition(int position)
    {
        if(start==null)
            System.out.println("Empty list");
        else if(position==1)
        {
            start=start.getNext();
            if(start!=null)
            start.setPrev(null);
        }
        else
        {
            node ptr=start;
            int i=1;
            while(i!=position-1)
            {
                if(ptr.getNext()==null)
                {
                    System.out.println("Invalid position");
                    return;
                }
                ptr=ptr.getNext();
                i++;
            }
            ptr.setNext(ptr.getNext().getNext());
            if(ptr.getNext()!=null)
                ptr.getNext().setPrev(ptr);
        }
    }

    void deallocate()
    {
        start=null;
    }

    int count()
    {
        int c=0;
        node ptr=start;
        while(ptr!=null)
        {
            c++;
            ptr=ptr.getNext();
        }
        return c;
    }

    void  display()
    {
        node ptr=start;
        System.out.println("List");
        while(ptr!=null)
        {
            System.out.print(ptr.getData()+" ");
            ptr=ptr.getNext();
        }
        System.out.println();
    }
}