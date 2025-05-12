class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        
        int maxi = prices[n-1];
        int max_profit = 0;
        if(n==1) return 0;
        int dip = 0;
        for(int r = n-1;r>1;r--) {

            if( prices[r-1]<prices[r]) {
                dip = prices[r-1];
                max_profit = max(max_profit,maxi - dip);
            }
            else {
                maxi = max(maxi,prices[r-1]);
            }

        }

        if(prices[0]<prices[1]) {
            dip = prices[0];
            max_profit = max(max_profit,maxi-dip);
        }

       

        return max_profit;
    }
};