class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 1;
        int j = 0;
        int cnt = 0;

        while(j<n) {
            if(i == arr[j]) {
                i++;j++;
            }
            else {
                cnt++;
                if(cnt == k) {
                    cnt = i;
                    break;
                }
                i++;
            }
        }
        if(k>cnt) {
            k = k-cnt;
            return (arr[n-1]+k);
        }
        return cnt;
        
    }
};