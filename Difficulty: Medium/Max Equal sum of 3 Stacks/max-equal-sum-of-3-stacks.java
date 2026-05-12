class Solution {
    public static int maxEqualSum(int n1, int n2, int n3, int[] s1, int[] s2,
                                  int[] s3) {
        // code here
        int s1sum = 0;
        int s2sum = 0;
        int s3sum = 0;
        for(int i: s1) s1sum+=i;
        for(int i: s2) s2sum += i;
        for(int i: s3) s3sum += i;
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        int targetSum = Integer.min(s1sum,Integer.min(s2sum,s3sum));
        
        while(i<n1 && j<n2 && k<n3) {
            targetSum = Integer.min(s1sum,Integer.min(s2sum,s3sum));
            while(s1sum>targetSum && i<n1) {
                s1sum-=s1[i];
                i++;
            }
            while(s2sum>targetSum && j<n2) {
                s2sum-=s2[j];
                j++;
            }
            while(s3sum>targetSum && k<n3) {
                s3sum -= s3[k];
                k++;
            }
            if(s1sum==s2sum && s2sum==s1sum && s3sum==s1sum) break;
        }
        return Integer.min(s1sum,Integer.min(s2sum,s3sum));
    }
}
