class Solution {
    public int secondsBetweenTimes(String startTime, String endTime) {
        
        String[] st = startTime.split(":");
        String[] endt = endTime.split(":");

        int start = 0;
        int end = 0;

        int mul = 3600;
        for(String s : st) {
            start += (Integer.parseInt(s)*mul);
            mul/=60;
        }

        mul = 3600;
        for(String e: endt) {
            end += (Integer.parseInt(e)*mul);
            mul/=60;
        }

        return Math.abs(end-start);

        

    }
}