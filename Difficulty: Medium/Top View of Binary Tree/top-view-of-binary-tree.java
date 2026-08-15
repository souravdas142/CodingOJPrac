/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}
*/

class Pair<T,P> {
    public T first;
    public P second;
    public Pair(T f, P s) {
        this.first = f;
        this.second = s;
    }
    
    
}

class Solution {
    private void solve(Node root, int level, int dir, TreeMap<Integer,Pair<Integer,Integer>> ans) {
        if(root==null) return;
        if(ans.containsKey(dir)) {
            if(ans.get(dir).first>level) {
                ans.get(dir).first=level;
                ans.get(dir).second = root.data;
            }
        }
        else {
            ans.put(dir,new Pair<Integer,Integer>(level,root.data));
        }
        solve(root.left,level+1,dir-1,ans);
        solve(root.right,level+1,dir+1,ans);
        
    }
    public ArrayList<Integer> topView(Node root) {
        // code here
        TreeMap<Integer,Pair<Integer,Integer>> ans = new TreeMap<>();
        ArrayList<Integer> ans2 = new ArrayList<>();
        solve(root,0,0,ans);
       // System.out.println(ans);
        for(int a: ans.keySet()) {
            //System.out.print(ans.get(a)+" ");
            ans2.add(ans.get(a).second);
        }
        return ans2;
    }
}