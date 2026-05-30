class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer,Integer> mp = new HashMap<>();
        int n = fruits.length;
        int  i = 0;
        int j = 0;
        int ans = 0;
        while(j<n) {
            
            if(mp.size()==2 && mp.getOrDefault(fruits[j],-1)==-1) {
                ans = Math.max(ans,j-i);
                int key = -1;
                int kv = Integer.MAX_VALUE;
                for(int k: mp.keySet()) {
                    if(mp.get(k)<=kv) {
                        kv = mp.get(k);
                        key = k;
                    } 
                }
                i = Math.max(i,mp.get(key)+1);
              
                mp.remove(key);
            }
            
            mp.put(fruits[j],j);

            j++;
        }
        ans = Math.max(ans,j-i);
        
        return ans;
    }
}