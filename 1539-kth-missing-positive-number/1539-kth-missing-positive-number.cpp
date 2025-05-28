class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;

        while(j<n) {
            int m = arr[j]-i-1;

           
                if(cnt+m>=k) {
                    ans = (i+(k-cnt));
                    break;
                }
                cnt+=m;
            
        
            i = arr[j];


            j++;
        }
        if(k>cnt) {
            return (i+(k-cnt));
        }
        
        return ans;
        
    }
};