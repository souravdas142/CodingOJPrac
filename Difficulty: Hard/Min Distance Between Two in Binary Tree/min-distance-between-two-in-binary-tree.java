/* A binary tree node
class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}
*/


class Solution {
    
    private Node lca(Node root, int a, int b) {
        if(root== null) return root;
        
        if(root.data==a || root.data==b) return root;
        
        Node left = lca(root.left, a, b);
        Node right = lca(root.right,a,b);
        
        if((left!=null && (left.data==a || left.data==b)) &&
            (right!=null && (right.data ==a || right.data==b))) {
                return root;
        }
        
        if(left==null) return right;
        return left;
    }
    
    int calcHeight(Node root, int a,int level) {
        
        if(root==null) return -1;
        
        if(root.data==a) return level;
        
        int left = calcHeight(root.left,a,level+1);
        if(left!=-1) return left;
        int right = calcHeight(root.right,a,level+1);
        if(right!=-1) return right;
      
        return Math.max(left,right);
    }
    
    public int findDist(Node root, int a, int b) {
        // code here
        
        Node lca = lca(root,a,b);
        
        int h1 = calcHeight(lca,a,0);
        int h2 = calcHeight(lca,b,0);
        
        return Math.abs(h1+h2);
        
    }
}