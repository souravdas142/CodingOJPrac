class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k==0) return 0;
        int i = 0;
        int j = 0;
        int lastNum = 0;
        int maxi = 0;
        while(j<n) {

            if(nums[j]==0) {
                if(k>0) {
                    
                    k--;
                }
                else {
                    while(nums[i]!=0) i++;
                    i++;
                
                }
                

            }
            maxi = max(maxi,j-i+1);
            cout<<i<<endl;
            j++;
        }
        return maxi;
    }
};