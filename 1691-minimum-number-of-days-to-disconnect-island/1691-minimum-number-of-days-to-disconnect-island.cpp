class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int Count(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
    
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<int>> original = grid;
        if (Count(original) != 1) return 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    vector<vector<int>> temp = grid;
                    if (Count(temp) != 1) return 1;
                    grid[i][j] = 1; 
                }
            }
        }
        
        return 2;
    }
};
