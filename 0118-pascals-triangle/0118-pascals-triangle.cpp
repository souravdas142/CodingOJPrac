class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans(numRows);
        ans[0].push_back(1);

        for(int i = 1;i<numRows;i++) {
            vector<int> prev = ans[i-1];
            int j = 0, k =j+1;
            ans[i].push_back(1);
            while(k<prev.size()) {
                ans[i].push_back(prev[j]+prev[k]);
                j++;k++;
            }
            ans[i].push_back(1);
        }

        return ans;

        
        
    }
};