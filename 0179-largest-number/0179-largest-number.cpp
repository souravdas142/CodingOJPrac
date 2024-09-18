class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> arr;
        for(auto a:nums) {
            arr.push_back(to_string(a));
        }
        sort(arr.begin(),arr.end());
      /*  cout<<endl;
        for(auto a:arr) cout<<a;
        cout<<endl;
        */
    
    
        int n = nums.size();
        int i = 0,j = n-1;
        string ans = "";
        while(i<=j) {

            string x = arr[i];
            string y = arr[j];
            string xy = x+y;

            string yx = y+x;

            if(stol(xy)>stol(yx)) {
                ans+=x;
                i++;
            }
            else {
                ans+=y;
                j--;
            }
            
        }
        return ans;
    }
};