class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int> > ans;
        
        sort(intervals.begin(),intervals.end());
cout<<endl;

        for(int i = 0;i<n;i++) {
            for(auto ele:intervals[i]) {
                cout<<ele<<" ";
            }
            cout<<endl;
        }

        vector<int> interval = intervals[0];

        for(int i = 1;i<n;i++) {
            //vector<int> prev = intervals[i-1];
            vector<int> cur = intervals[i];
            if(cur[0]<=interval[1]) {
                
                interval[1] = max(interval[1],cur[1]);
            }
            else {
                ans.push_back(interval);
                interval = cur;
            }
        }
        ans.push_back(interval);
        return ans;
    }
};