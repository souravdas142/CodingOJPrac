
ostream& operator<<(ostream& print, vector<int>& p) {
    for(auto e: p) {
        print<<e<<" ";
    }
    return print;
}

class Solution {
public:

    void nse(vector<int>& heights, vector<int>& nsePos, int n) {
        stack<int> st;
        int j = n-1;
        while(j>=0) {

            while(!st.empty() && heights[st.top()]>=heights[j]) {
                st.pop();
            }
            if(!st.empty()) {
                nsePos[j] = st.top();
            }
            st.push(j);

            j--;
        }
        
    }

    void pse(vector<int>& heights, vector<int>& psePos, int n) {
        stack<int> st;
        int j = 0;
        while(j<n) {
            while(!st.empty() && heights[st.top()]>=heights[j]) {
                st.pop();
            }
            if(!st.empty()) {
                psePos[j] = st.top();
            }
            st.push(j);
            j++;
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psePos(n,-1),nsePos(n,n);
        pse(heights,psePos,n);
        nse(heights,nsePos,n);
        cout<<psePos<<endl<<nsePos<<endl;
        int maxArea = 0;

        int j = 0;
        while(j<n) {

            int cur = heights[j];
            int area = (nsePos[j]-psePos[j]-1)*cur;
            maxArea = max(maxArea,area);

            j++;
        }

        return maxArea;
    }
};