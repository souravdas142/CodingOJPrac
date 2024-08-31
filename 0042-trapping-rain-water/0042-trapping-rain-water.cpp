class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMax(n,0);
        prefixMax[0] = height[0];
        suffixMax[n-1] = height[n-1];
        for(int i = 1,j=n-2;i<n && j>=0;j--,i++) {

            prefixMax[i] = max(prefixMax[i-1],height[i]);
            suffixMax[j] = max(suffixMax[j+1],height[j]);
        }

        int ans = 0;

        for(int i = 0;i<n;i++) {
            int diff = min(prefixMax[i],suffixMax[i]);

            if(diff>height[i]) {
                ans+= (diff-height[i]);
            }
        }

        return ans;
        



    }
};