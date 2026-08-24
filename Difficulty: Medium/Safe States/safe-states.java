class Solution {
    public ArrayList<Integer> safeNodes(int V, int[][] edges) {
        // Code here
        
        int n = edges.length;
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist.get(u).add(v);
        }
        
        boolean[] visited = new boolean[V];
        boolean[] loop = new boolean[V];
        
        Set<Integer> path = new HashSet<>();
        
        for(int i = 0;i<V;i++) {
            if(visited[i]==false && loop[i]==false) {
                boolean status = dfs(i,adjlist,visited,loop,path);
                if(status == true) {
                    loop[i] = true;
                }
            }
            path.clear();
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i = 0;i<V;i++) {
            if(loop[i]==false) {
                ans.add(i);
            }
        }
        
        return ans;
        
    }
    
    public boolean dfs(int u, ArrayList<ArrayList<Integer>> adjlist,
                            boolean[] visited, boolean[] loop, Set<Integer> path) {
         
        if(visited[u] == true || loop[u] == true) {
            if(path.contains(u)==true) {
                loop[u] = true;
                return true;
            }
            
            return loop[u];
        }
        
       
        visited[u]= true;
        path.add(u);
        

        
        for(Integer v: adjlist.get(u)) {
            if(dfs(v,adjlist,visited,loop,path)==true) {
                loop[u] = true;
              
                path.remove(u);
                return true;
            }
        }
        
        path.remove(u);
        return false;
    }
}