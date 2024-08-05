class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int pick = prices[0];
        int sz = prices.size();
        for(int i = 0;i<sz;i++) {
            if(prices[i]<pick) {
                pick = prices[i];
            }
            else {
                profit = max(profit,prices[i]-pick);
            }

        }

        return profit;
        
    }
};