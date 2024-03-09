//program to calculate the number of nodes and the number of leaf nodes in a binary tree

#include <stdio.h>
#include <stdlib.h>

//node of binary tree containing data and link to two children
struct node {
    
    struct node *leftchild;
    int data;
    struct node *rightchild;
    
};

//required function prototypes
struct node *buildtree(int *,int);
void inorder(struct node *);
void counttotalandleaf(struct node *,int *,int *);

int main(void) {
    
    //an array representation of the binary tree will be taken input from the user
    
    //read length of array
    printf("ENTER NUMBER OF ITEMS IN ARRAY?\n");
    int N;
    scanf("%d",&N);
    
    //read array items
    printf("ENTER ELEMENTS OF ARRAY?\n");
    int A[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    
    //build binary tree and initialize root pointer
    struct node *root=buildtree(A,0);
    
    //display inorder traversal of binary tree
    printf("INORDER:\n");
    inorder(root);
    printf("\n");
    
    //count total number of nodes and number of leaf nodes
    int total=0,leaf=0;
    counttotalandleaf(root,&total,&leaf);
    
    //display total number of nodes
    printf("TOTAL NUMBER OF NODES:\n");
    printf("%d\n",total);
    
    //display number of leaf nodes
    printf("NUMBER OF LEAF NODES:\n");
    printf("%d\n",leaf);
    
    //display footnote
    printf("END\n");
    
    return 0;
    
}

//function to build binary tree and return root pointer
struct node *buildtree(int *a,int i) {
    
    struct node *nptr=NULL;
    
    //if node exists
    if(*(a+i)!=0) {
        
        //allocate memory for node
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

//function to count the total number of nodes and number of leaf nodes in a binary tree
void counttotalandleaf(struct node *r,int *t,int *l) {
    
    //if node exists
    if(r!=NULL) {
        
        //add 1 to total
        (*t)++;
        
        //if this node is a leaf node then add 1 to leaf
        if(r->leftchild==NULL&&r->rightchild==NULL)
            (*l)++;
        
        //if this node is not a leaf node
        else {
            
            //count total number of nodes and number of leaf nodes in left subtree
            counttotalandleaf(r->leftchild,t,l);
            
            //count total number of nodes and number of leaf nodes in right subtree
            counttotalandleaf(r->rightchild,t,l);
            
        }
        
    }
    
}




