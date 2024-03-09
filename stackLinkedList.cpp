#include <iostream>
using namespace std;
class node
{
	private:
		int data;
		node *link;
	public:
		node()
		{
			data=0;
			link=NULL;
		}
		node(int d,node *l)
		{
			data=d;
			link=l;
		}
		int getData()
		{
			return data;
		}
		node *getLink()
		{
			return link;
		}
		void setData(int d)
		{
			data=d;
		}
		void setLink(node *l)
		{
			link=l;
		}
};
class stack
{
	private:
		node *top;
	public:
		stack()
		{
			top=NULL;
		}
		stack(node *t)
		{
			top=t;
		}
		bool isEmpty()
		{
			return top==NULL;
		}
		void push(int item)
		{
			
			node *nptr=new node(item,top);
			top=nptr;
		}
		void pop()
		{
			if(isEmpty())
			{
				cout<<"empty"<<endl;
				return;
			}
			node *temp=top;
			top=top->getLink();
			cout<<temp->getData()<<endl;
			delete temp;
		}
		void peek()
		{
			if(isEmpty())
			{
				cout<<"empty"<<endl;
				return;
			}
			cout<<top->getData()<<endl;
		}
		void show()
		{
			if(isEmpty())
			{
				cout<<"empty"<<endl;
				return;
			}
			node *ptr=top;
			while(ptr!=NULL)
			{
				cout<<ptr->getData()<<endl;
				ptr=ptr->getLink();
			}
		}
		~stack()
		{
			while(top!=NULL)
			{
				node *temp=top;
				top=top->getLink();
				delete temp;
			}
		}
};
int main()
{
	stack s;
	while(true)
	{
		cout<<"0. exit"<<endl;
		cout<<"1. push"<<endl;
		cout<<"2. pop"<<endl;
		cout<<"3. peek"<<endl;
		cout<<"4. show"<<endl;
		cout<<"Enter choice: ";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 0:
				return 0;
			case 1:
				cout<<"Enter item: ";
				int item;
				cin>>item;
				s.push(item);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.peek();
				break;
			case 4:
				s.show();
				break;
		}
	}
}