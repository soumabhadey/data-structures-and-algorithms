import java.util.Scanner;
class Program
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        Queue q=new Queue();
        do
        {
            System.out.println("\nMenu");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Show");
            System.out.println("0. Exit");
            System.out.print("\nEnter choice: ");
            switch(sc.nextInt())
            {
                case 1:
                    q.enqueue();
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.show();
                    break;
                case 0:
                    System.exit(0);
                default:
                    System.out.println("\nInvalid choice");
            }
        }
        while(true);
    }
}