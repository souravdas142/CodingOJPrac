class Solution {
    
    
    public void bfs(int[][] grid, Deque<int[]> queue, boolean[][] visited, ArrayList<ArrayList<Integer>> gridAns) {
        int[] dx = {0,1,-1,0};
        int[] dy = {1,0,0,-1};
        
        int n = grid.length;
        int m = grid[0].length;
        
        while(queue.isEmpty()!=true) {
            int[] node = queue.poll();
            
            for(int i=0;i<4;i++) {
                int x = node[0]+dx[i];
                int y = node[1]+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==false && grid[x][y] == 0) {
                    visited[x][y] = true;
                    int d = Math.abs(x-node[0])+Math.abs(y-node[1])+node[2];
                    gridAns.get(x).set(y,d);
                    queue.add(new int[]{x,y,d});
                }
            }
            
        }
        
        
    }
    
    public ArrayList<ArrayList<Integer>> nearest(int[][] grid) {
        // code here
        int n = grid.length;
        int m = grid[0].length;
        ArrayList<ArrayList<Integer>> gridAns = new ArrayList<>();
        for(int i = 0;i<n;i++) {
            ArrayList<Integer> arr = new ArrayList<>();
            for(int j = 0;j<m;j++) arr.add(0);
            gridAns.add(arr);
        }
        
        Deque<int[]> queue = new ArrayDeque<>();
        boolean[][] visited = new boolean[n][m];
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                    queue.add(new int[]{i,j,0});
                    
                    visited[i][j] = true;
                }
            }
        }
        
        bfs(grid,queue,visited,gridAns);
        
        return gridAns;
        
    }
}