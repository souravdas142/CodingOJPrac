// User function Template for Java

class Solution {

    int maxValue(int arr[]) {
        // Complete the function
        int mod = 1000000007;
        Arrays.sort(arr);
        int n = arr.length;
        int ans = 0;
        for(int i = 1;i<n;i++) {
            ans = (int) ((ans + (long) i * arr[i]) % mod);
        }
        
        return ans;
    }
}
