
class state {
    public:
        int containerA;
        int containerB;
        state() {
            containerA = 0,
            containerB = 0;
        }
        state(int a, int b) {
            containerA = a;
            containerB = b;
        }

};

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        vector<vector<bool>> visited(x+1,vector<bool>(y+1,false));
        queue<pair<int,state>> que;
        visited[0][0] = true;
        que.push({0,state(0,0)});

        while(!que.empty()) {
            pair<int,state> u = que.front();
            que.pop();
            
            if(u.second.containerA==target || u.second.containerB == target) {
                return true;
            }

            int steps = u.first+1;

            pair<int,state> v1({steps,{0,u.second.containerB}});
            pair<int,state> v2({steps,{u.second.containerA,0}});

            int cap = y - u.second.containerB;
            int canBefull = min(cap,u.second.containerA);
            int nwcontA = u.second.containerA-canBefull;
            int nwcontB = u.second.containerB+canBefull;

            pair<int,state> v3({steps,{nwcontA,nwcontB}});
            
            cap = x - u.second.containerA;
            canBefull = min(cap,u.second.containerB);
            nwcontA = u.second.containerA+canBefull;
            nwcontB = u.second.containerB - canBefull;
            pair<int,state> v4({steps,{nwcontA,nwcontB}});

            pair<int,state> v5({steps,{x,u.second.containerB}});
            pair<int,state> v6({steps,{u.second.containerA,y}});

            if(!visited[v1.second.containerA][v1.second.containerB]) {
                visited[v1.second.containerA][v1.second.containerB] = true;
                que.push(v1);
            }
            if(!visited[v2.second.containerA][v2.second.containerB]) {
                visited[v2.second.containerA][v2.second.containerB] = true;
                que.push(v2);
            }
            if(!visited[v3.second.containerA][v3.second.containerB]) {
                visited[v3.second.containerA][v3.second.containerB] = true;
                que.push(v3);
            }
            if(!visited[v4.second.containerA][v4.second.containerB]) {
                visited[v4.second.containerA][v4.second.containerB] = true;
                que.push(v4);
            }
            if(!visited[v5.second.containerA][v5.second.containerB]) {
                visited[v5.second.containerA][v5.second.containerB] = true;
                que.push(v5);
            }
            if(!visited[v6.second.containerA][v6.second.containerB]) {
                visited[v6.second.containerA][v6.second.containerB] = true;
                que.push(v6);
            }
            
            

        }



        return false;

    }
};