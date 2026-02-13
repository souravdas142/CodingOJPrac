class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        int totalSum = 0;
        int sum2 = 0;
        
        int j = 0;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        bool allneg = true;
        
        while(j<n) {
            totalSum+=arr[j];
            sum += arr[j];
            sum2 +=arr[j];
            
            mini = min(mini,sum);
            maxi = max(maxi,sum2);
           
            if(sum>0) {
                sum = 0;
            }
            
            if(sum2<0) {
                sum2 = 0;
            }
            
            

            
            j++;
        }
        
        // mini, maxi
        
        if(mini==totalSum) {
            return maxi;
        }
        
        return max(maxi,(totalSum-mini));
        
    }
};