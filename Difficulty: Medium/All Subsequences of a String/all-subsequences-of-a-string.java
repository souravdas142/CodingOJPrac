class Solution {
    
    private void solve(String s, int index, int n, List<String> ans, StringBuilder imdAns) {
        if(index>=n) {
            ans.add(imdAns.toString());
            return;
        }
        
        solve(s,index+1,n,ans,imdAns);
        
        imdAns.append(s.charAt(index));
        solve(s,index+1,n,ans,imdAns);
        imdAns.deleteCharAt(imdAns.length()-1);
    }
    
    public List<String> powerSet(String s) {
        // Code here
        int n = s.length();
        List<String> ans = new ArrayList<>();
        
        StringBuilder imdAns = new StringBuilder();
        int index = 0;
        
        solve(s,index,n,ans,imdAns);
        
        Collections.sort(ans);
        
        return ans;
    }
}