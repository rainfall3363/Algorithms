class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int answer = (j - i) * Math.min(height[i], height[j]);
        int jump = 1;
        
        while (i != j) {
            jump = 1;
            if (height[i] <= height[j]) {
                while (i + jump < j && height[i] >= height[i + jump]) {
                    jump++;
                }
                if (i + jump <= j) {
                    i += jump;                
                }
            }
            else if (height[i] > height[j]) {
                while (j - jump > i && height[j] >= height[j - jump]) {
                    jump++;
                }
                if (j - jump >= i) {
                    j -= jump;                
                }
            }
            
            answer = Math.max(answer, (j - i) * Math.min(height[i], height[j]));
        }
        
        return answer;
    }
}
