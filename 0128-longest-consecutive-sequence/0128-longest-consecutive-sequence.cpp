class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int,int> ump;
        int sz = nums.size();
        for(int i = 0;i<sz;i++) {
            ump[nums[i]]=1;
        }
        int maxi = 0;
        for(int i = 0;i<sz;i++) {
            int num = nums[i];
            int cnt =ump[num];
            int back = num - 1;
            while(ump.count(back)) {
                if(ump[back]==0) break;
                cnt+=ump[back];
                ump[back]= 0;
                back = back-1;
            }
            ump[num]=cnt;
            maxi = max(maxi,ump[num]);
        }

        return maxi;
        
    }
};