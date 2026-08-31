/* Structure of binary tree node
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}*/

class Dist {
    public Node node;
    public int dist;
    public Dist(Node node, int dist) {
        this.node = node;
        this.dist = dist;
    }
}


class Solution {
    
    public void dfs(Node root, Node parent, Map<Integer,Node>parents) {
        if(root==null) return;
        parents.put(root.data,parent);
        dfs(root.left,root,parents);
        dfs(root.right,root,parents);
    }
    
    public int minTime(Node root, int target) {
        // code here
        Set<Integer> visited = new HashSet<>();
        Map<Integer,Node> parents = new HashMap<>();
        dfs(root,null,parents);
        
        int ans = Integer.MIN_VALUE;
        
        Queue<Dist> que = new ArrayDeque<>();
        Node targetParent = parents.get(target);
        Node targetRoot = null;
        if(targetParent==null) targetRoot = root;
        else if(targetParent.left!=null && targetParent.left.data==target) {
            targetRoot = targetParent.left;
        }
        else {
            targetRoot = targetParent.right;
        }
        
        que.add(new Dist(targetRoot,0));
        visited.add(targetRoot.data);
        
        while(!que.isEmpty()) {
            Dist ud = que.poll();
            Node u = ud.node;
            int dist = ud.dist;
            
            ans = Math.max(ans,dist);
            
            Node v = u.left;
            if(v!=null && visited.contains(v.data)==false) {
                visited.add(v.data);
                que.add(new Dist(v,dist+1));
                
            }
            
            v = u.right;
            
            if(v!=null && visited.contains(v.data)==false) {
                visited.add(v.data);
                que.add(new Dist(v,dist+1));
                
            }
            
            v = parents.get(u.data);
            
            if(v!=null && visited.contains(v.data)==false) {
                visited.add(v.data);
                que.add(new Dist(v,dist+1));
                
            }
            
        }
        
        return ans;
    }
}