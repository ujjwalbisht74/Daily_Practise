class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    res += (grid[i][j] * 6);
                  
                    res -= (grid[i][j] - 1) * 2;
                    if (j > 0) {
                        res -= min(grid[i][j], grid[i][j - 1]) * 2;
                    }
                    if (i > 0) {
                        res -= min(grid[i][j], grid[i - 1][j]) * 2;
                    }
                }
            }
        }
        
        return res;
    }
};