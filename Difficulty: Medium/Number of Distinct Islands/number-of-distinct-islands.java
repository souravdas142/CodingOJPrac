class Solution {
    
    public void bfs(char[][] grid, int i, int j, boolean[][] visited, TreeSet<List<int[]>> hashedBfs) {
        
        int[] dx = {0,1,-1,0};
        int[] dy = {1,0,0,-1};
        int n =grid.length;
        int m = grid[0].length;
        
        Queue<int[]> que = new ArrayDeque<>();
        List<int[]> ans = new ArrayList<>();
        
        visited[i][j] = true;
        que.add(new int[]{i,j});
        
        while(!que.isEmpty()) {
            int[] node = que.poll();
            
            
            for(int ii = 0;ii<4;ii++) {
                int x = node[0]+dx[ii];
                int y = node[1]+dy[ii];
                if(x>=0 && y>=0 && x<n && y<m && visited[x][y] == false && grid[x][y] == 'L') {
                    que.add(new int[]{x,y});
                    visited[x][y] = true;
                }
            }
            
            node[0] -= i;
            node[1] -= j;
            ans.add(node);
            
        }
        
        // for(int[] x: ans) {
        //     System.out.print(x[0]+", "+x[1]+" -> ");
        // }
        hashedBfs.add(ans);
    }
    
    public int countDistinctIslands(char[][] grid) {
        // code here
        int n =grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        TreeSet<List<int[]>> hashedBfs = new TreeSet<>((list1,list2)->{
            if (list1.size() != list2.size()) return Integer.compare(list1.size(), list2.size());
            int c = list1.size();
            for(int s = 0;s<c;s++) {
                int[] arr1 = list1.get(s);
                int[] arr2 = list2.get(s);
                if(arr1[0]!=arr2[0]) return Integer.compare(arr1[0],arr2[0]);
                if(arr1[1]!=arr2[1]) return Integer.compare(arr1[1],arr2[1]);
            }
            return 0;
        });
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]=='L' && visited[i][j]==false) {
                    bfs(grid,i,j,visited,hashedBfs);
                }
            }
        }
        
        // System.out.println(hashedBfs);
        
        return hashedBfs.size();
    }
}