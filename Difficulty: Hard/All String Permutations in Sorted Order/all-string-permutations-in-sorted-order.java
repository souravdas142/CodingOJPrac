class Solution {
    
    public void swap(StringBuilder s, int index, int i) {
        char temp = s.charAt(i);
        s.setCharAt(i,s.charAt(index));
        s.setCharAt(index,temp);
    }
    
    public void solve(StringBuilder imdans,int n, int index, ArrayList<String> ans) {
        
        if(index>=n) {
            ans.add(imdans.toString());
            return;
        }
        
        for(int i = index;i<n;i++) {
            swap(imdans,index,i);
            solve(imdans,n,index+1,ans);
            swap(imdans,index,i);
        }
        
    }
    public ArrayList<String> permutation(String s) {
        // code here
        int n = s.length();
        int index = 0;
        StringBuilder imdans = new StringBuilder(s);
        ArrayList<String> ans = new ArrayList<>();
        solve(imdans,n,index,ans);
        Collections.sort(ans);
        return ans;
    }
}