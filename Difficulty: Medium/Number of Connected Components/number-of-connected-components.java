class Solution {
    
    public void bfs(ArrayList<ArrayList<Integer>> adjlist, int s, int e, boolean[] visited) {
        
        visited[s] = true;
        Queue<Integer> que = new ArrayDeque<>();
        que.add(s);
        
        while(que.isEmpty()!=true) {
            
            int u = que.poll();
            for(int v: adjlist.get(u)) {
                
                if(visited[v]==false) {
                    visited[v] = true;
                    que.add(v);
                }
            }
            
        }
        
        
    } 
    
    int countConnected(int V, ArrayList<ArrayList<Integer>> edges) {
        // code here
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        for(int i = 0;i<V;i++) {
            adjlist.add(new ArrayList<Integer>());
        }
        
        int e = edges.size();
        for(int i = 0;i<e;i++) {
            adjlist.get(edges.get(i).get(0)).add(edges.get(i).get(1));
            adjlist.get(edges.get(i).get(1)).add(edges.get(i).get(0));
        }
        
        
        boolean[] visited = new boolean[V];
        
        int ans = 0;
        
        for(int i = 0;i<V;i++) {
            if(visited[i]==false) {
                ans++;
                bfs(adjlist,i,e,visited);
            }
        }
        
        
        return ans;
        
    }
}