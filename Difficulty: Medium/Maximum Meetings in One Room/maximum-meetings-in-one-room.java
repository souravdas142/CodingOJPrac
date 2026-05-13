class Solution {
    public List<Integer> maxMeetings(int[] s, int[] f) {
        // code here
        ArrayList<int[]> arr = new ArrayList<>();
        int n = s.length;
        for(int i = 0;i<n;i++) {
            arr.add(new int[]{s[i],f[i],i});
        }
        Collections.sort(arr,(a,b)->{
            if(b[1]==a[1]) {
                return Integer.compare(a[0],b[0]);
            }
            else return Integer.compare(a[1],b[1]);
        });
        
        int start = arr.get(0)[0];
        int end = arr.get(0)[1];
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(arr.get(0)[2]+1);
        
        for(int i = 1;i<n;i++) {
            if(arr.get(i)[0]>end) {
                ans.add(arr.get(i)[2]+1);
                start = arr.get(i)[0];
                end = arr.get(i)[1];
            }
        }
        Collections.sort(ans);
        return ans;
    }
}