class node
{
    private node prev;
    private int data;
    private node next;
    node()
    {
        prev=null;
        data=0;
        next=null;
    }

    node(node p,int d,node n)
    {
        prev=p;
        data=d;
        next=n;
    }

    node getPrev()
    {
        return prev;
    }

    int getData()
    {
        return data;
    }

    node getNext()
    {
        return next;
    }

    void setPrev(node p)
    {
        prev=p;
    }

    void setData(int d)
    {
        data=d;
    }

    void setNext(node n)
    {
        next=n;
    }
}