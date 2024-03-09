import java.util.Scanner;
class Dequeue
{
    Scanner sc=new Scanner(System.in);
    private Node left,right;
    public Dequeue()
    {
        left=right=null;
    }
    public Dequeue(Node left,Node right)
    {
        this.left=left;
        this.right=right;
    }
    public void insertLeft()
    {
        Node nptr=new Node();
        if(nptr==null)
        {
            System.out.println("Overflow");
            return;
        }
        System.out.println("Enter item");
        nptr.setData(sc.nextInt());
        nptr.setLink(left);
        if(left==null)
            left=right=nptr;
        else
            left=nptr;
    }
    public void insertRight()
    {
        Node nptr=new Node();
        if(nptr==null)
        {
            System.out.println("Overflow");
            return;
        }
        System.out.println("Enter item");
        nptr.setData(sc.nextInt());
        if(right==null)
            left=right=nptr;
        else
        {
            right.setLink(nptr);
            right=nptr;
        }
    }
    public int removeLeft()
    {
        int item=left.getData();
        if(left==right)
            left=right=null;
        else
            left=left.getLink();
        return item;
    }
    public int removeRight()
    {
        int item=right.getData();
        if(left==right)
            left=right=null;
        else
        {
            Node ptr;
            for(ptr=left;ptr.getLink()!=right;ptr=ptr.getLink());
            ptr.setLink(null);
            right=ptr;
        }
        return item;
    }
    public void display()
    {
        if(isEmpty())
        {
            System.out.println("Empty");
            return;
        }
        for(Node ptr=left;ptr!=null;ptr=ptr.getLink())
            System.out.print(ptr.getData()+" ");
        System.out.println();
    }
    public boolean isEmpty()
    {
        return left==null;
    }
}