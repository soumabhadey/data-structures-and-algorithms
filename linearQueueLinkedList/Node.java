class Node
{
    private int data;
    private Node link;
    Node()
    {
        data=0;
        link=null;
    }

    Node(int data,Node link)
    {
        this.data=data;
        this.link=link;
    }

    void setData(int data)
    {
        this.data=data;
    }

    void setLink(Node link)
    {
        this.link=link;
    }

    int getData()
    {
        return data;
    }

    Node getLink()
    {
        return link;
    }
}