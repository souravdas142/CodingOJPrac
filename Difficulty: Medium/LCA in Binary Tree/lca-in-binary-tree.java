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
    
    private Node lcaSolve(Node root, int a, int b) {
        if(root== null) return root;
        
        if(root.data==a || root.data==b) return root;
        
        Node left = lcaSolve(root.left, a, b);
        Node right = lcaSolve(root.right,a,b);
        
        if((left!=null && (left.data==a || left.data==b)) &&
            (right!=null && (right.data ==a || right.data==b))) {
                return root;
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