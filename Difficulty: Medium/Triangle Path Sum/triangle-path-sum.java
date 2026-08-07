class Solution {
    
    public int solve(ArrayList<ArrayList<Integer>> triangle, int index, int jc) {
    
        if(jc==-1) return Integer.MAX_VALUE;
        if(index==0) {
            return triangle.get(0).get(0);
        }
        
        
        int m = triangle.get(index).size();
        
        if(jc==m) return Integer.MAX_VALUE;
        
        if(jc==-2) {
            int ans = Integer.MAX_VALUE;
        
            
            for(int j = 0;j<m;j++) {
                int x = solve(triangle,index-1,j);
                int y = solve(triangle,index-1,j-1);
                ans = Math.min(ans,triangle.get(index).get(j)+Math.min(x,y));
                
            }
            return ans;
            
        }
        
        int x = solve(triangle,index-1,jc);
        int y = solve(triangle,index-1,jc-1);
        return triangle.get(index).get(jc)+Math.min(x,y);
        
    }
    
    
    public int solve2(ArrayList<ArrayList<Integer>> triangle, int index, int jc, ArrayList<ArrayList<Integer>> dp) {
    
        if(jc==-1) return Integer.MAX_VALUE;
        if(index==0) {
            return triangle.get(0).get(0);
        }
        
        
        int m = triangle.get(index).size();
        
        if(jc==m) return Integer.MAX_VALUE;
        
        if(jc!=-2 && dp.get(index).get(jc)!=-1) return dp.get(index).get(jc);
        
        if(jc==-2) {
            int ans = Integer.MAX_VALUE;
        
            
            for(int j = 0;j<m;j++) {
                int x = solve2(triangle,index-1,j,dp);
                int y = solve2(triangle,index-1,j-1,dp);
                ans = Math.min(ans,triangle.get(index).get(j)+Math.min(x,y));
                
            }
            return ans;
            
        }
        
        int x = solve2(triangle,index-1,jc,dp);
        int y = solve2(triangle,index-1,jc-1,dp);
        int ans2 = triangle.get(index).get(jc)+Math.min(x,y);
        dp.get(index).set(jc,ans2);
        return ans2;
        
    }
    
    public int minPathSum(ArrayList<ArrayList<Integer>> triangle) {
        // Code here
        int n = triangle.size();
        
        int index = n-1;
        
        ArrayList<ArrayList<Integer>> dp = new ArrayList<>();
        for(int i = 0;i<n;i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for(int j = 0;j<i+1;j++) {
                temp.add(-1);
            }
            dp.add(temp);
        }
        
        int ans = 0;
        // ans = solve(triangle,index,-2);
        ans = solve2(triangle,index,-2,dp);
        return ans;
    }
}