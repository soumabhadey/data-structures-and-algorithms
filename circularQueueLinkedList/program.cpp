#include <conio>
#include "circularQueue.cpp"
int main()
{
	CircularQueue cq;
   do
   {
   	cout<<endl<<"1. Enque"<<endl;
      cout<<"2. Delque"<<endl;
      cout<<"3. Show"<<endl;
      cout<<"0. Exit"<<endl;
      cout<<endl<<"Enter choice: "<<endl;
      int ch;
      cin>>ch;
      switch(ch)
      {
      	case 1:
         	cq.enque();
            break;
         case 2:
         	if(cq.isEmpty())
            	cout<<endl<<"Underflow"<<endl;
            else
            	cout<<endl<<cq.delque()<<endl;
            break;
         case 3:
				if(cq.isEmpty())
            	cout<<endl<<"Empty"<<endl;
            else
            	cq.show();
            break;
         case 0:
         	return 0;
         default:
         	cout<<endl<<"Invalid"<<endl;
      }
   } while(true);
}
