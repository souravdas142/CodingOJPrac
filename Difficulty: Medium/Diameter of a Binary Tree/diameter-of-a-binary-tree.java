/*
Definition for Node
class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = right = null;
    }
} */

class Solution {
    public int solve(Node root,int[] ans) {
        if(root==null) return 0;
        
        int left = solve(root.left,ans);
        
        int right = solve(root.right,ans);
        
        ans[0] = Math.max(ans[0],left+right);
        
        return Math.max(left,right)+1;
    }
    public int diameter(Node root) {
        // code here
        int[] ans = new int[1];
        ans[0] = 0;
        int x = solve(root,ans);
        //System.out.println(x);
        return ans[0];
    }
}