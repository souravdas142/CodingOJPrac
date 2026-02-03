class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int n = prices.size();

        int j = 0;
        int p = prices[j];

        while(j<n) {
            
            if(prices[j]>p) {
                ans = max(ans,prices[j]-p);
            }
            else {
                p = prices[j];
            }

            j++;
        }




        return ans;
    }
};