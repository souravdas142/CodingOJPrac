class Solution {
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        int n = edges.length;
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        int[] indeg = new int[V];
        // boolean[] visited = new boolean[V];
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist.get(u).add(v);
            indeg[v]++;
        }
        
        Queue<Integer> que = new ArrayDeque<Integer>();
        
        for(int i = 0;i<V;i++) {
            if(indeg[i]==0) {
                que.add(i);
                // visited[i]=true;
            }
        }
        
        int ans = 0;
        
        while(!que.isEmpty()) {
            int u = que.poll();
            ans++;
            for(Integer v: adjlist.get(u)) {
                indeg[v]--;
                if(indeg[v]==0) {
                    que.add(v);
                    // visited[v]=true;
                }
            }
        }
        
        if(ans==V) return false;
        return true;
    }
}