class Solution {
    
    private int solve(int[] arr, int index, int n,int[] visited) {
        if(index>=n) {
            return 0;
        }
        
        if(visited[index]!=0) return visited[index];
        
        int missing = solve(arr,index+1,n,visited);
        int including = arr[index]+solve(arr,index+2,n,visited);
        
        visited[index] =  Math.max(missing,including);
        return visited[index];
        
    }
    
    public int findMaxSum(int arr[]) {
        // code here
        int n = arr.length;
        
        int index = 0;
        int sum1 = 0;
        int sum2 = 0;
        
        int[] visited = new int[n];
        
        int ans = solve(arr, index, n,visited);
        return ans;
        //return Math.max(sum1,sum2);
        
        
    }
}