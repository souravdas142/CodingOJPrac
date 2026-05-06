class Solution {
    int cntEnclaves(int[][] grid) {
        // code here
        int n = grid.length;
        int m = grid[0].length;;
        
        Deque<int[]> que = new ArrayDeque<>();
        
        for(int i = 0;i<n;i++) {
            if(i==0 || i == n-1) {
                for(int j = 0;j<m;j++) {
                    if(grid[i][j] == 1) {
                        que.add(new int[]{i,j});
                        grid[i][j] = 2;
                    }
                }
            }
            else if(grid[i][0]==1 || grid[i][m-1]==1) {
                if(grid[i][0]==1) {
                    que.add(new int[]{i,0});
                    grid[i][0] = 2;
                }
                if(grid[i][m-1]==1) {
                    que.add(new int[]{i,m-1});
                    grid[i][m-1] = 2;
                }
            }
        }
        
        
        int ans = 0;
        
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};
        
        while(que.isEmpty()!=true) {
            int[] node = que.poll();
            for(int i = 0;i<4;i++) {
                int x = node[0] + dx[i];
                int y = node[1] + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1) {
                    grid[x][y] = 2;
                    que.add(new int[]{x,y});
                }
            }
            
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
}