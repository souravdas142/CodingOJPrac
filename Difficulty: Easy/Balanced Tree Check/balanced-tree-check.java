/* Structure of binary tree node
class Node {
    int data;
    Node left, right;

    Node(int d)
    {
        data = d;
        left = right = null;
    }
}*/

class Solution {
    private int solve(Node root) {
        if(root==null) return 0;
        int left = solve(root.left);
        if(left == Integer.MIN_VALUE) return left;
        int right = solve(root.right);
        if(right == Integer.MIN_VALUE) return right;
        
        if(Math.abs(left-right)>1) return Integer.MIN_VALUE;
        
        return 1+Math.max(left,right);
    }
    public boolean isBalanced(Node root) {
        // code here
        
        int ans = solve(root);
        if(ans!=Integer.MIN_VALUE) return true;
        return false;
        
    }
}