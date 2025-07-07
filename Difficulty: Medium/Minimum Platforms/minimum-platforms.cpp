
ostream& operator << (ostream& print, vector<int>& tmp) {
    for(auto e: tmp) {
        print<<e<<" ";
    }
    return print;
}

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        //cout<<arr<<endl<<dep<<endl;
        
        int cnt = 0;
        
        int n = arr.size();
        int i = 0, j = 0;
        int ans = 0;
        
        while(i<n) {
            if(arr[i]<=dep[j]) {
                cnt++;
                ans = max(ans,cnt);
                i++;
            }
           
            else {
                cnt--;
                j++;
            }
           
        }
      
        return ans;
        
    }
};
