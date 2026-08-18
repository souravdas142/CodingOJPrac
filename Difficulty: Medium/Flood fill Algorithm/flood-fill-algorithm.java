// class Solution {
//     public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
//         // code here
        
//     }
// }



class Solution {
    int[] dx = {0,1,0,-1};
    int[] dy = {1,0,-1,0};

    public static class Pair <T,P> {
        private T first;
        private P second;
        private Pair(T first, P second) {
            this.first = first;
            this.second = second;
        }

        public T first() {
            return this.first;
        }

        public void first(T first) {
            this.first = first;
        }

        public P second() {
            return this.second;
        }

        public void second(P second) {
            this.second = second;
        }

        public static <T,P> Pair<T,P> makePair(T first, P second) {
            return new Pair<>(first,second);
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {

        int n = image.length;
        int m = image[0].length;

        boolean[][] visited = new boolean[n][m];

        // for(int i = 0;i<n;i++) {
        //     for(int j = 0;j<m;j++) {
        //         if(image[i][j]==color || image[i][j]!=image[sr][sc]) {
        //             visited[i][j] = true;
        //         }
        //     }
        // }


        int oldC = image[sr][sc];

        Deque<Pair<Integer,Integer>> deque = new ArrayDeque<>();


        deque.add(Pair.makePair(sr,sc));
        visited[sr][sc] = true;



        while(deque.isEmpty()==false) {

            Pair<Integer,Integer> pr = deque.poll();

            for(int i = 0;i<4;i++) {
                int nx = pr.first()+dx[i];
                int ny = pr.second()+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny]==false && image[nx][ny]==oldC) {
                    visited[nx][ny] = true;
                    deque.add(Pair.makePair(nx,ny));
                    image[nx][ny]= color;

                }
            }
        }

        image[sr][sc] = color;

        return image;

    }
}