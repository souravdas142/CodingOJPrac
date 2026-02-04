class Solution {
public:
    int countMonobit(int n) {
        if(n==0) return 1;
        

        int ans = 1;
        for(int i = 0;i<=n;i++) {
            int x = 2<<i;
            if(x-1>n) break;
            if(x-1<=n) ans++;
        }
        return ans;
    }
};