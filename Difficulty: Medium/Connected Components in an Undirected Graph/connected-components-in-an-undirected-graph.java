class Solution {
    
    private void bfs(ArrayList<ArrayList<Integer>> adjlist,
                        boolean[] visited,int i, 
                        ArrayList<ArrayList<Integer>> ans) {
                            
        ArrayList<Integer> ans1 = new ArrayList<>();
        
        visited[i] = true;
        
        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(i);
        
        while(dq.isEmpty()==false) {
            
            int u = dq.poll();
            ans1.add(u);
            
            for(Integer v: adjlist.get(u)) {
                if(visited[v]==false) {
                    visited[v] = true;
                    dq.add(v);
                    
                }
            }
        }
        
        ans.add(ans1);
        
    }
    
    public ArrayList<ArrayList<Integer>> getComponents(int V, int[][] edges) {
        // code here
        int n = edges.length;
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjlist.get(u).add(v);
            adjlist.get(v).add(u);
        }
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        boolean[] visited = new boolean[V];
        
        for(int i = 0;i<V;i++) {
            if(visited[i]==false) {
                bfs(adjlist,visited,i,ans);
            }
        }
        
        return ans;
        
    }
}