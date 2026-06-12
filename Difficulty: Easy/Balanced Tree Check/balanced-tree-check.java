/*
Definition for Node
class Node {
    int data;
    Node left, right;

    Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
    public int solve(Node root) {
        if(root==null) return -1;
        int left = solve(root.left);
        if(left==-5) return -5;
        int right = solve(root.right);
        if(right==-5) return -5;
        if(Math.abs(left-right)>1) return -5;
        
        return Math.max(left,right)+1;
    }
    public boolean isBalanced(Node root) {
        // code here
        if(solve(root)==-5) return false;
        return true;
    }
}