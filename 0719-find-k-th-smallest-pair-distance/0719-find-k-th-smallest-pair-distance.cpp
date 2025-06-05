class Solution {
public:
    bool is_possible(vector<int>& nums,int ans, int k) {
        int i = 0;
        int n = nums.size();
        int j = 1;
        int cnt = 0;
        while(j<n) {
            while(nums[j] - nums[i]>ans) {
                i++;
            }
            cnt += (j-i);
            j++;
        }
        if(cnt<k) return false;
        return true;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
    
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j = 1;
        int i = 0;
        int low = 0;
        int high = nums[n-1]-nums[0];

        while(low<high) {
            int mid = low+(high-low)/2;
            if(is_possible(nums,mid,k)) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }

        return high;

    }
};