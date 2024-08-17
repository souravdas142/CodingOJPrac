class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2 = nums2.size();

        if(n2>n1) {
            return findMedianSortedArrays(nums2,nums1);
        }

        int n = n1+n2;
        int left = (n+1)/2;
        int low = 0, high = n1;

        while(low<=high) {

            int mid1 = (high+low)/2;
            int mid2 = left-mid1;
            int l1 = (mid1>0)?nums1[mid1-1]:INT_MIN, r1 = (mid1<n1)?nums1[mid1]:INT_MAX;
            int l2 = (mid2>0)?nums2[mid2-1]:INT_MIN, r2 = (mid2<n2)?nums2[mid2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1) {

                if(n&1) {
                    return (max(l1,l2))/1.0;
                }
                else {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }

            }
            else if(l1>r2) {
                high = mid1-1;
            }
            else if(l2>r1) {
                low = mid1+1;
            }
        }

        return 0.0;
    }
};