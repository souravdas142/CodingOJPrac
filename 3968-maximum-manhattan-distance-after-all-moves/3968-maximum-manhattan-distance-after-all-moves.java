class Solution {
    public int maxDistance(String moves) {
        int n = moves.length();
        int x = 0, y = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            char ch = moves.charAt(i);
            
            if(ch=='L') {
                x = x-1;
            }
            else if(ch=='R') {
                x = x+1;
            }
            else if(ch=='U') {
                y = y+1;
            }
            else if(ch=='D') {
                y = y-1;
            }
            else {
                cnt++;
            }
        }

        int ans = Math.abs(x)+Math.abs(y)+cnt;
        return ans;
    }
}