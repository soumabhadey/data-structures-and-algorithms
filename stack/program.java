import java.util.Scanner;
class program
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        stack s=new stack();
        while(true)
        {
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Count");
            System.out.println("4. Sort");
            System.out.println("5. Peek");
            System.out.println("6. Show");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            int choice=sc.nextInt();
            switch(choice)
            {
                case 1:
                    System.out.print("Enter item: ");
                    int item=sc.nextInt();
                    s.push(item);
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    System.out.println(s.count());
                    break;
                case 4:
                    s.sort();
                    break;
                case 5:
                    s.peek();
                    break;
                case 6:
                    s.show();
                    break;
                case 7:
                    return;
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}