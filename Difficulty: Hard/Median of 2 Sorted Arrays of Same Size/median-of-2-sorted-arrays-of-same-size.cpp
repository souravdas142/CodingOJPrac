class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n = a.size();
        int m = b.size();
        int mid = ((n+m)/2)+1;
        int cnt = 0;
        int prev = 0;
        int cur = 0;
        int i = 0;
        int j = 0;
        while(i<n && j<m) {
            prev = cur;
            if(a[i]<=b[j]) {
                cur = a[i];
                i++;
            }
            else {
                cur = b[j];
                j++;
            }
            cnt++;
            if(cnt==mid) break;
        }
        while(i<n && cnt<mid) {
            prev = cur;
            cur = a[i];
            i++;
            cnt++;
            //if(cnt==mid) break;
        }
        while(j<m && cnt<mid) {
            prev =cur;
            cur = b[j];
            j++;
            cnt++;
            //if(cnt==mid) break;
        }
        //cout<<prev<<" "<<cur<<" "<<cnt<<" "<<mid<<endl;
        if(!((n+m)&1)) {
            return (prev+cur)/2.0f;
        }
        return cur;
    }
};