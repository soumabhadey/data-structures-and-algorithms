class stack
{
    private node top;
    public stack()
    {
        top=null;
    }

    public stack(node t)
    {
        top=t;
    }

    public void push(int item)
    {
        node nptr=new node(item,top);
        top=nptr;

    }

    private boolean isEmpty()
    {
        return top==null;
    }

    public void pop()
    {
        if(isEmpty())
            System.out.println("Empty");
        else
        {
            System.out.println(top.getData());
            top=top.getLink();
        }
    }

    public void show()
    {
        if(isEmpty())
            System.out.println("Empty");
        else
        {
            node ptr=top;
            while(ptr!=null)
            {
                System.out.println(ptr.getData());
                ptr=ptr.getLink();
            }
        }
    }

    public void peek()
    {
        if(isEmpty())
            System.out.println("Empty");
        else
            System.out.println(top.getData());
    }

    public int count()
    {
        int c=0;
        node ptr=top;
        while(ptr!=null)
        {
            c++;
            ptr=ptr.getLink();
        }
        return c;
    }

    public void sort()
    {
        int n=count();
        for(int i=0;i<n;i++)
        {
            node ptr1=top;
            node ptr2=top.getLink();
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
}