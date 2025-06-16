class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftWall = height[0];
        int rightWall = height[n-1];
        int l = 0;
        int r = n-1;
        int sum = 0;
        int cur = 0;

        while(l<=r) {

            if(rightWall>=leftWall) {
                int mini = min(leftWall,rightWall);
                int x = max(0,mini-height[l]);
                if(leftWall<height[l]) {
                    leftWall = height[l];
                }
                sum+=x;
                l++;
            }
            else if(leftWall>=rightWall) {
                int mini = min(leftWall,rightWall);
                int x = max(0,mini-height[r]);
                sum+=x;
                if(rightWall<height[r]) {
                    rightWall = height[r];
                }
                r--;
               
            }

        }
        return sum;
    }
};