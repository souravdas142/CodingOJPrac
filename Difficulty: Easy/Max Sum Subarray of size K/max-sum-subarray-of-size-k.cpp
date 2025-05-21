class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        int sum = 0;
        while(j<n) {
            
            while(j<k) {
                sum+=arr[j++];
                maxi = max(maxi,sum);
                if(j>=n) return maxi;
            }
            sum -=arr[i];
            sum += arr[j];
            maxi = max(maxi,sum);
            i++;
            j++;
        }
        return maxi;
    }
};