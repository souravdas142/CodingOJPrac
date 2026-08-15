/*
Definition for Node
class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = right = null;

    }
}
*/


class Pair<T,P> {
    private T first;
    private P second;
    private Pair(T f, P s) {
        this.first = f;
        this.second = s;
    }

    public T first() {
        return this.first;
    }

    public P second() {
        return this.second;
    }

    public void first(T f) {
        this.first = f;
    }

    public void second(P s) {
        this.second = s;
    }

    public  static <T,P> Pair<T,P> makePair(T a, P b) {
        return new Pair<T,P>(a,b);
    }


}

class Solution {
    
    private void solve(Node root, int level, int dir, TreeMap<Integer,Pair<Integer,Integer>> ans) {
        if(root==null) return;
        if(ans.containsKey(dir)) {
            if(ans.get(dir).first()<=level) {
                ans.get(dir).first(level);
                ans.get(dir).second(root.data);
            }
        }
        else {
            //ans.put(dir,new Pair<Integer,Integer>(level,root.data));
            ans.put(dir,Pair.makePair(level,root.data));
        }
        solve(root.left,level+1,dir-1,ans);
        solve(root.right,level+1,dir+1,ans);

    }
    
    public ArrayList<Integer> bottomView(Node root) {
        // code here
        
         TreeMap<Integer,Pair<Integer,Integer>> ans = new TreeMap<>();
         ArrayList<Integer> ans2 = new ArrayList<>();
         solve(root,0,0,ans);
        // System.out.println(ans);
         for(int a: ans.keySet()) {
             //System.out.print(ans.get(a)+" ");
             ans2.add(ans.get(a).second());
         }
         return ans2;
    }
}