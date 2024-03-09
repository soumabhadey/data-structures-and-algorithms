//program to calculate the height of a binary tree

#include <stdio.h>
#include <stdlib.h>

//create node of binary tree containing data and link to two children
struct node {
    
    struct node *leftchild;
    int data;
    struct node *rightchild;
    
};

//required function prototypes
struct node *buildtree(int *,int);
void inorder(struct node *);
int height(struct node *);
int max(int,int);

int main(void) {
    
    //an array representation of binary tree will be read from the user
    
    //read length of array
    printf("ENTER NUMBER OF ITEMS IN ARRAY?\n");
    int N;
    scanf("%d",&N);
    
    //read array
    printf("ENTER ARRAY?\n");
    int A[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    
    //root node of binary tree is created and tree is built
    struct node *root=buildtree(A,0);
    
    //display inorder traversal of entered tree
    printf("INORDER:\n");
    inorder(root);
    printf("\n");
    
    //display the height of binary tree
    printf("HEIGHT:\n");
    printf("%d\n",height(root));
    
    //footnote
    printf("END\n");
    
    return 0;
    
}

//function to build binary tree and return root pointer
struct node *buildtree(int *a,int i) {
    
    struct node *nptr=NULL;
    
    //if node is present
    if(*(a+i)!=0) {
        
        //allocate memory
        nptr=(struct node *)malloc(sizeof(struct node));
        
        //build left subtree
        nptr->leftchild=buildtree(a,i*2+1);
        
        //store data
        nptr->data=*(a+i);
        
        //build right subtree
        nptr->rightchild=buildtree(a,i*2+2);
        
    }
    
    //return node pointer
    return nptr;
    
}

//function for inorder traversal of binary tree
void inorder(struct node *r) {
    
    //if node is present
    if(r!=NULL) {
        
        //inorder traversal of left subtree
        inorder(r->leftchild);
        
        //display data of this node
        printf("%d ",r->data);
        
        //inorder traversal of right subtree
        inorder(r->rightchild);
        
    }
    
}

//function to calculate and return height of binary tree
int height(struct node *r) {
    
    //if node is not present then return zero
    if(r==NULL)
        return 0;
    
    //if node is present return height of the tree with this node as root
    return 1+max(height(r->leftchild),height(r->rightchild));
    
}

//function to return maximum between two integers
int max(int a,int b) {
    
    return a>b?a:b;
    
}



