import java.util.Scanner;
class Node {
	private int data;
	private Node next;
	Node() {}
	Node(int data,Node next) {
		this.data=data;
		this.next=next;
	}
	void setData(int data) {
		this.data=data;
	}
	void setNext(Node next) {
		this.next=next;
	}
	int getData() {
		return data;
	}
	Node getNext() {
		return next;
	}
}
class Stack {
	private Node top;
	void push(int item) {
		Node nptr=new Node(item,top);
		if(nptr==null) {
			System.out.println("overflow");
			return;
		}
		top=nptr;
	}
	int pop() {
		int item=top.getData();
		top=top.getNext();
		return item;
	}
	boolean isEmpty() {
		return top==null;
	}
	void peek() {
		System.out.println(top.getData());
	}
	void show() {
		show2(top);
		System.out.println();
	}
	void show2(Node ptr) {
		if(ptr==null)
			return;
		System.out.print(ptr.getData()+" ");
		show2(ptr.getNext());
	}
}
class Queue {
	Stack s1,s2;
	Queue() {
		s1=new Stack();
		s2=new Stack();
	}
	void enqueue(int item) {
		s1.push(item);
	}
	int dequeue() {
		while(!s1.isEmpty())
			s2.push(s1.pop());
		int item=s2.pop();
		while(!s2.isEmpty())
			s1.push(s2.pop());
		return item;
	}
	void show() {
		while(!s1.isEmpty())
			s2.push(s1.pop());
		s2.show();
		while(!s2.isEmpty())
			s1.push(s2.pop());
	}
	boolean isEmpty() {
		return s1.isEmpty();
	}
	void peek() {
		while(!s1.isEmpty())
			s2.push(s1.pop());
		s2.peek();
		while(!s2.isEmpty())
			s1.push(s2.pop());
	}
}
class Operate {
	private Scanner sc;
	private Queue q1;
	Operate() {
		sc=new Scanner(System.in);
		q1=new Queue();
	}
	void showMenu() {
		System.out.println("1. enqueue");
		System.out.println("2. dequeue");
		System.out.println("3. peek");
		System.out.println("4. show");
		System.out.println("0. exit");
	}
	void display() {
		do {
			showMenu();
			System.out.print("enter choice: ");
			int choice=sc.nextInt();
			if(choice==0)
				break;
			perform(choice);
		} while(true);
	}
	void perform(int choice) {
		switch(choice) {
			case 1:
				System.out.print("enter item: ");
				q1.enqueue(sc.nextInt());
				q1.show();
				break;
			case 2:
				if(q1.isEmpty()) {
					System.out.println("underflow");
					break;
				}
				System.out.println(q1.dequeue());
				q1.show();
				break;
			case 3:
				if(q1.isEmpty()) {
					System.out.println("empty");
					break;
				}
				q1.peek();
				break;
			case 4:
				if(q1.isEmpty()) {
					System.out.println("empty");
					break;
				}
				q1.show();
				break;
			default:
				System.out.println("invalid choice");
		}
	}
}
class Driver {
	public static void main(String args[]) {
		Operate ot=new Operate();
		ot.display();
	}
}




