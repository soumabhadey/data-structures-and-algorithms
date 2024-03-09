#include "queue.cpp"
int main()
{
	Queue q;
	do
	{
		cout<<"\nMenu"<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Show"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"\nEnter choice: ";
		int choice;
		cin>>choice;
		switch(choice)
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
				return 0;
			default:
				cout<<"\nInvalid choice"<<endl;
		}
	}
	while(true);
}
