class Solution {
    public int minPlatform(int arr[], int dep[]) {
        //  code here
        ArrayList<int[]> comb = new ArrayList<>();
        int n = arr.length;
        for(int i = 0;i<n;i++) {
            comb.add(new int[]{arr[i],1});
            comb.add(new int[]{dep[i],0});
        }
        
        Collections.sort(comb,(a,b)->{
            if(a[0]==b[0]) {
                return Integer.compare(b[1],a[1]);
            }
            return Integer.compare(a[0],b[0]);
        });
        int cs = comb.size();
        // for(int i = 0;i<cs;i++) {
        //     System.out.print(comb.get(i)[0]+":"+comb.get(i)[1]+", ");
        // }
        
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i<cs;i++) {
            int status = comb.get(i)[1];
            if(status==1) {
                cnt++;
                ans = Math.max(cnt,ans);
            }
            else {
                cnt--;
            }
        }
        return ans;
        // int pf = 1;
        // int ans = 1;
        
        // // int start = comb.get(0)[0];
        // // int dept = comb.get(0)[1];
        // for(int i = 1;i<n;i++) {
        //     if(comb.get(i)[0]<comb.get(i-1)[1]) {
        //         pf++;
        //         ans = Math.max(ans,pf);
        //     }
        //     else {
        //         pf--;
        //     }
        // }
        // return ans;
    }
}
