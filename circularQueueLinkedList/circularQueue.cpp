#include "node.cpp"
class CircularQueue
{
	Node *front, *rear;
   public:
   	CircularQueue()
      {
      	front=rear=NULL;
      }
      CircularQueue(Node *front,Node *rear)
      {
      	this->front=front;
         this->rear=rear;
      }
      void enque()
      {
      	Node *nptr=new Node();
         if(nptr==NULL)
         {
         	cout<<endl<<"Overflow"<<endl;
            return;
         }
         if(isEmpty())
         	front=rear=nptr;
         else
         {
         	rear->setLink(nptr);
            rear=nptr;
         }
         rear->setLink(front);
         cout<<endl<<"Enter item: ";
         int item;
         cin>>item;
         rear->setData(item);
      }
      int delque()
      {
      	Node *temp=front;
         if(front==rear)
         	front=rear=NULL;
         else
         {
         	front=front->getLink();
            rear->setLink(front);
         }
         int item=temp->getData();
         delete temp;
         temp=NULL;
         return item;
      }
      void show()
      {
      	cout<<endl;
      	for(Node *ptr=front;ptr!=rear;ptr=ptr->getLink())
         	cout<<ptr->getData()<<" ";
         cout<<rear->getData()<<endl;
      }
      bool isEmpty()
      {
      	return front==NULL;
      }
};
