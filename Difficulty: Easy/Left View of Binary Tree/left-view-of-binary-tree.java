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
    private void solve(Node root,int level, ArrayList<Integer> ans) {
        if(root==null) return;
        if(level==ans.size()) {
            ans.add(root.data);
        }
        
        solve(root.left,level+1,ans);
        solve(root.right,level+1,ans);
    }
    public ArrayList<Integer> leftView(Node root) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        int level = 0;
        solve(root,level,ans);
        return ans;
    }
}