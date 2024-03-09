#include "node.cpp"
using namespace std;
class Queue
{
	private:
		Node *front, *rear;
	public:
		Queue()
		{
			front=rear=NULL;
		}
		Queue(Node *front,Node *rear)
		{
			this->front=front;
			this->rear=rear;
		}
		bool isEmpty()
		{
			return front==NULL;
		}
		void enqueue()
		{
			Node *nptr=new Node();
			if(nptr==NULL)
				cout<<"\nOverflow"<<endl;
			else
			{
				cout<<"\nEnter item: ";
				int item;
				cin>>item;
				nptr->setData(item);
				if(isEmpty())
					front=rear=nptr;
				else
				{
					rear->setLink(nptr);
					rear=rear->getLink();
				}
				show();
			}
		}
		void dequeue()
		{
			if(isEmpty())
				cout<<"\nUnderflow"<<endl;
			else
			{
				cout<<"\n"<<front->getData()<<endl;
				Node *temp=front;
				if(front==rear)
					front=rear=NULL;
				else
					front=front->getLink();
				delete temp;
				temp=NULL;
				show();
			}
		}
		void show()
		{
			if(isEmpty())
				cout<<"\nEmpty"<<endl;
			else
			{
				cout<<"\nQueue"<<endl;
				Node *ptr=front;
				while(ptr!=NULL)
				{
					cout<<ptr->getData()<<"\t";
					ptr=ptr->getLink();
				}
				cout<<endl;
			}
		}
		~Queue()
		{
			while(front!=NULL)
			{
				Node *temp=front;
				front=front->getLink();
				delete temp;
				temp=NULL;
			}
			rear=NULL;
		}
};
