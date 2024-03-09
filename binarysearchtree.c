#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *leftchild;
	int info;
	struct node *rightchild;
} *root;
struct node * insert(struct node *,int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
int main()
{
	int n,item,i;
	root=NULL;
	printf("Enter number of items: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&item);
		root=insert(root,item);
	}
	printf("Inorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\n");
	return 0;
}
struct node * insert(struct node *ptr,int item)
{
	if(ptr==NULL)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->info=item;
		ptr->leftchild=ptr->rightchild=NULL;
	}
	else if(item<ptr->info)
		ptr->leftchild=insert(ptr->leftchild,item);
	else if(item>ptr->info)
		ptr->rightchild=insert(ptr->rightchild,item);
	return ptr;
}
void inorder(struct node *ptr)
{
	if(ptr==NULL)
		return;
	inorder(ptr->leftchild);
	printf("%d ",ptr->info);
	inorder(ptr->rightchild);
}
void preorder(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d ",ptr->info);
	preorder(ptr->leftchild);
	preorder(ptr->rightchild);
}
void postorder(struct node *ptr)
{
	if(ptr==NULL)
		return;
	postorder(ptr->leftchild);
	postorder(ptr->rightchild);
	printf("%d ",ptr->info);
}
	




