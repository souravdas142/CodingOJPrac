class Solution {
    public int longestUniqueSubstr(String s) {
        // code here
        int n = s.length();
        int[] maps = new int[26];
        for(int i = 0;i<26;i++) maps[i] = -1;
        
        int i = 0;
        int j = 0;
        int ans = 0;
        
        while(j<n) {
             
            if(maps[s.charAt(j)-'a']!=-1) {
                ans = Math.max(ans,j-i);
                i = Math.max(i,maps[s.charAt(j)-'a']+1);
            }
            maps[s.charAt(j)-'a'] = j;
           
            j++;
        }
        
        ans = Math.max(ans,j-i);
        
        return ans;
        
    }
}