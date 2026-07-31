class Solution {
    public int cntSubarrays(int[] arr, int k) {
        // code here
        int n = arr.length;
        Map<Integer,Integer> mp = new HashMap<>();
        
        int j = 0;
        int sum = 0;
        int ans = 0;
        
        while(j<n) {
            sum+=arr[j];
            if(sum==k) {
                ans+=1;
            }
            
            int need = sum-k;
            if(mp.containsKey(need)) {
                ans+=mp.get(need);
            }
            
            mp.put(sum,mp.getOrDefault(sum,0)+1);
            j++;
        }
        
        return ans;
    }
}