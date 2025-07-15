#define ll long long

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ll sum = 0;
        int n = nums.size();
        for(int& e: nums) {
            sum+=e;
        }
        cout<<sum<<endl;
        if(sum<p) return -1;
        if(sum%p==0) return 0;
        

        int rem = sum%p;

        int ans = n;

   
        int j = 0;
        ll lsum = 0;
   
        unordered_map<int,int> prefixMod;
        prefixMod[0] = -1;

        while(j<n) {
            lsum+=nums[j];
            int curMod = lsum%p;
            int targetMod = (curMod-rem+p)%p;
            
            if(prefixMod.find(targetMod)!=prefixMod.end()) {
                ans = min(ans,j-prefixMod[targetMod]);
            }
            
            prefixMod[curMod] = j;
            j++;
        }

        if(ans==n) return -1;
        return ans;


    }
};