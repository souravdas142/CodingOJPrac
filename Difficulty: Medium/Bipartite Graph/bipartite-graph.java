
class Node{
    public int data;
    public int color;
    public Node(int d, int c) {
        data = d;
        color =c;
    }
}

class Solution {
    
    public boolean bfs(int V, int start, ArrayList<ArrayList<Integer>> adjlist, boolean[] visited) {
        Queue<Node> que = new ArrayDeque<>();
        int[] colors = new int[V];
        Arrays.fill(colors,-1);
        que.add(new Node(start,0));
        visited[start] = true;
        colors[start] = 0;
        
        while(!que.isEmpty()) {
            Node u = que.poll();
            
            for(Integer v: adjlist.get(u.data)) {
                if(visited[v]==false) {
                    visited[v] = true;
                    que.add(new Node(v,1-u.color));
                    colors[v] = 1-u.color;
                    
                }
                else {
                    if(u.color==colors[v]) return false;
                    
                }
            }
            
            
        }
        
        return true;
        
    }
    
    public boolean isBipartite(int V, int[][] edges) {
        // Code here
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        int n = edges.length;
        boolean[] visited = new boolean[V];
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjlist.get(u).add(v);
            adjlist.get(v).add(u);
            
        }
        
        for(int i = 0;i<V;i++) {
            if(visited[i]==false) {
                boolean status = bfs(V,i,adjlist,visited);
                if(status==false) return false;
            }
        }
        
        
        return true;
    }
}