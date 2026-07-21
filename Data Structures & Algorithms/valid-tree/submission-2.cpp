class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for(vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        q.push({0, -1});
        int count = 0;

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            if(vis[node] == 1) return false;
            else{
                vis[node] = 1;
                count++;
            }

            for(int adjn: adj[node]){
                if(adjn == parent) continue;

                if(vis[adjn] == 1) return false;
                else q.push({adjn, node});
            }
        }

        return count == n;
    }
};
