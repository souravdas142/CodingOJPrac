class Solution {
public:
    int search(vector<int>& nums, int target) {

        int sz = nums.size();
        int left = 0, right = sz-1;
        while(left<right) {

            int mid = left+(right-left)/2;

            if(nums[mid]>=nums[left]) { //sorted

                if(target>=nums[left] && target<=nums[mid])
                    right = mid;
                else 
                    left = mid+1;
            }
            else {  
                if(target>=nums[mid+1] && target<=nums[right])
                    left = mid+1;
                else 
                    right = mid;
            }
        }
        cout<<left<<" "<<right<<endl;
        if(nums[left]!=target) return -1;
        return left;
        
    }
};