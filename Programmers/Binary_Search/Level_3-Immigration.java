import java.util.Arrays;

class Solution {
    long solution(int n, int[] times) {
        long answer = times[times.length - 1] * (long)n;
        long immigrant;
        long start = 1;
        long end = answer;
        long mid;

        Arrays.sort(times);
        while (end >= start) {
            immigrant = 0;
            mid = (end + start) / 2;
            for (int i = 0; i < times.length; i++) {
                immigrant += mid / times[i];
            }

            if (immigrant >= n) {
                end = mid - 1;
                if (answer > mid)
                    answer = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return answer;
    }    
}
