class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    queue<pair<pair<int, int>, int>> q;
                    q.push({{i, j}, 0});
                    vector<int> dx = {0, -1, 0, 1};
                    vector<int> dy = {-1, 0, 1, 0};

                    while(!q.empty()){
                        int r = q.front().first.first;
                        int c = q.front().first.second;
                        int dist = q.front().second;
                        q.pop();

                        for(int k = 0; k < 4; k++){
                            int x = r + dx[k];
                            int y = c + dy[k];

                            if(0 <= x && x < m && 0 <= y && y < n && grid[x][y] > 0){
                                if(dist + 1 < grid[x][y]){
                                    grid[x][y] = dist+1;
                                    q.push({{x, y}, dist+1});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};
