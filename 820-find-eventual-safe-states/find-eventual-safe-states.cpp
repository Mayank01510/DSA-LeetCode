class Solution {
public:

    bool dfs(vector<vector<int>>& graph , vector<int>& state,int node ){
        if(state[node] == 1)return false; // cycle 
        if(state[node] == 2)return true ; // safe
        if(state[node] == 3)return false; //unsafe

        state[node] = 1;
        
        for(auto it : graph[node]){
                if(dfs(graph,state,it)  == false){
                    return false;
            }
        }
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>state(n,0);
        vector<int>ans;
        for(int i = 0;i<n;i++){
                if(dfs(graph,state ,i)) ans.push_back(i);
        }
        return ans;
    }
};