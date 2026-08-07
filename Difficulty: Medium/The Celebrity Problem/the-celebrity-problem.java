class Solution {
    public int celebrity(int mat[][]) {
        // code here
        int n = mat.length;
        
        int i = 0;
        int j = i+1;
        
        while(i<n && j<n) {
            if(mat[i][j]==1 && mat[j][i]==1) {
                 i=Math.max(j,i)+1;
                j=Math.max(j,i)+1;
            }
            else if(mat[i][j]==1) {
                i=Math.max(j,i)+1;
            }
            else if(mat[j][i]==1) {
                j=Math.max(j,i)+1;
            }
            else if(mat[i][j]==0 && mat[j][i]==0) {
                //System.out.println(i+" "+j);
                i=Math.max(j,i)+1;
                j=Math.max(j,i)+1;
            }
            
            //System.out.println(i+" "+j);
            /*
            
            0 1
            2 1
            2 3
            4 3
            4 5
            4 7
            
            7
     0 1 2 3 4 5 6
     --------------
0 -> 1 1 1 1 0 0 1
1 -> 0 1 1 1 0 0 1
2 -> 1 0 1 1 0 0 1
3 -> 0 1 0 1 1 0 1
4 -> 1 0 0 0 1 0 1
5 -> 1 1 0 0 1 1 1
6 -> 0 0 0 0 0 0 1
            
            */
        }
        
        int pc = -1;
        
        if(j<n) {
            pc = j;
        }
        else if(i<n) {
            pc = i;
        }
        
        if(pc==-1) return pc;
        
        for(int k = 0;k<n;k++) {
            if(pc==k) continue;
            if(mat[pc][k]==1) return -1;
        }
        
        for(int k = 0;k<n;k++) {
            if(mat[k][pc]==0) return -1;
        }
        
        return pc;
    }
}