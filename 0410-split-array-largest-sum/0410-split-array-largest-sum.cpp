#define ll long long

class Solution {
public:
    bool is_possible(vector<int>& nums, int n, ll maxSum, int noSubArray) {
        ll sum = 0;
        ll subarr = 1;
        
        for(int i = 0;i<n;i++) {
            sum+=nums[i];
            if(sum>maxSum) {
                subarr++;
                sum = nums[i];
            }
            
            //cout<<nums[i]<<" "<<sum<<" "<<subarr<<endl;
            if(subarr>noSubArray) return false;
        }
        
        if(subarr>noSubArray) return false;
        
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        ll low = INT_MIN;
        ll high = 0;
        for(auto e:nums) {
            high+=e;
            low = (low>e)?low:e;
        }
        //low = 0;
        ll ans = -1;

        while(low<=high) {

            ll mid = low+(high-low)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            if(is_possible(nums,n,mid,k)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};