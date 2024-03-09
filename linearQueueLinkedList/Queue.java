import java.util.Scanner;
class Queue
{
    private Node front,rear;
    Queue()
    {
        front=null;
        rear=null;
    }

    Queue(Node front,Node rear)
    {
        this.front=front;
        this.rear=rear;
    }

    void enqueue()
    {
        Scanner sc=new Scanner(System.in);
        Node nptr=new Node();
        if(nptr==null)
            System.out.println("\nOverflow");
        else
        {
            System.out.print("\nEnter item: ");
            nptr.setData(sc.nextInt());
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
            show();
        }
    }

    boolean isEmpty()
    {
        return front==null;
    }

    void show()
    {
        if(isEmpty())
            System.out.println("\nEmpty");
        else
        {
            System.out.println("\nQueue");
            Node ptr=front;
            while(ptr!=null)
            {
                System.out.print(ptr.getData()+"\t");
                ptr=ptr.getLink();
            }
            System.out.println();
        }
    }

    void dequeue()
    {
        if(isEmpty())
            System.out.println("\nUnderflow");
        else
        {
            System.out.println("\n"+front.getData());
            if(front==rear)
            {
                front=null;
                rear=null;
            }
            else
                front=front.getLink();
            show();
        }
    }
}