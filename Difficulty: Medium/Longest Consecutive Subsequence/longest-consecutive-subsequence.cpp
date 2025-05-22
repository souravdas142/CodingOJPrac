class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> ump;
        int n = arr.size();
        for(auto ele: arr) ump[ele]++;
        
        int ans = 0;
        
        for(int i = 0;i<n;i++) {
            if(ump[arr[i]]==0) continue;
            int num = arr[i];
            int left = num-1;
            int right = num+1;
            int cnt = 1;
            while(ump.find(left)!=ump.end()) {
                cnt++;
                ump[left] = 0;
                left--;
            }
            while(ump.find(right)!=ump.end()) {
                cnt++;
                ump[right] = 0;
                right++;
            }
            ans = max(ans,cnt);
            
        }
        
        return ans;
        
    }
};