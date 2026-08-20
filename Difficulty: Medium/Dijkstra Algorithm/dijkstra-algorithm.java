class Solution {
    public ArrayList<Integer> dijkstra(int V, int[][] edges, int src) {
        // code here
        
        int n = edges.length;
        
        ArrayList<ArrayList<int[]>> adjlist = new ArrayList<>();
        
        for(int i = 0;i<V;i++) {
            adjlist.add(new ArrayList<>());
        }
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjlist.get(u).add(new int[]{v,w});
            adjlist.get(v).add(new int[]{u,w});
        }
        
        
        int[] dist = new int[V];
        for(int i = 0;i<V;i++) dist[i] = Integer.MAX_VALUE;
        
        dist[src] = 0;
        
        PriorityQueue<int[]> que = 
        new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        
       
        
        que.add(new int[]{0,src});
        
        while(que.isEmpty()==false) {
            int[] uu = que.poll();
            
            int u = uu[1];
            int w = uu[0];
            
            if(w>dist[u]) continue;
            
            for(int[] vw: adjlist.get(u)) {
                int v = vw[0];
                int wv = vw[1];
                if(w+wv<dist[v]) {
                    dist[v] = w+wv;
                  
                    que.add(new int[]{dist[v],v});
                }
            }
        }
        
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i: dist) ans.add(i);
        
        return ans;
        
    }
}