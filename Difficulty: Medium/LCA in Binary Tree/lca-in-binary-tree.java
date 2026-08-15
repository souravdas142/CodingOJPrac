/* Structure of binary tree node
class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        this.data = val;
        left = right = null;
    }
}
}*/

class Solution {
    
    private Node lcaSolve(Node root, int n1, int n2) {
        if(root==null) return null;
        
        if(root.data==n1 || root.data==n2) {
            return root;
        }
        
        Node left = lcaSolve(root.left,n1,n2);
        Node right = lcaSolve(root.right,n1,n2);
        
        if((left!=null && (left.data==n1 || left.data==n2) ) &&
            (right!=null && (right.data==n1 || right.data == n2))) {
            return root;
        }
        else if(left!=null && (left.data == n1 || left.data==n2)) {
            return left;
        }
        else if(right!=null && (right.data==n1 || right.data==n2)) {
            return right;
        }
        
        if(left==null) return right;
        return left;
    }
    Node lca(Node root, int n1, int n2) {
        // code here
        Node ans = lcaSolve(root,n1,n2);
        return ans;
    }
}