#include <iostream>
using namespace std;
struct node
{
	node *leftchild;
	char data;
	node *rightchild;
};
struct btree
{
	node *root;
	node * build(char *,int);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
};
node * btree::build(char *a,int index)
{
	node *nptr;
	if(a[index]=='\0')
	{
		return NULL;
	}
	nptr=new node;
	nptr->leftchild=build(a,index*2+1);
	nptr->data=a[index];
	nptr->rightchild=build(a,index*2+2);
	return nptr;
}
void btree::inorder(node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	inorder(ptr->leftchild);
	cout<<ptr->data<<" ";
	inorder(ptr->rightchild);
}
void btree::preorder(node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	cout<<ptr->data<<" ";
	preorder(ptr->leftchild);
	preorder(ptr->rightchild);
}
void btree::postorder(node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	postorder(ptr->leftchild);
	postorder(ptr->rightchild);
	cout<<ptr->data<<" ";
}
int main(void)
{
	char a[]={'A','B','C','D','E','F','G','\0','\0','H','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	btree bt;
	bt.root=bt.build(a,0);
	cout<<"Inorder: ";
	bt.inorder(bt.root);
	cout<<endl<<"Preorder: ";
	bt.preorder(bt.root);
	cout<<endl<<"Postorder: ";
	bt.postorder(bt.root);
	cout<<endl;
	return 0;
}






