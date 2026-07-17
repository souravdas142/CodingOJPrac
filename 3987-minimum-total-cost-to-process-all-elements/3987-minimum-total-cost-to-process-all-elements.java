class Solution {
    public int minimumCost(int[] nums, int k) {
        int n = nums.length;
        int cost = 0;


        int j = 0;
        long r = k;
        long ct = 0;

        while(j<n) {

            if(r>=nums[j]) {
                r-=nums[j];
            }
            else {
                long need = nums[j]-r;
                long total = (long)Math.ceil(((double)need/(double)k));
                 
                ct+=total;
                //System.out.println(ct);
                r = (total*k)+r;
                r = r-nums[j];
            
            }
            j++;
        }

        long MOD = 1000000007;
        
        long term1 = ct;
        long term2 = ct + 1;
        
        if (term1 % 2 == 0) {
            term1 /= 2;
        } else {
            term2 /= 2;
        }
        
        long ans = ((term1 % MOD) * (term2 % MOD)) % MOD;
        return (int) ans;
    }
}