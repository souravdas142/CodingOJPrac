class Solution {
    void merge(vector<int>& nums,int sz,int left, int mid, int right) {
        vector<int> tmp;
        int lend = mid;
        int rf = mid+1;
        int a = left;
        int i = 0;
        while(left<=lend && rf<=right) {
            if(nums[left]>nums[rf]) {
                tmp.push_back(nums[rf]);
                rf++;
            }
            else if(nums[left]<=nums[rf]) {
                tmp.push_back(nums[left++]);
            }
            i++;
            
        }
        while(left<=lend) {
            tmp.push_back(nums[left++]);
            
        }
        while(rf<=right) {
            tmp.push_back(nums[rf++]);

        }
        i = a;
        int k = 0;
        while(i<=right) {
            nums[i] = tmp[k++];
            i++;
        }
    }
private:
    void msort(vector<int>& nums,int sz,int left,int right) {
        if(left>=right) return;

        int mid = left+(right-left)/2;
        msort(nums,mid-left+1,left,mid);
        msort(nums,right-mid,mid+1,right);
        merge(nums,sz,left,mid,right);
    }
public:
    void sortColors(vector<int>& nums) {

        int sz = nums.size();
        int left = 0,right  =sz - 1;
        msort(nums,sz,left,right);
        
        
    }
};