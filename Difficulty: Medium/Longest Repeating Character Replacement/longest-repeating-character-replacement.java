class Solution {
    public int longestSubstr(String s, int k) {
        // code here
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        Map<Character,Integer> mp = new HashMap<>();
        int maxi = 0;
        
        while(j<n) {
            
            mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)+1);
            int totalLength = (j-i+1);
            maxi = Math.max(maxi,mp.get(s.charAt(j)));
            int needChanges = totalLength - maxi;
            
            if(needChanges>k) {
                mp.put(s.charAt(i),mp.get(s.charAt(i))-1);
                if(mp.get(s.charAt(i))==0) {
                    mp.remove(s.charAt(i));
                    needChanges-=1;
                }
                i++;
            }
            
            if(needChanges<=k) {
                ans = Math.max(ans,j-i+1);
            }
            
            j++;
        }
        
        // int totalLength = (j-i);
        // int needChanges = mp.size()-1;
        
        // if(needChanges<=k)
        //     ans = Math.max(ans,j-i);
        return ans;
    }
}
