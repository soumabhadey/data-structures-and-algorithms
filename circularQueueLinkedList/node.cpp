#include <iostream>
class Node
{
	int data;
   Node *link;
   public:
   	Node()
      {
      	data=0;
         link=NULL;
      }
      Node(int data,Node *link)
      {
      	this->data=data;
         this->link=link;
      }
      int getData()
      {
      	return data;
      }
      Node * getLink()
      {
      	return link;
      }
      void setData(int data)
      {
      	this->data=data;
      }
      void setLink(Node *link)
      {
      	this->link=link;
      }
};
