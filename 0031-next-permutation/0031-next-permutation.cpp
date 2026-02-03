#define debug(x) cout<<#x<<" = "<<x<<endl;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int dip = 0;
        int i = n-1;

        while(i>0) {
            if(arr[i]>arr[i-1]) {
                dip = i-1;
                break;
            }
            i--;
        }

        //debug(dip);

        i = n-1;

        while(dip>0 && i>dip) {
            if(arr[i]>arr[dip]) {
                swap(arr[i],arr[dip]);
                break;
            }
            i--;
        }
        if(dip==0) reverse(arr.begin(),arr.end());
        else reverse(arr.begin()+dip+1,arr.end());
    }
};