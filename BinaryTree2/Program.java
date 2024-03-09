package BinaryTree2;
class Program
{
    public static void main(String args[])
    {
        char a[]={'A','B','C','D','E','F','G','\u0000','\u0000','H','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000'};
        BTree bt=new BTree();
        bt.build(a);
        bt.inorder();
        bt.preorder();
        bt.postorder();
    }
}