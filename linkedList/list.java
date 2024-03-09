class list
{
    node start;
    list()
    {
        start=null;
    }

    void append(int value)
    {
        node nptr=new node();
        node ptr;
        nptr.setData(value);
        if(start==null)
            start=nptr;
        else
        {
            ptr=start;
            while(ptr.getLink()!=null)
                ptr=ptr.getLink();
            ptr.setLink(nptr);
        }
    }

    void addAtBegin(int value)
    {
        node nptr=new node();
        nptr.setData(value);
        nptr.setLink(start);
        start=nptr;
    }

    void addAtPosition(int value,int position)
    {
        node nptr;
        if(position==1)
        {
            nptr=new node();
            nptr.setData(value);
            nptr.setLink(start);
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
                if(ptr.getLink()==null)
                {
                    System.out.println("Invalid position");
                    return;
                }
                ptr=ptr.getLink();
                i++;
            }
            nptr=new node();
            nptr.setData(value);
            nptr.setLink(ptr.getLink());
            ptr.setLink(nptr);
        }
    }

    void reverse()
    {
        node ptr1,ptr2=null,ptr3=start;
        while(ptr3!=null)
        {
            ptr1=ptr2;
            ptr2=ptr3;
            ptr3=ptr3.getLink();
            ptr2.setLink(ptr1);
        }
        start=ptr2;
    }

    void sort()
    {
        int n=count();
        for(int i=0;i<n;i++)

        {
            node ptr1=start;
            node ptr2=start.getLink();
            for(int j=0;j<n-i-1;j++)
            {
                if(ptr1.getData()>ptr2.getData())
                {
                    int temp=ptr1.getData();
                    ptr1.setData(ptr2.getData());
                    ptr2.setData(temp);
                }
                ptr1=ptr1.getLink();
                ptr2=ptr2.getLink();
            }
        }
    }

    void addSorted(int value)
    {
        node nptr=new node();
        nptr.setData(value);
        if(start==null||value<start.getData())
        {
            nptr.setLink(start);
            start=nptr;
        }
        else
        {
            node ptr=start;
            while(ptr!=null)
            {
                if(value>=ptr.getData()&&(ptr.getLink()==null||value<ptr.getLink().getData()))
                {
                    nptr.setLink(ptr.getLink());
                    ptr.setLink(nptr);
                    return;
                }
                ptr=ptr.getLink();
            }
        }
    }

    void deletePosition(int position)
    {
        if(start==null)
            System.out.println("Empty list");
        else if(position==1)
            start=start.getLink();
        else
        {
            node ptr=start;
            int i=1;
            while(i!=position-1)
            {
                if(ptr.getLink()==null)
                {
                    System.out.println("Invalid position");
                    return;
                }
                ptr=ptr.getLink();
                i++;
            }
            if(ptr.getLink()==null)
            {
                System.out.println("Invalid position");
            }
            else
                ptr.setLink(ptr.getLink().getLink());
        }
    }

    void deallocate()
    {
        start=null;
    }

    int count()
    {
        node ptr=start;
        int c=0;
        while(ptr!=null)
        {
            c++;
            ptr=ptr.getLink();
        }
        return c;
    }

    void display()
    {
        node ptr=start;
        System.out.println("List");
        while(ptr!=null)
        {
            System.out.print(ptr.getData()+" ");
            ptr=ptr.getLink();
        }
        System.out.println();
    }

}