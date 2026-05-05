class Solution {
    public int orangesRot(int[][] mat) {
        // code here
        int[] dx = {0,1,-1,0};
        int[] dy = {1,0,0,-1};
        int n = mat.length;
        int m = mat[0].length;
        boolean[][] visited = new boolean[n][m];
        Deque<int[]> que = new ArrayDeque<>();
        
        int rotten = 0;
        int fresh = 0;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j]==2) {
                    que.add(new int[]{i,j,0});
                    visited[i][j] = true;
                    rotten++;
                }
                else if(mat[i][j]==1) {
                    fresh++;
                }
            }
        }
        
        int ans = 0;
        
        
        while(que.isEmpty()!=true) {
            int[] unode = que.poll();
            for(int i = 0;i<4;i++) {
                int vr = unode[0]+dx[i];
                int vc = unode[1]+dy[i];
                int t = unode[2]+1;
                if(vr>=0 && vr<n && vc>=0 && vc<m && mat[vr][vc]==1 & visited[vr][vc]==false) {
                    visited[vr][vc]  = true;
                    que.add(new int[]{vr,vc,t});
                    mat[vr][vc] = 2;
                    ans = Math.max(ans,t);
                    fresh--;
                }
            }
        }
        
        if(fresh!=0) return -1;
        return ans;
        
    }
}


