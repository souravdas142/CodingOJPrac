class Solution {
  public:
    bool recurSol(vector<int>& arr, int i, int sum) {
        if(sum==0) {
            return true;
        }
        if(i<0) {
            return false;
        }
        
        if(sum-arr[i]>=0) {
            bool sum1c = recurSol(arr,i-1,sum-arr[i]);
            if(sum1c) return true;
        }
       
      
        bool sum3c = recurSol(arr,i-1,sum);
        if(sum3c) return true;
        
        return false;
        
        
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(auto& e: arr) sum+=e;
        if(sum&1) return false;
        
        return recurSol(arr,n-1,sum>>1);
    }
};