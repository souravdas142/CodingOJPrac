class Solution {
    public int longestUniqueSubstr(String s) {
        // code here
        
        int n = s.length();
        int[] charArr = new int[26];
        for(int i = 0;i<26;i++) charArr[i] = -1;
        
        int j = 0;
        int i = 0;
        int ans = 1;
        
        while(j<n) {
            
            
            if(charArr[s.charAt(j)-'a']!=-1) {
                i = Math.max(i,charArr[s.charAt(j)-'a']+1);
            }
            
            charArr[s.charAt(j)-'a'] = j;
            
            ans = Math.max(ans,j-i+1);
            
            j++;
        }
        return ans;
    }
}