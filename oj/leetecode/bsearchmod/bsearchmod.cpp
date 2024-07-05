#include <bits/stdc++.h>
using namespace std;
#define newln "\n"
#define debug(x) cout<<newln<<#x<<" = "<<x<<newln

class Solution {

    public:

        int searchInsert(vector<int>& nums,int target) {
            
            int low = 0;
            int high = nums.size();
            
            while(low<high) {
                int mid = (high+low)/2;
                if(target == nums[mid]) {
                    return mid;
                }
                else if(target>nums[mid]) {
                    low = mid+1;
                }
                else {
                    high = mid - 1;
                }
                
                debug(low);
                debug(high);
            }
            
            return low+1;





        }



};

int main() {
    
    vector<int> vec = {1,2,3,4,8};
    Solution solve;
    cout<<"pos = "<<solve.searchInsert(vec,8)<<endl;
    return 0;



    
}