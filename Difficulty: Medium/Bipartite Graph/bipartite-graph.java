
class Node{
    public int data;
    public int color;
    public Node(int d, int c) {
        data = d;
        color =c;
    }
}

class Solution {
    
    public boolean bfs(int V, int start,
                        ArrayList<ArrayList<Integer>> adjlist, 
                        boolean[] visited, int[] colors) {
        Queue<Node> que = new ArrayDeque<>();
        
        
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
    
    public boolean dfs(int u, int p,
                        ArrayList<ArrayList<Integer>> adjlist, 
                        boolean[] visited, int[] colors) {
                            
        if(visited[u]==true) {
            if(colors[u] == colors[p]) return false;
            return true;
        }
        
        visited[u] = true;
        colors[u] = (p<0)?0:1-colors[p];
        
        for(Integer v: adjlist.get(u)) {
            if(dfs(v,u,adjlist,visited,colors)==false) return false;
        }
        
        return true;
                            
    }
    
    public boolean isBipartite(int V, int[][] edges) {
        // Code here
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        int n = edges.length;
        boolean[] visited = new boolean[V];
        int[] colors = new int[V];
        Arrays.fill(colors,-1);
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjlist.get(u).add(v);
            adjlist.get(v).add(u);
            
        }
        
        for(int i = 0;i<V;i++) {
            if(visited[i]==false) {
                // boolean status = bfs(V,i,adjlist,visited,colors);
                boolean status = dfs(i,-1,adjlist,visited,colors);
                if(status==false) return false;
            }
        }
        
        
        return true;
    }
}