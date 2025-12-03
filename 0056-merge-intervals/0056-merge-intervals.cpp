class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int j = 1;
        while(j<n) {
            if(intervals[j][0]<=end) {
                end = max(end,intervals[j][1]);
            }
            else {
                ans.push_back({start,end});
                start = intervals[j][0];
                end = intervals[j][1];
            }
            j++;

        }
        ans.push_back({start,end});
        return ans;

    }
};