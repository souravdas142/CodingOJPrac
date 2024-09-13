
ostream& operator<<(ostream& print,vector<int>& vec) {
    print<<endl;
    for(auto a: vec) cout<<a<<"->";
    print<<endl;
    return print;
}


class Solution {
private:
    void calcNse(vector<int> &heights, vector<int>& nse, int n) {
        int i = n-1;
        stack<int> st;
        while(i>=0) {
            while(!st.empty() && heights[i]<=heights[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                nse[i] = n;
            }
            else {
                nse[i] = st.top();
            }
            st.push(i);
            i--;
        }
    } 

    void calcPse(vector<int>& heights, vector<int>& pse,int n) {
        int i = 0;
        stack<int> st;
        while(i<n) {
            
            while(!st.empty() && heights[i]<=heights[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                pse[i] = -1;
            }
            else {
                pse[i] = st.top();
            }
            st.push(i);


            i++;
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse(n),nse(n);
        calcNse(heights,nse,n);
        calcPse(heights,pse,n);

       // cout<<nse<<endl;
      //  cout<<pse<<endl;

        int i = 0;
        int maxi = 0;

        while(i<n) {

            int xpse = i-pse[i];
            int xnse = nse[i]-i-1;
            int x = xpse+xnse;
            int area = x*heights[i];

            maxi = max(maxi,area);

            i++;
        }
        return maxi;
    }
};