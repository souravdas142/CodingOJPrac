class Solution {
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        int n = edges.length;
        boolean[] visited = new boolean[V];
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjlist.get(u).add(v);
        }
        Set<Integer> path = new HashSet<>();
        for(int i = 0;i<V;i++) {
            if(visited[i]==false) {
                
                boolean status = dfs(i,adjlist,visited,path);
                path.clear();
                if(status == true) {
                    ///System.out.println(i);
                    return true;
                }
                
            }
        }
        return false;
    }
    
    public boolean dfs(int u, ArrayList<ArrayList<Integer>> adjlist, 
                        boolean[] visited, Set<Integer> path) {
        
        if(visited[u]==true) {
            if(path.contains(u)==true) {
                return true;
            }
            return false;
        }
        path.add(u); 
        visited[u] = true;
        
        for(Integer v: adjlist.get(u)) {
            if(dfs(v, adjlist,visited,path)==true) {
                
                return true;
            }
        }
        path.remove(u);
        return false;
    }
}