import java.util.Scanner;
class Program
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        CircularQueue cq=new CircularQueue();
        do
        {
            System.out.println("\n1. Insert");
            System.out.println("2. Remove");
            System.out.println("3. Show");
            System.out.println("0. Exit");
            System.out.print("\nEnter choice: ");
            int ch=sc.nextInt();
            switch(ch)
            {
                case 1:
                    cq.enqueue();
                    break;
                case 2:
                    if(cq.isEmpty())
                        System.out.println("\nUnderflow");
                    else
                        System.out.println("\n"+cq.delqueue());
                    break;
                case 3:
                    cq.show();
                    break;
                case 0:
                    return;
                default:
                    System.out.println("\nInvalid");
            }
        } while(true);
    }
}