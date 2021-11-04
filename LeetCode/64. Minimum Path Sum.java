class Solution {
    public int minPathSum(int[][] grid) {
        int minSum = 0;
        int[][] gridSum = new int[grid.length][grid[0].length];
        gridSum[0][0] = grid[0][0];
        
        for(int i = 1; i < grid[0].length; i++) {
            gridSum[0][i] += gridSum[0][i - 1] + grid[0][i];
        }
        
        for (int i = 1; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (j == 0) {
                    gridSum[i][j] += gridSum[i - 1][j] + grid[i][j];
                }
                else {
                    gridSum[i][j] += Math.min(gridSum[i - 1][j] + grid[i][j], gridSum[i][j - 1] + grid[i][j]);
                }           
            }
        }
        
        minSum = gridSum[grid.length - 1][grid[0].length - 1];
             
        return minSum;
    }
}
