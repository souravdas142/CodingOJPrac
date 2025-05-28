class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high) {
            int mid = low+(high-low)/2;

            int cnt = arr[mid]-mid-1;
            
            if(cnt<k) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        if(ans == -1) return k;
        int nom = arr[ans]-ans;
        return (arr[ans]+(k-nom)+1);
        
    }
};