/* Structure of Binary Tree Node
class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int val) {
        data = val;
        left = null;
        right = null;
    }
};
*/

class Dist {
    public Node node;
    public int dist;
    public Dist(Node node, int dist) {
        this.node = node;
        this.dist =dist;
    }
}
class Solution {
    
    public void dfs(Node root, Node parent, Map<Integer,Node> parents) {
        if(root==null) return;
        parents.put(root.data,parent);
        dfs(root.left,root,parents);
        dfs(root.right,root,parents);
    }
    public ArrayList<Integer> kDistanceNodes(Node root, int target, int k) {
        // code here
        Set<Integer> visited = new HashSet<>();
        Map<Integer,Node> parents = new HashMap<>();
        dfs(root,null,parents);
        
        Node target_parent = null;
        Node targetNode = null;
        target_parent = parents.get(target);
        if(target_parent==null) targetNode = root;
        else if(target_parent.left.data==target) targetNode = target_parent.left;
        else targetNode=target_parent.right;
        
        Queue<Dist> que = new ArrayDeque<>();
        
        que.add(new Dist(targetNode,0));
        visited.add(targetNode.data);
        ArrayList<Integer> ans = new ArrayList<>();
        
        while(!que.isEmpty()) {
            Dist ud = que.poll();
            Node u = ud.node;
            int dist = ud.dist;
            if(dist>k) break;
            if(dist==k) ans.add(u.data);
            if(u.left!=null && visited.contains(u.left.data)==false) {
                visited.add(u.left.data);
                que.add(new Dist(u.left,dist+1));
            } 
            if(u.right!=null && visited.contains(u.right.data)==false) {
                visited.add(u.right.data);
                que.add(new Dist(u.right,dist+1));
            } 
            
            Node parent = parents.get(u.data);
            
            if(parent!=null && visited.contains(parent.data)==false) {
                visited.add(parent.data);
                que.add(new Dist(parent,dist+1));
            } 
            
            
        }
        
        Collections.sort(ans);
        return ans;
    }
}