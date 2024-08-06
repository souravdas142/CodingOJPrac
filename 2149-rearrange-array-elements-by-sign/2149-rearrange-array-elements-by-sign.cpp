class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int sz = nums.size();
        int pos = 0;
        int neg = 0;
        int index = 0;
        vector<int> ans;

        while(index<sz) {

            while(pos<sz) {
                if(nums[pos++]>=0) break;
            }
            while(neg<sz) {
                if(nums[neg++]<0) break;
            }
            cout<<"pos = "<<pos<<" neg = "<<neg<<endl;
            ans.push_back(nums[pos-1]);
            ans.push_back(nums[neg-1]);







            index = max(pos,neg);
        }
        return ans; 
    }
};