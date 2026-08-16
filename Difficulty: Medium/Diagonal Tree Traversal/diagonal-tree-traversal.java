/* Node is defined as
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}*/
class Tree {
    
    private void solve(Node root,int level, ArrayList<ArrayList<Integer>> ians) {
        if(root==null) return;
        
        if(ians.size()==level) {
            ians.add(new ArrayList<Integer> ());
        }
        ians.get(level).add(root.data);
        
        solve(root.left,level+1,ians);
        solve(root.right,level,ians);
        
        
    }
    
    public ArrayList<Integer> diagonal(Node root) {
        // add your code here.
        ArrayList<ArrayList<Integer>> ians = new ArrayList<>();
        ArrayList<Integer> ans = new ArrayList<>();
        int level = 0;
        
        solve(root,level,ians);
        
        for(ArrayList<Integer> jans:ians) {
            ans.addAll(jans);
        }
        
        return ans;
    }
}