package BinaryTree;
class Program
{
    public static void main(String args[])
    {
        char a[]={'A','B','C','D','E','F','G','H'};
        int l[]={1,3,5,-1,7,-1,-1,-1};
        int r[]={2,4,6,-1,-1,-1,-1,-1};
        BTree bt=new BTree();
        bt.build(a,l,r);
        bt.inorder();
        bt.preorder();
        bt.postorder();
    }
}