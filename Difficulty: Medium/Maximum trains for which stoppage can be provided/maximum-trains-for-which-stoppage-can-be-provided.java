class Solution {
    
    public int solve(int[][] trains, int i, int j) {
        
        int start = trains[i][0];
        int end = trains[i][1];
        i+=1;
        int cnt = 1;
        while(i<j) {
            if(trains[i][0]>=end) {
                cnt++;
                start = trains[i][0];
                end = trains[i][1];
            }
            i++;
        }
        
        // System.out.println(cnt);
        
        return cnt;
    }
    
    public int maxStop(int plat, int[][] trains) {
        // code here
        int n = trains.length;
        Arrays.sort(trains,(a,b)->{
            if(b[2]==a[2]) {

                return Integer.compare(a[1],b[1]);
            }
            return Integer.compare(a[2],b[2]);
        });
        
        // for(int i = 0;i<n;i++) {
        //     System.out.println(trains[i][0]+" "+trains[i][1]+" "+trains[i][2]);
        // }
        
        int ans = 0;
        
        int i = 0;
        int j = 0;
        
        while(i<n && j<n) {
            if(trains[i][2]!=trains[j][2]) {
                ans += solve(trains,i,j);
                i = j;
            }
            j++;
        }
        
        ans+=solve(trains,i,j);
        
        return ans;
    }
}