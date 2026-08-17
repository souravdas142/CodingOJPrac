/* Definition for Node
class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int val) {
        data = val;
        left = right = null;
    }
};
*/

class Solution {
    
    public int solve(Node root,int k, int node, int[] ans) {
        
        if(root==null) return Integer.MIN_VALUE;
        
        if(root.data==node) return 0;
        
        int left = solve(root.left,k,node,ans);
    
        int right = Integer.MIN_VALUE;
        
        if(left==Integer.MIN_VALUE)
            right = solve(root.right,k,node,ans);
        
        int cur = Math.max(left,right);
        
        if(cur==Integer.MIN_VALUE) return cur;
        
        cur+=1;
        
        //System.out.println(cur);
        
        if(cur==k) {
            ans[0] = root.data;
        }
        
        return cur;
        
    }
    
    public int kthAncestor(Node root, int k, int node) {
        // code here
        
        int[] ans = new int[1];
        ans[0] = -1;
        
        solve(root,k,node,ans);
        
        return ans[0];
        
    }
}