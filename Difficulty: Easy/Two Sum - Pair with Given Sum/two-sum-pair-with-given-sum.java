class Solution {
    boolean twoSum(int arr[], int target) {
        // code here
        Map<Integer,Boolean> mp = new HashMap<>();
        int n = arr.length;
        
        int j = 0;
        while(j<n) {
            int need = target - arr[j];
            
            if(mp.containsKey(need)) {
                return true;
            }
            
            mp.put(arr[j],true);
            
            j++;
        }
        
        return false;
    }
}