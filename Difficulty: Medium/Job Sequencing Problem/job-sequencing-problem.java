class Solution {
    public ArrayList<Integer> jobSequencing(int[] deadline, int[] profit) {
        // code here
        int n = profit.length;
        ArrayList<int[]> arr = new ArrayList<>();
        int maxi = Integer.MIN_VALUE;
        for(int i = 0;i<n;i++) {
            arr.add(new int[] {deadline[i],profit[i]});
            maxi = Math.max(maxi,deadline[i]);
        }
        
        Collections.sort(arr,(a,b)->{
            if(a[1]==b[1]) {
                return Integer.compare(b[0],a[0]);
            }
            return Integer.compare(b[1],a[1]);
        });
        
        // for(int i = 0;i<n;i++) {
        //     System.out.println(arr.get(i)[0]+" "+arr.get(i)[1]);
        // }
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        TreeSet<Integer> st = new TreeSet<>();
        for(int i = 1;i<=maxi;i++) {
            st.add(i);
        }
        int cnt = 0;
        int profits = 0;
        
        for(int i = 0;i<n;i++) {
            int d = arr.get(i)[0];
            int p = arr.get(i)[1];
            
            int index = -1;
            
            try {
                index = st.floor(d);
            } catch (Exception e) {
                index = -1;
            }
            
            
            if(index>0) {
                profits+=p;
                cnt++;
                st.remove(index);
            }
        }
        
        ans.add(cnt);
        ans.add(profits);
        
        return ans;
    }
}