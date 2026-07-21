class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            visited[x][y] = 1;
            q.pop();

            for(int k = 0; k < 4; k++){
                int newx = x + dx[k];
                int newy = y + dy[k];

                if(0 <= newx && newx < m && 0 <= newy && newy < n && visited[newx][newy] == 0 && grid[newx][newy] == '1'){
                    q.push({newx, newy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    islands++;
                    bfs(grid, visited, i, j);
                }
            }
        }

        return islands;
    }
};
