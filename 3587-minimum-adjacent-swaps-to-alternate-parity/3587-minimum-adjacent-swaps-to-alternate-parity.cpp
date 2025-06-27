class Solution {
public:
    int tryOutCombination(int oddPos,vector<int>& nums) {
        int n = nums.size();
        int letsSearchForOdds = 0;
        int i = oddPos;
        int ans = 0;
        int icnt = 1;
        int jcnt = 0;
        while(letsSearchForOdds<n) {
            
           
            if(nums[letsSearchForOdds] &1) {
                jcnt++;
                ans += abs(letsSearchForOdds-i);
                i+=2;
                if(i<n) icnt++;
            }


            letsSearchForOdds++;
        }

        if(icnt!=jcnt) return INT_MAX;
       

        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return 0;
        int oddCnt = 0;
        int evenCnt = 0;
        int ans = -1;
        for(int e:nums) {
            if(e&1) oddCnt++;
            else evenCnt++;
           
        }

      
        
        if(abs(evenCnt-oddCnt)>1) return ans;

        // ok lets try two combination
        // even numbers tum gand maro

        int oddPos = 0;

        ans = min(tryOutCombination(oddPos,nums),tryOutCombination(oddPos+1,nums));
        
        return ans;

    }
};