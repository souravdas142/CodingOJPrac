class Solution {
    
    
    public void bfs(int[][] image, int sr, int sc, boolean[][] visited, int oldColor, int newColor ) {
        
        int[] dx = {1,0,0,-1};
        int[] dy = {0,-1,1,0};
        
        int n = image.length;
        int m = image[0].length;
        
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        Deque<int[]> que = new ArrayDeque<>();
        que.add(new int[]{sr,sc});
        
        while(que.isEmpty()!=true) {
            int[] node = que.poll();
            int ur = node[0];
            int uc = node[1];
            for(int i = 0;i<4;i++) {
                int vr = ur+dx[i];
                int vc = uc+dy[i];
                if(vr>=0 && vr<n && vc>=0 && vc<m && visited[vr][vc] == false && image[vr][vc]==oldColor)  {
                    visited[vr][vc] = true;
                    que.add(new int[]{vr,vc});
                    image[vr][vc] = newColor;
                    
                }
            }
        }
        
        
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        // code here
        int n = image.length;
        int m = image[0].length;
        
        
        boolean[][] visited = new boolean[n][m];
        
        int oldColor = image[sr][sc];
        
        bfs(image,sr,sc,visited,oldColor,newColor);
        
        return image;
        
        
    }
}