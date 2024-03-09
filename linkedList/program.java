import java.util.Scanner;
class program
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        list l=new list();
        char cont='\u0000';
        int value=0,position=0;
        do
        {
            System.out.println("Menu");
            System.out.println("1. Append");
            System.out.println("2. Add at beginning");
            System.out.println("3. Add at given position");
            System.out.println("4. Reverse");
            System.out.println("5. Sort");
            System.out.println("6. Add in sorted order");
            System.out.println("7. Delete position");
            System.out.println("8. Deallocate");
            System.out.println("9. Count");
            System.out.println("10. Display");
            System.out.println("Enter your choice");
            int ch=sc.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.println("Enter value");
                    value=sc.nextInt();
                    l.append(value);
                    break;
                case 2:
                    System.out.println("Enter value");
                    value=sc.nextInt();
                    l.addAtBegin(value);
                    break;
                case 3:
                    System.out.println("Enter value");
                    value=sc.nextInt();
                    System.out.println("Enter position");
                    position=sc.nextInt();
                    l.addAtPosition(value,position);
                    break;
                case 4:
                    l.reverse();
                    break;
                case 5:
                    l.sort();
                    break;
                case 6:
                    System.out.println("Enter value");
                    value=sc.nextInt();
                    l.addSorted(value);
                    break;
                case 7:
                    System.out.println("Enter position");
                    position=sc.nextInt();
                    l.deletePosition(position);
                    break;
                case 8:
                    l.deallocate();
                    break;
                case 9:
                    System.out.println("Number of nodes = "+l.count());
                    break;
                case 10:
                    l.display();
                    break;
                default:
                    System.out.println("Invalid choice");
            }
            System.out.println("Do you want to continue? y/n");
            cont=sc.next().charAt(0);
        }
        while(cont=='y'||cont=='Y');
    }
}