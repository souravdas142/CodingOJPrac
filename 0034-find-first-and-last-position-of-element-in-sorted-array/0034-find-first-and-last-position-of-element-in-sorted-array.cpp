class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int right = nums.size()-1;
       int left = 0;
       int firstpos = -1;
       int firstEnc = -1;

       while(left<=right) {
            int mid = left+(right-left)/2;
            if(nums[mid]==target) { // we found but we may have anoter target on left
                right = mid-1;
                firstpos = mid;
                if(firstEnc==-1) firstEnc = mid;

            }
            else if(nums[mid]>target) {
                right = mid-1;
            }
            else if(nums[mid]<target) {
                left = mid+1;
            }
       } 

        if(firstEnc==-1) return {firstpos,firstpos};
        cout<<firstEnc<<endl;

        left = firstEnc;
        right = nums.size()-1;
        int sec = -1;

        while(left<=right) {
            int mid = left+(right-left)/2;

            if(nums[mid]==target) { // we may have another in right
                sec = mid;
                left = mid+1;
            }
            else if(nums[mid]>target) {
                right = mid-1;
            }
            else if(nums[mid]<target) {
                left = mid+1;
            }
        }

        if(firstpos==-1 && sec == -1) return {-1,-1};
        if(sec==-1) return {firstpos,firstpos};
        return {firstpos,sec};


        //return {firstpos,-1};

    }
};