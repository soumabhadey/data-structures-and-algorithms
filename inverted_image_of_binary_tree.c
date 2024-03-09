//program to create inverted binary tree

#include <stdio.h>
#include <stdlib.h>

//node of binary tree containing data and links to two children
struct node {
    
    struct node *leftchild;
    int data;
    struct node *rightchild;
    
};

//binary tree containing root pointer
struct binarytree {
    
    struct node *root;
    
};

//required function prototypes
struct node *buildtree(int *,int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node *invert(struct node *);

int main(void) {
    
    //an array representing a binary tree will be read from the user
    
    //read length of array
    printf("ENTER NUMBER OF ITEMS IN ARRAY?\n");
    int N;
    scanf("%d",&N);
    
    //read array items
    printf("ENTER ARRAY ITEMS?\n");
    int A[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    
    //build original binary tree and initialize root pointer
    struct binarytree b;
    b.root=buildtree(A,0);
    
    //display inorder traversal of original binary tree
    printf("ORIGINAL BINARY TREE INORDER:\n");
    inorder(b.root);
    printf("\n");
    
    //display preorder traversal of original binary tree
    printf("ORIGINAL BINARY TREE PREORDER:\n");
    preorder(b.root);
    printf("\n");
    
    //display postorder traversal of original binary tree
    printf("ORIGINAL BINARY TREE POSTORDER:\n");
    postorder(b.root);
    printf("\n");
    
    //build inverted binary tree and initialize root pointer
    struct binarytree m;
    m.root=invert(b.root);
    
    //display inorder traversal of inverted binary tree
    printf("INVERTED BINARY TREE INORDER:\n");
    inorder(m.root);
    printf("\n");
    
    //display preorder traversal of inverted binary tree
    printf("INVERTED BINARY TREE PREORDER:\n");
    preorder(m.root);
    printf("\n");
    
    //display postorder traversal of inverted binary tree
    printf("INVERTED BINARY TREE POSTORDER:\n");
    postorder(m.root);
    printf("\n");
    
    //display end note
    printf("END\n");
    
    return 0;
    
}

//function to build binary tree from array and return root pointer
struct node *buildtree(int *a,int i) {
    
    struct node *nptr=NULL;
    
    //if node exists
    if(*(a+i)!=0) {
        
        //allocate memory for new node
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

//function to display inorder traversal of binary tree
void inorder(struct node *r) {
    
    //if node exists
    if(r!=NULL) {
        
        //display inorder traversal of left subtree
        inorder(r->leftchild);
        
        //display data of this node
        printf("%d ",r->data);
        
        //display inorder traversal of right subtree
        inorder(r->rightchild);
        
    }
}

//function to display preorder traversal of binary tree
void preorder(struct node *r) {
    
    //if node exists
    if(r!=NULL) {
        
        //display data of this node
        printf("%d ",r->data);
        
        //display preorder traversal of left subtree
        preorder(r->leftchild);        
        
        //display preorder traversal of right subtree
        preorder(r->rightchild);
        
    }
}

//function to display postorder traversal of binary tree
void postorder(struct node *r) {
    
    //if node exists
    if(r!=NULL) {
        
        //display postorder traversal of left subtree
        postorder(r->leftchild);        
        
        //display postorder traversal of right subtree
        postorder(r->rightchild);
        
        //display data of this node
        printf("%d ",r->data);
        
    }
}

//function to build inverted binary tree
struct node *invert(struct node *r) {
    
    struct node *nptr=NULL;
    
    //if node exists
    if(r!=NULL) {
        
        //allocate memory for new node
        nptr=(struct node *)malloc(sizeof(struct node));
        
        //build left subtree
        nptr->leftchild=invert(r->rightchild);
        
        //store data
        nptr->data=r->data;
        
        //build right subtree
        nptr->rightchild=invert(r->leftchild);
        
    }
    
    //return node pointer
    return nptr;
    
}






