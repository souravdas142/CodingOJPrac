#define vi vector<int>
class Solution {
    double solve(vi& nums1,vi& nums2,int n,int m,int mn) {
        
        int mid = mn/2;
        
        int cnt = 0;
        int i = 0,j = 0;
        int cur = 0, prevCur = 0;
        double ans = 0.0;

        while(cnt<=mid) {
            prevCur = cur;
            if(i<n && j<m) {
                if(nums1[i]>nums2[j]) {
                    cur = nums2[j++];

                }
                else {
                    cur = nums1[i++];
                }
            }
            else if(i<n) {
                cur = nums1[i++];
            }
            else if(j<m) {
                cur = nums2[j++];
            }
            cnt++;
        }

        if(mn&1) return cur;
        else {
             ans = (cur+prevCur)/2.0;
        
        }
        return (double)ans;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int sz1 = nums1.size();
        int sz2 = nums2.size();
        int sz = sz1+sz2;
        double ans =  solve(nums1,nums2,sz1,sz2,sz);
        return ans;
        
    }
};