class Solution {
    public int maxScore(int[] arr, int k) {
        int n = arr.length;

        int i = n-k;
        int ans = 0;
        int sum = 0;
        int j = i;
        boolean flag = true;

        while(i<n) {
            
            while(j<n && flag && j-i+1<=k) {
                sum+=arr[j];
                
                if(j-i+1==k) {
                    ans = Math.max(sum,ans);
                    //System.out.println("inner "+ans);
                    flag = false;
                }
                j++;

            }
            
            j = j%n;
            

            sum-=arr[i];
            i++;
            sum+=arr[j];
            ans = Math.max(ans,sum);
            j++;
           
           
        }

        return ans;
    }
}