class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int i = 0, j = 0;
        int total = 0;
        int ans = 0;

        while(j<k) {
            total+=cardPoints[j];
            j++;
        }

        j= n-1;
        i = k-1;
        ans = total;

        while(i>=0) {
            total-=cardPoints[i];
            i--;
            total+=cardPoints[j];
            j--;
            ans = max(ans,total);
        }

        return ans;
    }
};