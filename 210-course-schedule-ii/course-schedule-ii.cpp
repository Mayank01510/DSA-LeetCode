class Solution {
public:

    bool dfs( vector<vector<int>> adj,vector<int>& visit,int node , vector<int>& path){
        visit[node] = 1;

        for(auto it : adj[node]){
            if(visit[it] == 0){
                if(dfs(adj , visit , it,path))return true;
            }
            else if(visit[it] == 1)return true;
        }
        visit[node] = 2;
        path.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }
        vector<int>visit(numCourses,0);
        vector<int> path;
        for(int i = 0;i<numCourses;i++){
            if(!visit[i]){
                if(dfs(adj,visit ,i,path))return {};
            }
        }
        reverse(path.begin(),path.end());
        return path;
    }
};