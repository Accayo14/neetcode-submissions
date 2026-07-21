class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }

        grid[r][c] = 0;
        int res = 1;

        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            res += dfs(grid, r + dx[i], c + dy[i]);
        }

        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int area = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    area = max(area, dfs(grid, i, j));
                }
            }
        }

        return area;
    }
};
