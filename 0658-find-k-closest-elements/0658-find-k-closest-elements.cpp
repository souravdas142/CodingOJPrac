class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int sz = arr.size();
        vector<int> ans;
        auto lb = lower_bound(arr.begin(),arr.end(),x);
        if(lb == arr.end() || lb == arr.end()-1) {
            ans = vector<int>(arr.begin()+(sz-k),arr.end());
            return ans;
        }
        int j = lb-arr.begin();
        int i = j-1;

        while(k>0 && i>= 0 && j<sz) {
            int m = abs(arr[j]-x);
            int n = abs(arr[i]-x);

            if(m<n) {
                ans.push_back(arr[j]);
                j++;
            }
            else {
                ans.push_back(arr[i]);
                i--;
            }
            k--;
        }
        while(k>0 && i>=0) {
            ans.push_back(arr[i]);
            i--;
            k--;
        }
        while(k>0 &&j<sz) {
            ans.push_back(arr[j]);
            j++;
            k--;
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};