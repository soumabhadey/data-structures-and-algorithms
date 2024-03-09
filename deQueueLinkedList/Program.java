import java.util.Scanner;
class Program
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        Dequeue dq=new Dequeue();
        do
        {
            System.out.println("1. Insert left");
            System.out.println("2. Insert Right");
            System.out.println("3. Remove left");
            System.out.println("4. Remove right");
            System.out.println("5. Display");
            System.out.println("0. Exit");
            System.out.println("Enter choice");
            switch(sc.nextInt())
            {
                case 1:
                    dq.insertLeft();
                    break;
                case 2:
                    dq.insertRight();
                    break;
                case 3:
                    if(dq.isEmpty())
                        System.out.println("Underflow");
                    else
                        System.out.println(dq.removeLeft());
                    break;
                case 4:
                    if(dq.isEmpty())
                        System.out.println("Underflow");
                    else
                        System.out.println(dq.removeRight());
                    break;
                case 5:
                    dq.display();
                    break;
                case 0:
                    return;
                default:
                    System.out.println("Invalid");
            }
        } while(true);
    }
}