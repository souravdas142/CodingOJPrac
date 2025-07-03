// User function Template for C++

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        int i = 0;
        
        int ans = 0;
        int mindiff = INT_MAX;
        
        while(i<n) {
            int j = i+1, k = n-1;
            while(j<k) {
                int sum = arr[i]+arr[j]+arr[k];
                
                if(abs(target-sum)<mindiff) {
                    mindiff = abs(target-sum);
                    ans = sum;
                }
                if(abs(target-sum)==mindiff) {
                    ans = max(ans,sum);
                    
                }
                
                if(sum>target) {
                    k--;
                }
                else {
                    j++;
                }
                
            }
            
            i++;
        }
        
        return ans;
        
    }
};