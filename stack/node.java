class node
{
    private int data;
    private node link;
    public node()
    {
        data=0;
        link=null;
    }

    public node(int d,node l)
    {
        data=d;
        link=l;
    }

    public void setData(int d)
    {
        data=d;
    }

    public void setLink(node l)
    {
        link=l;
    }

    public int getData()
    {
        return data;
    }

    public node getLink()
    {
        return link;
    }
}