class Solution {
private:
    int lbf(vector<int>& arr,int x) {
        int sz = arr.size();
        int left = 0;int right = sz-1;
        while(left<right) {
            int mid = left+(right-left)/2;
            if(arr[mid]>=x) {
                right = mid;
            }
            else {
                left = mid+1;
            }
            
        }
        return left;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // write your code here
        int lb = lbf(arr,x);
        int sz = arr.size();
        vector<int> ans;
        //ans.push_back(arr[lb]);
        int i = lb - 1,j = lb;
        //k--;
        while(i>=0 && j<sz && k>0) {
            if(arr[i]<arr[j]) {
                ans.push_back(arr[i]);
                i--;
            }
            else if(arr[j]<arr[i]) {
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
            ans.push_back(arr[i--]);
            k--;
        }
        while(k>0 && j<sz) {
            ans.push_back(arr[j++]);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};