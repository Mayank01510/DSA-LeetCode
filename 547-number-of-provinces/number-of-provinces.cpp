class Solution {
public:

    void dfs(vector<vector<int>>& isConnected , vector<int>& visit , int node){
        visit[node] = 1;

        for(int j = 0;j<isConnected.size();j++){
            if(isConnected[node][j] == 1 && visit[j] == 0){
                dfs(isConnected,visit,j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visit(n,0);

        int count = 0;
        
        for(int i = 0;i<n;i++){
            if(visit[i] == 0){
                dfs(isConnected , visit , i);
                count++;
            }
        }
        return count;
    }
};