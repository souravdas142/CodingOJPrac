/* Structure of Binary Tree Node
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
    
    private void solve(Node root, int level, ArrayList<ArrayList<Integer>> arr) {
       
       if(root==null) return;
       
        if(level == arr.size()) {
            arr.add(new ArrayList<Integer>());
            
        }
        
            arr.get(level).add(root.data);
        
        
        solve(root.left,level+1,arr);
        solve(root.right,level+1,arr);
        
    }
    ArrayList<Integer> zigZagTraversal(Node root) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        ArrayList<ArrayList<Integer>> ansi = new ArrayList<>();
        int level = 0;
        solve(root,0,ansi);
        
        int i = 0;
        for(ArrayList<Integer> arr: ansi) {
            if(i%2==1) {
                Collections.reverse(arr);
            }
            ans.addAll(arr);
            i++;
            
        }
        
        return ans;
        
    }
}