// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int ans = INT_MIN;
        int diff = INT_MAX;
        
        for(int i = 0;i<n;i++) {
            int j = i+1;
            int k = n-1;
            //diff = INT_MAX;
            
            while(j<k) {
                int x = arr[i]+arr[j]+arr[k];
                if(abs(target-x)<diff) {
                    diff = abs(target-x);
                    //cout<<i<<j<<k<<endl;
                    ans = x;
                }
                if(abs(target-x)==diff) {
                    diff = abs(target-x);
                    //cout<<i<<j<<k<<endl;
                    ans = max(ans,x);
                }
                if(x<target) {
                    j++;
                }
                else  {
                    k--;
                }
            }
        }
        return ans;
    }
};
