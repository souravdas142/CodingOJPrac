class Solution {
    
    private void bfs(ArrayList<ArrayList<Integer>> adjlist,boolean[] visited,  int start) {
        
        Deque<Integer> dq = new ArrayDeque<>();
        
        dq.add(start);
        visited[start] = true;
        
        while(dq.isEmpty()==false) {
            int u = dq.poll();
            for(Integer v: adjlist.get(u)) {
                
                if(visited[v]==false) {
                    visited[v] = true;
                    
                    dq.add(v);
                }
            }
        }
        
    }
    
    
    int countConnected(int V, ArrayList<ArrayList<Integer>> edges) {
        // code here
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        boolean[] visited = new boolean[V];
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        int n = edges.size();
        for(int i = 0;i<n;i++) {
            
            int u = edges.get(i).get(0);
            int v = edges.get(i).get(1);
        
            adjlist.get(u).add(v);
            adjlist.get(v).add(u);
        }
        
        int ans = 0;
        
        
        
        // System.out.println(adjlist);
        
        for(int i = 0;i<V;i++) {
            if(visited[i]==false) {
                ans++;
                bfs(adjlist,visited,i);
            }
            // for(int j = 0;j<V;j++) {
            // System.out.println(visited[j]);
            // }
        }
        return ans;
    }
}