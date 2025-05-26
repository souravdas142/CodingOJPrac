ostream& operator<<(ostream& print, set<int>& st) {
    for(auto ele:st) {
        print<<ele<<" ";
    }
    return print;
}

class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<high) {
            int mid = low+(high-low)/2;
            if(mid%2==0) mid--;
            if(mid&1) {
                if(nums[mid]==nums[mid+1])
                    high = mid-1;
                else 
                    low = mid+1;
               
            }
        }
        return nums[high];
    }   
};