/* Structure of Binary Tree Node
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = this.right = null;
    }
}*/

class Solution {
    
    private void solve(Node root, ArrayList<Integer> ans, int level) {
        
        if(root==null) return;
        
        if(ans.size()==level)
            ans.add(root.data);
            
        solve(root.left,ans,level+1);
        solve(root.right,ans,level+1);
    }
    
    public ArrayList<Integer> leftView(Node root) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        int level = 0;
        
        solve(root,ans,level);
        return ans;
    }
}