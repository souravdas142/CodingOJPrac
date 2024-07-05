#include <bits/stdc++.h>
using namespace std;
#define newln "\n"
#define debug(x) cout<<__LINE__<<":: "<<#x<<" = "<<newln
#define ull unsigned long long 

class Solution {
    
    private:
        
        int mind(int x) {
            int min_ = INT_MAX;
            while(x) {
                min_ = min(min_,x%10);
                x=x/10; 
            }
        }
        int maxd(int x) {
            int maxd_ = INT_MIN;
            while(x) {
                maxd_ = max(maxd_,x%10);
                x=x/10; 
            }
        }
        
        int solve() {
            
            if(i == 1) return a1;
            int ans = solve();

            int min_ = mind(ans);
            int max_ maxd(ans);



            return ans;

            
            
            
        }
            

    public:

        int solve_main() {
            
            ull tc =1;
            cin>>tc;
            while(tc--) {
                
                solve();
                
            }
            
            return 0;
            
        }




};

int main() {

    Solution sol;
    sol.solve_main();
    return 0;

}

