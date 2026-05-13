class Solution {
    static int solve(int bt[]) {
        // code here
        Arrays.sort(bt);
        int n = bt.length;
        int wt = 0;
        int totalTime = 0;
        for(int i = 1;i<n;i++) {
            wt+=bt[i-1];
            totalTime+=wt;
        }
        double avg = ((double)totalTime/(double)n);
        return (int)Math.floor(avg);
    }
}
