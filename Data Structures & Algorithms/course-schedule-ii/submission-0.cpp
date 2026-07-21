class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(vector<int> prereq: prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
            indegree[prereq[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) if(indegree[i] == 0) q.push(i);

        int finish = 0;
        vector<int> output(numCourses);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            output[numCourses - finish - 1] = node;
            finish++;

            for(int adjnode: adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode] == 0) q.push(adjnode);
            }
        }

        if(finish != numCourses) return {};

        return output;
    }
};
