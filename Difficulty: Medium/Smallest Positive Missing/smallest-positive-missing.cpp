class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        unordered_map<int,bool> ump;
        
        int n = arr.size();
        for(int i = 0 ;i<n;i++) {
            maxi = max(maxi,arr[i]);
            mini = (arr[i]>=0 && arr[i]<mini)? arr[i]:mini;
            if(arr[i]>=0) ump[arr[i]] = true;
        }
        
        int sum = 0;
        int j = mini;
        
        if(maxi<=0) return 1;
        
        for(int i = 1;i<=maxi;i++) {
            if(ump[i]==false) return i;
        }
        
       
        return maxi+1;
        
       
    }
};