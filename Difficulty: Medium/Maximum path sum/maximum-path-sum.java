/*
Definition for Node
class Node{
    int data;
    Node left, right;
    Node(int val){
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    public int solve(Node root, int[] ans) {
        if(root==null) return 0;
        
        int left = solve(root.left,ans);
        int right = solve(root.right,ans);
        
        int x = Math.max(left,right)+root.data;
        int y = left+right+root.data;
        ans[0] = Math.max(ans[0],x);
        ans[0] = Math.max(ans[0],y);
        ans[0] = Math.max(ans[0],root.data);
        
        return Math.max(x,root.data);
        
    }
    int findMaxSum(Node root) {
        // code here
        int[] ans = new int[1];
        ans[0] = root.data;
        solve(root,ans);
        return ans[0];
    }
}