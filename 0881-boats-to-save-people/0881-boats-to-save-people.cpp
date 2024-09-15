class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int total = 0;
        int k = limit;
        for(int i= 0;i<n;i++) {
            if(people[i]>k) {
                total++;
                k = limit;
            }
            k-=people[i];
        }

        return total+1;
    }
};