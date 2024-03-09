import java.util.Scanner;
class CircularQueue
{
    private Node front,rear;
    public CircularQueue()
    {
        front=null;
        rear=null;
    }
    public CircularQueue(Node front,Node rear)
    {
        this.front=front;
        this.rear=rear;
    }
    public void enqueue()
    {
        Scanner sc=new Scanner(System.in);
        Node nptr=new Node();
        if(nptr==null)
        {
            System.out.println("\nOverflow");
            return;
        }
        System.out.print("\nEnter item: ");
        int item=sc.nextInt();
        nptr.setData(item);
        if(isEmpty())
        {
            front=nptr;
            rear=nptr;
        }
        else
        {
            rear.setLink(nptr);
            rear=nptr;
        }
        nptr.setLink(front);
    }
    public int delqueue()
    {
        int temp=front.getData();
        if(front==rear)
        {
            front=null;
            rear=null;
        }
        else
        {
            front=front.getLink();
            rear.setLink(front);
        }
        return temp;
    }
    public void show()
    {
        if(isEmpty())
        {
            System.out.println("\nEmpty");
            return;
        }
        System.out.println();
        for(Node ptr=front;ptr.getLink()!=front;ptr=ptr.getLink())
            System.out.print(ptr.getData()+" ");
        System.out.println(rear.getData());
    }
    boolean isEmpty()
    {
        return front==null;
    }
}