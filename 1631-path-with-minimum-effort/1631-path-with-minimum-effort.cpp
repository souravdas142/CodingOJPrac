#define pipii pair<int,pair<int,int> >
#define pii pair<int,int>
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        vector<vector<int> > distance(n,vector<int>(m,INT_MAX));

        distance[0][0] = 0;
        
        pq.push({0,{0,0}});
        int diff = 0;

        while(!pq.empty()) {
            pipii node = pq.top();
            pq.pop();
            
            int diff = node.first;
            pii loc = node.second;

            for(int i = 0;i<4;i++) {
                int newlocx = loc.first+dx[i];
                int newlocy = loc.second+dy[i];

                if(newlocx>=0 && newlocy>=0 && newlocx<n && newlocy<m) {
                    int absdiff = abs(heights[newlocx][newlocy]-heights[loc.first][loc.second]);
                    absdiff = max(absdiff,diff);
                    if(absdiff<distance[newlocx][newlocy]) {
                        distance[newlocx][newlocy] = absdiff;
                        pq.push({absdiff,{newlocx,newlocy}});
                    }
                }
            }



        }

        return distance[n-1][m-1];
    }
};