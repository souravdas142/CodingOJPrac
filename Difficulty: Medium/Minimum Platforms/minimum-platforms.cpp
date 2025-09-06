class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int,char>> vec;
        int n = arr.size();
        for(int i = 0;i<n;i++) {
            vec.push_back({arr[i],'a'});
            vec.push_back({dep[i],'d'});
        }
        sort(vec.begin(),vec.end());
        int ans = 0;
        int cnt = 0;
        n+=n;
        for(int i = 0;i<n;i++) {
            //cout<<vec[i].second<<endl;
            if(vec[i].second=='a') {
                cnt++;
                ans = max(ans,cnt);
            }
            else {
                cnt--;
            }
        }
        return ans;
    }
};
