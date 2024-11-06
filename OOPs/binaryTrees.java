import java.util.*;
class BinaryTrees{
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int val, Node leftChild, Node rightChild){
            this.data=val;
            this.left=leftChild;
            this.right=rightChild;
        }

    }
    public static void preorder(Node root){
        if (root==null){
            return;
        }
        System.out.print(root.data +" ");
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String args[]){
        Node n1 = new Node(6, null, null);
        Node n2 = new Node(5, n1, null);
        Node n3 = new Node(4, null, null);
        Node n4 = new Node(2, n3, n2);
        Node n5 = new Node(3, null, null);
        Node n6 = new Node(1, n4, n5);

        preorder(n6);
    }

}