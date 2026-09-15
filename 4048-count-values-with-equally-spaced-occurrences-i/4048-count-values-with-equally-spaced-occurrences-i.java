class Solution {
    public int countSpecialIntegers(int[] nums) {
        int ans = 0;
        Map<Integer,ArrayList<Integer>> mp = new HashMap<>();
        int n = nums.length;
        for(int i = 0;i<n;i++) {
            ArrayList<Integer> temp = mp.getOrDefault(nums[i],new ArrayList<>());
            temp.add(i);
            mp.put(nums[i],temp);
        
        }

 
        for(Integer val: mp.keySet()) {
            ArrayList<Integer> pos = mp.get(val);
            if(pos.size()==3) {
                int x = pos.get(0);
                int y = pos.get(1);
                int z = pos.get(2);
                if(y-x == z-y) {
                    ans++;
                }
            }
        }

        return ans;
    }
}