class Solution {
    void solve(vector<int>& height,int sz,int lft, int right,int& area) {
        if(lft>right) return;

        int carea = (right-lft) * min(height[lft],height[right]);
        area = max(area,carea);
        if(height[lft]<height[right])
            solve(height,sz,lft+1,right,area);
        else
            solve(height,sz,lft,right-1,area);
        

    }
public:
    int maxArea(vector<int>& height) {

        int sz = height.size();
        int lft = 0, right = sz-1;
        int area=0;
        solve(height,sz,lft,right,area);
        cout<<area<<endl;
        return area;
        
    }
};