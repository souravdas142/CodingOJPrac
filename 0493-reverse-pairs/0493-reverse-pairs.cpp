ostream& operator<<(ostream& print,vector<int> &vec) {
    print<<endl;
    for(int a:vec) print<<a<<" ";
    print<<endl;
    return print;
}

#define vi vector<int>

class Solution {

private:

    void merge(vi& nums, int& ans,int left, int mid, int right ) {
        int bleft = left;
        int lend = mid;
        int rf = mid+1;
        vi res(right-left+1);
        int k = rf;
        for(int i = left;i<=lend;i++) {
            
            while(k<=right  && nums[i]>((long long)nums[k])*2) {
                
                k++;
            }

            ans+=(k-rf);

        }

        k = 0;
        while(left<=lend && rf<=right) {
            if(nums[left]>nums[rf]) {
                res[k++]=nums[rf];
               
                rf++;
            }
            else if(nums[left]<=nums[rf]) {
                res[k++]=nums[left];
                left++;
            }
        }

        while(left<=lend) {
            res[k++] = nums[left++];

        }
        while(rf<=right) {
            res[k++] = nums[rf++];
        }

        for(int a: res) {
            nums[bleft++] = a;
        }
    }

    void msort(vi& nums,int &ans,int left, int right) {
        if(left>=right) return;
        int mid = left+(right-left)/2;
        msort(nums,ans,left,mid);
        msort(nums,ans,mid+1,right);
        merge(nums,ans,left,mid,right);
    }
public:
    int reversePairs(vector<int>& nums) {

       int sz = nums.size();
       int ans = 0;
      // cout<<nums<<endl;
       msort(nums,ans,0,sz-1);
      // cout<<nums<<endl;
       return ans;
        
    }
};