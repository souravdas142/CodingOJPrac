class Solution {
    
    public boolean bfs(ArrayList<ArrayList<Integer>> adj, boolean[] visited, int src) {
        
        Deque<int[]> que = new ArrayDeque<>();
        
        que.add(new int[]{src,-1});
        
        visited[src] = true;
        
        while(que.isEmpty()!=true) {
            int[] node = que.poll();
            int parent = node[1];
            int cur = node[0];
            
            for(int child: adj.get(cur)) {
                if(visited[child]==false) {
                    visited[child] = true;
                    que.add(new int[]{child,cur});
                }
                else if(visited[child] == true && child!=parent) {
                    return true;   
                }
            }
            
        }
        
        return false;
        
    }
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        int e = edges.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0;i<V;i++) adj.add(new ArrayList<>());
        for(int i = 0;i<e;i++) {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        boolean[] visited = new boolean[V];
        
        
        for(int i = 0;i<V;i++) {
            if(visited[i]==false) {
                boolean ans = bfs(adj,visited,i);
                if(ans==true) return true;
            }
        }
        
        return false;
        

    }
}