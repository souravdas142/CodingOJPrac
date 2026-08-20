class Solution {
    public ArrayList<ArrayList<Integer>> nearest(int[][] grid) {
        // code here
        int dx[] = {1,0,0,-1};
        int dy[] = {0,1,-1,0};
        
        int n = grid.length;
        int m = grid[0].length;
        
        boolean[][] visited = new boolean[n][m];
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for(int i = 0;i<n;i++) {
            ArrayList<Integer> temp = new ArrayList<Integer>();
            for(int j = 0;j<m;j++) {
                temp.add(0);
            }
            ans.add(temp);
        }
        
        Deque<int[]> dq = new ArrayDeque<>();
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==1) {
                    dq.add(new int[]{i,j,0});
                    visited[i][j] = true;
                }
            }
        }
        
        while(dq.isEmpty()==false) {
            int[] uu = dq.poll();
            
            for(int i = 0;i<4;i++) {
                int nx = uu[0]+dx[i];
                int ny = uu[1]+dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==false && grid[nx][ny]==0) {
                    dq.add(new int[]{nx,ny,uu[2]+1});
                    visited[nx][ny] = true;
                    ans.get(nx).set(ny,uu[2]+1);
                }
            }
        }
        
        return ans;
        
    }
}