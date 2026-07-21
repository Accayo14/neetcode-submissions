class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        else return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int uu = findUPar(u);
        int uv = findUPar(v);

        if(uu == uv) return;
        else if(size[uu] > size[uv]){
            parent[uv] = uu;
            size[uu] += size[uv];
        }
        else{
            parent[uu] = uv;
            size[uv] += size[uu];
        }
    }

    int maxSize(){
        int maxsize = 0;
        for(int sizes: size) maxsize = max(maxsize, sizes);
        return maxsize;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DisjointSet ds(m*n);
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;

                count++;
                int index = i*n + j;

                for(int k = 0; k < 4; k++){
                    int newx = i + dx[k];
                    int newy = j + dy[k];

                    if(0 <= newx && newx < m && 0 <= newy && newy < n && grid[newx][newy] == 1){
                        int newIndex = newx*n + newy;
                        ds.unionBySize(index, newIndex);
                    }
                }
            }
        }

        if(count) return ds.maxSize();
        else return 0;
    }
};
