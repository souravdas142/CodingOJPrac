class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int i = 0;
        int j = 0;
        int z = 0;
        int ans = 0;
        Queue<Integer> que = new ArrayDeque<>();

        while(j<n) {

            if(nums[j]==0) {
                z++;
                que.add(j);
            }
            
            if(z>k) {
                ans = Math.max(ans,j-i);
                i = Math.max(i,que.poll()+1);
                z--;
            } 

            j++;
        }
        ans = Math.max(ans,j-i);
        return ans;
    }
}