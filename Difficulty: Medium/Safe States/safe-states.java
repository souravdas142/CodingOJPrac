class Solution {
    public ArrayList<Integer> safeNodes(int V, int[][] edges) {
        // Code here
        int n = edges.length;
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        int[] indeg = new int[V];
        Queue<Integer> que = new ArrayDeque<>();
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjlist.get(v).add(u);
            indeg[u]++;
        }
        
        
        
        for(int i = 0;i<V;i++) {
            if(indeg[i]==0) {
                que.add(i);
            }
        }
        
        while(!que.isEmpty()) {
            int u = que.poll();
            ans.add(u);
            
            for(Integer v: adjlist.get(u)) {
                indeg[v]--;
                if(indeg[v]==0) {
                    que.add(v);
                }
            }
        }
        
        return ans;
        
    }
}