class node
{
    int data;
    node link;
    node()
    {
        data=0;
        link=null;
    }

    void setData(int d)
    {
        data=d;
    }

    void setLink(node l)
    {
        link=l;
    }

    int getData()
    {
        return data;
    }

    node getLink()
    {
        return link;
    }
}