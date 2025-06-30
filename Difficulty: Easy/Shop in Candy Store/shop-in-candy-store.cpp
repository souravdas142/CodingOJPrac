class Solution {
  public:
    vector<int> candyStore(int cand[], int n, int k) {
        // Write Your Code here
       
        sort(cand,cand+n);
        // for(int i = 0;i<n;i++) cout<<cand[i]<<" ";
        // cout<<endl;
        int i = 0;
        int j = n-1;
        int mini = 0;
        while(i<=j) {
            mini+=cand[i];
            i++;
            j-=k;
        }
        i = 0,j = n-1;
        int maxi = 0;
        while(i<=j) {
            maxi+=cand[j];
            j--;
            i+=k;
        }
        return {mini,maxi};
    }
};