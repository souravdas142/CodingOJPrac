class Solution {
    public ArrayList<Integer> shortestPath(int V, int[][] edges) {
        // Code here
        int e = edges.length;
        ArrayList<ArrayList<int[]>> adjlist = new ArrayList<>();
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<int[]>());
        int[] indeg = new int[V];
        int[] dist = new int[V];
        
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[0] = 0;
        
        for(int i = 0;i<e;i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjlist.get(u).add(new int[]{v,w});
            indeg[v]++;
        }
        
        Queue<Integer> que = new ArrayDeque<>();
        que.add(0);
        for(int i = 1;i<V;i++) {
            if(indeg[i]==0) {
                que.add(i);
                dist[i]=-1;
            }
        }
        
        
        
        while(!que.isEmpty()) {
            int u = que.poll();
           // System.out.print(u+" -> ");
            for(int[] vw: adjlist.get(u)) {
                int v = vw[0];
                int w = vw[1];
                if(dist[u]!=-1 && dist[u]!=Integer.MAX_VALUE && dist[v]>dist[u]+w) {
                    dist[v] = dist[u]+w;
                }
                indeg[v]--;
                if(indeg[v]==0) {
                    que.add(v);
                }
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i = 0;i<V;i++) {
            if(dist[i]==Integer.MAX_VALUE) dist[i]=-1;
            ans.add(dist[i]);
        }
        
        return ans;
        
    }
}