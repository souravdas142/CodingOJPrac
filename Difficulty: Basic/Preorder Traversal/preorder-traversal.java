/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    public void solve(Node root, List<Integer> list) {
        if(root==null) return;
        list.add(root.data);
        solve(root.left,list);
        solve(root.right,list);
    }
    public ArrayList<Integer> preOrder(Node root) {
        //  code here
        
        List<Integer> list = new ArrayList<>();
        
        solve(root,list);
        
        return (ArrayList<Integer>)list;
        
    }
}