class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        if(n>m) {
            return findMedianSortedArrays(nums2,nums1);
        }


        
        int med = (n+m+1)/2;

        int low = 0, high = n;
        double ans = 0;

        while(low<=high) {
            int mid1 = low+(high-low)/2;
            int mid2 = med - mid1; 

            int l1 = (mid1-1<0)?INT_MIN:nums1[mid1-1];
            int l2 = (mid2-1<0)?INT_MIN:nums2[mid2-1];
            int r1 = (mid1<n)?nums1[mid1]:INT_MAX;
            int r2 = (mid2<m)?nums2[mid2]:INT_MAX;

            if(l2>r1) {
                low = mid1+1;
            }
            else if(l1>r2) {
                high = mid1 - 1;
            }
            else {
                if((n+m)&1)
                    return max(l1,l2);
                ans = (max(l1,l2) + min(r1,r2))/2.0f;
                return ans;
            }

        }

        return ans;

        
    }
};