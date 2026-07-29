class Solution {
    public int longestKSubstr(String s, int k) {
        // code here
        int n = s.length();
        int[] freq = new int[26];
        
       // for(int i = 0;i<n;i++) freq[i] = -1;
        
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = -1;
        
        while(j<n) {
            
            if(freq[s.charAt(j)-'a']==0) {
                cnt++;
            }
            freq[s.charAt(j)-'a']++;
            if(cnt>k) {
                freq[s.charAt(i)-'a']--;
                if(freq[s.charAt(i)-'a']==0) {
                    cnt--;
                }
                i++;
                
            }
            
            
            
            if(cnt==k) {
                ans = Math.max(ans,j-i+1);
            }
            j++;
        }
        
        return ans;
    }
}