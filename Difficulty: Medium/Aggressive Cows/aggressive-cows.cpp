// User function Template for C++

class Solution {
  public:
  
   bool is_placed_cow(vector<int>& stalls, int mini, int k) {
       
       int n = stalls.size();
       int cow = 1;
       int prev = 0;
       for(int i = 1;i<n;i++) {
           if(stalls[i]-stalls[prev]>=mini) {
               cow++;
               prev = i;
           }
           if(cow==k) return true;
       }
       return false;
       
       
   }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls[n-1]-stalls[0];
        int ans = -1;
        
        while(low<=high) {
            int mid = low+(high-low)/2;
            
            
            if(is_placed_cow(stalls,mid,k)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
            
            
        }
        
        return ans;
        
    }
};