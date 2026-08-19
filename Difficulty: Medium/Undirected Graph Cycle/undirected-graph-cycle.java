
@FunctionalInterface
interface Strategy {
    boolean traverse(ArrayList<ArrayList<Integer>> adjlist, boolean[] visited,int start);
}

class BfsTraversal implements Strategy {
    @Override
    public boolean traverse(ArrayList<ArrayList<Integer>> adjlist, boolean[] visited, int start) {
        
        int n = visited.length;
        
        Deque<int[]> deq = new ArrayDeque<>();
        
        deq.add(new int[]{start,-1});
        visited[start] = true;
        
        while(deq.isEmpty()==false) {
            int[] uu = deq.poll();
            int u = uu[0];
            int p = uu[1];
            
            for(Integer v: adjlist.get(u)) {
                if(visited[v]==false) {
                    visited[v] = true;
                    deq.add(new int[]{v,u});
                }
                else if(visited[v]==true && p!=v) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
}

class DfsTraversal implements Strategy {
    @Override
    public boolean traverse(ArrayList<ArrayList<Integer>> adjlist, boolean[] visited, int u) {
        return false;
    }
}

class Solution {
    public boolean isCycle(int V, int[][] edges) {
        // Code hereli
        
        ArrayList<ArrayList<Integer>> adjlist = new ArrayList<>();
        int n = edges.length;
        
        for(int i = 0;i<V;i++) adjlist.add(new ArrayList<Integer>());
        
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist.get(u).add(v);
            adjlist.get(v).add(u);
        }
        
        boolean[] visited = new boolean[V];
        
        Strategy strategy = new BfsTraversal();
        
        for(int i = 0;i<V;i++) {
            if(visited[i] ==false) {
                boolean status = strategy.traverse(adjlist,visited,i);
                
                if(status == true) return true;
            }
        }
        
        return false;
    }
}