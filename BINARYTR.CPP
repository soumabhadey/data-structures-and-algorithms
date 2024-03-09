#include <iostream.h>
#include <conio.h>
struct node
{
	node *leftchild;
	char data;
	node *rightchild;
};
struct btree
{
	node *root;
	node * build(char *a,int *l,int *r,int index)
	{
		node *nptr;
		if(index==-1)
		{
			return NULL;
		}
		nptr=new node;
		nptr->leftchild=build(a,l,r,l[index]);
		nptr->data=a[index];
		nptr->rightchild=build(a,l,r,r[index]);
		return nptr;
	}
	void inorder(node *ptr)
	{
		if(ptr==NULL)
		{
			return;
		}
		inorder(ptr->leftchild);
		cout<<ptr->data<<" ";
		inorder(ptr->rightchild);
	}
	void preorder(node *ptr)
	{
		if(ptr==NULL)
		{
			return;
		}
		cout<<ptr->data<<" ";
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
	void postorder(node *ptr)
	{
		if(ptr==NULL)
		{
			return;
		}
		postorder(ptr->leftchild);
		postorder(ptr->rightchild);
		cout<<ptr->data<<" ";
	}
};
int main(void)
{
	char a[]={'A','B','C','D','E','F','G','H'};
	int l[]={1,3,5,-1,7,-1,-1,-1};
	int r[]={2,4,6,-1,-1,-1,-1,-1};
	btree bt;
    clrscr();
	bt.root=bt.build(a,l,r,0);
	cout<<"Inorder: ";
	bt.inorder(bt.root);
	cout<<endl;
	cout<<"Preorder: ";
	bt.preorder(bt.root);
	cout<<endl;
	cout<<"Postorder: ";
	bt.postorder(bt.root);
	cout<<endl;
    getch();
	return 0;
}