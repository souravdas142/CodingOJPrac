class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        int ele1 = 0, ele2 = 0, cnt1 = 0, cnt2 = 0;
        int i = 0;
        while(i<n) {
            
            if (cnt1==0 && nums[i]!=ele2) {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2==0 && nums[i]!=ele1) {
                ele2 = nums[i];
                cnt2 = 1;
            } 
            else if (nums[i]==ele1) {
                cnt1++;
            }
            else if(nums[i]==ele2) {
                cnt2++;
            }
            else {
                cnt1--; cnt2--;
            }
            i++;
        }
        vector<int> ans;
        i = 0, cnt1 = 0, cnt2 = 0;
        while(i<n) {
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
            i++;
        }
        int mini = (n/3)+1;

        if(cnt1>=mini) {
            ans.push_back(ele1);
            
        }
        if(cnt2>=mini && ele1!=ele2) {
            ans.push_back(ele2);
        }
        sort(ans.begin(),ans.end());
        return ans;

        
    }
};