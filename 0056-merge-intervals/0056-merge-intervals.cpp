class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        int pstart = intervals[0][0];
        int pend = intervals[0][1];
        int i = 0,j = 1;
        int sz = intervals.size();
        vector<vector<int> > ans;
        while(j<sz) {
            int start = intervals[j][0];
            int end = intervals[j][1];
            if(start<=pend) {
                pend = max(end,pend);
            }
            else {
                ans.push_back({pstart,pend});
                pstart = start;
                pend = end;

            }

            j++;
        }

        ans.push_back({pstart,pend});
        return ans;
        
    }

};