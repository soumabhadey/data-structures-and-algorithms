//program to traverse binary tree non-recursively

#include <stdio.h>
#include <stdlib.h>

//node of binary tree containing data and links to two children
struct node {
    
    struct node *leftchild;
    int data;
    struct node *rightchild;
    
};

//required function prototypes
struct node *buildtree(int [],int);
void inorder(struct node *,int);
void preorder(struct node *,int);
void postorder(struct node *,int);

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
    
    //build binary tree and initialize root pointer
    struct node *root=buildtree(A,0); 
    
    //display inorder traversal of binary tree
    printf("INORDER:\n");
    inorder(root,N);
    
    //display preorder traversal of binary tree
    printf("PREORDER:\n");
    preorder(root,N);
    
    //display postorder traversal of original binary tree
    printf("POSTORDER:\n");
    postorder(root,N);
    
    //display end note
    printf("END\n");
    
    return 0;
    
}

//function to build binary tree from array and return root pointer
struct node *buildtree(int a[],int i) {
    
    struct node *nptr=NULL;
    
    //if node exists
    if(a[i]!=0) {
        
        //allocate memory for new node
        nptr=(struct node *)malloc(sizeof(struct node));
        
        //build left subtree
        nptr->leftchild=buildtree(a,i*2+1);
        
        //store data
        nptr->data=a[i];
        
        //build right subtree
        nptr->rightchild=buildtree(a,i*2+2);
        
    }
    
    //return node pointer
    return nptr;
    
}

//function to display inorder traversal of binary tree
void inorder(struct node *r,int n) {
    
    //create stack for traversal
    struct node *stack[n];
    int top=-1;
    
    //push root into stack
    stack[++top]=r;
    
    //start traversal
    while(1) {
        
        //if node exists then push left child into stack
        if(stack[top]!=NULL)
            stack[++top]=stack[top]->leftchild;
        
        //if node does not exist
        else {
            
            //pop node
            --top;
            
            //if stack is empty then stop
            if(top==-1)
                break;
            
            //display top node
            printf("%d ",stack[top]->data);
            
            //pop top node and push its rightchild
            struct node *temp=stack[top--];
            stack[++top]=temp->rightchild;
            
        }
    }
    
    printf("\n");
    
}

//function to display preorder traversal of binary tree
void preorder(struct node *r,int n) {
    
    //create stack for traversal
    struct node *stack[n];
    int top=-1;
    
    //push root into stack
    stack[++top]=r;
    
    //start traversal
    while(1) {
        
        //if node exists
        if(stack[top]!=NULL) {
            
            //display top node
            printf("%d ",stack[top]->data);
            
            //pop top node and push its rightchild then leftchild
            struct node *temp=stack[top--];
            stack[++top]=temp->rightchild;
            stack[++top]=temp->leftchild;
            
        }
        
        //if node does not exist
        else {
            
            //pop node
            --top;
            
            //if stack is empty then stop
            if(top==-1)
                break;
            
        }
    }
    
    printf("\n");
    
}

//function to display postorder traversal of binary tree
void postorder(struct node *r,int n) {
    
    //create stack for traversal
    struct node *stack[n];
    int done[n];
    int top=-1;
    
    //push root into stack
    stack[++top]=r;
    done[top]=0;
    
    //start traversal
    while(1) {
        
        //if node exists
        if(stack[top]!=NULL) {
            
            //if left and right subtree already traversed
            if(done[top]) {
                
                //display top node
                printf("%d ",stack[top]->data);
                
                //pop
                --top;
                
                //if stack is empty then stop
                if(top==-1)
                    break;
                
            }
            
            //if left and right subtree not traversed
            else {
                
                done[top]=1;
                
                //push rightchild then leftchild
                struct node *temp=stack[top];
                stack[++top]=temp->rightchild;
                done[top]=0;
                stack[++top]=temp->leftchild;
                done[top]=0;
                
            }
            
        }
        
        //if node does not exist
        else {
            
            //pop node
            --top;
            
            //if stack is empty then stop
            if(top==-1)
                break;
            
        }
    }
    
    printf("\n");
    
}







