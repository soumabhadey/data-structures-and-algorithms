package BinaryTree2;
class BTree
{
    Node root;
    void build(char a[])
    {
        root=build2(a,0);
    }
    Node build2(char a[],int index)
    {
        if(a[index]=='\u0000')
            return null;
        Node nptr=new Node();
        nptr.leftchild=build2(a,index*2+1);
        nptr.data=a[index];
        nptr.rightchild=build2(a,index*2+2);
        return nptr;
    }
    void inorder()
    {
        System.out.print("Inorder: ");
        inorder2(root);
        System.out.println();
    }
    void inorder2(Node ptr)
    {
        if(ptr==null)
            return;
        inorder2(ptr.leftchild);
        System.out.print(ptr.data+" ");
        inorder2(ptr.rightchild);
    }
    void preorder()
    {
        System.out.print("Preorder: ");
        preorder2(root);
        System.out.println();
    }
    void preorder2(Node ptr)
    {
        if(ptr==null)
            return;
        System.out.print(ptr.data+" ");
        preorder2(ptr.leftchild);
        preorder2(ptr.rightchild);
    }
    void postorder()
    {
        System.out.print("Postorder: ");
        postorder2(root);
        System.out.println();
    }
    void postorder2(Node ptr)
    {
        if(ptr==null)
            return;
        postorder2(ptr.leftchild);
        postorder2(ptr.rightchild);
        System.out.print(ptr.data+" ");
    }
}