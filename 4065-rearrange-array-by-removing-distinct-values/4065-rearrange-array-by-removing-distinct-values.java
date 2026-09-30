class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int[] ans = new int[n];
        int[] freq = new int[101];
        for(int i: nums) {
            freq[i]++;
        }
        
        int i = 0;

        while(i<n) {
            int j = 0;
            while(j<101) {
                if(freq[j]>0) {
                    ans[i] = j;
                    freq[j]-=1;
                    i++;
                    if(i>=n) break;
                }
                j++;
            }
        }

        return ans;

            
        
        
    }
}