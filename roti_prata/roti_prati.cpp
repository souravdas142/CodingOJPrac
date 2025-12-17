#include <bits/stdc++.h>
using namespace std;

class Roti {

	public:
		bool letsCheck(vector<int>& cooks,int p, int c,int mid) {

			int cnt = 0;

			for(int i = 0;i<c;i++) {
				int j = 1;
				int total = 0;
				int k = 0;
				while(total<=mid) {
					total+=(j*cooks[i]);
					if(total>mid) break;
					if(cnt+k>=p) return true;
					k = j;
					j++;
				}

				

				cnt+=k;

				if(cnt>=p) return true;

			}

			return false;
				


		}

		int solve(vector<int>& cooks,int p, int c) {
			sort(cooks.begin(),cooks.end());
			int r = cooks[c-1];
			int high = ceil((r*(p*(p+1)))/2);
			int low = 1;
			int ans = 0;

			while(low<=high) {
				int mid = low+(high-low)/2;

				if(letsCheck(cooks,p,c,mid)) {
						ans = mid;
						high = mid-1;
				}
				else {
					low = mid+1;
				}
			}

			return ans;
			//return high;

		
						
		}

};

int main() {

	Roti roti;

	int tc = 1;
	cin>>tc;
	while(tc--) {
		int p,c;
		cin>>p>>c;
		vector<int> cooks(c,0);
		for(auto& e: cooks) {
			cin>>e;
		}

		int ans = roti.solve(cooks,p,c);
		cout<<ans<<endl;
	}

	return 0;


}
