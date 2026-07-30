class Solution {
    public int longestSubarray(int[] arr, int k) {
        // code here
        int n = arr.length;
        
        int i = 0;
        int j = 0;
        
        int prefixSum = 0;
        
        Map<Integer,Integer> map = new HashMap<>();
        int sum = 0;
        
        int ans = 0;
        
        while(j<n) {
            sum += arr[j];
            if(sum==k) {
                ans = Math.max(ans,j+1);
            }
            int find = sum-k;
            if(map.containsKey(find)) {
                ans = Math.max(ans,j-map.get(find));
            }
            
            if(map.containsKey(sum)==false) {
                map.put(sum,j);
            }
            j++;
        }
        
        return ans;
    }
}
